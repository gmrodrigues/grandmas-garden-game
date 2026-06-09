// TIM2.EXE: FUN_4fd6_0266 @ file 0x0551C6 Ghidra 0x4FFC6
// Subsystem: physics | Size: 40 bytes


void __cdecl16near FUN_4fd6_0266(void)

{
  char *pcVar1;
  char cVar2;
  code *pcVar3;
  int iVar4;
  int unaff_BP;
  char *pcVar5;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  int iVar6;
  
  iVar6 = (int)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
  pcVar5 = (char *)(char *)*(undefined4 *)(unaff_BP + 6);
  if (iVar6 != 0 || pcVar5 != (char *)0x0) {
    iVar4 = 0xc;
    do {
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
      cVar2 = *pcVar1;
      pcVar1 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      *pcVar1 = cVar2;
      if (cVar2 == '\0') goto LAB_4fd6_027d;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    *unaff_DI = '\0';
  }
LAB_4fd6_027d:
  pcVar3 = (code *)swi(0x21);
  (*pcVar3)();
  return;
}

