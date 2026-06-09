// TIM2.EXE: FUN_4bdc_270f @ file 0x0536CF Ghidra 0x4E4CF
// Subsystem: physics | Size: 116 bytes


int __cdecl16far FUN_4bdc_270f(int param_1)

{
  int iVar1;
  int in_DX;
  undefined2 local_6;
  
  local_6 = FUN_4bdc_3951(param_1);
  if (0 < param_1) {
    iVar1 = FUN_4bdc_2785(local_6,in_DX);
    return iVar1;
  }
  while( true ) {
    if (local_6 == 0 && in_DX == 0) {
      return 0;
    }
    iVar1 = FUN_4bdc_2785(local_6,in_DX);
    if (iVar1 != 0 || in_DX != 0) break;
    local_6 = FUN_4bdc_3951(0xfffd);
  }
  return iVar1;
}

