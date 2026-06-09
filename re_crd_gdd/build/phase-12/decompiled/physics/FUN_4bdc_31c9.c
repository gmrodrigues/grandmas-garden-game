// TIM2.EXE: FUN_4bdc_31c9 @ file 0x054189 Ghidra 0x4EF89
// Subsystem: physics | Size: 56 bytes


undefined2 __cdecl16far FUN_4bdc_31c9(void)

{
  undefined2 uVar1;
  
  uVar1 = 0x554c;
  if (DAT_554c_5756 != 0) {
    uVar1 = (*(code *)s_DOSREQ_RES_554c_31ac._2_2_)(0x4bdc);
  }
  DAT_42da_0412 = uVar1;
  return uVar1;
}

