// TIM2.EXE: FUN_1000_3cc7 @ file 0x018EC7 Ghidra 0x13CC7
// Subsystem: utility | Size: 34 bytes


undefined2 __cdecl16far FUN_1000_3cc7(int param_1)

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
    *(undefined2 *)(param_1 * 2 + 0x5916) = 0;
    uVar2 = 0;
  }
  return uVar2;
}

