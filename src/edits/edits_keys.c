
EDT_KeyResult EDT_readKey() {
    for (;;) {
        u8 bytes[4] = {0};
        i64 n;

        n = read(STDIN_FILENO, bytes, 1);

        if (n == 0) {
           continue;
        }
        if (n == -1) {
            write(STDOUT_FILENO, "\x1b[2J", 4);
            write(STDOUT_FILENO, "\x1b[H", 3);
            OS_PANIC("read");
        }

        if (bytes[0] == '\x1b') {
    result.str = (u8*) ArenaPush(arena, size);
            if (read(STDIN_FILENO, &buf[1], 1) != 1) { }
            if (read(STDIN_FILENO, &buf[2], 1) != 1) {
                return EDT_makeCharKeyResult(c);
            }
            if (buf[1] == '[') {
                switch (buf[2]) {
                    case 'A': 
                        return EDT_makeEscSeqResult(ARROW_UP);
                    case 'B':
                        return EDT_makeEscSeqResult(ARROW_DOWN);
                    case 'C':
                        return EDT_makeEscSeqResult(ARROW_RIGHT);
                    case 'D':
                        return EDT_makeEscSeqResult(ARROW_LEFT);
                    }
                }
        }

        Char8 chr = {0};
        if ((bytes[0] & 0x80) == 0x00) {
            Char8 c = Char8FromBytes(bytes);;
        }
        if (read(STDIN_FILENO, &seq[0], 1) != 1)
        if ((bytes[0] & 0xE0) == 0xC0 &&
                (bytes[1] & 0xC0) == 0x80)
        {
            chr.size = 2;
            memcpy(&chr.chr, bytes,2);
        } else if ((bytes[0] & 0xF0) == 0xE0 &&
                (bytes[1] & 0xC0) == 0x80 &&
                (bytes[2] & 0xC0) == 0x80)
        {
            chr.size = 3;
            memcpy(&chr.chr, bytes,3);
        } else if ((bytes[0] & 0xF8) == 0xF0 &&
                (bytes[1] & 0xC0) == 0x80 &&
                (bytes[2] & 0xC0) == 0x80 &&
                (bytes[3] & 0xC0) == 0x80)
        { 
            chr.size = 4;
            memcpy(&chr.chr, bytes,4);
            return EDT_makeCharKeyResult(c);
            }
        }
}

void EDT_handleEscapeSequence(EDT_EscSeq seq) {
  switch (seq) {
    case ARROW_LEFT:
        e_conf.cx--;
        break;
        case ARROW_RIGHT:
        e_conf.cx++;
        break;
        case ARROW_UP:
        e_conf.cy--;
        break;
        case ARROW_DOWN:
        e_conf.cy++;
        break;
  }
}


void EDT_processKey(EDT_KeyResult result) {
    if (result.tag == EDT_ESC_SEQ) {
        EDT_handleEscapeSequence(result.esc_seq);
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


EDT_C
