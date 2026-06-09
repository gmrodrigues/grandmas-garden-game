// TIM2.EXE: FUN_2e67_1398 @ file 0x034C08 Ghidra 0x2FA08
// Subsystem: misc | Size: 60 bytes


bool __cdecl16far FUN_2e67_1398(int param_1,int param_2,int param_3)

{
  bool bVar1;
  
  if (param_3 < param_2) {
    bVar1 = (uint)(param_1 - param_3) <= (uint)(param_2 - param_3);
  }
  else if ((uint)(param_3 - param_2) < (uint)(param_1 - param_2)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}

