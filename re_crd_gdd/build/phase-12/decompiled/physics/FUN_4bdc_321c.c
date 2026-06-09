// TIM2.EXE: FUN_4bdc_321c @ file 0x0541DC Ghidra 0x4EFDC
// Subsystem: physics | Size: 139 bytes


void __cdecl16far FUN_4bdc_321c(void)

{
  if (DAT_554c_5740 != 0 || DAT_554c_5742 != 0) {
    FUN_4bdc_23e0();
    if (DAT_554c_573a == 0) {
      FUN_4bdc_1944();
      FUN_4bdc_1944();
    }
    else {
      FUN_4bdc_32a7();
    }
  }
  if (DAT_554c_5744 != 0 || DAT_554c_5746 != 0) {
    FUN_1000_1384();
  }
  if (DAT_554c_5740 != 0 || DAT_554c_5742 != 0) {
    FUN_2e67_10e9(DAT_554c_5740,DAT_554c_5742,1);
    DAT_554c_5742 = 0;
    DAT_554c_5740 = 0;
  }
  if (DAT_554c_5744 != 0 || DAT_554c_5746 != 0) {
    FUN_2e67_10e9(DAT_554c_5744,DAT_554c_5746,1);
    DAT_554c_5746 = 0;
    DAT_554c_5744 = 0;
  }
  return;
}

