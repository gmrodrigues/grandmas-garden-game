// TIM2.EXE: FUN_54b0_0034 @ file 0x059D34 Ghidra 0x54B34
// Subsystem: misc | Size: 49 bytes


uint FUN_54b0_0034(void)

{
  byte *pbVar1;
  code *pcVar2;
  byte bVar3;
  byte bVar4;
  undefined2 uVar5;
  byte bVar6;
  char extraout_DL;
  char *in_BX;
  int unaff_SI;
  int unaff_DI;
  byte in_AF;
  
  pcVar2 = (code *)swi(0x3f);
  uVar5 = (*pcVar2)();
  bVar3 = (byte)uVar5;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar3;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar3;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar3;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar3;
  in_AF = 9 < (bVar3 & 0xf) | in_AF;
  bVar4 = bVar3 + in_AF * -6 & 0xf;
  bVar6 = (char)((uint)uVar5 >> 8) - in_AF;
  pbVar1 = (byte *)(in_BX + unaff_SI);
  bVar3 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar4;
  *in_BX = *in_BX + extraout_DL + CARRY1(bVar3,bVar4);
  pbVar1 = (byte *)(in_BX + 0x12);
  bVar3 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar6;
  in_BX[unaff_DI] = (in_BX[unaff_DI] - bVar4) - CARRY1(bVar3,bVar6);
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_BX[unaff_SI] = in_BX[unaff_SI] + bVar4;
  in_AF = 9 < bVar4 | in_AF;
  return CONCAT11(bVar6 - in_AF,bVar4 + in_AF * -6) & 0xff0f;
}

