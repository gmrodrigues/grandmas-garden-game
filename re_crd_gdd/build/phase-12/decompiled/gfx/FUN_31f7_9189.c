// TIM2.EXE: FUN_31f7_9189 @ file 0x0402F9 Ghidra 0x3B0F9
// Subsystem: gfx | Size: 214 bytes


void __cdecl16far FUN_31f7_9189(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if (DAT_5b41_1a7e == 0) {
    for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
      uVar2 = FUN_4551_0370(DAT_5b41_0a4e,((undefined2 *)&DAT_554c_3c5e)[iVar1]);
      ((undefined2 *)&DAT_5b41_1a7c)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_0a4e,((undefined2 *)&DAT_554c_3c64)[iVar1]);
      ((undefined2 *)&DAT_5b41_0993)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_0a4e,((undefined2 *)&DAT_554c_3c6a)[iVar1]);
      ((undefined2 *)&DAT_5b41_1a82)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_0a4e,((undefined2 *)&DAT_554c_3c70)[iVar1]);
      ((undefined2 *)&DAT_5b41_1a88)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_0a4e,((undefined2 *)&DAT_554c_3c76)[iVar1]);
      ((undefined2 *)&DAT_5b41_0999)[iVar1] = uVar2;
    }
  }
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined1 *)(iVar1 + 0x82) = 0xd;
  *(undefined1 *)(iVar1 + 0x83) = 0x4b;
  *(undefined2 *)(iVar1 + 0x98) = *(undefined2 *)*(undefined2 *)(DAT_554c_03a2 + 0x46);
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

