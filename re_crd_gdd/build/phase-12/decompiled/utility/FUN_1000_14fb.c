// TIM2.EXE: FUN_1000_14fb @ file 0x0166FB Ghidra 0x114FB
// Subsystem: utility | Size: 189 bytes


char * FUN_1000_14fb(int *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int local_6;
  int *local_4;
  
  local_6 = 1;
  if ((param_1 != (int *)0x0) && (local_4 = param_1, *param_1 != 0)) {
    while ((local_4 = local_4 + 1, *local_4 != 0 && (*(char *)*local_4 != '\0'))) {
      iVar1 = FUN_1000_54d4(*local_4);
      if (0x7f < (uint)(local_6 + iVar1 + 1)) goto LAB_1000_15ae;
      local_6 = local_6 + iVar1 + 1;
    }
  }
  local_6 = local_6 + 1;
  pcVar2 = (char *)FUN_1000_3226(local_6);
  if (pcVar2 == (char *)0x0) {
LAB_1000_15ae:
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = pcVar2 + 1;
    *pcVar2 = (char)local_6 + -2;
    local_4 = param_1;
    if ((char)((char)local_6 + -2) != '\0') {
      while ((local_4 = local_4 + 1, *local_4 != 0 && (*(char *)*local_4 != '\0'))) {
        *pcVar3 = ' ';
        pcVar3 = (char *)FUN_1000_140a(pcVar3 + 1,*local_4);
      }
    }
    *pcVar3 = '\r';
    pcVar3 = pcVar3 + (1 - local_6);
  }
  return pcVar3;
}

