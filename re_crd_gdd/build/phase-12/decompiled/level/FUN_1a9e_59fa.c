// TIM2.EXE: FUN_1a9e_59fa @ file 0x0255DA Ghidra 0x203DA
// Subsystem: level | Size: 28 bytes


bool __cdecl16far FUN_1a9e_59fa(void)

{
  code *pcVar1;
  bool bVar2;
  
  bVar2 = DAT_554c_5594 != '\0';
  if (bVar2) {
    DAT_554c_5594 = '\0';
    pcVar1 = (code *)swi(0x33);
    (*pcVar1)();
    pcVar1 = (code *)swi(0x33);
    (*pcVar1)();
  }
  return bVar2;
}

