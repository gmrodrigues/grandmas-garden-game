// TIM2.EXE: FUN_1000_414d @ file 0x01934D Ghidra 0x1414D
// Subsystem: utility | Size: 65 bytes


uint __cdecl16near FUN_1000_414d(void)

{
  uint uVar1;
  bool bVar2;
  uint local_4;
  
  local_4 = 0x57d4;
  do {
    if (*(char *)(local_4 + 4) < '\0') break;
    uVar1 = local_4 + 0x10;
    bVar2 = local_4 < DAT_554c_5914 * 0x10 + 0x57d4U;
    local_4 = uVar1;
  } while (bVar2);
  if (-1 < *(char *)(local_4 + 4)) {
    local_4 = 0;
  }
  return local_4;
}

