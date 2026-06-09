// TIM2.EXE: FUN_31f7_1265 @ file 0x0383D5 Ghidra 0x331D5
// Subsystem: misc | Size: 283 bytes


void __cdecl16far FUN_31f7_1265(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if (DAT_5b41_0975 == 0) {
    for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {
      uVar2 = FUN_4551_0370(DAT_5b41_09c6,((undefined2 *)&DAT_554c_3a32)[iVar1]);
      ((undefined2 *)&DAT_5b41_0973)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_09c6,((undefined2 *)&DAT_554c_3a36)[iVar1]);
      ((undefined2 *)&DAT_5b41_197a)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_09c6,((undefined2 *)&DAT_554c_3a3a)[iVar1]);
      ((undefined2 *)&DAT_5b41_197e)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_09c6,((undefined2 *)&DAT_554c_3a3e)[iVar1]);
      ((undefined2 *)&DAT_5b41_1982)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_09c6,((undefined2 *)&DAT_554c_3a42)[iVar1]);
      ((undefined2 *)&DAT_5b41_1986)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_09c6,((undefined2 *)&DAT_554c_3a46)[iVar1]);
      ((undefined2 *)&DAT_5b41_0977)[iVar1] = uVar2;
      uVar2 = FUN_4551_0370(DAT_5b41_09c6,((undefined2 *)&DAT_554c_3a4a)[iVar1]);
      ((undefined2 *)&DAT_5b41_198a)[iVar1] = uVar2;
    }
  }
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)
        ((uint)((*(byte *)(iVar1 + 0xc) & 0x10) != 0) * 2 + *(int *)(iRam000557da + 0x46));
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

