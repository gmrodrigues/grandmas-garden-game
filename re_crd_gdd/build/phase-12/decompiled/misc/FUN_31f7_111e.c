// TIM2.EXE: FUN_31f7_111e @ file 0x03828E Ghidra 0x3308E
// Subsystem: misc | Size: 42 bytes


void __cdecl16far FUN_31f7_111e(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if ((*(byte *)(iVar1 + 0xc) & 0x10) == 0) {
    *(undefined2 *)(iVar1 + 0x16) = 1;
  }
  else {
    *(undefined2 *)(iVar1 + 0x16) = 0xffff;
  }
  *(undefined2 *)(iVar1 + 0xae) = 100;
  return;
}

