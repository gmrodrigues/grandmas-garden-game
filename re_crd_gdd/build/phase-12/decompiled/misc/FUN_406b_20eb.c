// TIM2.EXE: FUN_406b_20eb @ file 0x04799B Ghidra 0x4279B
// Subsystem: misc | Size: 38 bytes


undefined2 __cdecl16far FUN_406b_20eb(undefined1 param_1)

{
  undefined2 in_AX;
  
  out(0x3d4,0x12);
  out(0x3d5,param_1);
  out(0x3d4,0x15);
  out(0x3d5,param_1);
  return in_AX;
}

