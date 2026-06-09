// TIM2.EXE: FUN_4bdc_2861 @ file 0x053821 Ghidra 0x4E621
// Subsystem: physics | Size: 133 bytes


int __cdecl16far FUN_4bdc_2861(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = 0x17a;
  iVar1 = FUN_2e67_0edd(0x17a,0,2);
  if (iVar1 != 0 || iVar3 != 0) {
    *(undefined2 *)(iVar1 + 0x168) = param_2;
    *(undefined2 *)(iVar1 + 0x166) = param_1;
    uVar2 = FUN_4bdc_2846(param_1,param_2);
    *(undefined2 *)(iVar1 + 0x16c) = param_1;
    *(undefined2 *)(iVar1 + 0x16a) = uVar2;
    *(int *)(iVar1 + 10) = iVar3;
    *(int *)(iVar1 + 8) = iVar1 + 0x16a;
    *(undefined1 *)(iVar1 + 0x15e) = 0x7f;
    *(undefined2 *)(iVar1 + 0x174) = 0;
    *(undefined2 *)(iVar1 + 0x172) = 0;
    return iVar1;
  }
  return 0;
}

