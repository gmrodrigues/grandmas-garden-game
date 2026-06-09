// TIM2.EXE: FUN_4fd6_05a7 @ file 0x055507 Ghidra 0x50307
// Subsystem: physics | Size: 122 bytes


void __cdecl16near FUN_4fd6_05a7(void)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_ES;
  undefined1 uVar5;
  
  iRam000555dc = iRam000555dc + 1;
  if (*(int *)0x10 == 0) {
    uVar5 = 0;
    *(byte *)0x1a = *(byte *)0x1a | 8;
    iVar4 = FUN_4fd6_055d();
    *(undefined2 *)0xe = unaff_ES;
    (*(code *)*(undefined2 *)0x18)();
    if ((bool)uVar5) {
      pcVar2 = (code *)swi(0x21);
      (*pcVar2)();
      FUN_1000_17d2();
      return;
    }
    FUN_4fd6_0738();
  }
  else {
    *(undefined1 *)0x1b = 1;
    *(byte *)0x1a = *(byte *)0x1a | 4;
  }
  FUN_4fd6_0675();
  *"orland C++ - Copyright 1993 Borland Intl." =
       *"orland C++ - Copyright 1993 Borland Intl." + (*(byte *)0x1a & 3);
  uVar3 = FUN_4fd6_0788();
  iVar4 = iRam000555ec;
  while ((iVar1 = *(int *)0x1c, iVar1 != 0 && (uVar3 < uRam000555d8))) {
    if (*"orland C++ - Copyright 1993 Borland Intl." == '\0') {
      FUN_4fd6_06b4();
      iVar4 = FUN_4fd6_07a4();
    }
    else {
      iVar4 = 0;
    }
    uVar3 = iVar4 + uVar3;
    iVar4 = iVar1;
  }
  return;
}

