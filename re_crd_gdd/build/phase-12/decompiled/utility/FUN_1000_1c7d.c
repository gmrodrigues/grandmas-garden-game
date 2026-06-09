// TIM2.EXE: FUN_1000_1c7d @ file 0x016E7D Ghidra 0x11C7D
// Subsystem: utility | Size: 26 bytes


undefined2 __cdecl16far FUN_1000_1c7d(void)

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

