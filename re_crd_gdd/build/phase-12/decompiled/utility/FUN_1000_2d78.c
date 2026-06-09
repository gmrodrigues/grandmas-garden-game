// TIM2.EXE: FUN_1000_2d78 @ file 0x017F78 Ghidra 0x12D78
// Subsystem: utility | Size: 90 bytes


undefined2 __cdecl16near FUN_1000_2d78(void)

{
  undefined2 uVar1;
  uint in_AX;
  int iVar2;
  int iVar3;
  ulong uVar4;
  
  uVar4 = FUN_1000_309d(in_AX << 4,in_AX >> 0xc);
  iVar3 = (int)(uVar4 >> 0x10);
  if ((uint)uVar4 == 0xffff) {
    return 0;
  }
  if ((uVar4 & 0xf) != 0) {
    iVar2 = FUN_1000_309d(0x10 - ((uint)uVar4 & 0xf),0);
    if (iVar2 == -1) {
      return 0;
    }
    iVar3 = iVar3 + 1;
  }
  uVar1 = DAT_1000_2bad;
  DAT_1000_2bad = iVar3;
  *(uint *)0x0 = in_AX;
  *(undefined2 *)0x2 = uVar1;
  return 4;
}

