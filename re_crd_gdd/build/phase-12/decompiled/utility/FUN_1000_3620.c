// TIM2.EXE: FUN_1000_3620 @ file 0x018820 Ghidra 0x13620
// Subsystem: utility | Size: 37 bytes


int __cdecl16far FUN_1000_3620(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((byte)((undefined1 *)&DAT_554c_5b71)[iVar1] == param_1) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  return -1;
}

