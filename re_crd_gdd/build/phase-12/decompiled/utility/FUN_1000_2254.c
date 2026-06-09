// TIM2.EXE: FUN_1000_2254 @ file 0x017454 Ghidra 0x12254
// Subsystem: utility | Size: 8 bytes


void __cdecl16near FUN_1000_2254(void)

{
  byte bVar1;
  byte bVar2;
  byte in_AL;
  byte bVar4;
  byte bVar5;
  char *unaff_DI;
  undefined2 unaff_ES;
  byte in_AF;
  byte bVar3;
  
  bVar2 = 9 < (in_AL + 0x90 & 0xf) | in_AF;
  bVar4 = in_AL + 0x90 + bVar2 * '\x06';
  bVar3 = 0x90 < (bVar4 & 0xf0) | 0x6f < in_AL | bVar2 * (0xf9 < bVar4);
  bVar4 = bVar4 + bVar3 * '`';
  bVar1 = bVar4 + 0x40;
  bVar5 = bVar1 + bVar3;
  bVar2 = 9 < (bVar5 & 0xf) | bVar2;
  bVar5 = bVar5 + bVar2 * '\x06';
  *unaff_DI = bVar5 + (0x90 < (bVar5 & 0xf0) |
                      (0xbf < bVar4 || CARRY1(bVar1,bVar3)) | bVar2 * (0xf9 < bVar5)) * '`';
  return;
}

