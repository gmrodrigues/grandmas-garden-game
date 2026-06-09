// TIM2.EXE: FUN_31f7_763a @ file 0x03E7AA Ghidra 0x395AA
// Subsystem: misc | Size: 227 bytes


void __cdecl16far FUN_31f7_763a(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if (DAT_5b41_1a46 == 0) {
    for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {
      uVar2 = FUN_4551_0370(DAT_5b41_0a28,((undefined2 *)&DAT_554c_3bc6)[iVar1]);
      ((undefined2 *)&DAT_5b41_1a42)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_0a28,((undefined2 *)&DAT_554c_3bca)[iVar1]);
      ((undefined2 *)&DAT_5b41_1a46)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_0a28,((undefined2 *)&DAT_554c_3bce)[iVar1]);
      ((undefined2 *)&DAT_5b41_1a4a)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_0a28,((undefined2 *)&DAT_554c_3bd2)[iVar1]);
      ((undefined2 *)&DAT_5b41_1a4e)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_0a28,((undefined2 *)&DAT_554c_3bd6)[iVar1]);
      ((undefined2 *)&DAT_5b41_1a52)[iVar1] = uVar2;
    }
  }
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)
        ((uint)((*(byte *)(iVar1 + 0xc) & 0x10) != 0) * 2 + *(int *)(DAT_554c_037c + 0x46));
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

