// TIM2.EXE: FUN_31f7_9496 @ file 0x040606 Ghidra 0x3B406
// Subsystem: gfx | Size: 165 bytes


void __cdecl16far FUN_31f7_9496(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_1a90 == 0) {
    for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
      uVar3 = FUN_4551_0370(DAT_5b41_0a50,((undefined2 *)&DAT_554c_3c7c)[iVar2]);
      ((undefined2 *)&DAT_5b41_1a8e)[iVar2] = uVar3;
      uVar3 = FUN_4551_0370(DAT_5b41_0a50,((undefined2 *)&DAT_554c_3c82)[iVar2]);
      ((undefined2 *)&DAT_5b41_1a94)[iVar2] = uVar3;
      iVar1 = FUN_4551_0370(DAT_5b41_0a50,((undefined2 *)&DAT_554c_3c88)[iVar2]);
      ((undefined2 *)&DAT_5b41_1a9a)[iVar2] = iVar1 + -1;
    }
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  *(undefined2 *)(iVar2 + 0x98) =
       *(undefined2 *)
        ((uint)((*(byte *)(iVar2 + 0xc) & 0x10) != 0) * 2 + *(int *)(DAT_554c_03a4 + 0x46));
  FUN_28eb_3670(iVar2,uVar3);
  return;
}

