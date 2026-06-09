// TIM2.EXE: FUN_4fd6_06e7 @ file 0x055647 Ghidra 0x50447
// Subsystem: physics | Size: 81 bytes


uint __cdecl16near FUN_4fd6_06e7(void)

{
  undefined2 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  uint *puVar8;
  undefined2 unaff_ES;
  bool bVar9;
  
  uVar3 = uRam000555e0;
  uVar2 = *(uint *)0x10;
  *(uint *)0x10 = uRam000555e0;
  uVar4 = *(int *)0x8 + 1U >> 1;
  puVar6 = (undefined2 *)0x0;
  bVar9 = uVar2 <= uVar3;
  puVar7 = puVar6;
  if (bVar9) {
    puVar6 = (undefined2 *)((uVar4 - 1) * 2);
    puVar7 = puVar6;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    puVar1 = puVar6;
    puVar6 = puVar6 + (uint)bVar9 * -2 + 1;
    *puVar7 = *puVar1;
    puVar7 = puVar7 + (uint)bVar9 * -2 + 1;
  }
  *(undefined2 *)0xe = unaff_ES;
  if (*"d C++ - Copyright 1993 Borland Intl." != -0x33) {
    uVar3 = FUN_4fd6_0762();
    iVar5 = *(int *)0xc;
    puVar8 = (uint *)0x23;
    do {
      *puVar8 = uVar3;
      puVar8 = (uint *)((int)puVar8 + 5);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return uVar3;
}

