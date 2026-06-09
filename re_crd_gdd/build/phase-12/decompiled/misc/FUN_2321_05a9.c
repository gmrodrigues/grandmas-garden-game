// TIM2.EXE: FUN_2321_05a9 @ file 0x0289B9 Ghidra 0x237B9
// Subsystem: misc | Size: 109 bytes


undefined2 __cdecl16far FUN_2321_05a9(void)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 unaff_SS;
  undefined1 local_1f6 [499];
  undefined1 local_3;
  
  DAT_5b41_0953 = 1;
  DAT_5b41_0951 = 0xf0;
  for (uVar3 = 0; uVar3 < 10000; uVar3 = uVar3 + 1) {
    if (uVar3 % 0x1e == 0) {
      uVar1 = FUN_1000_418e(0x28e,0x29b);
      FUN_1000_3d77(uVar1);
    }
    for (uVar2 = 0; uVar2 < 500; uVar2 = uVar2 + 1) {
      local_1f6[uVar2] = (&local_3)[-uVar2];
    }
  }
  DAT_5b41_0953 = 0;
  return DAT_5b41_0951;
}

