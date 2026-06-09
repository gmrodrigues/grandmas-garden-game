// TIM2.EXE: FUN_4340_00a6 @ file 0x0486A6 Ghidra 0x434A6
// Subsystem: misc | Size: 141 bytes


void __cdecl16far FUN_4340_00a6(void)

{
  int iVar1;
  
  if (DAT_53c6_0000 != 0) {
    for (iVar1 = 1; iVar1 <= DAT_53c6_0000; iVar1 = iVar1 + 1) {
      FUN_4340_04aa(iVar1);
    }
    FUN_22de_0351(DAT_53c6_0002,DAT_53c6_0004);
    if (DAT_53c6_000a != 0) {
      FUN_1000_130c(DAT_53c6_000a);
    }
    DAT_53c6_000a = 0;
    DAT_53c6_0004 = 0;
    DAT_53c6_0002 = 0;
    DAT_53c6_0000 = 0;
  }
  return;
}

