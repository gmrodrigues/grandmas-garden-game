// TIM2.EXE: FUN_1a9e_047d @ file 0x02005D Ghidra 0x1AE5D
// Subsystem: level | Size: 130 bytes


undefined2 __cdecl16near FUN_1a9e_047d(int param_1)

{
  int iVar1;
  
  DAT_5b41_0042 = (int *)((undefined2 *)&DAT_5b41_0051)[param_1];
  if (DAT_5b41_0042 != (int *)0x0) {
    if ((DAT_5b41_0042[1] != 0 || DAT_5b41_0042[2] != 0) && (iRam00055622 == 0 && iRam00055624 == 0)
       ) {
      FUN_1a9e_5415(DAT_5b41_0042[1],DAT_5b41_0042[2]);
    }
    for (iVar1 = 0; (iVar1 < 4 && (((undefined2 *)&DAT_5b41_02dd)[iVar1] != *DAT_5b41_0042));
        iVar1 = iVar1 + 1) {
    }
    if (iVar1 < 4) {
      ((undefined2 *)&DAT_5b41_02dd)[iVar1] = 0;
    }
    else {
      FUN_1a9e_0466(*DAT_5b41_0042);
    }
    ((undefined2 *)&DAT_5b41_0051)[param_1] = 0;
  }
  return 0xffff;
}

