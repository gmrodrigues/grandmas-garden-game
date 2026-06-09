// TIM2.EXE: FUN_1a9e_5a40 @ file 0x025620 Ghidra 0x20420
// Subsystem: level | Size: 66 bytes


char __cdecl16far FUN_1a9e_5a40(int param_1,int param_2)

{
  code *pcVar1;
  char cVar2;
  
  cVar2 = -DAT_554c_5594;
  if (DAT_554c_5594 != '\0') {
    DAT_554c_5178 = param_1 << 2;
    DAT_554c_517a = param_2 << 2;
    pcVar1 = (code *)swi(0x33);
    (*pcVar1)();
    if (DAT_554c_5596 == '\0') {
      FUN_1a9e_58d9();
    }
    cVar2 = '\x01';
  }
  return cVar2;
}

