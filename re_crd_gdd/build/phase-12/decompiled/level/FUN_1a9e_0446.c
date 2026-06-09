// TIM2.EXE: FUN_1a9e_0446 @ file 0x020026 Ghidra 0x1AE26
// Subsystem: level | Size: 32 bytes


undefined2 __cdecl16near FUN_1a9e_0446(char *param_1)

{
  char *pcVar1;
  
  do {
    if (*param_1 == '\0') {
      return 0;
    }
    pcVar1 = param_1;
    param_1 = param_1 + 1;
  } while (*pcVar1 != 'r');
  return 1;
}

