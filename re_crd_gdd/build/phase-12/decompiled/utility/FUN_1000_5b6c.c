// TIM2.EXE: FUN_1000_5b6c @ file 0x01AD6C Ghidra 0x15B6C
// Subsystem: utility | Size: 55 bytes


void __cdecl16far FUN_1000_5b6c(void)

{
  undefined2 local_6;
  undefined2 local_4;
  
  local_4 = 0x57d4;
  for (local_6 = 4; local_6 != 0; local_6 = local_6 + -1) {
    if ((*(byte *)(local_4 + 2) & 3) != 0) {
      FUN_1000_3e17(local_4);
    }
    local_4 = local_4 + 0x10;
  }
  return;
}

