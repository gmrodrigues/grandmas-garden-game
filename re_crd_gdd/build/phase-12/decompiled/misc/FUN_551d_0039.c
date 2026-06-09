// TIM2.EXE: FUN_551d_0039 @ file 0x05A409 Ghidra 0x55209
// Subsystem: misc | Size: 257 bytes


/* WARNING: Instruction at (ram,0x00055288) overlaps instruction at (ram,0x00055287)
    */

undefined2 __cdecl16far FUN_551d_0039(undefined2 param_1,char *param_2)

{
  char *pcVar1;
  byte *pbVar2;
  code *pcVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  undefined2 uVar8;
  char *pcVar9;
  char cVar10;
  int in_CX;
  char cVar11;
  int in_BX;
  char *unaff_BP;
  char *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_SS;
  byte in_AF;
  
  pcVar3 = (code *)swi(0x3f);
  uVar8 = (*pcVar3)();
  bVar5 = (byte)uVar8;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar5;
  cVar10 = (char)(in_CX + -1);
  cVar11 = (char)((uint)(in_CX + -1) >> 8) + cVar10;
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  bVar5 = bVar5 + in_AF * -6;
  bVar6 = bVar5 & 0xf;
  pcVar9 = (char *)(CONCAT11((char)((uint)uVar8 >> 8) - in_AF,bVar5) & 0xff0f);
  pcVar1 = unaff_SI + in_BX;
  cVar4 = *pcVar1;
  *pcVar1 = *pcVar1 + bVar6;
  if (!SCARRY1(cVar4,bVar6)) {
    *(char **)(unaff_SI + in_BX) = pcVar9 + *(int *)(unaff_SI + in_BX);
    pbVar2 = (byte *)(unaff_SI + in_BX);
    bVar5 = *pbVar2;
    *pbVar2 = *pbVar2 << 1 | (char)bVar5 < '\0';
    unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6 + ((char)bVar5 < '\0');
    cVar4 = bVar6 + unaff_SI[in_BX];
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
    uRam000554c0 = (*pcVar3)();
    pcVar3 = (code *)swi(0x3f);
    bVar5 = (*pcVar3)();
    unaff_SI[in_BX] = unaff_SI[in_BX] + bVar5;
    unaff_SI[in_BX] = unaff_SI[in_BX] + bVar5;
    unaff_SI[in_BX] = unaff_SI[in_BX] + bVar5;
    unaff_SI[in_BX] = unaff_SI[in_BX] + bVar5;
    in_AF = 9 < (bVar5 & 0xf) | in_AF;
    bVar6 = bVar5 + in_AF * -6 & 0xf;
    pbVar2 = (byte *)(unaff_SI + in_BX);
    bVar5 = *pbVar2;
    *pbVar2 = *pbVar2 + bVar6;
    if (CARRY1(bVar5,bVar6)) {
      *(char *)(in_BX + 0x4602) = *(char *)(in_BX + 0x4602) + cVar11 + cVar10;
      *unaff_SI = *unaff_SI + bVar6;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
      in_AF = 9 < bVar6 | in_AF;
      bVar5 = bVar6 + in_AF * -6 & 0xf;
    }
    else {
      unaff_DI = unaff_DI + 2;
      cVar4 = bVar6 + *unaff_BP;
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
      bVar5 = (*pcVar3)();
    }
    in_AF = 9 < (bVar5 & 0xf) | in_AF;
    pbVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *pbVar2 = bVar5 + in_AF * -6 & 0xf;
    pcVar3 = (code *)swi(0x3f);
    uVar8 = (*pcVar3)();
    bVar6 = (char)uVar8 - 2;
    bVar5 = 9 < (bVar6 & 0xf) | in_AF;
    bVar6 = bVar6 + bVar5 * -6 & 0xf;
    unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
    unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
    unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
    unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
    unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
    unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
    unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
    in_AF = 9 < bVar6 | bVar5;
    bVar6 = bVar6 + in_AF * -6;
    bVar7 = bVar6 & 0xf;
    pcVar9 = (char *)(CONCAT11(((char)((uint)uVar8 >> 8) - bVar5) - in_AF,bVar6) & 0xff0f);
    pbVar2 = (byte *)(unaff_SI + in_BX);
    bVar5 = *pbVar2;
    *pbVar2 = *pbVar2 + bVar7;
    param_2 = pcVar9;
    if (!CARRY1(bVar5,bVar7) && *pbVar2 != 0) {
      unaff_BP[3] = unaff_BP[3] + (char)in_BX;
      unaff_BP[(int)unaff_DI] = unaff_BP[(int)unaff_DI] + bVar7;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar7;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar7;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar7;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar7;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar7;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar7;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar7;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar7;
      unaff_SI[in_BX] = unaff_SI[in_BX] + bVar7;
      in_AF = 9 < bVar7 | in_AF;
      bVar5 = bVar7 + in_AF * -6 & 0xf;
      goto LAB_3f2b_0a21;
    }
  }
  cVar4 = (char)pcVar9 + (char)*(undefined2 *)(param_2 + in_BX);
  param_2[in_BX] = param_2[in_BX] + cVar4;
  param_2[in_BX] = param_2[in_BX] + cVar4;
  param_2[in_BX] = param_2[in_BX] + cVar4;
  param_2[in_BX] = param_2[in_BX] + cVar4;
  param_2[in_BX] = param_2[in_BX] + cVar4;
  param_2[in_BX] = param_2[in_BX] + cVar4;
  param_2[in_BX] = param_2[in_BX] + cVar4;
  param_2[in_BX] = param_2[in_BX] + cVar4;
  param_2[in_BX] = param_2[in_BX] + cVar4;
  pcVar3 = (code *)swi(0x3f);
  bVar5 = (*pcVar3)();
  unaff_SI = param_2;
LAB_3f2b_0a21:
  in_AF = 9 < ((bVar5 ^ unaff_BP[(int)unaff_SI]) & 0xf) | in_AF;
  pcVar9 = unaff_SI + 2;
  pcVar9[in_BX] = pcVar9[in_BX] + (char)*(undefined2 *)unaff_SI;
  pcVar3 = (code *)swi(0x3f);
  cVar4 = (*pcVar3)();
  pcVar9[in_BX] = pcVar9[in_BX] + cVar4;
  pcVar9[in_BX] = pcVar9[in_BX] + cVar4;
  pcVar3 = (code *)swi(0x3f);
  bVar6 = (*pcVar3)();
  pbVar2 = (byte *)(pcVar9 + in_BX);
  bVar5 = *pbVar2;
  *pbVar2 = *pbVar2 + bVar6;
  (unaff_BP + (int)pcVar9)[1] =
       (unaff_BP + (int)pcVar9)[1] + (char)((uint)in_BX >> 8) + CARRY1(bVar5,bVar6);
  unaff_DI[0x1e01] = unaff_DI[0x1e01] + cVar10;
  unaff_DI[in_BX] = unaff_DI[in_BX] + bVar6;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar6;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar6;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar6;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar6;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar6;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar6;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar6;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar6;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar6;
  bVar5 = bVar6 + (9 < (bVar6 & 0xf) | in_AF) * -6 & 0xf;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar5;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar5;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar5;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar5;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar5;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar5;
  pcVar9[in_BX] = pcVar9[in_BX] + bVar5;
  pcVar3 = (code *)swi(0x3f);
  cVar4 = (*pcVar3)();
  pcVar9[in_BX] = pcVar9[in_BX] + cVar4;
  (unaff_BP + (int)unaff_DI)[1] = (unaff_BP + (int)unaff_DI)[1];
  *unaff_DI = *unaff_DI + cVar4;
  pcVar9[in_BX] = pcVar9[in_BX] + cVar4;
  pcVar9[in_BX] = pcVar9[in_BX] + cVar4;
  pcVar9[in_BX] = pcVar9[in_BX] + cVar4;
  pcVar9[in_BX] = pcVar9[in_BX] + cVar4;
  pcVar9[in_BX] = pcVar9[in_BX] + cVar4;
  pcVar9[in_BX] = pcVar9[in_BX] + cVar4;
  pcVar9[in_BX] = pcVar9[in_BX] + cVar4;
  pcVar9[in_BX] = pcVar9[in_BX] + cVar4;
  pcVar9[in_BX] = pcVar9[in_BX] + cVar4;
  uVar8 = DAT_5b41_1b4c;
  *(undefined2 *)(in_BX + 8) = DAT_5b41_1b4e;
  *(undefined2 *)(in_BX + 6) = uVar8;
  return *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -4) + 10);
}

