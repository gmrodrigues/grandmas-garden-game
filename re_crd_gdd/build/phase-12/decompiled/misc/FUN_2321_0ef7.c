// TIM2.EXE: FUN_2321_0ef7 @ file 0x029307 Ghidra 0x24107
// Subsystem: misc | Size: 43 bytes


void __cdecl16far FUN_2321_0ef7(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if ((int)param_1 != 0 || param_1._2_2_ != 0) {
    iVar1 = *(int *)(*(int *)((int)param_1 + 8) * 2 + 0x302);
    uVar2 = *(undefined2 *)(iVar1 + 0x2a);
    *(undefined2 *)((int)param_1 + 0x56) = *(undefined2 *)(iVar1 + 0x2c);
    *(undefined2 *)((int)param_1 + 0x54) = uVar2;
  }
  return;
}

