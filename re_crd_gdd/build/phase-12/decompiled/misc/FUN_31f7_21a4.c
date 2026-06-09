// TIM2.EXE: FUN_31f7_21a4 @ file 0x039314 Ghidra 0x34114
// Subsystem: misc | Size: 206 bytes


void __cdecl16far FUN_31f7_21a4(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int unaff_DI;
  
  if (DAT_5b41_19a2 == 0) {
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      uVar1 = FUN_4551_0370(DAT_5b41_09d2,((undefined2 *)&DAT_554c_3a58)[iVar3]);
      ((undefined2 *)&DAT_5b41_1996)[iVar3] = uVar1;
      uVar1 = FUN_4551_0370(DAT_5b41_09d2,((undefined2 *)&DAT_554c_3a64)[iVar3]);
      ((undefined2 *)&DAT_5b41_19a2)[iVar3] = uVar1;
      uVar1 = FUN_4551_0370(DAT_5b41_09d2,((undefined2 *)&DAT_554c_3a70)[iVar3]);
      ((undefined2 *)&DAT_5b41_19ae)[iVar3] = uVar1;
    }
  }
  for (iVar3 = 0; iVar2 = (int)param_1, iVar3 < 6; iVar3 = iVar3 + 1) {
    if (*(int *)(iVar2 + 0x10) == ((undefined2 *)&DAT_5b41_1996)[iVar3]) {
      unaff_DI = iVar3;
    }
  }
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(unaff_DI * 2 + *(int *)(iRam000557e6 + 0x46));
  *(undefined1 *)(iVar2 + 0x82) = ((undefined1 *)&DAT_554c_3a7c)[unaff_DI * 2];
  *(undefined1 *)(iVar2 + 0x83) = ((undefined1 *)&DAT_554c_3a7d)[unaff_DI * 2];
  FUN_28eb_3670(iVar2,param_1._2_2_);
  return;
}

