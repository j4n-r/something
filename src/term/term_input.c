u8 TERM_readByte() {
    u8 buf[1] = {0};
    u8 n = read(STDIN_FILENO, buf,1);
    if (n == -1) {
        OS_PANIC("read");
    }
    return buf[0];
}

u8 peekAndRead(Queue *que) {
    u8 *next = QueuePeek(sizeof(u8), 1);
    if (next == NULL) {
        u8 byte = TERM_readByte(); 
        return byte;
    }
    QueuePop(que, u8);
    return *next;
}

Result_KeyEvent TERM_parseTerminalInput(Arena *arena) {
    Queue que = QueueNew(arena, sizeof(u8*1000));
    for (;;) {
        KeyEvent key_event = {0};
        key.bytes = ArenaPush(arena, 4);
        u8 res = TERM_readByte(&que);
        if (res == 0) {
            // TODO idk what to do here yet, if I put continue here the function
            // blocks until it gets a valid KeyEvent
            continue;
        }
        queuePush(&que,res);
        /*************************/
        /* Parse Escape Sequence */
        /*************************/
        if (byte == 0x1b) {
            u8 next = TERM_readByte(&que); // currently 50ms timout (VTIME flag)
            // no bytes were added, this is only ESC key
            if (next == 0) {
                key_event.s_key = ESC;
                key_event.bytes[0] = byte;
                key_event.size = 1;
                queuePop(&que, sizeof(u8));
                continue;
            } else {
                //  push the read byte which was not used to the queue
                queuePush(&que, next);  
            }
            /*************/
            /* Parse ALT */
            /*************/
            if (next <= 0x1F) {
                key_event.mod = ALT; 
                KeyEvent.bytes[0] = next;
                KeyEvent.size = 1;
                queuePop(&que, sizeof(u8));
                return OK(KeyEvent, key_event);
            }

            // TODO parse esc sequence
        }


        /**************/
        /* Parse CTRL */
        /**************/
        if (byte <= 0x1F) {
            key_event.mod = CTRL; 
            keyEvent.bytes[0] = byte + 0x40;
            keyEvent.size = 1;
            queuePop(&que, sizeof(u8));
            return OK(KeyEvent, key_event);
        }

        /*********************/
        /* Parse UTF-8 Bytes */
        /*********************/
        // TODO refactor the rest
        if ((byte & 0x80) == 0x00) {
            keyEvent.bytes[0] = byte;        
            keyEvent.size = 1; 
            queuePop(&que, sizeof(u8));
            return OK(KeyEvent, keyEvent);
        }
        if ((bytes[0] & 0xE0) == 0xC0) {
            buf[1] = peekAndRead(&que);
            if (buf8[0] & 0xC0) == 0x80) {
                keyEvent.bytes[0] = byte;
                keyEvent.bytes[1] = buf8[0];
                return OK(KeyEvent, keyevent);
            }
        }
    };
}

