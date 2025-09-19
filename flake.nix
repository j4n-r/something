{
  description = "a basic flake with a shell";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        packages = {
          default = pkgs.stdenv.mkDerivation {
            pname = "something";
            version = "0.0.1";
            src = ./.;

            nativeBuildInputs = [ pkgs.gcc];

            CFLAGS = "-Wextra -Wall -pedantic -std=c11 -g3";
            CC = "gcc";

            buildPhase = ''
                mkdir -p build
                $CC $CFLAGS ./src/edits/kilo.c -o build/kilo
            '';

            installPhase = ''
                mkdir -p $out/bin
                cp build/kilo $out/bin/
            '';
          };
          test_ansi = pkgs.writeShellScriptBin "test_ansi" ''
            printf "$1"
            sleep 0.1
          '';

        };

        devShells.default = pkgs.mkShell {
          packages = with pkgs; [
            pkg-config
            gcc
            gf
            valgrind
            wayland
            wayland-utils
            wayland-protocols
            wayland-scanner
          ];
          env = {
            WAYLAND_DEBUG = true;
          };
        };
        apps = {
          default = {
            type = "app";
            program = "${self.packages.${system}.default}/bin/kilo";
          };
          test_ansi = {
            type = "app";
            program = "${self.packages.${system}.test_ansi}/bin/test_ansi";
          };
        };
      });
}
