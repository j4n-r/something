#ifndef TERM_UTILS_H
#define TERM_UTILS_H

void TERM_disableRawMode();
void TERM_enableRawMode();
bool TERM_IsCtrlCombination(Char8 key, u8 letter);

#endif // TERM_UTILS_H
