// TIM2.EXE: FUN_28eb_00cb @ file 0x02E17B Ghidra 0x28F7B
// Subsystem: misc | Size: 78 bytes


undefined2 __cdecl16far FUN_28eb_00cb(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2;
  if (param_2 < param_1) {
    iVar1 = param_1;
    param_1 = param_2;
  }
  if ((((param_1 != 0xc) || ((iVar1 != 0x2a && (iVar1 != 0x34)))) &&
      ((param_1 != 0x2a || ((iVar1 != 0x34 && (iVar1 != 0x2a)))))) &&
     ((param_1 != 0x36 || ((iVar1 != 0x36 && (iVar1 != 0x3a)))))) {
    return 0;
  }
  return 1;
}

