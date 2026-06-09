// TIM2.EXE: FUN_1000_9fb0 @ file 0x01F1B0 Ghidra 0x19FB0
// Subsystem: utility | Size: 32 bytes


undefined2 __cdecl16far FUN_1000_9fb0(undefined2 param_1,undefined2 param_2)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    FUN_1000_1b4b(uVar2);
  }
  else {
    param_2 = 0xffff;
  }
  return param_2;
}

