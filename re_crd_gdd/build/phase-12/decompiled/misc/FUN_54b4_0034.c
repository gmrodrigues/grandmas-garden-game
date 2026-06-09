// TIM2.EXE: FUN_54b4_0034 @ file 0x059D74 Ghidra 0x54B74
// Subsystem: misc | Size: 34 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00054d1f) overlaps instruction at (ram,0x00054d1e)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_54b4_0034(void)

{
  byte *pbVar1;
  int *piVar2;
  byte *pbVar3;
  code *pcVar4;
  byte bVar5;
  char cVar6;
  byte extraout_AL;
  byte bVar7;
  byte bVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  byte *pbVar11;
  char extraout_AH;
  uint uVar12;
  byte *pbVar13;
  byte *pbVar14;
  undefined2 in_CX;
  char cVar15;
  char cVar16;
  char extraout_DL;
  byte extraout_DH;
  int *in_BX;
  char *pcVar17;
  int iVar18;
  int unaff_SI;
  byte *pbVar19;
  int unaff_DI;
  undefined2 unaff_SS;
  byte bVar20;
  byte in_AF;
  bool bVar21;
  char cVar22;
  bool bVar23;
  longdouble in_ST0;
  undefined1 in_XMM0 [16];
  
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  *(undefined1 (*) [16])((int)in_BX + unaff_SI) = in_XMM0;
  pcVar4 = (code *)swi(0x3f);
  bVar5 = (*pcVar4)();
  *in_BX = (int)in_ST0;
  cVar6 = (char)in_CX;
  cVar15 = (char)((uint)in_CX >> 8) + cVar6;
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  pcVar4 = (code *)swi(0x3f);
  bVar5 = (*pcVar4)();
  iVar18 = TaskRegister();
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  bVar5 = bVar5 + in_AF * -6 & 0xf ^ (byte)*(undefined2 *)(iVar18 + unaff_DI);
  iVar18 = CONCAT11(cVar15 + cVar6,cVar6);
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  pbVar3 = (byte *)(unaff_DI + 2);
  pbVar19 = (byte *)(unaff_SI + 2);
  *(byte *)((int)in_BX + (int)pbVar19) =
       *(byte *)((int)in_BX + (int)pbVar19) | bVar5 + in_AF * -6 & 0xf;
  pcVar4 = (code *)swi(0x3f);
  uVar9 = (*pcVar4)();
  *(int *)(byte *)((int)in_BX + (int)pbVar19) = *(int *)(byte *)((int)in_BX + (int)pbVar19) + iVar18
  ;
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  uVar10 = GlobalDescriptorTableRegister();
  *(undefined2 *)(byte *)((int)in_BX + (int)pbVar19) = uVar10;
  pcVar4 = (code *)swi(0x3f);
  cVar6 = (*pcVar4)();
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + cVar6;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + cVar6;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + cVar6;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + cVar6;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + cVar6;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + cVar6;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + cVar6;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + cVar6;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + cVar6;
  pcVar4 = (code *)swi(0x3f);
  uVar10 = (*pcVar4)();
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + (char)uVar10;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + 0x6a;
  *(uint *)((int)in_BX + (int)pbVar3) = *(uint *)((int)in_BX + (int)pbVar3) | 0xe0;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + 0x6a;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + 0x6a;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + 0x6a;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + 0x6a;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + 0x6a;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + 0x6a;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + 0x6a;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + 0x6a;
  *(byte *)((int)in_BX + (int)pbVar19) = *(byte *)((int)in_BX + (int)pbVar19) + 0x6a;
  cVar15 = (char)uVar9;
  cVar16 = (char)((uint)uVar9 >> 8) + cVar15;
  in_AF = in_AF | 1;
  pbVar11 = (byte *)(CONCAT11((char)((uint)uVar10 >> 8) - in_AF,in_AF * -6 + 'j') & 0xff0f);
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  pcVar4 = (code *)swi(0x3f);
  uVar10 = (*pcVar4)();
  cVar16 = cVar16 + cVar15;
  in_AF = 9 < ((byte)uVar10 & 0xf) | in_AF;
  *(uint *)((int)in_BX + (int)pbVar19) =
       *(uint *)((int)in_BX + (int)pbVar19) |
       CONCAT11((char)((uint)uVar10 >> 8) - in_AF,(byte)uVar10 + in_AF * -6) & 0xff0f;
  pcVar4 = (code *)swi(0x3f);
  uVar10 = (*pcVar4)();
  out(2,uVar10);
  cVar16 = cVar16 + cVar15;
  in_AF = 9 < ((byte)uVar10 & 0xf) | in_AF;
  pcVar17 = (char *)((int)in_BX + -1);
  pcVar4 = (code *)swi(0x3f);
  cVar6 = (*pcVar4)();
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + cVar6;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + cVar6;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + cVar6;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + cVar6;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + cVar6;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + cVar6;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + cVar6;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + cVar6;
  pcVar4 = (code *)swi(0x3f);
  iVar18 = (*pcVar4)();
  bVar5 = (byte)iVar18;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
  *pbVar3 = *pbVar3 & extraout_DH;
  (pbVar11 + (int)pbVar3)[0x1f] = (pbVar11 + (int)pbVar3)[0x1f] + cVar16;
  *(uint *)(pcVar17 + (int)pbVar19) = *(int *)(pcVar17 + (int)pbVar19) + iVar18 + (uint)(bVar5 < 2);
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
  pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
  pbVar1 = (byte *)(pcVar17 + (int)pbVar19);
  bVar20 = CARRY1(*pbVar1,bVar5);
  *pbVar1 = *pbVar1 + bVar5;
  cVar22 = (char)*pbVar1 < '\0';
  bVar21 = *pbVar1 == 0;
  pcVar4 = (code *)swi(0x3f);
  uVar10 = (*pcVar4)();
  bVar23 = (int)_DAT_6000_21c0 < 0;
  _DAT_6000_21c0 = _DAT_6000_21c0 >> 1 | (uint)bVar20 << 0xf;
  in_AF = 9 < ((byte)uVar10 & 0xf) | in_AF;
  bVar5 = (byte)uVar10 + in_AF * -6 & 0xf;
  cVar6 = (char)((uint)uVar10 >> 8) - in_AF;
  if (bVar21 || (bVar23 != ((uint)bVar20 << 0xf != 0)) != (bool)cVar22) {
    in_AF = 9 < bVar5 | in_AF;
    bVar5 = (bVar5 + in_AF * -6 & 0xf) - in_AF;
    in_AF = 9 < (bVar5 & 0xf) | in_AF;
    iVar18 = CONCAT11(cVar16 + cVar15 * '\x02',cVar15);
    in_AF = 9 < ((bVar5 + in_AF * -6 & 0xf) - 0x1c & 0xf) | in_AF;
    pcVar4 = (code *)swi(0x3f);
    (*pcVar4)();
    bVar5 = extraout_AL;
    cVar6 = extraout_AH;
    if (iVar18 == 0) {
      pcVar4 = (code *)swi(0x3f);
      (*pcVar4)();
      *pbVar19 = *pbVar19;
      pcVar4 = (code *)swi(0x3f);
      (*pcVar4)();
      pcVar4 = (code *)swi(0x3f);
      uVar10 = (*pcVar4)();
      pbVar11[(int)pbVar19] = pbVar11[(int)pbVar19] + 1;
      in_AF = 9 < ((byte)uVar10 & 0xf) | in_AF;
      uVar12 = CONCAT11((char)((uint)uVar10 >> 8) - in_AF,(byte)uVar10 + in_AF * -6) & 0xff0f;
      piVar2 = (int *)(pcVar17 + (int)pbVar19);
      cVar15 = SCARRY2(*piVar2,uVar12);
      *piVar2 = *piVar2 + uVar12;
      cVar6 = *piVar2 < 0;
      bVar21 = *piVar2 == 0;
      pcVar4 = (code *)swi(0x3f);
      pbVar13 = (byte *)(*pcVar4)();
      bVar5 = (byte)pbVar13;
      if (bVar21 || cVar15 != cVar6) {
        *pbVar3 = *pbVar3 + bVar5;
        pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      }
      else {
        in_AF = 9 < (bVar5 & 0xf) | in_AF;
        bVar5 = bVar5 + in_AF * -6 & 0xf;
        pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
        pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
        pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
        pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
        pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
        pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
        pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
        pcVar4 = (code *)swi(0x3f);
        pbVar14 = (byte *)(*pcVar4)();
        pbVar1 = (byte *)(pcVar17 + (int)pbVar19);
        bVar5 = *pbVar1;
        *pbVar1 = *pbVar1 + (byte)pbVar14;
        *pcVar17 = *pcVar17 + extraout_DL + CARRY1(bVar5,(byte)pbVar14);
        pbVar13 = pbVar19;
        pbVar19 = pbVar14;
      }
      bVar5 = (byte)pbVar13;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      in_AF = 9 < (bVar5 & 0xf) | in_AF;
      bVar5 = bVar5 + in_AF * -6 & 0xf;
      in_AF = 9 < bVar5 | in_AF;
      bVar5 = bVar5 + in_AF * -6 & 0xf;
      in_AF = 9 < bVar5 | in_AF;
      bVar5 = bVar5 + in_AF * -6 & 0xf;
      in_AF = 9 < bVar5 | in_AF;
      in_AF = 9 < (bVar5 + in_AF * -6 & 0xf) | in_AF;
      pcVar4 = (code *)swi(0x3f);
      cVar6 = (*pcVar4)();
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + cVar6;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + cVar6;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + cVar6;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + cVar6;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + cVar6;
      pcVar4 = (code *)swi(0x3f);
      bVar5 = (*pcVar4)();
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      *pbVar11 = *pbVar11 ^ (byte)pcVar17;
      *(char **)(pbVar11 + (int)pbVar19) = pcVar17 + *(int *)(pbVar11 + (int)pbVar19);
      pbVar11[(int)pbVar19] = pbVar11[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      in_AF = 9 < (bVar5 & 0xf) | in_AF;
      bVar5 = bVar5 + in_AF * -6 & 0xf;
      in_AF = 9 < bVar5 | in_AF;
      bVar5 = bVar5 + in_AF * -6 & 0xf;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      in_AF = 9 < bVar5 | in_AF;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + (bVar5 + in_AF * -6 & 0xf);
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + -0x61;
      bVar5 = (byte)*(undefined2 *)pbVar19;
      *pbVar19 = *pbVar19 + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      in_AF = 9 < (bVar5 & 0xf) | in_AF;
      pcVar4 = (code *)swi(0x3f);
      (*pcVar4)();
      bVar21 = false;
      pcVar4 = (code *)swi(0x3f);
      bVar5 = (*pcVar4)();
      if (bVar21) {
        pcVar4 = (code *)swi(0x3f);
        bVar5 = (*pcVar4)();
      }
      else {
        in_AF = 9 < (bVar5 & 0xf) | in_AF;
        bVar5 = bVar5 + in_AF * -6 & 0xf;
      }
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      bVar5 = bVar5 + (9 < (bVar5 & 0xf) | in_AF) * -6 & 0xf;
      pcVar17[(int)pbVar19] = pcVar17[(int)pbVar19] + bVar5;
      *pbVar3 = *pbVar19;
      pcVar17[(int)(pbVar19 + 1)] = pcVar17[(int)(pbVar19 + 1)] + bVar5;
      return;
    }
  }
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  bVar7 = bVar5 + in_AF * -6 & 0xf;
  bVar5 = 9 < bVar7 | in_AF;
  bVar8 = (byte)((undefined1 *)&DAT_6000_21c0 +
                (uint)bVar5 + (CONCAT11((cVar6 - in_AF) - bVar5,bVar7 + bVar5 * -6) & 0xff0f));
  bVar20 = 9 < (bVar8 & 0xf) | bVar5;
  *(uint *)(pcVar17 + (int)pbVar19) =
       *(int *)(pcVar17 + (int)pbVar19) +
       (CONCAT11((char)((uint)((undefined1 *)&DAT_6000_21c0 +
                              (uint)bVar5 +
                              (CONCAT11((cVar6 - in_AF) - bVar5,bVar7 + bVar5 * -6) & 0xff0f)) >> 8)
                 - bVar20,bVar8 + bVar20 * -6) & 0xff0f) + (uint)bVar20;
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

