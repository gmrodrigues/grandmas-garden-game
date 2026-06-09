// TIM2.EXE: FUN_4340_056e @ file 0x048B6E Ghidra 0x4396E
// Subsystem: misc | Size: 71 bytes


undefined2 __cdecl16far FUN_4340_056e(undefined2 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int in_DX;
  
  iVar1 = FUN_4340_07f3(param_1);
  if (iVar1 == 0 && in_DX == 0) {
    uVar2 = 0xffff;
  }
  else {
    if ((*(int *)(iVar1 + 0xc) == 0) && (iVar3 = FUN_4340_021b(param_1), iVar3 == 0)) {
      return 0;
    }
    uVar2 = *(undefined2 *)(iVar1 + 0xc);
  }
  return uVar2;
}

