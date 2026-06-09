// TIM2.EXE: FUN_28eb_2a7b @ file 0x030B2B Ghidra 0x2B92B
// Subsystem: misc | Size: 46 bytes


void FUN_28eb_2a7b(void)

{
  uint *puVar1;
  undefined2 *puVar2;
  int *piVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 *puVar6;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 unaff_SS;
  
  uVar9 = *(undefined2 *)((int)*(undefined4 *)*(undefined4 *)(unaff_BP + -8) + 8);
  *(undefined2 *)(unaff_BP + -2) = uVar9;
  if ((undefined2 *)*(undefined2 *)(unaff_BP + 10) == (undefined2 *)&DAT_5b41_055f) {
    iVar5 = FUN_54b4_002a(0x28eb,uVar9);
    if (iVar5 != unaff_DI) {
      FUN_28eb_2be8();
      return;
    }
    unaff_SI = 1;
    goto LAB_28eb_2bec;
  }
  if ((*(byte *)((int)*(undefined4 *)(unaff_BP + 6) + 0xf) & 0x10) != 0) {
    if (((*(byte *)((int)*(undefined4 *)*(undefined4 *)(unaff_BP + -8) + 0xf) & 0x10) != 0) &&
       (*(int *)(unaff_BP + 0xc) == 0)) {
      unaff_SI = 1;
    }
    goto LAB_28eb_2bec;
  }
  if (*(int *)(*(int *)(unaff_DI * 2 + 0x302) + 0x38) !=
      *(int *)(*(int *)(*(int *)(unaff_BP + -2) * 2 + 0x302) + 0x38)) {
    if (*(int *)(*(int *)(unaff_DI * 2 + 0x302) + 0x38) <
        *(int *)(*(int *)(*(int *)(unaff_BP + -2) * 2 + 0x302) + 0x38)) {
      unaff_SI = 1;
    }
    else {
      unaff_SI = 0;
    }
    goto LAB_28eb_2bec;
  }
  uVar9 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
  iVar5 = (int)*(undefined4 *)(unaff_BP + 6);
  if (((*(int *)(iVar5 + 8) == 0x31) || (*(int *)(iVar5 + 8) == 10)) ||
     (*(int *)(iVar5 + 8) == 0x4c)) {
    unaff_SI = 1;
  }
  if (*(int *)(unaff_BP + -4) != 0) {
    uVar9 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -8) >> 0x10);
    iVar5 = (int)*(undefined4 *)(unaff_BP + -8);
    if (((*(int *)(iVar5 + 8) == 0x31) || (*(int *)(iVar5 + 8) == 10)) ||
       (*(int *)(iVar5 + 8) == 0x4c)) {
      unaff_SI = 1;
    }
  }
  if (unaff_SI != 0) goto LAB_28eb_2bec;
  puVar2 = (undefined2 *)*(undefined4 *)(unaff_BP + -8);
  uVar9 = *puVar2;
  *(undefined2 *)(unaff_BP + -10) = ((undefined2 *)puVar2)[1];
  *(undefined2 *)(unaff_BP + -0xc) = uVar9;
  if (*(int *)((int)*(undefined4 *)(unaff_BP + 6) + 8) == 0xb) {
    uVar9 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -0xc) >> 0x10);
    iVar5 = (int)*(undefined4 *)(unaff_BP + -0xc);
    if (*(int *)(iVar5 + 8) != 0xb) goto code_r0x0002ba3a;
    if ((*(int *)(iVar5 + 0xa6) <= *(int *)((int)*(undefined4 *)(unaff_BP + 6) + 0xa6)) &&
       ((*(int *)((int)*(undefined4 *)(unaff_BP + -0xc) + 0xa6) !=
         *(int *)((int)*(undefined4 *)(unaff_BP + 6) + 0xa6) ||
        (*(int *)((int)*(undefined4 *)(unaff_BP + 6) + 0xa4) <=
         *(int *)((int)*(undefined4 *)*(undefined4 *)(unaff_BP + -8) + 0xa4))))) goto LAB_28eb_2bec;
  }
  else {
code_r0x0002ba3a:
    if (*(int *)((int)*(undefined4 *)(unaff_BP + 6) + 0xa6) <=
        *(int *)((int)*(undefined4 *)(unaff_BP + -0xc) + 0xa6)) {
      if ((*(int *)((int)*(undefined4 *)(unaff_BP + -0xc) + 0xa6) ==
           *(int *)((int)*(undefined4 *)(unaff_BP + 6) + 0xa6)) &&
         (*(int *)((int)*(undefined4 *)*(undefined4 *)(unaff_BP + -8) + 0xa4) <
          *(int *)((int)*(undefined4 *)(unaff_BP + 6) + 0xa4))) {
        FUN_28eb_2b9c();
        return;
      }
      goto LAB_28eb_2bec;
    }
  }
  unaff_SI = 1;
LAB_28eb_2bec:
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
  puVar6 = (undefined2 *)puVar4;
  puVar6[1] = ((undefined2 *)puVar2)[1];
  *puVar4 = uVar9;
  uVar9 = *(undefined2 *)(unaff_BP + -8);
  puVar6[3] = *(undefined2 *)(unaff_BP + -6);
  puVar6[2] = uVar9;
  puVar2 = (undefined2 *)*(undefined4 *)(unaff_BP + -8);
  uVar9 = *(undefined2 *)(unaff_BP + 8);
  uVar7 = *(undefined2 *)(unaff_BP + 6);
  ((undefined2 *)puVar2)[1] = uVar9;
  *puVar2 = uVar7;
  piVar3 = (int *)*(undefined4 *)(unaff_BP + 6);
  if (*piVar3 != 0 || ((int *)piVar3)[1] != 0) {
    uVar8 = (undefined2)((ulong)*(undefined4 *)piVar3 >> 0x10);
    iVar5 = (int)*(undefined4 *)piVar3;
    uVar7 = *(undefined2 *)(unaff_BP + 6);
    *(undefined2 *)(iVar5 + 6) = uVar9;
    *(undefined2 *)(iVar5 + 4) = uVar7;
  }
  uVar9 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
  iVar5 = (int)*(undefined4 *)(unaff_BP + 6);
  puVar1 = (uint *)(iVar5 + 10);
  *puVar1 = *puVar1 & 0xc7ff;
  if ((undefined2 *)*(undefined2 *)(unaff_BP + 10) == (undefined2 *)&DAT_5b41_055f) {
    puVar1 = (uint *)(iVar5 + 10);
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

