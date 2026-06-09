// TIM2.EXE: FUN_4bdc_3c26 @ file 0x054BE6 Ghidra 0x4F9E6
// Subsystem: physics | Size: 188 bytes


undefined2 __cdecl16far
FUN_4bdc_3c26(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  bool bVar2;
  
  if ((DAT_554c_5740 != 0 || DAT_554c_5742 != 0) || (DAT_554c_5744 != 0 || DAT_554c_5746 != 0)) {
    return 1;
  }
  bVar2 = param_1 == -1;
  if (bVar2) {
    param_1 = 2;
  }
  iVar1 = FUN_4bdc_24de(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    if ((!bVar2) && (DAT_554c_4f22 == '\0')) {
      FUN_1a9e_3f33(0xd);
      DAT_554c_5738 = 1;
    }
    if ((!bVar2) && (DAT_554c_5740 != 0 || DAT_554c_5742 != 0)) {
      DAT_554c_573a = FUN_1a9e_3ec6(0x1944,0x4bdc,4);
    }
    if ((!bVar2) && (DAT_554c_5744 != 0 || DAT_554c_5746 != 0)) {
      DAT_554c_573c = FUN_1a9e_3ec6(0x1364,0x1000,2);
    }
    FUN_4bdc_2689();
    return 1;
  }
  return 0;
}

