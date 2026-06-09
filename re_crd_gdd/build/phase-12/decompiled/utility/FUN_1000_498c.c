// TIM2.EXE: FUN_1000_498c @ file 0x019B8C Ghidra 0x1498C
// Subsystem: utility | Size: 95 bytes


char * __cdecl16far FUN_1000_498c(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  undefined2 *local_4;
  
  if (param_1 != (char *)0x0) {
    uVar3 = 0xffff;
    pcVar7 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar1 = pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
    iVar4 = ~uVar3 - 1;
    if ((iVar4 != 0) && (local_4 = DAT_554c_5ea6, DAT_554c_5ea6 != (undefined2 *)0x0)) {
      while ((pcVar7 = (char *)*local_4, pcVar7 != (char *)0x0 && (*pcVar7 != '\0'))) {
        if ((*param_1 == *pcVar7) && (pcVar7[iVar4] == '=')) {
          bVar8 = true;
          iVar5 = iVar4;
          pcVar6 = param_1;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            pcVar2 = pcVar7;
            pcVar7 = pcVar7 + 1;
            pcVar1 = pcVar6;
            pcVar6 = pcVar6 + 1;
            bVar8 = *pcVar1 == *pcVar2;
          } while (bVar8);
          if (bVar8) {
            return pcVar7 + 1;
          }
        }
        local_4 = local_4 + 1;
      }
    }
  }
  return (char *)0x0;
}

