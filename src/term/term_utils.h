#ifndef TERM_UTILS
#define TERM_UTILS

void TERM_disableRawMode();
void TERM_enableRawMode();
bool TERM_IsCtrlCombination(Char8 key, u8 letter);

#endif // TERM_UTILS
