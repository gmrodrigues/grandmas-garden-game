// TIM2.EXE: FUN_4fd6_063a @ file 0x05559A Ghidra 0x5039A
// Subsystem: physics | Size: 59 bytes


void __cdecl16near FUN_4fd6_063a(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  do {
    iVar3 = iRam000555ec;
    iVar1 = iVar1 + 1;
    iRam000555ec = *(int *)0x1c;
  } while (iRam000555ec != 0);
  iRam000555e0 = iRam000555e6;
  do {
    iVar2 = iVar1;
    *(int *)0x1c = iRam000555ec;
    iRam000555ec = iVar3;
    iVar1 = FUN_4fd6_07a4();
    iRam000555e0 = iRam000555e0 - iVar1;
    FUN_4fd6_06e7();
    iVar1 = iVar2 + -1;
    iVar3 = iVar2;
  } while (iVar1 != 0);
  iRam000555e0 = uRam000555e4;
  return;
}

