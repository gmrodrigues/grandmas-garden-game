// TIM2.EXE: FUN_4340_0ce7 @ file 0x0492E7 Ghidra 0x440E7
// Subsystem: misc | Size: 88 bytes


char * __cdecl16far FUN_4340_0ce7(char *param_1,undefined1 param_2)

{
  byte bVar1;
  uint uVar2;
  
  if ((char *)param_1 != (char *)0x0 || param_1._2_2_ != 0) {
    bVar1 = FUN_1000_21ca(param_2);
    while (*param_1 != '\0') {
      uVar2 = FUN_1000_21ca(*param_1);
      if (uVar2 == bVar1) break;
      param_1 = (char *)CONCAT22(param_1._2_2_,(char *)param_1 + 1);
    }
    if (*param_1 != '\0') {
      return (char *)param_1;
    }
  }
  return (char *)0x0;
}

