// TIM2.EXE: FUN_4bdc_3165 @ file 0x054125 Ghidra 0x4EF25
// Subsystem: physics | Size: 73 bytes


void __cdecl16far FUN_4bdc_3165(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 7; iVar1 = iVar1 + 1) {
    if (*(char *)((int)*(undefined4 *)((undefined2 *)&DAT_5b41_2860 + iVar1 * 2) + 0x158) != -1) {
      FUN_4bdc_2371(((undefined2 *)&DAT_5b41_2860)[iVar1 * 2],
                    ((undefined2 *)&DAT_5b41_2862)[iVar1 * 2]);
      *(undefined1 *)((int)*(undefined4 *)((undefined2 *)&DAT_5b41_2860 + iVar1 * 2) + 0x158) = 0xff
      ;
    }
  }
  return;
}

