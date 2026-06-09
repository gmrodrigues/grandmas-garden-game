// TIM2.EXE: FUN_54e8_0089 @ file 0x05A109 Ghidra 0x54F09
// Subsystem: misc | Size: 72 bytes


/* WARNING: Control flow encountered bad instruction data */

void FUN_54e8_0089(void)

{
  byte *pbVar1;
  uint uVar2;
  code *pcVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  byte extraout_AL;
  undefined2 uVar7;
  char extraout_AH;
  undefined1 *puVar9;
  byte *pbVar10;
  int iVar11;
  byte bVar12;
  undefined2 in_CX;
  char cVar13;
  char extraout_DL;
  int in_BX;
  int unaff_BP;
  byte *unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  byte in_AF;
  bool bVar14;
  uint uVar8;
  
  pcVar3 = (code *)swi(0x3f);
  uVar7 = (*pcVar3)();
  bVar6 = (byte)uVar7;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
  bVar12 = (byte)in_CX;
  cVar13 = (char)((uint)in_CX >> 8) + bVar12;
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  bVar6 = bVar6 + in_AF * -6;
  bVar4 = bVar6 & 0xf;
  uVar8 = CONCAT11((char)((uint)uVar7 >> 8) - in_AF,bVar6) & 0xff0f;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar4;
  pbVar1 = unaff_SI + in_BX;
  bVar6 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar4;
  uVar2 = uVar8 + 0x194;
  cVar5 = (char)uVar2 + CARRY1(bVar6,bVar4);
  unaff_SI[in_BX] =
       unaff_SI[in_BX] + cVar5 + (0xfe6b < uVar8 || CARRY2(uVar2,(uint)CARRY1(bVar6,bVar4)));
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar5;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar5;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar5;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar5;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar5;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar5;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar5;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar5;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar5;
  pcVar3 = (code *)swi(0x3f);
  bVar6 = (*pcVar3)();
  pbVar1 = unaff_SI;
  *pbVar1 = *pbVar1 >> (bVar12 & 7) | *pbVar1 << 8 - (bVar12 & 7);
  cVar13 = cVar13 + bVar12 * '\x02';
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  unaff_SI[in_BX] = unaff_SI[in_BX] | bVar12;
  in_AF = 9 < (bVar6 + in_AF * -6 & 0xf) | in_AF;
                    /* WARNING: Call to offcut address within same function */
  func_0x00054f51();
  pcVar3 = (code *)swi(0x3f);
  uVar7 = (*pcVar3)();
  in_AF = 9 < ((byte)uVar7 & 0xf) | in_AF;
  pbVar1 = unaff_SI + in_BX;
  *(uint *)pbVar1 =
       *(int *)pbVar1 +
       (CONCAT11((char)((uint)uVar7 >> 8) + in_AF,(byte)uVar7 + in_AF * '\x06') & 0xff0f) +
       (uint)in_AF;
  bVar14 = *(int *)pbVar1 == 0;
  pcVar3 = (code *)swi(0x3f);
  (*pcVar3)();
  bVar6 = extraout_AL;
  cVar5 = extraout_AH;
  if (bVar14) {
    cVar13 = cVar13 + bVar12;
    bVar4 = 9 < (extraout_AL & 0xf) | in_AF;
    bVar6 = extraout_AL + bVar4 * -6 & 0xf;
    bVar12 = bVar12 | DAT_6000_21c0;
    in_AF = 9 < bVar6 | bVar4;
    bVar6 = bVar6 + in_AF * -6 & 0xf;
    cVar5 = (extraout_AH - bVar4) - in_AF;
  }
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  puVar9 = (undefined1 *)&DAT_6000_21c0 + (CONCAT11(cVar5 - in_AF,bVar6 + in_AF * -6) & 0xff0f);
  in_AF = 9 < ((byte)puVar9 & 0xf) | in_AF;
  bVar6 = (byte)puVar9 + in_AF * -6 & 0xf;
  pbVar10 = unaff_SI + 1;
  if (CONCAT11(cVar13 + bVar12,bVar12) == 1 || puVar9 == (undefined1 *)0x0) {
    bVar4 = 9 < bVar6 | in_AF;
    pbVar10 = (byte *)(CONCAT11(((char)((uint)puVar9 >> 8) - in_AF) - bVar4,bVar6 + bVar4 * -6) &
                      0xff0f);
    bVar6 = (byte)(unaff_SI + 1);
    bVar12 = CARRY1(bVar6,pbVar10[in_BX]) || CARRY1(bVar6 + pbVar10[in_BX],bVar4);
    pcVar3 = (code *)swi(0x3f);
    bVar6 = (*pcVar3)();
    cVar5 = CARRY1(bVar6,pbVar10[in_BX]) || CARRY1(bVar6 + pbVar10[in_BX],bVar12);
    pcVar3 = (code *)swi(0x3f);
    bVar6 = (*pcVar3)();
    pbVar10[unaff_BP] = (pbVar10[unaff_BP] - extraout_DL) - cVar5;
    in_AF = 9 < (bVar6 & 0xf) | bVar4;
  }
  pcVar3 = (code *)swi(0x3f);
  (*pcVar3)();
  pcVar3 = (code *)swi(0x3f);
  uVar7 = (*pcVar3)();
  bVar6 = (byte)uVar7;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar6;
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  bVar4 = bVar6 + in_AF * -6 & 0xf;
  bVar6 = 9 < bVar4 | in_AF;
  pbVar10[in_BX] = pbVar10[in_BX] + (bVar4 + bVar6 * -6 & 0xf);
  bVar4 = bRam000555d4;
  *(char *)(in_BX + unaff_DI) =
       *(char *)(in_BX + unaff_DI) + (((char)((uint)uVar7 >> 8) - in_AF) - bVar6);
  cRam000555c0 = cRam000555c0 + bVar4;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar4;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar4;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar4;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar4;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar4;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar4;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar4;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar4;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar4;
  bVar6 = bVar4 + (9 < (bVar4 & 0xf) | bVar6) * -6 & 0xf;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar6;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar6;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar6;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar6;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar6;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar6;
  pbVar10[in_BX] = pbVar10[in_BX] + bVar6;
  pcVar3 = (code *)swi(0x3f);
  iVar11 = (*pcVar3)();
  pbVar1 = pbVar10 + in_BX;
  bVar6 = *pbVar1;
  *pbVar1 = *pbVar1 + (byte)iVar11;
  *pbVar10 = *pbVar10 << 1 | CARRY1(bVar6,(byte)iVar11);
  *(int *)(pbVar10 + in_BX) = *(int *)(pbVar10 + in_BX) + iVar11;
  *(int *)(unaff_BP + iVar11) = *(int *)(unaff_BP + iVar11) + in_BX;
  cVar5 = (char)pbVar10;
  *(char *)(in_BX + iVar11) = *(char *)(in_BX + iVar11) + cVar5;
  *(char *)(in_BX + iVar11) = *(char *)(in_BX + iVar11) + cVar5;
  *(char *)(in_BX + iVar11) = *(char *)(in_BX + iVar11) + cVar5;
  *(char *)(in_BX + iVar11) = *(char *)(in_BX + iVar11) + cVar5;
  *(char *)(in_BX + iVar11) = *(char *)(in_BX + iVar11) + cVar5;
  *(char *)(in_BX + iVar11) = *(char *)(in_BX + iVar11) + cVar5;
  *(char *)(in_BX + iVar11) = *(char *)(in_BX + iVar11) + cVar5;
  *(char *)(in_BX + iVar11) = *(char *)(in_BX + iVar11) + cVar5;
  *(char *)(in_BX + iVar11) = *(char *)(in_BX + iVar11) + cVar5;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

