// TIM2.EXE: FUN_1000_54d4 @ file 0x01A6D4 Ghidra 0x154D4
// Subsystem: utility | Size: 28 bytes


int __cdecl16far FUN_1000_54d4(char *param_1)

{
  char *pcVar1;
  uint uVar2;
  
  uVar2 = 0xffff;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar1 = param_1;
    param_1 = param_1 + 1;
  } while (*pcVar1 != '\0');
  return ~uVar2 - 1;
}

