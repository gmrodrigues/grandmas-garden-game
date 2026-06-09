// TIM2.EXE: FUN_1000_90fe @ file 0x01E2FE Ghidra 0x190FE
// Subsystem: utility | Size: 46 bytes


undefined2 FUN_1000_90fe(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  do {
    pcVar2 = param_2;
    if (*param_1 == '\0') {
      return 1;
    }
    param_2 = (char *)CONCAT22(param_2._2_2_,(char *)param_2 + 1);
    pcVar1 = param_1;
    param_1 = param_1 + 1;
  } while (*pcVar2 == *pcVar1);
  return 0;
}

