// TIM2.EXE: FUN_4fd6_0d8e @ file 0x055CEE Ghidra 0x50AEE
// Subsystem: misc | Size: 176 bytes


int __cdecl16far FUN_4fd6_0d8e(void)

{
  code *pcVar1;
  char cVar2;
  char extraout_AH;
  undefined2 uVar3;
  char extraout_AH_00;
  char extraout_AH_01;
  uint extraout_DX;
  int in_BX;
  undefined2 unaff_SI;
  int unaff_ES;
  bool bVar4;
  
  bVar4 = false;
  if ((*(byte *)0x38 & 1) == 0) {
    pcVar1 = (code *)swi(0x21);
    in_BX = (*pcVar1)();
    if (bVar4) goto LAB_4fd6_0e32;
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    if ((!bVar4) && (bVar4 = false, (extraout_DX & 0x80) != 0)) {
      pcVar1 = (code *)swi(0x21);
      cVar2 = (*pcVar1)();
      if (!bVar4) {
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)();
        if (cVar2 == -1) {
          pcVar1 = (code *)swi(0x21);
          (*pcVar1)();
          if (unaff_ES == 0 && in_BX == 0) goto LAB_4fd6_0e32;
          pcVar1 = (code *)swi(0x67);
          (*pcVar1)();
          if (extraout_AH != '\0') goto LAB_4fd6_0e32;
          *(undefined1 *)0x38 = 1;
          pcVar1 = (code *)swi(0x67);
          uVar3 = (*pcVar1)();
          if (((char)((uint)uVar3 >> 8) != '\0') || ((byte)uVar3 < 0x32)) goto LAB_4fd6_0e32;
          *(byte *)0x39 = (byte)uVar3;
          pcVar1 = (code *)swi(0x67);
          (*pcVar1)();
          if (extraout_AH_00 != '\0') goto LAB_4fd6_0e32;
          *(int *)0x30 = in_BX;
          goto LAB_4fd6_0e1c;
        }
      }
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
  }
  else {
    unaff_SI = uRam00050008;
    if ((*(byte *)0x38 & 2) != 0) {
      return *(int *)0x36;
    }
LAB_4fd6_0e1c:
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    if (extraout_AH_01 == '\0') {
      *(int *)0x36 = in_BX;
      *(undefined2 *)0x32 = 0xffff;
      return in_BX;
    }
  }
LAB_4fd6_0e32:
  *(undefined1 *)0x38 = 0;
  return 0;
}

