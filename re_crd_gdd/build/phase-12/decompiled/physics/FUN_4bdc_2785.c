// TIM2.EXE: FUN_4bdc_2785 @ file 0x053745 Ghidra 0x4E545
// Subsystem: physics | Size: 45 bytes


undefined2 __cdecl16far FUN_4bdc_2785(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if ((*(uint *)(iVar1 + 0x12) & 1) != 0) {
    return *(undefined2 *)(iVar1 + 0xe);
  }
  uVar2 = FUN_4bdc_2636(*(undefined2 *)(iVar1 + 4),*(undefined2 *)(iVar1 + 6));
  return uVar2;
}

