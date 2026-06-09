// TIM2.EXE: FUN_1000_4cc1 @ file 0x019EC1 Ghidra 0x14CC1
// Subsystem: utility | Size: 118 bytes


void __cdecl16far FUN_1000_4cc1(char *param_1)

{
  char *local_4;
  
  if ((iRam0005554e < DAT_554c_5bf0) && (-1 < iRam0005554e)) {
    local_4 = (char *)*(undefined2 *)(iRam0005554e * 2 + 0x5b90);
  }
  else {
    local_4 = (char *)s_Unknown_error_554c_5ded;
  }
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    FUN_1000_41cb(param_1,0x57f4);
    FUN_1000_41cb(0x5dfb,0x57f4);
  }
  FUN_1000_41cb(local_4,0x57f4);
  FUN_1000_41cb(0x5dfe,0x57f4);
  return;
}

