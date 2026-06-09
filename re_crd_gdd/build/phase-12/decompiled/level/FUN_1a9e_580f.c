// TIM2.EXE: FUN_1a9e_580f @ file 0x0253EF Ghidra 0x201EF
// Subsystem: level | Size: 135 bytes


int __cdecl16far FUN_1a9e_580f(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (DAT_554c_5594 == '\0') {
    pcVar1 = (code *)swi(0x33);
    iVar3 = (*pcVar1)();
    iVar2 = -iVar3;
    DAT_554c_5594 = (char)iVar2;
    if (iVar3 != 0) {
      pcVar1 = (code *)swi(0x33);
      (*pcVar1)();
      pcVar1 = (code *)swi(0x33);
      (*pcVar1)();
      pcVar1 = (code *)swi(0x33);
      (*pcVar1)();
      pcVar1 = (code *)swi(0x33);
      (*pcVar1)();
      pcVar1 = (code *)swi(0x33);
      (*pcVar1)();
      FUN_1a9e_5897();
      pcVar1 = (code *)swi(0x33);
      (*pcVar1)();
      if (((DAT_554c_42dd == '\b') || (DAT_554c_42dd == '\x0f')) || (DAT_554c_42dd == '\x10')) {
        DAT_554c_558e = DAT_554c_558f;
        DAT_554c_5591 = DAT_554c_5592;
      }
      else {
        DAT_554c_558e = DAT_554c_5590;
        DAT_554c_5591 = DAT_554c_5593;
      }
      iVar2 = 1;
    }
  }
  return iVar2;
}

