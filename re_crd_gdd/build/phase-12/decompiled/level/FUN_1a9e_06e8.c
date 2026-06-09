// TIM2.EXE: FUN_1a9e_06e8 @ file 0x0202C8 Ghidra 0x1B0C8
// Subsystem: level | Size: 117 bytes


void __cdecl16near FUN_1a9e_06e8(void)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  
  bVar1 = *(byte *)(DAT_5b41_0042 + 0x1b);
  uVar3 = (uint)*(byte *)(DAT_5b41_0042 + 0x1a) - (uint)bVar1;
  if (DAT_5b41_02e7 < uVar3) {
    cVar2 = *(char *)(DAT_5b41_0042 + 0x1b) + (char)DAT_5b41_02e7;
    uVar3 = DAT_5b41_02e7;
  }
  else {
    cVar2 = '\0';
    *(undefined1 *)(DAT_5b41_0042 + 0x1a) = 0;
  }
  *(char *)(DAT_5b41_0042 + 0x1b) = cVar2;
  if (uVar3 != 0) {
    if ((DAT_5b41_02e9 & 0x40) != 0) {
      FUN_1000_05ea((undefined2)DAT_5b41_0049,DAT_5b41_0049._2_2_,DAT_5b41_0044 + (uint)bVar1,0x554c
                    ,uVar3);
    }
    DAT_5b41_02e7 = DAT_5b41_02e7 - uVar3;
    FUN_1000_1a00(0x1a9e);
  }
  return;
}

