// TIM2.EXE: FUN_28eb_56b0 @ file 0x033760 Ghidra 0x2E560
// Subsystem: misc | Size: 80 bytes


undefined2 __cdecl16far FUN_28eb_56b0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (int)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(int *)(iVar2 + 8) == 0x11) || (*(int *)(iVar2 + 8) == 0x6c)) {
    while( true ) {
      iVar1 = *(int *)(iVar2 + 0x8e);
      iVar2 = *(int *)(iVar2 + 0x8c);
      if (iVar2 == 0 && iVar1 == 0) break;
      iVar3 = iVar1;
      if ((iVar1 == param_3) && (iVar2 == param_2)) {
        return 1;
      }
    }
  }
  return 0;
}

