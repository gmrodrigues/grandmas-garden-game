// TIM2.EXE: FUN_31f7_7332 @ file 0x03E4A2 Ghidra 0x392A2
// Subsystem: misc | Size: 148 bytes


undefined2 __cdecl16far FUN_31f7_7332(void)

{
  undefined2 uVar1;
  int iVar2;
  
  if (DAT_5b41_1a34 == 0) {
    for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {
      uVar1 = FUN_4551_0370(DAT_5b41_0a22,((undefined2 *)&DAT_554c_3bba)[iVar2]);
      ((undefined2 *)&DAT_5b41_1a32)[iVar2] = uVar1;
      uVar1 = FUN_4551_0370(DAT_5b41_0a22,((undefined2 *)&DAT_554c_3bbe)[iVar2]);
      ((undefined2 *)&DAT_5b41_1a36)[iVar2] = uVar1;
      uVar1 = FUN_4551_0370(DAT_5b41_0a22,((undefined2 *)&DAT_554c_3bc2)[iVar2]);
      ((undefined2 *)&DAT_5b41_1a3a)[iVar2] = uVar1;
    }
    DAT_5b41_1a3e = FUN_4551_0370(DAT_5b41_0a22,0xe);
    DAT_5b41_1a40 = FUN_4551_0370(DAT_5b41_0a22,0xffff);
  }
  return 1;
}

