// TIM2.EXE: FUN_3f2b_0d4d @ file 0x0451FD Ghidra 0x3FFFD
// Subsystem: sound | Size: 87 bytes


undefined2 __cdecl16far
FUN_3f2b_0d4d(uint param_1,int param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 uVar1;
  undefined2 in_DX;
  
  if ((((DAT_5b41_1b54 != 0 || DAT_5b41_1b56 != 0) && (param_1 != 0 || param_2 != 0)) &&
      (param_2 == 0)) && (param_1 < 0xffdd)) {
    FUN_3f2b_0dd2();
    uVar1 = FUN_3f2b_0fa3(param_1,0,param_3,param_4);
    FUN_3f2b_0e15(uVar1,in_DX);
    return uVar1;
  }
  return 0;
}

