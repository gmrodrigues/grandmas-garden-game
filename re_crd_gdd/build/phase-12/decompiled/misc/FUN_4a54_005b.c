// TIM2.EXE: FUN_4a54_005b @ file 0x04F79B Ghidra 0x4A59B
// Subsystem: misc | Size: 141 bytes


void __cdecl16near
FUN_4a54_005b(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined1 uVar1;
  
  uVar1 = DAT_554c_42cc;
  DAT_5b41_2844 = (uint)((DAT_5b41_2856 & 2) != 0);
  DAT_5b41_2842 = (uint)((DAT_5b41_2856 & 1) != 0);
  if (DAT_5b41_2844 == 0) {
    if (DAT_5b41_2842 == 0) {
      DAT_5b41_285c = 0;
    }
    else {
      DAT_5b41_285c = 0x2a5;
    }
  }
  else if (DAT_5b41_2842 == 0) {
    DAT_5b41_285c = 0x256;
  }
  else {
    DAT_5b41_285c = 0x2f4;
  }
  DAT_554c_42cc = 1;
  FUN_4a54_00ea(param_1,param_2,param_3,param_4);
  DAT_554c_42cc = uVar1;
  return;
}

