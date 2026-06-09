// TIM2.EXE: FUN_49fc_0004 @ file 0x04F1C4 Ghidra 0x49FC4
// Subsystem: misc | Size: 108 bytes


undefined2 __cdecl16far FUN_49fc_0004(int param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  char local_52;
  char local_51;
  char local_50;
  
  if (param_1 == 0 && param_2 == 0) {
LAB_49fc_0066:
    uVar2 = 0;
  }
  else {
    FUN_4340_0a29(&local_52);
    if ((local_51 != ':') || (local_50 != '\0')) {
      iVar1 = FUN_1000_147f(&local_52);
      if (iVar1 != 0) goto LAB_49fc_0066;
    }
    if (local_51 == ':') {
      iVar1 = (int)local_52;
      if (0x60 < iVar1) {
        iVar1 = iVar1 + -0x20;
      }
      iVar1 = FUN_1000_18a4(iVar1 + -0x41);
      if (iVar1 == 0) goto LAB_49fc_0066;
    }
    uVar2 = 1;
  }
  return uVar2;
}

