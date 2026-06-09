// TIM2.EXE: FUN_1000_147f @ file 0x01667F Ghidra 0x1147F
// Subsystem: utility | Size: 26 bytes


undefined2 __cdecl16far FUN_1000_147f(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    uVar2 = FUN_1000_1b4b(uVar2);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

