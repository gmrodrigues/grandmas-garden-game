// TIM2.EXE: FUN_4bdc_3614 @ file 0x0545D4 Ghidra 0x4F3D4
// Subsystem: physics | Size: 121 bytes


undefined2 __cdecl16far FUN_4bdc_3614(undefined2 param_1,int param_2)

{
  int in_DX;
  int local_6;
  
  if (0x3f < param_2) {
    param_2 = 0x3f;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  local_6 = FUN_4bdc_270f(param_1);
  if (local_6 == 0 && in_DX == 0) {
    return 0;
  }
  while (local_6 != 0 || in_DX != 0) {
    FUN_4bdc_2342(local_6,in_DX,*(undefined1 *)(param_2 + 0x5760));
    local_6 = FUN_4bdc_270f(0xfffd);
  }
  return 1;
}

