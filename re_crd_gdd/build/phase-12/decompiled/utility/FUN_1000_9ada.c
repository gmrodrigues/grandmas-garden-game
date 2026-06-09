// TIM2.EXE: FUN_1000_9ada @ file 0x01ECDA Ghidra 0x19ADA
// Subsystem: utility | Size: 74 bytes


undefined2 __cdecl16far FUN_1000_9ada(int *param_1)

{
  int *piVar1;
  uint *puVar2;
  
  if (*param_1 == 0) {
    puVar2 = DAT_554c_5b50;
    if (DAT_554c_5b50 == (uint *)0x0) {
      return 1;
    }
  }
  else {
    piVar1 = (int *)(*param_1 + -4);
    if (piVar1 == DAT_554c_5b52) {
      return 5;
    }
    puVar2 = (uint *)((int)piVar1 + *piVar1 & 0xfffe);
  }
  *param_1 = (int)puVar2;
  *param_1 = *param_1 + 4;
  param_1[1] = *puVar2 & 0xfffe;
  param_1[2] = *puVar2 & 1;
  return 2;
}

