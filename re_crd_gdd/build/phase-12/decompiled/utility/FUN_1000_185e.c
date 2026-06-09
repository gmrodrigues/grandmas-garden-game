// TIM2.EXE: FUN_1000_185e @ file 0x016A5E Ghidra 0x1185E
// Subsystem: utility | Size: 21 bytes


void __cdecl16far FUN_1000_185e(undefined2 *param_1)

{
  code *pcVar1;
  undefined2 in_CX;
  undefined2 extraout_DX;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  *param_1 = in_CX;
  param_1[1] = extraout_DX;
  return;
}

