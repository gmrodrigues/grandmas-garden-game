// TIM2.EXE: FUN_2e67_0231 @ file 0x033AA1 Ghidra 0x2E8A1
// Subsystem: misc | Size: 132 bytes


undefined2 __cdecl16far FUN_2e67_0231(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  if (DAT_5b41_0bec == 0) {
    uVar1 = 0;
  }
  else {
    if ((DAT_5b41_0bea != 0) && (iVar2 = FUN_4340_0b8a(param_1,0x554c,0x6b40,0x554c), iVar2 == 0)) {
      return 1;
    }
    if (DAT_5b41_0bea != 0) {
      FUN_2e67_09da();
      FUN_4bdc_32e9(0);
      FUN_1a9e_6e73(DAT_5b41_0bea);
      DAT_5b41_0bea = 0;
    }
    if (param_1 != 0) {
      DAT_5b41_0bea = FUN_1a9e_69e9(param_1);
      FUN_4340_0a29(0x6b40,0x554c,param_1,0x554c);
    }
    if (DAT_5b41_0bea == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

