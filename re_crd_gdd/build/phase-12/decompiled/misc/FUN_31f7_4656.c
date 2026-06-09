// TIM2.EXE: FUN_31f7_4656 @ file 0x03B7C6 Ghidra 0x365C6
// Subsystem: misc | Size: 117 bytes


void __cdecl16far FUN_31f7_4656(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (param_2 == 0xf) {
    iVar1 = DAT_5b41_097d;
    if ((*(int *)(iVar2 + 0x10) != DAT_5b41_097b) &&
       (iVar1 = DAT_5b41_097b, *(int *)(iVar2 + 0x10) == DAT_5b41_097d)) {
      iVar1 = DAT_5b41_097f;
    }
    *(int *)(iVar2 + 0x10) = iVar1;
  }
  *(undefined2 *)(iVar2 + 0xa8) = *(undefined2 *)(iVar2 + 0x10);
  FUN_31f7_4540(iVar2,param_1._2_2_);
  FUN_28eb_3328(iVar2,param_1._2_2_);
  FUN_2424_0f94(iVar2,param_1._2_2_,3);
  FUN_28eb_2d82(iVar2,param_1._2_2_,2);
  return;
}

