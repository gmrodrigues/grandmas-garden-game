// TIM2.EXE: FUN_406b_029f @ file 0x045B4F Ghidra 0x4094F
// Subsystem: sound | Size: 83 bytes


void __cdecl16far FUN_406b_029f(void)

{
  int iVar1;
  
  FUN_406b_02f2(0,0,0);
  for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {
    FUN_22de_0351(*(undefined2 *)(iVar1 * 0x12 + 0x12),*(undefined2 *)(iVar1 * 0x12 + 0x14));
    *(undefined2 *)(iVar1 * 0x12 + 0x14) = 0;
    *(undefined2 *)(iVar1 * 0x12 + 0x12) = 0;
  }
  return;
}

