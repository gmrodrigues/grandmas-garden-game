// TIM2.EXE: FUN_460e_1cd3 @ file 0x04CFB3 Ghidra 0x47DB3
// Subsystem: misc | Size: 151 bytes


bool __cdecl16far FUN_460e_1cd3(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if (param_1 != 0) {
    FUN_460e_1cd3(0,0);
  }
  if (param_2 == 0) {
    if (DAT_5b41_1ce2 != 0) {
      FUN_1000_0c9d(DAT_5b41_1ce2);
    }
    DAT_5b41_1ba2 = 0;
    DAT_5b41_1ba4 = 0;
    DAT_5b41_1ce2 = 0;
    return false;
  }
  if (param_1 == 0) {
    if (DAT_5b41_1c82 == '\0') goto LAB_460e_1d47;
    uVar1 = 0x3fcd;
  }
  else {
    FUN_4340_0a29((undefined1 *)&DAT_5b41_1c82,0x554c,param_1,0x554c);
    uVar1 = 0x3fca;
  }
  DAT_5b41_1ce2 = FUN_1000_0b20((undefined1 *)&DAT_5b41_1c82,uVar1);
LAB_460e_1d47:
  if (DAT_5b41_1ce2 != 0) {
    DAT_5b41_1ce4 = 1;
    DAT_5b41_1ba4 = 0x460e;
    DAT_5b41_1ba2 = 0x1d6a;
  }
  return DAT_5b41_1ce2 != 0;
}

