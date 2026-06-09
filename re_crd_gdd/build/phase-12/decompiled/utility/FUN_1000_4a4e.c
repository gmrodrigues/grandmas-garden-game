// TIM2.EXE: FUN_1000_4a4e @ file 0x019C4E Ghidra 0x14A4E
// Subsystem: utility | Size: 73 bytes


void __cdecl16far FUN_1000_4a4e(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  bool bVar9;
  
  bVar9 = param_1 < param_2;
  uVar5 = (uint)bVar9;
  if (uVar5 != 0) {
    param_1 = param_1 + (param_3 - 1);
    param_2 = param_2 + (param_3 - 1);
  }
  if (((uint)param_2 & 1) != 0) {
    if (param_3 == 0) {
      return;
    }
    puVar3 = param_2;
    param_2 = param_2 + (uint)bVar9 * -2 + 1;
    puVar1 = param_1;
    param_1 = param_1 + (uint)bVar9 * -2 + 1;
    *puVar3 = *puVar1;
    param_3 = param_3 - 1;
  }
  puVar7 = (undefined2 *)(param_1 + -uVar5);
  puVar8 = (undefined2 *)(param_2 + -uVar5);
  for (uVar6 = param_3 >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
    puVar4 = puVar8;
    puVar8 = puVar8 + (uint)bVar9 * -2 + 1;
    puVar2 = puVar7;
    puVar7 = puVar7 + (uint)bVar9 * -2 + 1;
    *puVar4 = *puVar2;
  }
  if ((param_3 & 1) != 0) {
    *(undefined1 *)((int)puVar8 + uVar5) = *(undefined1 *)((int)puVar7 + uVar5);
  }
  return;
}

