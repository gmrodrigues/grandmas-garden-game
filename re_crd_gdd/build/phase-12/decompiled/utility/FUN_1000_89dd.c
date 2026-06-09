// TIM2.EXE: FUN_1000_89dd @ file 0x01DBDD Ghidra 0x189DD
// Subsystem: utility | Size: 42 bytes


void __cdecl16far FUN_1000_89dd(undefined2 *param_1,uint param_2)

{
  if (param_1 != (undefined2 *)0x0) {
    param_1[1] = 0x1000;
    *param_1 = 0x8f73;
    if ((param_2 & 1) != 0) {
      FUN_1000_1499(param_1);
    }
  }
  return;
}

