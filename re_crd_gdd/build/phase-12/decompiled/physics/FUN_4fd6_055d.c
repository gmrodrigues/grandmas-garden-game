// TIM2.EXE: FUN_4fd6_055d @ file 0x0554BD Ghidra 0x502BD
// Subsystem: physics | Size: 74 bytes


void __cdecl16near FUN_4fd6_055d(void)

{
  char *pcVar1;
  uint uVar2;
  undefined2 unaff_ES;
  byte in_CF;
  undefined4 uVar3;
  
  iRam000555ea = iRam000555ea + 1;
  FUN_4fd6_07b0();
  while( true ) {
    uVar3 = FUN_4fd6_0788();
    uVar2 = (uint)((ulong)uVar3 >> 0x10);
    if (uVar2 <= (uint)uVar3) break;
    if ((in_CF & 1) != 0) {
      FUN_4fd6_063a(uVar2);
    }
    in_CF = 0;
    if (*"orland C++ - Copyright 1993 Borland Intl." == '\0') {
      uRam000555ec = *(undefined2 *)0x1c;
      FUN_4fd6_0622();
      FUN_4fd6_07a4();
    }
    else {
      pcVar1 = "orland C++ - Copyright 1993 Borland Intl.";
      uRam000555ec = *(undefined2 *)0x1c;
      *pcVar1 = *pcVar1 + -1;
      FUN_4fd6_06e7();
      FUN_4fd6_0738();
    }
  }
  *(undefined2 *)0x10 = uRam000555e0;
  return;
}

