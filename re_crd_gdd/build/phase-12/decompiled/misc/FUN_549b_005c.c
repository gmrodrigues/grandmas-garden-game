// TIM2.EXE: FUN_549b_005c @ file 0x059C0C Ghidra 0x54A0C
// Subsystem: misc | Size: 30 bytes


void FUN_549b_005c(undefined2 param_1,int param_2)

{
  code *pcVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  int extraout_DX;
  int extraout_DX_00;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  byte in_CF;
  byte in_AF;
  undefined4 uVar5;
  uint *in_stack_0000000e;
  
  pcVar1 = (code *)swi(0x3f);
  bVar2 = (*pcVar1)();
  *(int *)(unaff_BP + unaff_SI) = (*(int *)(unaff_BP + unaff_SI) - extraout_DX) - (uint)in_CF;
  in_AF = 9 < (bVar2 & 0xf) | in_AF;
  pcVar1 = (code *)swi(0x3f);
  bVar2 = (*pcVar1)();
  in_BX = in_BX + -1;
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) | bVar2;
  pcVar1 = (code *)swi(0x3f);
  bVar2 = (*pcVar1)();
  in_AF = 9 < (bVar2 & *unaff_DI & 0xf) | in_AF;
  in_AF = 9 < ((bVar2 & *unaff_DI) + in_AF * -6 & 0xf) | in_AF;
  pcVar1 = (code *)swi(0x3f);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x3f);
  uVar5 = (*pcVar1)();
  in_AF = 9 < ((byte)uVar5 & 0xf) | in_AF;
  bVar2 = (byte)uVar5 + in_AF * -6;
  out((int)((ulong)uVar5 >> 0x10),bVar2 & 0xf);
  *(int *)(in_BX + unaff_SI) =
       *(int *)(in_BX + unaff_SI) + (CONCAT11((char)((ulong)uVar5 >> 8) - in_AF,bVar2) & 0xff0f);
  pcVar1 = (code *)swi(0x3f);
  bVar2 = (*pcVar1)();
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar2;
  in_AF = 9 < (bVar2 & 0xf) | in_AF;
  uVar4 = CONCAT11('\x01' - in_AF,bVar2 + in_AF * -6) & 0xff0f;
  cVar3 = (char)uVar4;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(byte *)(in_BX + (int)in_stack_0000000e) = *(byte *)(in_BX + (int)in_stack_0000000e) >> 1;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *in_stack_0000000e = uVar4;
  *(int *)(param_2 + unaff_SI) = *(int *)(param_2 + unaff_SI) + extraout_DX_00;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  pcVar1 = (code *)swi(0x3f);
  (*pcVar1)();
  pcVar1 = (code *)swi(1);
  (*pcVar1)();
  return;
}

