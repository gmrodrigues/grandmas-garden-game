// TIM2.EXE: FUN_1000_0f97 @ file 0x016197 Ghidra 0x10F97
// Subsystem: utility | Size: 48 bytes


int __cdecl16far FUN_1000_0f97(undefined2 param_1)

{
  int *piVar1;
  
  if (((DAT_5b41_0469 != 0) && (piVar1 = (int *)FUN_1000_0abd(param_1), piVar1 != (int *)0x0)) &&
     (piVar1[8] == 0)) {
    return *piVar1 * 0x1c + 0x6300;
  }
  return 0;
}

