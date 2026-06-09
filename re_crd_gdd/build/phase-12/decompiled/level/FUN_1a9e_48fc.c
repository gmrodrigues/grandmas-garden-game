// TIM2.EXE: FUN_1a9e_48fc @ file 0x0244DC Ghidra 0x1F2DC
// Subsystem: level | Size: 196 bytes


undefined1 __cdecl16far FUN_1a9e_48fc(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined2 in_BX;
  undefined2 unaff_ES;
  bool bVar3;
  
  iVar2 = 0x554c;
  if (DAT_554c_4fc2 == '\0') {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    pcVar1 = (code *)swi(0x21);
    uRam000148f4 = in_BX;
    uRam000148f6 = unaff_ES;
    (*pcVar1)();
    pcVar1 = (code *)swi(0x21);
    DAT_1000_48f8 = in_BX;
    DAT_1000_48fa = unaff_ES;
    (*pcVar1)();
    if (param_1 != 0) {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
    }
    *(undefined1 *)0x5153 = 0;
    iVar2 = FUN_1a9e_443d();
    bVar3 = iVar2 != 0;
    if (bVar3) {
      pcVar1 = (code *)swi(0x15);
      (*pcVar1)();
      if ((bVar3) && (DAT_0000_0496 == '\x10')) {
        *(undefined1 *)0x5153 = 1;
      }
      else {
        uRam00014a9f = 0xfe;
        uRam00014aac = 0xfe;
        *(undefined1 *)0x50ed = *(undefined1 *)0x510c;
        *(undefined1 *)0x50ef = *(undefined1 *)0x510f;
        *(undefined1 *)0x5112 = *(undefined1 *)0x5111;
        *(undefined1 *)0x510e = *(undefined1 *)0x5114;
      }
    }
    *(undefined1 *)&DAT_554c_4fc2 = 1;
    iVar2 = param_1;
  }
  DAT_0000_0417 = DAT_0000_0417 & 0xdf;
  if (*(char *)&DAT_554c_4fc3 != '\0') {
    DAT_0000_0417 = DAT_0000_0417 | 0x40;
  }
  return *(undefined1 *)&DAT_554c_4fc2;
}

