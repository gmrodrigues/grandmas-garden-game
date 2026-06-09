// TIM2.EXE: FUN_1000_2af6 @ file 0x017CF6 Ghidra 0x12AF6
// Subsystem: utility | Size: 89 bytes


uint __cdecl16far FUN_1000_2af6(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_1000_1fce();
  if ((int)((ulong)uVar2 >> 0x10) == 0) {
    uVar1 = FUN_1000_3226((int)uVar2);
  }
  else {
    uVar1 = 0;
  }
  if (uVar1 != 0) {
    FUN_1000_4a0a(uVar1,(int)uVar2,uVar1 & 0xff00);
  }
  return uVar1;
}

