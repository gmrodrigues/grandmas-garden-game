// TIM2.EXE: FUN_4fd6_0675 @ file 0x0555D5 Ghidra 0x503D5
// Subsystem: physics | Size: 63 bytes


void __cdecl16near FUN_4fd6_0675(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined2 unaff_ES;
  
  if (*(int *)0xc == 0) {
    return;
  }
  if (*"d C++ - Copyright 1993 Borland Intl." != -0x16) {
    if (*(int *)0x2 != 0) {
      FUN_4fd6_0756();
    }
    uVar2 = *(undefined2 *)0x10;
    iVar4 = *(int *)0xc;
    puVar5 = (undefined1 *)0x20;
    do {
      uVar3 = *(undefined2 *)(puVar5 + 2);
      *puVar5 = 0xea;
      puVar1 = (undefined2 *)(puVar5 + 3);
      *(undefined2 *)(puVar5 + 1) = uVar3;
      puVar5 = puVar5 + 5;
      *puVar1 = uVar2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}

