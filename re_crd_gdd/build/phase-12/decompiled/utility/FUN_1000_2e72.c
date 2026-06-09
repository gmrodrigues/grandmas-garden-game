// TIM2.EXE: FUN_1000_2e72 @ file 0x018072 Ghidra 0x12E72
// Subsystem: utility | Size: 124 bytes


ulong __cdecl16near FUN_1000_2e72(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int in_DX;
  int in_BX;
  int iVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  bool bVar11;
  
  iVar8 = in_BX;
  uVar3 = FUN_1000_2df5(DAT_1000_2bb5,DAT_1000_2bb3);
  if (in_DX == 0) {
    return (ulong)uVar3;
  }
  uVar3 = *(int *)0x0 - 1;
  puVar10 = (undefined2 *)0x4;
  puVar9 = (undefined2 *)0x4;
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    puVar2 = puVar10;
    puVar10 = puVar10 + 1;
    puVar1 = puVar9;
    puVar9 = puVar9 + 1;
    *puVar2 = *puVar1;
  }
  if (uVar3 != 0) {
    iVar5 = in_DX + 1;
    iVar4 = in_BX + 1;
    while( true ) {
      puVar10 = (undefined2 *)0x0;
      puVar9 = (undefined2 *)0x0;
      uVar6 = uVar3;
      if (0x1000 < uVar3) {
        uVar6 = 0x1000;
      }
      for (iVar7 = uVar6 << 3; iVar7 != 0; iVar7 = iVar7 + -1) {
        puVar2 = puVar10;
        puVar10 = puVar10 + 1;
        puVar1 = puVar9;
        puVar9 = puVar9 + 1;
        *puVar2 = *puVar1;
      }
      bVar11 = uVar3 < 0x1000;
      uVar3 = uVar3 - 0x1000;
      if (bVar11 || uVar3 == 0) break;
      iVar5 = iVar5 + 0x1000;
      iVar4 = iVar4 + 0x1000;
    }
  }
  FUN_1000_2ceb(iVar8,in_BX);
  return CONCAT22(in_DX,4);
}

