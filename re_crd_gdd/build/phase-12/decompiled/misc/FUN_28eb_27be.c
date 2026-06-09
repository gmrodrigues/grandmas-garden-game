// TIM2.EXE: FUN_28eb_27be @ file 0x03086E Ghidra 0x2B66E
// Subsystem: misc | Size: 84 bytes


void __cdecl16far FUN_28eb_27be(undefined4 param_1)

{
  if (((iRam000557bc == 1) || (iRam000557bc == 6)) || (*(int *)((int)param_1 + 8) == 0x37)) {
    FUN_28eb_2a23((int)param_1,param_1._2_2_);
    FUN_2321_0c23((int)param_1,param_1._2_2_);
  }
  if ((param_1._2_2_ == DAT_5b41_0567._2_2_) && ((int)param_1 == (int)DAT_5b41_0567)) {
    DAT_5b41_0567._2_2_ = 0;
    DAT_5b41_0567._0_2_ = 0;
  }
  return;
}

