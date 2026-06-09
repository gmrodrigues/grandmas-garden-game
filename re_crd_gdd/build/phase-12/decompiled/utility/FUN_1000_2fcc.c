// TIM2.EXE: FUN_1000_2fcc @ file 0x0181CC Ghidra 0x12FCC
// Subsystem: utility | Size: 142 bytes


undefined2 FUN_1000_2fcc(undefined2 param_1,int param_2)

{
  int iVar1;
  uint local_4;
  
  local_4 = (param_2 - iRam0005554a) + 0x40U >> 6;
  if (local_4 != DAT_554c_5b4e) {
    local_4 = local_4 * 0x40;
    if (uRam00055560 < local_4 + iRam0005554a) {
      local_4 = uRam00055560 - iRam0005554a;
    }
    iVar1 = FUN_1000_9fb0(iRam0005554a,local_4);
    if (iVar1 != -1) {
      uRam0005555e = 0;
      uRam00055560 = iRam0005554a + iVar1;
      return 0;
    }
    DAT_554c_5b4e = local_4 >> 6;
  }
  iRam0005555c = param_2;
  uRam0005555a = param_1;
  return 1;
}

