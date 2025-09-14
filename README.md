# Something
Thanks https://www.rfleury.com/ for the content and https://github.com/EpicGamesExt/raddebugger (ideas, and some interfaces are stolen from him) \
And thanks https://viewsourcecode.org/snaptoken/kilo

### Conventions:
- Structs: PRE_ (prefix + CamelCase)
- base Functions: camelCase
- Functions with Prefix: PRE_camelCase 
- Functions without prefix: PascaleCase 
- Variables: snake_case 
- Macros: PRE_CAPS_LOCK

### Helper Commands

``` fish
 nix run .#test_ansi '\x1b[6n'
```

``` fish
showkey -a
```

## Notes
- [ ] Bracketed paste mode:
- [ ] Resizes & signals:

### Keyboard input
Since the goal is to have vim like layers (normal, insert, visual) and most
of the shotcuts will be with a  <leader> key (SPC) i will implement the kitty 
keyboard protocol and reduce the 

