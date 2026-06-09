// TIM2.EXE: FUN_1000_1873 @ file 0x016A73 Ghidra 0x11873
// Subsystem: utility | Size: 20 bytes


void FUN_1000_1873(undefined2 param_1,undefined2 *param_2)

{
  code *pcVar1;
  undefined2 in_CX;
  undefined2 extraout_DX;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  *param_2 = in_CX;
  param_2[1] = extraout_DX;
  return;
}

