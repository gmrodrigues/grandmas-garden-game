// TIM2.EXE: FUN_1000_3bfb @ file 0x018DFB Ghidra 0x13BFB
// Subsystem: utility | Size: 112 bytes


uint __cdecl16far FUN_1000_3bfb(byte *param_1)

{
  ulong uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  
  uVar3 = 0;
  do {
    bVar5 = *param_1;
    param_1 = param_1 + 1;
  } while ((*(byte *)(bVar5 + 0x59c1) & 1) != 0);
  bVar2 = false;
  if (bVar5 != 0x2b) {
    if (bVar5 != 0x2d) goto LAB_1000_3c29;
    bVar2 = true;
  }
  do {
    bVar5 = *param_1;
    param_1 = param_1 + 1;
LAB_1000_3c29:
    if ((0x39 < bVar5) || (bVar5 < 0x30)) goto LAB_1000_3c5c;
    uVar1 = (ulong)uVar3;
    uVar4 = (uint)(uVar1 * 10);
    uVar3 = uVar4 + (byte)(bVar5 - 0x30);
  } while ((char)((char)(uVar1 * 10 >> 0x10) + CARRY2(uVar4,(uint)(byte)(bVar5 - 0x30))) == '\0');
  while( true ) {
    bVar5 = *param_1;
    param_1 = param_1 + 1;
    if ((0x39 < bVar5) || (bVar5 < 0x30)) break;
    uVar3 = uVar3 * 10 + (uint)(byte)(bVar5 - 0x30);
  }
LAB_1000_3c5c:
  if (bVar2) {
    uVar3 = -uVar3;
  }
  return uVar3;
}

