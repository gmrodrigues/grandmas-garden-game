// TIM2.EXE: FUN_3e34_0a69 @ file 0x043FA9 Ghidra 0x3EDA9
// Subsystem: sound | Size: 108 bytes


undefined2 __cdecl16far FUN_3e34_0a69(undefined2 param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  
  iVar1 = FUN_3f2b_0811(param_1);
  uVar2 = iVar1 - 1;
  if ((uVar2 < 500) && (*(int *)(uVar2 * 8 + 0x70) != 0 || *(int *)(uVar2 * 8 + 0x72) != 0)) {
    FUN_3e34_0085(*(undefined2 *)(uVar2 * 8 + 0x70),*(undefined2 *)(uVar2 * 8 + 0x72));
    *(undefined2 *)(uVar2 * 8 + 0x72) = 0;
    *(undefined2 *)(uVar2 * 8 + 0x70) = 0;
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

