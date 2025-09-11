
EDT_KeyResult EDT_readKey() {
    for (;;) {
        u8 buf[4] = {0};
        i64 n;

        n = read(STDIN_FILENO, buf, 4);

        if (n == 0) {
           continue;
        }
        if (n == -1) {
            write(STDOUT_FILENO, "\x1b[2J", 4);
            write(STDOUT_FILENO, "\x1b[H", 3);
            OS_PANIC("read");
        }

        Char8 c = Char8FromBytes(buf);;
        if (c.chr[0] == '\x1b') {
            char seq[3];
            if (read(STDIN_FILENO, &seq[0], 1) != 1) {
                return EDT_makeCharKeyResult(c);
            }
            if (read(STDIN_FILENO, &seq[1], 1) != 1) {
                return EDT_makeCharKeyResult(c);
            }
            if (seq[0] == '[') {
                switch (seq[1]) {
                    case 'A': {
                        return EDT_makeEscSeqResult(ARROW_DOWN);
                    case 'B':
                        return EDT_makeEscSeqResult(ARROW_DOWN);
                    case 'C':
                        return EDT_makeEscSeqResult(ARROW_RIGHT);
                    case 'D':
                        return EDT_makeEscSeqResult(ARROW_LEFT);
               }
            }
        }
            return EDT_makeCharKeyResult(c);
        } else {
            return EDT_makeCharKeyResult(c);
        }
    }
}

void editorMoveCursor(u8 key) {
  switch (key) {
    case 'a':
      e_conf.cx--;
      break;
    case 'd':
      e_conf.cx++;
      break;
    case 'w':
      e_conf.cy--;
      break;
    case 's':
      e_conf.cy++;
      break;
  }
}


void EDT_processKey(EDT_KeyResult result) {
    if (result.tag == EDT_ESC_SEQ) {
    }
    if (result.tag == CHAR8_KEY){
        if (TERM_IsCtrlCombination(result.chr, 'q')) {
            write(STDOUT_FILENO, TERM_CLEAR_SCREEN.str, 4);
            write(STDOUT_FILENO, TERM_MOVE_CURSOR_TOP_LEFT.str, 3);
            exit(0);
        }
        if (result.chr.chr[0] != '\0') {
            Char8Print(&result.chr);
            fflush(stdout);
        }
    }

}


EDT_KeyResult EDT_makeCharKeyResult(Char8 chr) {
    EDT_KeyResult r;
    r.tag = CHAR8_KEY;
    r.chr = chr; 
    return r;
 }

EDT_KeyResult EDT_makeEscSeqResult(EDT_EscSeq key) {
    EDT_KeyResult r;
    r.tag = EDT_ESC_SEQ;
    r.esc_seq = key; 
    return r;
 }
