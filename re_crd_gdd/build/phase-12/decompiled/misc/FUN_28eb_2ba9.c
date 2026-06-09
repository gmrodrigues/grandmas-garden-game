// TIM2.EXE: FUN_28eb_2ba9 @ file 0x030C59 Ghidra 0x2BA59
// Subsystem: misc | Size: 33 bytes


void FUN_28eb_2ba9(void)

{
  uint *puVar1;
  undefined2 *puVar2;
  int *piVar3;
  undefined2 *puVar4;
  int in_AX;
  undefined2 *puVar5;
  int iVar6;
  int unaff_BP;
  int unaff_SI;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 unaff_SS;
  
  if ((in_AX == *(int *)((int)*(undefined4 *)(unaff_BP + 6) + 0xa6)) &&
     (*(int *)((int)*(undefined4 *)*(undefined4 *)(unaff_BP + -8) + 0xa4) <
      *(int *)((int)*(undefined4 *)(unaff_BP + 6) + 0xa4))) {
    FUN_28eb_2b9c();
    return;
  }
  if (unaff_SI == 0) {
    puVar2 = (undefined2 *)*(undefined4 *)(unaff_BP + -8);
    uVar9 = *puVar2;
    *(undefined2 *)(unaff_BP + -6) = ((undefined2 *)puVar2)[1];
    *(undefined2 *)(unaff_BP + -8) = uVar9;
    *(undefined2 *)(unaff_BP + -4) = 0;
    piVar3 = (int *)*(undefined4 *)(unaff_BP + -8);
    if (*piVar3 != 0 || ((int *)piVar3)[1] != 0) {
      FUN_28eb_2a7b();
      return;
    }
  }
  puVar2 = (undefined2 *)*(undefined4 *)(unaff_BP + -8);
  uVar9 = *puVar2;
  puVar4 = (undefined2 *)*(undefined4 *)(unaff_BP + 6);
  uVar7 = (undefined2)((ulong)puVar4 >> 0x10);
  puVar5 = (undefined2 *)puVar4;
  puVar5[1] = ((undefined2 *)puVar2)[1];
  *puVar4 = uVar9;
  uVar9 = *(undefined2 *)(unaff_BP + -8);
  puVar5[3] = *(undefined2 *)(unaff_BP + -6);
  puVar5[2] = uVar9;
  puVar2 = (undefined2 *)*(undefined4 *)(unaff_BP + -8);
  uVar9 = *(undefined2 *)(unaff_BP + 8);
  uVar7 = *(undefined2 *)(unaff_BP + 6);
  ((undefined2 *)puVar2)[1] = uVar9;
  *puVar2 = uVar7;
  piVar3 = (int *)*(undefined4 *)(unaff_BP + 6);
  if (*piVar3 != 0 || ((int *)piVar3)[1] != 0) {
    uVar8 = (undefined2)((ulong)*(undefined4 *)piVar3 >> 0x10);
    iVar6 = (int)*(undefined4 *)piVar3;
    uVar7 = *(undefined2 *)(unaff_BP + 6);
    *(undefined2 *)(iVar6 + 6) = uVar9;
    *(undefined2 *)(iVar6 + 4) = uVar7;
  }
  uVar9 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
  iVar6 = (int)*(undefined4 *)(unaff_BP + 6);
  puVar1 = (uint *)(iVar6 + 10);
  *puVar1 = *puVar1 & 0xc7ff;
  if ((undefined2 *)*(undefined2 *)(unaff_BP + 10) == (undefined2 *)&DAT_5b41_055f) {
    puVar1 = (uint *)(iVar6 + 10);
    *puVar1 = *puVar1 | 0x800;
  }
  else if ((undefined2 *)*(undefined2 *)(unaff_BP + 10) == (undefined2 *)&DAT_5b41_0557) {
    puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + 6) + 10);
    *puVar1 = *puVar1 | 0x1000;
  }
  else if ((undefined2 *)*(undefined2 *)(unaff_BP + 10) == (undefined2 *)&DAT_5b41_054f) {
    puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + 6) + 10);
    *puVar1 = *puVar1 | 0x2000;
  }
  return;
}

