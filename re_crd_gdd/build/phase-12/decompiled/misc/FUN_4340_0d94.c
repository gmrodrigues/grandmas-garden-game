// TIM2.EXE: FUN_4340_0d94 @ file 0x049394 Ghidra 0x44194
// Subsystem: misc | Size: 98 bytes


int __cdecl16far FUN_4340_0d94(byte *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 1;
  if ((byte *)param_1 == (byte *)0x0 && param_1._2_2_ == 0) {
    iVar1 = 0;
  }
  else {
    while ((*param_1 != 0 && (*param_1 < 0x21))) {
      param_1 = (byte *)CONCAT22(param_1._2_2_,(byte *)param_1 + 1);
    }
    if (*param_1 != 0x2d) goto LAB_4340_0de0;
    iVar2 = -1;
    while( true ) {
      param_1 = (byte *)CONCAT22(param_1._2_2_,(byte *)param_1 + 1);
LAB_4340_0de0:
      if ((*param_1 < 0x30) || (0x39 < *param_1)) break;
      iVar1 = iVar1 * 10 + (uint)*param_1 + -0x30;
    }
    iVar1 = iVar1 * iVar2;
  }
  return iVar1;
}

