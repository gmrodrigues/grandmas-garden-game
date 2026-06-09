// TIM2.EXE: FUN_1000_4354 @ file 0x019554 Ghidra 0x14354
// Subsystem: utility | Size: 112 bytes


int FUN_1000_4354(uint *param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_4;
  
  if ((int)*param_1 < 0) {
    iVar4 = param_1[3] + *param_1 + 1;
  }
  else {
    uVar5 = (int)*param_1 >> 0xf;
    iVar4 = (*param_1 ^ uVar5) - uVar5;
  }
  local_4 = iVar4;
  if ((param_1[1] & 0x40) == 0) {
    pcVar2 = (char *)param_1[5];
    if ((int)*param_1 < 0) {
      while (iVar6 = iVar4 + -1, iVar4 != 0) {
        pcVar2 = pcVar2 + -1;
        iVar4 = iVar6;
        if (*pcVar2 == '\n') {
          local_4 = local_4 + 1;
        }
      }
    }
    else {
      while (iVar6 = iVar4 + -1, iVar4 != 0) {
        pcVar3 = pcVar2 + 1;
        pcVar1 = pcVar2;
        pcVar2 = pcVar3;
        iVar4 = iVar6;
        if (*pcVar1 == '\n') {
          local_4 = local_4 + 1;
        }
      }
    }
  }
  return local_4;
}

