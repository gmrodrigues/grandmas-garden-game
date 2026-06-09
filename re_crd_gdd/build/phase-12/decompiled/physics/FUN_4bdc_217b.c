// TIM2.EXE: FUN_4bdc_217b @ file 0x05313B Ghidra 0x4DF3B
// Subsystem: physics | Size: 218 bytes


void __cdecl16near FUN_4bdc_217b(void)

{
  char *pcVar1;
  int in_AX;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  undefined2 unaff_ES;
  undefined2 uVar7;
  
  if ((*(int *)(in_AX + 8) != -1) || (*(int *)(in_AX + 10) != -1)) {
    pcVar1 = *(char **)*(undefined4 *)(in_AX + 8);
    uVar7 = (undefined2)((ulong)pcVar1 >> 0x10);
    pcVar2 = (char *)pcVar1;
    if ((pcVar2[0x23] != -2) || ((pcVar2[0x22] != -3 || (pcVar2[0x21] != -4)))) {
      iVar6 = 0x20;
      do {
        iVar5 = iVar6 + -2;
        *(undefined2 *)(iVar6 + 0x10c) = 0;
        iVar6 = iVar5;
      } while (iVar5 != 0);
      cRam00040212 = -1;
      pcVar3 = pcVar2;
      if (*pcVar1 == -0x10) {
        cRam00040212 = pcVar2[1];
        pcVar3 = pcVar2 + 8;
      }
      while (*pcVar3 != cRam00040202) {
        if (*pcVar3 == -1) goto LAB_4bdc_221e;
        for (pcVar4 = pcVar3 + 1; pcVar3 = pcVar4 + 1, *pcVar4 != -1; pcVar4 = pcVar4 + 6) {
        }
      }
      iVar6 = 0;
      for (pcVar3 = pcVar3 + 1; *pcVar3 != -1; pcVar3 = pcVar3 + 6) {
        *(undefined2 *)(iVar6 + 0x10e) = *(undefined2 *)(pcVar3 + 2);
        iVar6 = iVar6 + 2;
      }
LAB_4bdc_221e:
      iVar6 = 0;
      pcVar3 = pcVar2;
      do {
        *(undefined2 *)pcVar3 = *(undefined2 *)(iVar6 + 0x10e);
        iVar6 = iVar6 + 2;
        pcVar3 = pcVar3 + 2;
      } while (iVar6 != 0x20);
      *pcVar3 = cRam00040212;
      pcVar2[0x21] = -4;
      pcVar2[0x22] = -3;
      pcVar2[0x23] = -2;
    }
  }
  return;
}

