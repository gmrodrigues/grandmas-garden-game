// TIM2.EXE: FUN_1000_543a @ file 0x01A63A Ghidra 0x1543A
// Subsystem: utility | Size: 56 bytes


char * __cdecl16far FUN_1000_543a(char *param_1,char param_2)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  
  if (((uint)param_1 & 1) == 0) goto LAB_1000_5455;
  pcVar1 = param_1;
  param_1 = param_1 + 1;
  cVar3 = *pcVar1;
  while (cVar3 != param_2) {
    if (cVar3 == '\0') {
      return (char *)0x0;
    }
LAB_1000_5455:
    pcVar1 = param_1;
    param_1 = param_1 + 2;
    cVar2 = (char)*(undefined2 *)pcVar1;
    if (cVar2 == param_2) goto LAB_1000_546b;
    cVar3 = (char)((uint)*(undefined2 *)pcVar1 >> 8);
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  param_1 = param_1 + 1;
LAB_1000_546b:
  return param_1 + -2;
}

