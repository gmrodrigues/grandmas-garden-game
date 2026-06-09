// TIM2.EXE: FUN_1000_5472 @ file 0x01A672 Ghidra 0x15472
// Subsystem: utility | Size: 34 bytes


char * __cdecl16far FUN_1000_5472(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar3 = 0xffff;
  pcVar4 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  pcVar4 = param_1;
  for (uVar3 = ~uVar3; uVar3 != 0; uVar3 = uVar3 - 1) {
    pcVar2 = pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar1 = param_2;
    param_2 = param_2 + 1;
    *pcVar2 = *pcVar1;
  }
  return param_1;
}

