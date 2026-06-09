// TIM2.EXE: FUN_2321_04db @ file 0x0288EB Ghidra 0x236EB
// Subsystem: misc | Size: 188 bytes


void __cdecl16far FUN_2321_04db(void)

{
  bool bVar1;
  int iVar2;
  
  if (DAT_5b41_04f7 == 0) {
    if (((DAT_5b41_0953 != 0) && (DAT_554c_2f1c < 0x13ec)) && (DAT_5b41_0951 != 0)) {
      DAT_5b41_0951 = DAT_5b41_0951 + -1;
    }
    if (DAT_5b41_04f5 != 0) {
      DAT_5b41_04f5 = DAT_5b41_04f5 + -1;
    }
    if (DAT_5b41_0507 != 0) {
      DAT_5b41_0507 = DAT_5b41_0507 + -1;
    }
    if (DAT_5b41_10ba != 0) {
      DAT_5b41_10ba = DAT_5b41_10ba + -1;
    }
    if (DAT_5b41_0509 != 0) {
      DAT_5b41_0509 = DAT_5b41_0509 + -1;
    }
    if (DAT_5b41_1b9c == 0) {
      if (DAT_554c_02e2 != 0) {
        DAT_554c_02e2 = DAT_554c_02e2 + -1;
      }
    }
    else {
      DAT_554c_02e2 = 0xe10;
    }
    iVar2 = FUN_406b_03cb(0xfffc,0);
    if (((0 < iVar2) && (iVar2 < 4)) &&
       (bVar1 = DAT_5b41_0471 == '\0', DAT_5b41_0471 = DAT_5b41_0471 + -1, bVar1)) {
      DAT_5b41_0470 = DAT_5b41_0470 + '\x01';
      if ('\x03' < DAT_5b41_0470) {
        DAT_5b41_0470 = '\0';
      }
      DAT_5b41_0471 = '\x0f';
      FUN_406b_0d37((int)*(char *)(DAT_5b41_0470 + 0x1dc));
    }
  }
  return;
}

