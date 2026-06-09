// TIM2.EXE: FUN_31f7_818e @ file 0x03F2FE Ghidra 0x3A0FE
// Subsystem: misc | Size: 243 bytes


void __cdecl16far FUN_31f7_818e(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_0989 == 0) {
    for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
      uVar3 = FUN_4551_0370(DAT_5b41_0a3a,((undefined2 *)&DAT_554c_3bda)[iVar2]);
      ((undefined2 *)&DAT_5b41_0987)[iVar2] = uVar3;
      uVar3 = FUN_4551_0370(DAT_5b41_0a3a,((undefined2 *)&DAT_554c_3be0)[iVar2]);
      ((undefined2 *)&DAT_5b41_098d)[iVar2] = uVar3;
      uVar3 = FUN_4551_0370(DAT_5b41_0a3a,((undefined2 *)&DAT_554c_3be6)[iVar2]);
      ((undefined2 *)&DAT_5b41_1a5e)[iVar2] = uVar3;
      uVar3 = FUN_4551_0370(DAT_5b41_0a3a,((undefined2 *)&DAT_554c_3bec)[iVar2]);
      ((undefined2 *)&DAT_5b41_1a64)[iVar2] = uVar3;
    }
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  iVar2 = (uint)(DAT_5b41_0989 <= *(int *)(iVar1 + 0xa8)) +
          (uint)(DAT_5b41_098b <= *(int *)(iVar1 + 0xa8));
  *(undefined2 *)(iVar1 + 0x82) = *(undefined2 *)(iVar2 * 2 + 0x3bf2);
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)(*(int *)(*(int *)(*(int *)(iVar1 + 8) * 2 + 0x302) + 0x46) + iVar2 * 2);
  FUN_28eb_3670(iVar1,uVar3);
  return;
}

