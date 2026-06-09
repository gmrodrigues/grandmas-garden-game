// TIM2.EXE: FUN_54bb_003e @ file 0x059DEE Ghidra 0x54BEE
// Subsystem: misc | Size: 328 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00054d1f) overlaps instruction at (ram,0x00054d1e)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16near FUN_54bb_003e(void)

{
  byte *pbVar1;
  int *piVar2;
  code *pcVar3;
  char cVar4;
  byte bVar5;
  byte extraout_AL;
  byte bVar6;
  byte bVar7;
  int iVar8;
  undefined2 uVar9;
  char extraout_AH;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  undefined2 in_CX;
  char extraout_DL;
  byte extraout_DH;
  char *in_BX;
  byte *unaff_BP;
  byte *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  byte bVar13;
  byte in_AF;
  bool bVar14;
  char cVar15;
  bool bVar16;
  
  pcVar3 = (code *)swi(0x3f);
  cVar4 = (*pcVar3)();
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar4;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar4;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar4;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar4;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar4;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar4;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar4;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar4;
  pcVar3 = (code *)swi(0x3f);
  iVar8 = (*pcVar3)();
  bVar5 = (byte)iVar8;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
  *unaff_DI = *unaff_DI & extraout_DH;
  (unaff_BP + (int)unaff_DI)[0x1f] = (unaff_BP + (int)unaff_DI)[0x1f] + (char)((uint)in_CX >> 8);
  *(uint *)(in_BX + (int)unaff_SI) = *(int *)(in_BX + (int)unaff_SI) + iVar8 + (uint)(bVar5 < 2);
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
  pbVar1 = (byte *)(in_BX + (int)unaff_SI);
  bVar13 = CARRY1(*pbVar1,bVar5);
  *pbVar1 = *pbVar1 + bVar5;
  cVar15 = (char)*pbVar1 < '\0';
  bVar14 = *pbVar1 == 0;
  pcVar3 = (code *)swi(0x3f);
  uVar9 = (*pcVar3)();
  bVar16 = (int)_DAT_6000_21c0 < 0;
  _DAT_6000_21c0 = _DAT_6000_21c0 >> 1 | (uint)bVar13 << 0xf;
  in_AF = 9 < ((byte)uVar9 & 0xf) | in_AF;
  bVar5 = (byte)uVar9 + in_AF * -6 & 0xf;
  cVar4 = (char)((uint)uVar9 >> 8) - in_AF;
  if (bVar14 || (bVar16 != ((uint)bVar13 << 0xf != 0)) != (bool)cVar15) {
    in_AF = 9 < bVar5 | in_AF;
    bVar5 = (bVar5 + in_AF * -6 & 0xf) - in_AF;
    in_AF = 9 < (bVar5 & 0xf) | in_AF;
    iVar8 = CONCAT11((char)((uint)in_CX >> 8) + (char)in_CX * '\x02',(char)in_CX);
    in_AF = 9 < ((bVar5 + in_AF * -6 & 0xf) - 0x1c & 0xf) | in_AF;
    pcVar3 = (code *)swi(0x3f);
    (*pcVar3)();
    bVar5 = extraout_AL;
    cVar4 = extraout_AH;
    if (iVar8 == 0) {
      pcVar3 = (code *)swi(0x3f);
      (*pcVar3)();
      *unaff_SI = *unaff_SI;
      pcVar3 = (code *)swi(0x3f);
      (*pcVar3)();
      pcVar3 = (code *)swi(0x3f);
      uVar9 = (*pcVar3)();
      unaff_BP[(int)unaff_SI] = unaff_BP[(int)unaff_SI] + 1;
      in_AF = 9 < ((byte)uVar9 & 0xf) | in_AF;
      uVar10 = CONCAT11((char)((uint)uVar9 >> 8) - in_AF,(byte)uVar9 + in_AF * -6) & 0xff0f;
      piVar2 = (int *)(in_BX + (int)unaff_SI);
      cVar15 = SCARRY2(*piVar2,uVar10);
      *piVar2 = *piVar2 + uVar10;
      cVar4 = *piVar2 < 0;
      bVar14 = *piVar2 == 0;
      pcVar3 = (code *)swi(0x3f);
      pbVar11 = (byte *)(*pcVar3)();
      bVar5 = (byte)pbVar11;
      if (bVar14 || cVar15 != cVar4) {
        *unaff_DI = *unaff_DI + bVar5;
        in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      }
      else {
        in_AF = 9 < (bVar5 & 0xf) | in_AF;
        bVar5 = bVar5 + in_AF * -6 & 0xf;
        in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
        in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
        in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
        in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
        in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
        in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
        in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
        pcVar3 = (code *)swi(0x3f);
        pbVar12 = (byte *)(*pcVar3)();
        pbVar1 = (byte *)(in_BX + (int)unaff_SI);
        bVar5 = *pbVar1;
        *pbVar1 = *pbVar1 + (byte)pbVar12;
        *in_BX = *in_BX + extraout_DL + CARRY1(bVar5,(byte)pbVar12);
        pbVar11 = unaff_SI;
        unaff_SI = pbVar12;
      }
      bVar5 = (byte)pbVar11;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
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
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar4;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar4;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar4;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar4;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar4;
      pcVar3 = (code *)swi(0x3f);
      bVar5 = (*pcVar3)();
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      *unaff_BP = *unaff_BP ^ (byte)in_BX;
      *(char **)(unaff_BP + (int)unaff_SI) = in_BX + *(int *)(unaff_BP + (int)unaff_SI);
      unaff_BP[(int)unaff_SI] = unaff_BP[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_AF = 9 < (bVar5 & 0xf) | in_AF;
      bVar5 = bVar5 + in_AF * -6 & 0xf;
      in_AF = 9 < bVar5 | in_AF;
      bVar5 = bVar5 + in_AF * -6 & 0xf;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_AF = 9 < bVar5 | in_AF;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + (bVar5 + in_AF * -6 & 0xf);
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + -0x61;
      bVar5 = (byte)*(undefined2 *)unaff_SI;
      *unaff_SI = *unaff_SI + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_AF = 9 < (bVar5 & 0xf) | in_AF;
      pcVar3 = (code *)swi(0x3f);
      (*pcVar3)();
      bVar14 = false;
      pcVar3 = (code *)swi(0x3f);
      bVar5 = (*pcVar3)();
      if (bVar14) {
        pcVar3 = (code *)swi(0x3f);
        bVar5 = (*pcVar3)();
      }
      else {
        in_AF = 9 < (bVar5 & 0xf) | in_AF;
        bVar5 = bVar5 + in_AF * -6 & 0xf;
      }
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      bVar5 = bVar5 + (9 < (bVar5 & 0xf) | in_AF) * -6 & 0xf;
      in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar5;
      *unaff_DI = *unaff_SI;
      in_BX[(int)(unaff_SI + 1)] = in_BX[(int)(unaff_SI + 1)] + bVar5;
      return;
    }
  }
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  bVar6 = bVar5 + in_AF * -6 & 0xf;
  bVar5 = 9 < bVar6 | in_AF;
  bVar7 = (byte)((undefined1 *)&DAT_6000_21c0 +
                (uint)bVar5 + (CONCAT11((cVar4 - in_AF) - bVar5,bVar6 + bVar5 * -6) & 0xff0f));
  bVar13 = 9 < (bVar7 & 0xf) | bVar5;
  *(uint *)(in_BX + (int)unaff_SI) =
       *(int *)(in_BX + (int)unaff_SI) +
       (CONCAT11((char)((uint)((undefined1 *)&DAT_6000_21c0 +
                              (uint)bVar5 +
                              (CONCAT11((cVar4 - in_AF) - bVar5,bVar6 + bVar5 * -6) & 0xff0f)) >> 8)
                 - bVar13,bVar7 + bVar13 * -6) & 0xff0f) + (uint)bVar13;
  pcVar3 = (code *)swi(0x3f);
  (*pcVar3)();
  pcVar3 = (code *)swi(0x3f);
  (*pcVar3)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

