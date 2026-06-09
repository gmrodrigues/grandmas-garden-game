// TIM2.EXE: FUN_54b4_005c @ file 0x059D9C Ghidra 0x54B9C
// Subsystem: misc | Size: 80 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00054d1f) overlaps instruction at (ram,0x00054d1e)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_54b4_005c(void)

{
  byte *pbVar1;
  int *piVar2;
  code *pcVar3;
  char cVar4;
  byte bVar5;
  byte extraout_AL;
  byte bVar6;
  byte bVar7;
  undefined2 uVar8;
  byte *pbVar9;
  int iVar10;
  char extraout_AH;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined2 in_CX;
  char cVar14;
  char extraout_DL;
  byte extraout_DH;
  int in_BX;
  char *pcVar15;
  byte *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_SS;
  byte bVar16;
  byte in_AF;
  bool bVar17;
  char cVar18;
  bool bVar19;
  char cVar20;
  
  pcVar3 = (code *)swi(0x3f);
  cVar4 = (*pcVar3)();
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar4;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar4;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar4;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar4;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar4;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar4;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar4;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar4;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar4;
  pcVar3 = (code *)swi(0x3f);
  uVar8 = (*pcVar3)();
  unaff_SI[in_BX] = unaff_SI[in_BX] + (char)uVar8;
  unaff_SI[in_BX] = unaff_SI[in_BX] + 0x6a;
  *(uint *)(unaff_DI + in_BX) = *(uint *)(unaff_DI + in_BX) | 0xe0;
  unaff_SI[in_BX] = unaff_SI[in_BX] + 0x6a;
  unaff_SI[in_BX] = unaff_SI[in_BX] + 0x6a;
  unaff_SI[in_BX] = unaff_SI[in_BX] + 0x6a;
  unaff_SI[in_BX] = unaff_SI[in_BX] + 0x6a;
  unaff_SI[in_BX] = unaff_SI[in_BX] + 0x6a;
  unaff_SI[in_BX] = unaff_SI[in_BX] + 0x6a;
  unaff_SI[in_BX] = unaff_SI[in_BX] + 0x6a;
  unaff_SI[in_BX] = unaff_SI[in_BX] + 0x6a;
  unaff_SI[in_BX] = unaff_SI[in_BX] + 0x6a;
  cVar20 = (char)in_CX;
  cVar14 = (char)((uint)in_CX >> 8) + cVar20;
  in_AF = in_AF | 1;
  pbVar9 = (byte *)(CONCAT11((char)((uint)uVar8 >> 8) - in_AF,in_AF * -6 + 'j') & 0xff0f);
  pcVar3 = (code *)swi(0x3f);
  (*pcVar3)();
  pcVar3 = (code *)swi(0x3f);
  uVar8 = (*pcVar3)();
  cVar14 = cVar14 + cVar20;
  in_AF = 9 < ((byte)uVar8 & 0xf) | in_AF;
  *(uint *)(unaff_SI + in_BX) =
       *(uint *)(unaff_SI + in_BX) |
       CONCAT11((char)((uint)uVar8 >> 8) - in_AF,(byte)uVar8 + in_AF * -6) & 0xff0f;
  pcVar3 = (code *)swi(0x3f);
  uVar8 = (*pcVar3)();
  out(2,uVar8);
  cVar14 = cVar14 + cVar20;
  in_AF = 9 < ((byte)uVar8 & 0xf) | in_AF;
  pcVar15 = (char *)(in_BX + -1);
  pcVar3 = (code *)swi(0x3f);
  cVar4 = (*pcVar3)();
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + cVar4;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + cVar4;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + cVar4;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + cVar4;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + cVar4;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + cVar4;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + cVar4;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + cVar4;
  pcVar3 = (code *)swi(0x3f);
  iVar10 = (*pcVar3)();
  bVar5 = (byte)iVar10;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
  *unaff_DI = *unaff_DI & extraout_DH;
  (pbVar9 + (int)unaff_DI)[0x1f] = (pbVar9 + (int)unaff_DI)[0x1f] + cVar14;
  *(uint *)(pcVar15 + (int)unaff_SI) =
       *(int *)(pcVar15 + (int)unaff_SI) + iVar10 + (uint)(bVar5 < 2);
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
  pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
  pbVar1 = (byte *)(pcVar15 + (int)unaff_SI);
  bVar16 = CARRY1(*pbVar1,bVar5);
  *pbVar1 = *pbVar1 + bVar5;
  cVar18 = (char)*pbVar1 < '\0';
  bVar17 = *pbVar1 == 0;
  pcVar3 = (code *)swi(0x3f);
  uVar8 = (*pcVar3)();
  bVar19 = (int)_DAT_6000_21c0 < 0;
  _DAT_6000_21c0 = _DAT_6000_21c0 >> 1 | (uint)bVar16 << 0xf;
  in_AF = 9 < ((byte)uVar8 & 0xf) | in_AF;
  bVar5 = (byte)uVar8 + in_AF * -6 & 0xf;
  cVar4 = (char)((uint)uVar8 >> 8) - in_AF;
  if (bVar17 || (bVar19 != ((uint)bVar16 << 0xf != 0)) != (bool)cVar18) {
    in_AF = 9 < bVar5 | in_AF;
    bVar5 = (bVar5 + in_AF * -6 & 0xf) - in_AF;
    in_AF = 9 < (bVar5 & 0xf) | in_AF;
    iVar10 = CONCAT11(cVar14 + cVar20 * '\x02',cVar20);
    in_AF = 9 < ((bVar5 + in_AF * -6 & 0xf) - 0x1c & 0xf) | in_AF;
    pcVar3 = (code *)swi(0x3f);
    (*pcVar3)();
    bVar5 = extraout_AL;
    cVar4 = extraout_AH;
    if (iVar10 == 0) {
      pcVar3 = (code *)swi(0x3f);
      (*pcVar3)();
      *unaff_SI = *unaff_SI;
      pcVar3 = (code *)swi(0x3f);
      (*pcVar3)();
      pcVar3 = (code *)swi(0x3f);
      uVar8 = (*pcVar3)();
      pbVar9[(int)unaff_SI] = pbVar9[(int)unaff_SI] + 1;
      in_AF = 9 < ((byte)uVar8 & 0xf) | in_AF;
      uVar11 = CONCAT11((char)((uint)uVar8 >> 8) - in_AF,(byte)uVar8 + in_AF * -6) & 0xff0f;
      piVar2 = (int *)(pcVar15 + (int)unaff_SI);
      cVar20 = SCARRY2(*piVar2,uVar11);
      *piVar2 = *piVar2 + uVar11;
      cVar4 = *piVar2 < 0;
      bVar17 = *piVar2 == 0;
      pcVar3 = (code *)swi(0x3f);
      pbVar12 = (byte *)(*pcVar3)();
      bVar5 = (byte)pbVar12;
      if (bVar17 || cVar20 != cVar4) {
        *unaff_DI = *unaff_DI + bVar5;
        pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      }
      else {
        in_AF = 9 < (bVar5 & 0xf) | in_AF;
        bVar5 = bVar5 + in_AF * -6 & 0xf;
        pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
        pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
        pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
        pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
        pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
        pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
        pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
        pcVar3 = (code *)swi(0x3f);
        pbVar13 = (byte *)(*pcVar3)();
        pbVar1 = (byte *)(pcVar15 + (int)unaff_SI);
        bVar5 = *pbVar1;
        *pbVar1 = *pbVar1 + (byte)pbVar13;
        *pcVar15 = *pcVar15 + extraout_DL + CARRY1(bVar5,(byte)pbVar13);
        pbVar12 = unaff_SI;
        unaff_SI = pbVar13;
      }
      bVar5 = (byte)pbVar12;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      in_AF = 9 < (bVar5 & 0xf) | in_AF;
      bVar5 = bVar5 + in_AF * -6 & 0xf;
      in_AF = 9 < bVar5 | in_AF;
      bVar5 = bVar5 + in_AF * -6 & 0xf;
      in_AF = 9 < bVar5 | in_AF;
      bVar5 = bVar5 + in_AF * -6 & 0xf;
      in_AF = 9 < bVar5 | in_AF;
      in_AF = 9 < (bVar5 + in_AF * -6 & 0xf) | in_AF;
      pcVar3 = (code *)swi(0x3f);
      cVar4 = (*pcVar3)();
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + cVar4;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + cVar4;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + cVar4;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + cVar4;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + cVar4;
      pcVar3 = (code *)swi(0x3f);
      bVar5 = (*pcVar3)();
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      *pbVar9 = *pbVar9 ^ (byte)pcVar15;
      *(char **)(pbVar9 + (int)unaff_SI) = pcVar15 + *(int *)(pbVar9 + (int)unaff_SI);
      pbVar9[(int)unaff_SI] = pbVar9[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      in_AF = 9 < (bVar5 & 0xf) | in_AF;
      bVar5 = bVar5 + in_AF * -6 & 0xf;
      in_AF = 9 < bVar5 | in_AF;
      bVar5 = bVar5 + in_AF * -6 & 0xf;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      in_AF = 9 < bVar5 | in_AF;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + (bVar5 + in_AF * -6 & 0xf);
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + -0x61;
      bVar5 = (byte)*(undefined2 *)unaff_SI;
      *unaff_SI = *unaff_SI + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      in_AF = 9 < (bVar5 & 0xf) | in_AF;
      pcVar3 = (code *)swi(0x3f);
      (*pcVar3)();
      bVar17 = false;
      pcVar3 = (code *)swi(0x3f);
      bVar5 = (*pcVar3)();
      if (bVar17) {
        pcVar3 = (code *)swi(0x3f);
        bVar5 = (*pcVar3)();
      }
      else {
        in_AF = 9 < (bVar5 & 0xf) | in_AF;
        bVar5 = bVar5 + in_AF * -6 & 0xf;
      }
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      bVar5 = bVar5 + (9 < (bVar5 & 0xf) | in_AF) * -6 & 0xf;
      pcVar15[(int)unaff_SI] = pcVar15[(int)unaff_SI] + bVar5;
      *unaff_DI = *unaff_SI;
      pcVar15[(int)(unaff_SI + 1)] = pcVar15[(int)(unaff_SI + 1)] + bVar5;
      return;
    }
  }
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  bVar6 = bVar5 + in_AF * -6 & 0xf;
  bVar5 = 9 < bVar6 | in_AF;
  bVar7 = (byte)((undefined1 *)&DAT_6000_21c0 +
                (uint)bVar5 + (CONCAT11((cVar4 - in_AF) - bVar5,bVar6 + bVar5 * -6) & 0xff0f));
  bVar16 = 9 < (bVar7 & 0xf) | bVar5;
  *(uint *)(pcVar15 + (int)unaff_SI) =
       *(int *)(pcVar15 + (int)unaff_SI) +
       (CONCAT11((char)((uint)((undefined1 *)&DAT_6000_21c0 +
                              (uint)bVar5 +
                              (CONCAT11((cVar4 - in_AF) - bVar5,bVar6 + bVar5 * -6) & 0xff0f)) >> 8)
                 - bVar16,bVar7 + bVar16 * -6) & 0xff0f) + (uint)bVar16;
  pcVar3 = (code *)swi(0x3f);
  (*pcVar3)();
  pcVar3 = (code *)swi(0x3f);
  (*pcVar3)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

