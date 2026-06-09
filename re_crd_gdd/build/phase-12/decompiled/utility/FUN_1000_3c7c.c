// TIM2.EXE: FUN_1000_3c7c @ file 0x018E7C Ghidra 0x13C7C
// Subsystem: utility | Size: 31 bytes


undefined2 __cdecl16far FUN_1000_3c7c(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    param_3 = FUN_1000_1b4b(uVar2);
  }
  return param_3;
}

