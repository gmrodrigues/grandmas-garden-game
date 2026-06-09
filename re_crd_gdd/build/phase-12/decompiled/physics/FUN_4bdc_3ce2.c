// TIM2.EXE: FUN_4bdc_3ce2 @ file 0x054CA2 Ghidra 0x4FAA2
// Subsystem: physics | Size: 170 bytes


void __cdecl16far FUN_4bdc_3ce2(void)

{
  if ((DAT_554c_5740 != 0 || DAT_554c_5742 != 0) || (DAT_554c_5744 != 0 || DAT_554c_5746 != 0)) {
    FUN_4bdc_32e9(0);
    if ((int)DAT_554c_574e != 0 || DAT_554c_574e._2_2_ != 0) {
      FUN_2e67_10e9((int)DAT_554c_574e,DAT_554c_574e._2_2_,10);
    }
    if ((DAT_554c_5752 != 0) && (DAT_554c_5754 != 0)) {
      FUN_1a9e_6e73(DAT_554c_5752);
    }
    if (DAT_554c_573a != 0) {
      FUN_1a9e_3f10(DAT_554c_573a);
      DAT_554c_573a = 0;
    }
    if (DAT_554c_573c != 0) {
      FUN_1a9e_3f10(DAT_554c_573c);
      DAT_554c_573c = 0;
    }
    if (DAT_554c_5738 != 0) {
      FUN_1a9e_3fa0();
      DAT_554c_5738 = 0;
    }
    FUN_4bdc_302e();
    FUN_4bdc_321c();
  }
  return;
}

