// TIM2.EXE: FUN_2e67_03fe @ file 0x033C6E Ghidra 0x2EA6E
// Subsystem: misc | Size: 35 bytes


undefined2 __cdecl16far FUN_2e67_03fe(int param_1)

{
  undefined2 uVar1;
  
  uVar1 = DAT_5b41_0bee;
  if (DAT_5b41_0bec == 0) {
    uVar1 = 0xffff;
  }
  else {
    DAT_5b41_0bee = 0;
    FUN_2e67_06ab(param_1);
    if (param_1 == DAT_5b41_0be2) {
      DAT_5b41_0be2 = 0;
    }
    if (param_1 == DAT_5b41_0be4) {
      DAT_5b41_0be4 = 0;
    }
    if (param_1 == DAT_5b41_0be6) {
      DAT_5b41_0be6 = 0;
    }
    DAT_5b41_0bee = uVar1;
    uVar1 = FUN_4bdc_32e9(param_1);
  }
  return uVar1;
}

