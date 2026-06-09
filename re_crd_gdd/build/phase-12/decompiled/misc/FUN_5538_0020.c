// TIM2.EXE: FUN_5538_0020 @ file 0x05A5A0 Ghidra 0x553A0
// Subsystem: misc | Size: 141 bytes


/* WARNING: Instruction at (ram,0x000553e4) overlaps instruction at (ram,0x000553e3)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_5538_0020(void)

{
  int *piVar1;
  char *pcVar2;
  uint *puVar3;
  byte bVar4;
  code *pcVar5;
  char cVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  undefined2 in_CX;
  char cVar10;
  int in_BX;
  int unaff_BP;
  undefined2 *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  byte in_AF;
  
  pcVar5 = (code *)swi(0x3f);
  cVar6 = (*pcVar5)();
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + cVar6;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + cVar6;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + cVar6;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + cVar6;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + cVar6;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + cVar6;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + cVar6;
  pcVar5 = (code *)swi(0x3f);
  bVar7 = (*pcVar5)();
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar7;
  *(byte *)((int)unaff_SI + 1) = *(byte *)((int)unaff_SI + 1) ^ bVar7;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + '.';
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar7;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar7;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar7;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar7;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar7;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar7;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar7;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar7;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar7;
  cVar6 = (char)in_CX;
  cVar10 = (char)((uint)in_CX >> 8) + cVar6;
  in_AF = 9 < (bVar7 & 0xf) | in_AF;
  *(undefined1 *)(unaff_BP + (int)unaff_DI) = 0;
  pcVar5 = (code *)swi(0x3f);
  bVar7 = (*pcVar5)();
  in_AF = 9 < ((bVar7 ^ (byte)*(undefined2 *)(unaff_BP + (int)unaff_DI)) & 0xf) | in_AF;
  bVar7 = in_AF * -6 & 0xf;
  if (CONCAT11(cVar10 + cVar6,cVar6) == 1 || (char)(cVar10 + cVar6) != '\0') {
    bVar4 = 9 < bVar7 | in_AF;
    uVar8 = CONCAT11(((char)((uint)(*(int *)(unaff_BP + (int)unaff_SI) * -0x3300) >> 8) - in_AF) -
                     bVar4,bVar7 + bVar4 * -6) & 0xff0f;
  }
  else {
    pcVar5 = (code *)swi(0x3f);
    uVar8 = (*pcVar5)();
  }
  *unaff_DI = *unaff_SI;
  piVar1 = (int *)(in_BX + (int)(unaff_SI + 1));
  *piVar1 = *piVar1 + uVar8;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar2 = (char *)((int)unaff_SI + in_BX + 4);
  *pcVar2 = *pcVar2 + (char)unaff_SI[1];
  pcVar5 = (code *)swi(0x3f);
  cVar6 = (*pcVar5)();
  pcVar2 = (char *)((int)unaff_SI + in_BX + 4);
  *pcVar2 = *pcVar2 + cVar6;
  unaff_DI[1] = unaff_DI[1] - (int)&stack0x0010;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar5 = (code *)swi(0x3f);
  iVar9 = (*pcVar5)();
  puVar3 = (uint *)((int)unaff_SI + in_BX + 4);
  *puVar3 = *puVar3 & iVar9 - 1U;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

