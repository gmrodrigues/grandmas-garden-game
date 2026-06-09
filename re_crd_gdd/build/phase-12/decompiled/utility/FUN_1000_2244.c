// TIM2.EXE: FUN_1000_2244 @ file 0x017444 Ghidra 0x12244
// Subsystem: utility | Size: 7 bytes


void FUN_1000_2244(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte extraout_AH;
  char *unaff_DI;
  undefined2 unaff_ES;
  byte in_AF;
  
  FUN_1000_224b();
  FUN_1000_2254();
  in_AF = 9 < (extraout_AH + 0x90 & 0xf) | in_AF;
  bVar3 = extraout_AH + 0x90 + in_AF * '\x06';
  bVar2 = 0x90 < (bVar3 & 0xf0) | 0x6f < extraout_AH | in_AF * (0xf9 < bVar3);
  bVar3 = bVar3 + bVar2 * '`';
  bVar1 = bVar3 + 0x40;
  bVar4 = bVar1 + bVar2;
  in_AF = 9 < (bVar4 & 0xf) | in_AF;
  bVar4 = bVar4 + in_AF * '\x06';
  *unaff_DI = bVar4 + (0x90 < (bVar4 & 0xf0) |
                      (0xbf < bVar3 || CARRY1(bVar1,bVar2)) | in_AF * (0xf9 < bVar4)) * '`';
  return;
}

