// TIM2.EXE: FUN_552e_0034 @ file 0x05A514 Ghidra 0x55314
// Subsystem: misc | Size: 100 bytes


void FUN_552e_0034(void)

{
  code *pcVar1;
  char cVar2;
  byte bVar3;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  byte in_AF;
  
  pcVar1 = (code *)swi(0x3f);
  cVar2 = (*pcVar1)();
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  pcVar1 = (code *)swi(0x3f);
  cVar2 = (*pcVar1)();
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(undefined1 *)(in_BX + unaff_DI) = *(undefined1 *)(in_BX + unaff_DI);
  cVar2 = *(char *)(in_BX + unaff_SI);
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar2;
  pcVar1 = (code *)swi(0x3f);
  bVar3 = (*pcVar1)();
  *(char *)(in_BX + unaff_DI) = *(char *)(in_BX + unaff_DI) + bVar3;
  in_AF = 9 < (bVar3 & 0xf) | in_AF;
  bVar3 = bVar3 + in_AF * -6 & 0xf;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  bVar3 = bVar3 + (9 < bVar3 | in_AF) * -6 & 0xf;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  *(int *)(in_BX + unaff_DI) = *(int *)(in_BX + unaff_DI) + -0x1300;
  *(int *)(unaff_BP + unaff_SI) = *(int *)(unaff_BP + unaff_SI) + unaff_BP;
  *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) + bVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar3;
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}

