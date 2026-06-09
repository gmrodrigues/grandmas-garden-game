// TIM2.EXE: FUN_4fd6_06b4 @ file 0x055614 Ghidra 0x50414
// Subsystem: physics | Size: 51 bytes


void __cdecl16near FUN_4fd6_06b4(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 unaff_ES;
  
  if (*"d C++ - Copyright 1993 Borland Intl." != -0x33) {
    uVar2 = 0;
    FUN_4fd6_0756();
    *(undefined2 *)0x2 = uVar2;
    iVar3 = *(int *)0xc;
    puVar4 = (undefined2 *)0x20;
    do {
      uVar2 = *(undefined2 *)((int)puVar4 + 1);
      *puVar4 = uRam000555d0;
      puVar1 = puVar4 + 2;
      puVar4[1] = uVar2;
      puVar4 = (undefined2 *)((int)puVar4 + 5);
      *(undefined1 *)puVar1 = 0;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

