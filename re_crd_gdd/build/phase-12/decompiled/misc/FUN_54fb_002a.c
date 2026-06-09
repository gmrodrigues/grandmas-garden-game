// TIM2.EXE: FUN_54fb_002a @ file 0x05A1DA Ghidra 0x54FDA
// Subsystem: misc | Size: 67 bytes


void __cdecl16near FUN_54fb_002a(void)

{
  code *pcVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  byte in_BL;
  int iVar7;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  byte in_AF;
  longdouble in_ST0;
  undefined2 in_stack_0000000a;
  
  pcVar1 = (code *)swi(0x3f);
  bVar2 = (*pcVar1)();
  in_AF = 9 < (bVar2 & 0xf) | in_AF;
  bVar2 = bVar2 + in_AF * -6 & 0xf;
  in_AF = 9 < bVar2 | in_AF;
  bVar2 = bVar2 + in_AF * -6 & 0xf;
  FastExitMediaState();
  in_AF = 9 < bVar2 | in_AF;
  bVar2 = 9 < (in_BL & 0xf) | 9 < (((bVar2 + in_AF * -6 & 0xf) - 0xd) - in_AF & 0xf) | in_AF;
  bVar2 = 9 < ((in_BL + bVar2 * -6 & 0xf) + 0xd & 0xf) | bVar2;
  iVar7 = 0xc;
  pcVar1 = (code *)swi(0x3f);
  bVar3 = (*pcVar1)();
  bVar2 = 9 < (bVar3 & 0xf) | bVar2;
  uVar6 = 0;
  pcVar1 = (code *)swi(0x3f);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x3f);
  uVar5 = (*pcVar1)();
  *(long *)(unaff_BP + unaff_SI) = (long)in_ST0;
  bVar2 = 9 < ((byte)uVar5 & 0xf) | bVar2;
  bVar4 = (byte)uVar5 + bVar2 * -6 & 0xf;
  *(undefined2 *)(unaff_BP + unaff_SI) =
       CONCAT11((char)((uint)uVar6 >> 8) + (char)uVar6,(char)uVar6);
  bVar3 = 9 < bVar4 | bVar2;
  *(uint *)(iVar7 + unaff_SI) =
       *(uint *)(iVar7 + unaff_SI) |
       CONCAT11(((char)((uint)uVar5 >> 8) - bVar2) - bVar3,bVar4 + bVar3 * -6) & 0xff0f;
  pcVar1 = (code *)swi(0x3f);
  (*pcVar1)();
  return;
}

