// TIM2.EXE: FUN_1000_2d14 @ file 0x017F14 Ghidra 0x12D14
// Subsystem: utility | Size: 100 bytes


undefined2 __cdecl16near FUN_1000_2d14(void)

{
  uint in_AX;
  uint uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_1000_309d(0,0);
  if ((uVar1 & 0xf) != 0) {
    FUN_1000_309d(0x10 - (uVar1 & 0xf),0);
  }
  uVar3 = FUN_1000_309d(in_AX << 4,in_AX >> 0xc);
  uVar2 = (undefined2)((ulong)uVar3 >> 0x10);
  if ((int)uVar3 != -1) {
    DAT_1000_2bab = uVar2;
    DAT_1000_2bad = uVar2;
    *(uint *)0x0 = in_AX;
    *(undefined2 *)0x2 = uVar2;
    return 4;
  }
  return 0;
}

