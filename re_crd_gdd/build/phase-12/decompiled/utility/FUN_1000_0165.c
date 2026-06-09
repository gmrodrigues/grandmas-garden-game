// TIM2.EXE: FUN_1000_0165 @ file 0x015365 Ghidra 0x10165
// Subsystem: utility | Size: 41 bytes


void __cdecl16far FUN_1000_0165(void)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar1 = 0;
  pbVar3 = (byte *)0x0;
  iVar2 = 0x10;
  do {
    iVar1 = CONCAT11((char)((uint)iVar1 >> 8) + CARRY1((byte)iVar1,*pbVar3),(byte)iVar1 + *pbVar3);
    pbVar3 = pbVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (iVar1 != 0x2b9) {
    FUN_1000_173e(0x45);
  }
  return;
}

