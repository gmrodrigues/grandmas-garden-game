// TIM2.EXE: FUN_4fd6_0738 @ file 0x055698 Ghidra 0x50498
// Subsystem: physics | Size: 30 bytes


void __cdecl16near FUN_4fd6_0738(void)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_ES;
  
  iVar1 = FUN_4fd6_07a4();
  iRam000555e0 = iRam000555e0 + iVar1;
  iVar1 = 0x5464;
  do {
    iVar2 = iVar1;
    iVar1 = *(int *)0x1c;
  } while (*(int *)0x1c != 0);
  *(undefined2 *)0x1c = unaff_ES;
  *(undefined2 *)0x1c = 0;
  return;
}

