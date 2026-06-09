// TIM2.EXE: FUN_1000_4764 @ file 0x019964 Ghidra 0x14764
// Subsystem: utility | Size: 61 bytes


void __cdecl16near FUN_1000_4764(void)

{
  undefined2 local_6;
  undefined2 local_4;
  
  local_6 = 0x14;
  local_4 = 0x57d4;
  while (local_6 != 0) {
    if ((*(uint *)(local_4 + 2) & 0x300) == 0x300) {
      FUN_1000_3e17(local_4);
    }
    local_4 = local_4 + 0x10;
    local_6 = local_6 + -1;
  }
  return;
}

