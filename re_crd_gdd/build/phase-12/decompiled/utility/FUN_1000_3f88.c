// TIM2.EXE: FUN_1000_3f88 @ file 0x019188 Ghidra 0x13F88
// Subsystem: utility | Size: 68 bytes


int __cdecl16far FUN_1000_3f88(void)

{
  undefined2 local_8;
  undefined2 local_6;
  undefined2 local_4;
  
  local_8 = 0;
  local_6 = DAT_554c_5914;
  local_4 = 0x57d4;
  while (local_6 != 0) {
    if ((*(byte *)(local_4 + 2) & 3) != 0) {
      FUN_1000_3e17(local_4);
      local_8 = local_8 + 1;
    }
    local_4 = local_4 + 0x10;
    local_6 = local_6 + -1;
  }
  return local_8;
}

