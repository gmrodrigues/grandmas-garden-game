// TIM2.EXE: FUN_1a9e_0033 @ file 0x01FC13 Ghidra 0x1AA13
// Subsystem: utility | Size: 80 bytes


undefined2 __cdecl16near FUN_1a9e_0033(void)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 1;
  if ((DAT_5b41_02e9 & 0x20) == 0) {
    uVar1 = FUN_1a9e_0b56();
  }
  else {
    while ((iVar3 != 0 && (uVar2 = FUN_1a9e_0131(), uVar2 != 0xffff))) {
      if ((uVar2 & 0x80) == 0) {
        iVar3 = FUN_1a9e_0225(uVar2 & 0x7f);
      }
      else {
        uVar1 = FUN_1a9e_0131(uVar2 & 0x7f);
        iVar3 = FUN_1a9e_02a5(uVar1);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

