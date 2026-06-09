// TIM2.EXE: FUN_1000_3f57 @ file 0x019157 Ghidra 0x13F57
// Subsystem: utility | Size: 49 bytes


undefined2 __cdecl16far FUN_1000_3f57(void)

{
  code *pcVar1;
  undefined2 uVar2;
  uint uVar3;
  byte in_CF;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  uVar3 = (uint)(in_CF & 1);
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if ((uVar3 & 1) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_1000_1b4b();
  }
  return uVar2;
}

