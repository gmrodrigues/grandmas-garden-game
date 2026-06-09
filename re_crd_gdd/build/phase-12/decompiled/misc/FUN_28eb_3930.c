// TIM2.EXE: FUN_28eb_3930 @ file 0x0319E0 Ghidra 0x2C7E0
// Subsystem: misc | Size: 59 bytes


undefined2 __cdecl16far FUN_28eb_3930(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_3 >> 0x10);
  iVar1 = (int)param_3;
  if ((*(int *)(iVar1 + 0x60) == param_2) && (*(int *)(iVar1 + 0x5e) == param_1)) {
    return 0;
  }
  if ((*(int *)(iVar1 + 100) == param_2) && (*(int *)(iVar1 + 0x62) == param_1)) {
    return 1;
  }
  return 0xffff;
}

