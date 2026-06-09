// TIM2.EXE: FUN_1000_8973 @ file 0x01DB73 Ghidra 0x18973
// Subsystem: utility | Size: 94 bytes


undefined2 * __cdecl16far FUN_1000_8973(undefined2 *param_1)

{
  undefined2 local_4;
  
  if ((param_1 == (undefined2 *)0x0) &&
     (param_1 = (undefined2 *)FUN_1000_1dd2(8), param_1 == (undefined2 *)0x0)) {
    return (undefined2 *)0x0;
  }
  param_1[1] = 0x1000;
  *param_1 = 0x8f73;
  local_4 = 0;
  FUN_1000_6d2e(0x8f54,0x1000,&local_4);
  return param_1;
}

