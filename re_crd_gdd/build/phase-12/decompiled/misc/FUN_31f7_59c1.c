// TIM2.EXE: FUN_31f7_59c1 @ file 0x03CB31 Ghidra 0x37931
// Subsystem: misc | Size: 244 bytes


void __cdecl16far FUN_31f7_59c1(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if (DAT_5b41_1a12 == 0) {
    for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {
      uVar2 = FUN_4551_0370(DAT_5b41_0a02,((undefined2 *)&DAT_554c_3b42)[iVar1]);
      ((undefined2 *)&DAT_5b41_19fe)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_0a02,((undefined2 *)&DAT_554c_3b46)[iVar1]);
      ((undefined2 *)&DAT_5b41_1a02)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_0a02,((undefined2 *)&DAT_554c_3b4a)[iVar1]);
      ((undefined2 *)&DAT_5b41_1a06)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_0a02,((undefined2 *)&DAT_554c_3b52)[iVar1]);
      ((undefined2 *)&DAT_5b41_1a0a)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_0a02,((undefined2 *)&DAT_554c_3b4e)[iVar1]);
      ((undefined2 *)&DAT_5b41_1a0e)[iVar1] = uVar2;
    }
    DAT_5b41_1a12 = FUN_4551_0370(DAT_5b41_0a02,10);
  }
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)
        ((uint)((*(byte *)(iVar1 + 0xc) & 0x10) != 0) * 2 + *(int *)(iRam00055816 + 0x46));
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

