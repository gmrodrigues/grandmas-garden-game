// TIM2.EXE: FUN_1a9e_60a1 @ file 0x025C81 Ghidra 0x20A81
// Subsystem: level | Size: 35 bytes


void __cdecl16near FUN_1a9e_60a1(char param_1)

{
  code *pcVar1;
  
  DAT_0000_0410 = DAT_0000_0410 & 0xcf | param_1 << 4;
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  return;
}

