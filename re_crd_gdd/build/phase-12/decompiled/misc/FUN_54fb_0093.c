// TIM2.EXE: FUN_54fb_0093 @ file 0x05A243 Ghidra 0x55043
// Subsystem: misc | Size: 69 bytes


/* WARNING: Control flow encountered bad instruction data */

void FUN_54fb_0093(void)

{
  char *pcVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  undefined2 uVar9;
  undefined2 in_CX;
  char cVar11;
  int iVar10;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int iVar12;
  int unaff_DI;
  undefined2 unaff_SS;
  byte in_AF;
  undefined4 uVar13;
  
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  cVar8 = (char)in_CX;
  cVar11 = (char)((uint)in_CX >> 8) + cVar8;
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) - in_AF;
  pcVar5 = (code *)swi(0x3f);
  uVar9 = (*pcVar5)();
  bVar6 = (byte)uVar9;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar6;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar6;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar6;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar6;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar6;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar6;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar6;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar6;
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  bVar6 = bVar6 + in_AF * -6;
  bVar7 = bVar6 & 0xf;
  pcVar1 = (char *)(in_BX + unaff_SI);
  *pcVar1 = *pcVar1 + bVar7;
  iVar10 = CONCAT11(cVar11 + cVar8,cVar8) + -1;
  if (iVar10 == 0 || *pcVar1 == '\0') {
    *(int *)(in_BX + unaff_SI) =
         *(int *)(in_BX + unaff_SI) + (CONCAT11((char)((uint)uVar9 >> 8) - in_AF,bVar6) & 0xff0f);
    cVar8 = bVar7 + 0x44 + (char)*(undefined2 *)(in_BX + unaff_SI);
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar8;
    pcVar5 = (code *)swi(0x3f);
    (*pcVar5)();
  }
  pcVar5 = (code *)swi(0x3f);
  cVar8 = (*pcVar5)();
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar8;
  pcVar5 = (code *)swi(0x3f);
  uVar13 = (*pcVar5)();
  cVar8 = (char)uVar13;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar8;
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) >> 1;
  puVar2 = (uint *)(in_BX + unaff_SI);
  uVar3 = *puVar2;
  *puVar2 = *puVar2 + (uint)uVar13;
  bVar6 = ((byte)iVar10 & 0x1f) % 0x11;
  uVar4 = *(uint *)(unaff_BP + unaff_DI);
  *(uint *)(unaff_BP + unaff_DI) =
       uVar4 << bVar6 | (uint)(CONCAT12(CARRY2(uVar3,(uint)uVar13),uVar4) >> 0x11 - bVar6);
  iVar12 = unaff_SI + 1;
  *(int *)(in_BX + unaff_DI) = *(int *)(in_BX + unaff_DI) + iVar10;
  *(char *)(in_BX + iVar12) = *(char *)(in_BX + iVar12) + cVar8;
  *(char *)(in_BX + iVar12) = *(char *)(in_BX + iVar12) + cVar8;
  *(char *)(in_BX + iVar12) = *(char *)(in_BX + iVar12) + cVar8;
  *(char *)(in_BX + iVar12) = *(char *)(in_BX + iVar12) + cVar8;
  *(char *)(in_BX + iVar12) = *(char *)(in_BX + iVar12) + cVar8;
  *(char *)(in_BX + iVar12) = *(char *)(in_BX + iVar12) + cVar8;
  *(char *)(in_BX + iVar12) = *(char *)(in_BX + iVar12) + cVar8;
  *(char *)(in_BX + iVar12) = *(char *)(in_BX + iVar12) + cVar8;
  *(char *)(in_BX + iVar12) = *(char *)(in_BX + iVar12) + cVar8;
  *(uint *)(unaff_BP + unaff_DI) = *(uint *)(unaff_BP + unaff_DI) ^ (uint)((ulong)uVar13 >> 0x10);
  uVar3 = *(uint *)(unaff_BP + iVar12);
  *(uint *)(unaff_BP + iVar12) = uVar3 | (uint)(CONCAT12(in_AF,uVar3) >> 0x11);
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

