// TIM2.EXE: FUN_4340_0e53 @ file 0x049453 Ghidra 0x44253
// Subsystem: misc | Size: 68 bytes


undefined2 __cdecl16far FUN_4340_0e53(char *param_1)

{
  int iVar1;
  undefined2 in_DX;
  
  if (((char *)param_1 != (char *)0x0 || param_1._2_2_ != 0) && (*param_1 != '\0')) {
    iVar1 = FUN_4340_0a29((char *)param_1,param_1._2_2_,(char *)param_1 + 1,param_1._2_2_);
    *(undefined1 *)(iVar1 + 1) = 0;
    return 1;
  }
  return 0;
}

