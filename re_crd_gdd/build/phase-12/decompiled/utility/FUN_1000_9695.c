// TIM2.EXE: FUN_1000_9695 @ file 0x01E895 Ghidra 0x19695
// Subsystem: utility | Size: 29 bytes


undefined1 __cdecl16far FUN_1000_9695(void)

{
  code *pcVar1;
  undefined1 uVar2;
  
  if (DAT_554c_5e96 == '\0') {
    pcVar1 = (code *)swi(0x21);
    uVar2 = (*pcVar1)();
  }
  else {
    DAT_554c_5e96 = '\0';
    uVar2 = DAT_554c_5e97;
  }
  return uVar2;
}

