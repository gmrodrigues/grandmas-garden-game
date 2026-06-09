// TIM2.EXE: FUN_54ac_002a @ file 0x059CEA Ghidra 0x54AEA
// Subsystem: misc | Size: 72 bytes


uint FUN_54ac_002a(void)

{
  char *pcVar1;
  byte *pbVar2;
  code *pcVar3;
  byte bVar4;
  byte bVar5;
  undefined2 uVar6;
  byte bVar7;
  char cVar8;
  undefined2 in_CX;
  char cVar9;
  char extraout_DL;
  char *in_BX;
  int unaff_SI;
  int unaff_DI;
  byte in_AF;
  byte bVar10;
  
  pcVar3 = (code *)swi(0x3f);
  bVar4 = (*pcVar3)();
  cVar8 = (char)in_CX;
  cVar9 = (char)((uint)in_CX >> 8) + cVar8 * '\x02';
  in_AF = 9 < (bVar4 & 0xf) | in_AF;
  bVar5 = bVar4 + in_AF * -6 & 0xf;
  bVar10 = 9 < bVar5 | in_AF;
  *(uint *)(in_BX + unaff_SI) =
       *(int *)(in_BX + unaff_SI) +
       (CONCAT11((((char)bVar4 >> 7) - in_AF) - bVar10,bVar5 + bVar10 * -6) & 0xff0f);
  pcVar3 = (code *)swi(0x3f);
  bVar4 = (*pcVar3)();
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  cVar9 = cVar9 + cVar8 * '\x03';
  bVar10 = 9 < (bVar4 & 0xf) | bVar10;
  bVar4 = bVar4 + bVar10 * -6 & 0xf;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  bVar4 = DAT_6000_28c6;
  pcVar1 = (char *)(unaff_DI + -1);
  *pcVar1 = *pcVar1 + DAT_6000_28c6;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  bVar10 = 9 < (bVar4 & 0xf) | bVar10;
  bVar4 = bVar4 + bVar10 * -6 & 0xf;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  bVar10 = 9 < bVar4 | bVar10;
  if (CONCAT11(cVar9,cVar8) != 1 && cVar9 != '\0') {
    bVar10 = 9 < (bVar4 + bVar10 * -6 & 0xf) | bVar10;
    pcVar3 = (code *)swi(0x3f);
    uVar6 = (*pcVar3)();
    bVar4 = (byte)uVar6;
    in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
    in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
    in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
    in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
    bVar10 = 9 < (bVar4 & 0xf) | bVar10;
    bVar5 = bVar4 + bVar10 * -6 & 0xf;
    bVar7 = (char)((uint)uVar6 >> 8) - bVar10;
    pbVar2 = (byte *)(in_BX + unaff_SI);
    bVar4 = *pbVar2;
    *pbVar2 = *pbVar2 + bVar5;
    *in_BX = *in_BX + extraout_DL + CARRY1(bVar4,bVar5);
    pbVar2 = (byte *)(in_BX + 0x12);
    bVar4 = *pbVar2;
    *pbVar2 = *pbVar2 + bVar7;
    in_BX[unaff_DI + -1] = (in_BX[unaff_DI + -1] - bVar5) - CARRY1(bVar4,bVar7);
    in_BX[unaff_SI] = in_BX[unaff_SI] + bVar5;
    in_BX[unaff_SI] = in_BX[unaff_SI] + bVar5;
    in_BX[unaff_SI] = in_BX[unaff_SI] + bVar5;
    in_BX[unaff_SI] = in_BX[unaff_SI] + bVar5;
    in_BX[unaff_SI] = in_BX[unaff_SI] + bVar5;
    in_BX[unaff_SI] = in_BX[unaff_SI] + bVar5;
    in_BX[unaff_SI] = in_BX[unaff_SI] + bVar5;
    in_BX[unaff_SI] = in_BX[unaff_SI] + bVar5;
    bVar10 = 9 < bVar5 | bVar10;
    return CONCAT11(bVar7 - bVar10,bVar5 + bVar10 * -6) & 0xff0f;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

