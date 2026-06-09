// TIM2.EXE: FUN_5517_0025 @ file 0x05A395 Ghidra 0x55195
// Subsystem: misc | Size: 71 bytes


void __stdcall16far FUN_5517_0025(void)

{
  undefined1 uVar1;
  code *pcVar2;
  byte bVar3;
  char extraout_AH;
  char extraout_AH_00;
  char cVar4;
  undefined2 in_CX;
  int iVar5;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_BP;
  char *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  byte in_AF;
  
  pcVar2 = (code *)swi(0x3f);
  bVar3 = (*pcVar2)();
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  in_AF = 9 < (bVar3 & 0xf) | in_AF;
  bVar3 = bVar3 + in_AF * -6 & 0xf;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  *(byte *)(unaff_BP + 1) = *(byte *)(unaff_BP + 1) & extraout_AH - in_AF;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  cVar4 = (char)in_CX + *unaff_SI;
  unaff_DI[unaff_BP] = unaff_DI[unaff_BP] + bVar3;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar3;
  iVar5 = CONCAT11((char)((uint)in_CX >> 8) + (char)in_CX + cVar4,cVar4);
  uVar1 = in(extraout_DX);
  *unaff_DI = uVar1;
  unaff_SI[in_BX] = unaff_SI[in_BX] + (bVar3 + (9 < bVar3 | in_AF) * -6 & 0xf);
  pcVar2 = (code *)swi(0x3f);
  cVar4 = (*pcVar2)();
  bVar3 = (byte)((uint)(iVar5 + -1) >> 8);
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar4;
  pcVar2 = (code *)swi(0x3f);
  cVar4 = (*pcVar2)();
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar4;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar4;
  pcVar2 = (code *)swi(0x3f);
  cVar4 = (*pcVar2)();
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar4;
  unaff_SI[in_BX + 1] = unaff_SI[in_BX + 1] ^ bVar3;
  unaff_DI[10] = unaff_DI[10] + extraout_AH_00;
  return;
}

