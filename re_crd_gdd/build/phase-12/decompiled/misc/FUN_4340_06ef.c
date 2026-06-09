// TIM2.EXE: FUN_4340_06ef @ file 0x048CEF Ghidra 0x43AEF
// Subsystem: misc | Size: 105 bytes


undefined2 __cdecl16far FUN_4340_06ef(uint param_1)

{
  int iVar1;
  int iVar2;
  int in_DX;
  
  iVar1 = FUN_4340_07f3(param_1);
  if ((iVar1 != 0 || in_DX != 0) &&
     (((*(int *)(iVar1 + 0xc) != 0 || (iVar2 = FUN_4340_021b(param_1), iVar2 != 0)) &&
      ((int)(param_1 % 1000) <= *(int *)(iVar1 + 0xc))))) {
    return *(undefined2 *)((int)*(undefined4 *)(iVar1 + 4) + (param_1 % 1000) * 4 + -4);
  }
  return 0;
}

