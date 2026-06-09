// TIM2.EXE: FUN_550e_002a @ file 0x05A30A Ghidra 0x5510A
// Subsystem: misc | Size: 137 bytes


/* WARNING: Instruction at (ram,0x0005515f) overlaps instruction at (ram,0x0005515c)
    */

void FUN_550e_002a(undefined2 param_1,int param_2)

{
  byte *pbVar1;
  code *pcVar2;
  byte bVar3;
  byte extraout_AL;
  byte bVar4;
  undefined2 uVar5;
  char extraout_AH;
  char cVar7;
  uint uVar6;
  char cVar8;
  undefined2 in_CX;
  char cVar9;
  char cVar10;
  int in_BX;
  int iVar11;
  int iVar12;
  char *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  byte in_AF;
  byte bVar13;
  bool bVar14;
  char cVar15;
  undefined4 uVar16;
  undefined2 in_stack_00000014;
  undefined2 in_stack_0000001a;
  
  pcVar2 = (code *)swi(0x3f);
  bVar3 = (*pcVar2)();
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  cVar8 = (char)in_CX;
  cVar9 = (char)((uint)in_CX >> 8) + cVar8 * '\x02';
  in_AF = 9 < (bVar3 & 0xf) | in_AF;
  *unaff_DI = *unaff_DI & (byte)in_BX;
  in_AF = 9 < (bVar3 + in_AF * -6 & 0xf) | in_AF;
  pcVar2 = (code *)swi(0x3f);
  (*pcVar2)();
  pcVar2 = (code *)swi(0x3f);
  (*pcVar2)();
  iVar11 = 0;
  bVar3 = 0;
  pcVar2 = (code *)swi(0x3f);
  uVar5 = (*pcVar2)();
  *(uint *)(unaff_SI + iVar11) = *(uint *)(unaff_SI + iVar11) >> 1 | (uint)bVar3 << 0xf;
  cVar9 = cVar9 + cVar8 * '\x03';
  in_AF = 9 < ((byte)uVar5 & 0xf) | in_AF;
  uVar6 = CONCAT11((char)((uint)uVar5 >> 8) - in_AF,(byte)uVar5 + in_AF * -6) & 0xff0f;
  in_AF = 9 < ((byte)iVar11 & 0xf) | in_AF;
  bVar3 = (((byte)iVar11 + in_AF * -6 & 0xf) - 0x16) - in_AF;
  in_AF = 9 < (bVar3 & 0xf) | in_AF;
  bVar3 = (bVar3 + in_AF * -6 & 0xf) + in_AF;
  in_AF = 9 < (bVar3 & 0xf) | in_AF;
  bVar3 = bVar3 + in_AF * -6 & 0xf;
  pbVar1 = unaff_DI + 1;
  cVar10 = SCARRY1(bVar3,bVar3 < *unaff_DI);
  cVar15 = '\0';
  bVar14 = (byte)(bVar3 + (bVar3 < *unaff_DI)) == '\0';
  pcVar2 = (code *)swi(0x3f);
  (*pcVar2)();
  bVar3 = extraout_AL;
  cVar7 = extraout_AH;
  if (bVar14 || cVar10 != cVar15) {
LAB_550e_0074:
    in_AF = 9 < (bVar3 & 0xf) | in_AF;
    bVar3 = bVar3 + in_AF * -6 & 0xf;
    cVar7 = cVar7 - in_AF;
    cVar10 = cVar9 + cVar8;
    if ((char)(cVar9 + cVar8) == '\0') {
      in_AF = 9 < bVar3 | in_AF;
      cVar7 = cVar7 - in_AF;
      bVar3 = (bVar3 + in_AF * -6 & 0xf) - DAT_6000_21c0;
      cVar10 = cVar8;
    }
  }
  else {
    cVar9 = cVar9 + cVar8;
    in_AF = 9 < (extraout_AL & 0xf) | in_AF;
    unaff_SI = unaff_SI + -1;
    pcVar2 = (code *)swi(0x3f);
    uVar5 = (*pcVar2)();
    pbVar1[uVar6] = pbVar1[uVar6] + 1;
    cVar10 = cVar9 + cVar8;
    bVar13 = 9 < ((byte)uVar5 & 0xf) | in_AF;
    bVar3 = (byte)uVar5 + bVar13 * -6 & 0xf;
    if (cVar10 == '\0' || SCARRY1(cVar9,cVar8) != cVar10 < '\0') {
      pcVar2 = (code *)swi(0x3f);
      uVar6 = (*pcVar2)();
      goto code_r0x00055161;
    }
    bVar14 = SCARRY1(cVar10,cVar8);
    cVar9 = cVar10 + cVar8;
    in_AF = 9 < bVar3 | bVar13;
    bVar3 = bVar3 + in_AF * -6 & 0xf;
    cVar7 = ((char)((uint)uVar5 >> 8) - bVar13) - in_AF;
    cVar10 = cVar9;
    if (cVar9 != '\0' && bVar14 == cVar9 < '\0') goto LAB_550e_0074;
  }
  bVar13 = 9 < (bVar3 & 0xf) | in_AF;
  uVar6 = CONCAT11(cVar7 - bVar13,bVar3 + bVar13 * -6) & 0xff0f;
code_r0x00055161:
  bVar3 = (byte)((undefined1 *)&DAT_6000_21c0 + uVar6);
  bVar13 = 9 < (bVar3 & 0xf) | bVar13;
  uVar6 = CONCAT11((char)((uint)((undefined1 *)&DAT_6000_21c0 + uVar6) >> 8) - bVar13,
                   bVar3 + bVar13 * -6) & 0xff0f;
  pcVar2 = (code *)swi(0x3f);
  bVar3 = (*pcVar2)();
  unaff_SI[uVar6] = unaff_SI[uVar6] + (bVar3 | 0x13);
  pcVar2 = (code *)swi(0x3f);
  cVar7 = (*pcVar2)();
  unaff_SI[uVar6] = unaff_SI[uVar6] + cVar7;
  iVar12 = CONCAT11((char)(uVar6 >> 8) + cVar10,(char)uVar6);
  bVar3 = cRam00055620 + 0x8c;
  unaff_SI[param_2] = unaff_SI[param_2] + bVar3;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar3;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar3;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar3;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar3;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar3;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar3;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar3;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar3;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar3;
  cVar10 = cVar10 + cVar8;
  bVar13 = 9 < (bVar3 & 0xf) | bVar13;
  pcVar2 = (code *)swi(0x3f);
  uVar16 = (*pcVar2)();
  bVar3 = (byte)uVar16;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar3;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar3;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar3;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar3;
  bVar13 = 9 < (bVar3 & 0xf) | bVar13;
  bVar4 = bVar3 + bVar13 * -6 & 0xf;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar4;
  *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) & (char)((ulong)uVar16 >> 8) - bVar13;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar4;
  cVar7 = *unaff_SI;
  pbVar1[param_2] = pbVar1[param_2] + bVar4;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar4;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar4;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar4;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar4;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar4;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar4;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar4;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar4;
  unaff_SI[iVar12] = unaff_SI[iVar12] + bVar4;
  iVar11 = CONCAT11(cVar10 + cVar8 + cVar8 + cVar7,cVar8 + cVar7);
  bVar3 = in((int)((ulong)uVar16 >> 0x10));
  *pbVar1 = bVar3;
  unaff_SI[iVar12] = unaff_SI[iVar12] + (bVar4 + (9 < bVar4 | bVar13) * -6 & 0xf);
  pcVar2 = (code *)swi(0x3f);
  cVar10 = (*pcVar2)();
  bVar3 = (byte)((uint)(iVar11 + -1) >> 8);
  unaff_SI[iVar12] = unaff_SI[iVar12] + cVar10;
  pcVar2 = (code *)swi(0x3f);
  cVar10 = (*pcVar2)();
  unaff_SI[iVar12] = unaff_SI[iVar12] + cVar10;
  unaff_SI[iVar12] = unaff_SI[iVar12] + cVar10;
  pcVar2 = (code *)swi(0x3f);
  uVar5 = (*pcVar2)();
  unaff_SI[iVar12] = unaff_SI[iVar12] + (char)uVar5;
  unaff_SI[iVar12 + 1] = unaff_SI[iVar12 + 1] ^ bVar3;
  unaff_DI[0xb] = unaff_DI[0xb] + (char)((uint)uVar5 >> 8);
  return;
}

