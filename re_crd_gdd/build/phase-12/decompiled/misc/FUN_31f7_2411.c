// TIM2.EXE: FUN_31f7_2411 @ file 0x039581 Ghidra 0x34381
// Subsystem: misc | Size: 171 bytes


void __cdecl16far FUN_31f7_2411(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (param_2 == 0xf) {
    iVar1 = DAT_5b41_1998;
    if ((((*(int *)(iVar2 + 0x10) != DAT_5b41_1996) &&
         (iVar1 = DAT_5b41_199e, *(int *)(iVar2 + 0x10) != DAT_5b41_1998)) &&
        (iVar1 = DAT_5b41_1996, *(int *)(iVar2 + 0x10) != DAT_5b41_199a)) &&
       ((iVar1 = DAT_5b41_19a0, *(int *)(iVar2 + 0x10) != DAT_5b41_199c &&
        (iVar1 = DAT_5b41_199a, *(int *)(iVar2 + 0x10) == DAT_5b41_199e)))) {
      iVar1 = DAT_5b41_199c;
    }
    *(int *)(iVar2 + 0x10) = iVar1;
  }
  *(undefined2 *)(iVar2 + 0xa8) = *(undefined2 *)(iVar2 + 0x10);
  FUN_31f7_21a4(iVar2,param_1._2_2_);
  FUN_28eb_3328(iVar2,param_1._2_2_);
  FUN_2424_0f94(iVar2,param_1._2_2_,3);
  FUN_28eb_2d82(iVar2,param_1._2_2_,2);
  return;
}

