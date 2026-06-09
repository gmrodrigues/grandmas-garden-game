// TIM2.EXE: FUN_1000_2c8b @ file 0x017E8B Ghidra 0x12C8B
// Subsystem: utility | Size: 41 bytes


void __cdecl16near FUN_1000_2c8b(void)

{
  int iVar1;
  
  iVar1 = iRam000554c6;
  DAT_1000_2baf = uRam000554c4;
  if (iRam000554c6 != 0x554c) {
    *(int *)0x6 = iRam000554c6;
    *(undefined2 *)0x4 = DAT_1000_2baf;
    return;
  }
  DAT_1000_2baf = 0;
  return;
}

