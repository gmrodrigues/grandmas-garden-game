// TIM2.EXE: FUN_28eb_2be8 @ file 0x030C98 Ghidra 0x2BA98
// Subsystem: misc | Size: 186 bytes


void __cdecl16far FUN_28eb_2be8(void)

{
  uint *puVar1;
  undefined2 *puVar2;
  int *piVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  int iVar6;
  int unaff_BP;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 unaff_SS;
  
  puVar2 = (undefined2 *)*(undefined4 *)(unaff_BP + -8);
  uVar9 = *puVar2;
  *(undefined2 *)(unaff_BP + -6) = ((undefined2 *)puVar2)[1];
  *(undefined2 *)(unaff_BP + -8) = uVar9;
  *(undefined2 *)(unaff_BP + -4) = 0;
  piVar3 = (int *)*(undefined4 *)(unaff_BP + -8);
  if (*piVar3 == 0 && ((int *)piVar3)[1] == 0) {
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
  FUN_28eb_2a7b();
  return;
}

