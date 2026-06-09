// TIM2.EXE: FUN_460e_22ac @ file 0x04D58C Ghidra 0x4838C
// Subsystem: misc | Size: 128 bytes


undefined2 __cdecl16far FUN_460e_22ac(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined2 uVar2;
  
  if (((DAT_5b41_1cea == '\0') && (DAT_5b41_1ce6 == 0 && DAT_5b41_1ce8 == 0)) ||
     (DAT_5b41_1cea == '\0')) {
LAB_460e_2326:
    uVar2 = 0;
  }
  else {
    if (param_2 < DAT_5b41_1cef) {
      iVar1 = FUN_460e_232c(0);
      if (iVar1 != 0) goto LAB_460e_2326;
    }
    if (((param_1 == 0) || (param_1 == DAT_5b41_1ceb)) && (param_3 == 0)) {
      iVar1 = FUN_460e_232c(param_1);
      if (iVar1 == 0) goto LAB_460e_22ff;
    }
    else {
LAB_460e_22ff:
      if (param_1 != 0) {
        iVar1 = FUN_460e_215d(param_1,0);
        if (iVar1 == 0) goto LAB_460e_2326;
      }
      if (DAT_5b41_1ceb != 0) {
        FUN_1000_137d();
      }
      DAT_5b41_1cef = param_2;
    }
    uVar2 = 1;
  }
  return uVar2;
}

