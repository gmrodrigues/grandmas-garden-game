// TIM2.EXE: FUN_31f7_4540 @ file 0x03B6B0 Ghidra 0x364B0
// Subsystem: misc | Size: 278 bytes


void __cdecl16far FUN_31f7_4540(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_097d == 0) {
    for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
      uVar3 = FUN_4551_0370(DAT_5b41_09f6,((undefined2 *)&DAT_554c_3afc)[iVar1]);
      ((undefined2 *)&DAT_5b41_097b)[iVar1] = uVar3;
      uVar3 = FUN_4551_0370(DAT_5b41_09f6,((undefined2 *)&DAT_554c_3b02)[iVar1]);
      ((undefined2 *)&DAT_5b41_19da)[iVar1] = uVar3;
      uVar3 = FUN_4551_0370(DAT_5b41_09f6,((undefined2 *)&DAT_554c_3b08)[iVar1]);
      ((undefined2 *)&DAT_5b41_0981)[iVar1] = uVar3;
      uVar3 = FUN_4551_0370(DAT_5b41_09f6,((undefined2 *)&DAT_554c_3b0e)[iVar1]);
      ((undefined2 *)&DAT_5b41_19e0)[iVar1] = uVar3;
      uVar3 = FUN_4551_0370(DAT_5b41_09f6,((undefined2 *)&DAT_554c_3b14)[iVar1]);
      ((undefined2 *)&DAT_5b41_19e6)[iVar1] = uVar3;
    }
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = (uint)(DAT_5b41_097d <= *(int *)(iVar2 + 0xa8)) +
          (uint)(DAT_5b41_097f <= *(int *)(iVar2 + 0xa8));
  *(undefined2 *)(iVar2 + 0x82) = *(undefined2 *)(iVar1 * 2 + 0x3b1a);
  *(undefined2 *)(iVar2 + 0x98) =
       *(undefined2 *)(*(int *)(*(int *)(*(int *)(iVar2 + 8) * 2 + 0x302) + 0x46) + iVar1 * 2);
  FUN_28eb_3670(iVar2,uVar3);
  return;
}

