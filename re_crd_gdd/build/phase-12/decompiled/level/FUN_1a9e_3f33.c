// TIM2.EXE: FUN_1a9e_3f33 @ file 0x023B13 Ghidra 0x1E913
// Subsystem: level | Size: 109 bytes


void __cdecl16far FUN_1a9e_3f33(uint param_1)

{
  ulong uVar1;
  code *pcVar2;
  byte bVar3;
  undefined2 in_BX;
  undefined2 unaff_ES;
  
  if (DAT_554c_4f22 == '\0') {
    DAT_554c_4f2b = 0;
    FUN_1a9e_443d();
    pcVar2 = (code *)swi(0x21);
    (*pcVar2)();
    uRam00013f2f = in_BX;
    uRam00013f31 = unaff_ES;
    if (((int)param_1 < 0x100) && (param_1 != 0)) {
      DAT_554c_4f27 = param_1;
      DAT_554c_4f29 = param_1;
      uVar1 = 0xffff / (ulong)param_1;
      DAT_554c_4f25 = (undefined2)uVar1;
      out(0x43,0x36);
      out(0x40,(char)uVar1);
      out(0x40,(char)(uVar1 >> 8));
      bVar3 = in(0x21);
      out(0x21,bVar3 & 0xfc);
      pcVar2 = (code *)swi(0x21);
      (*pcVar2)();
      *(undefined1 *)&DAT_554c_4f22 = 1;
    }
  }
  return;
}

