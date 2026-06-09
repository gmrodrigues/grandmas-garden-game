// TIM2.EXE: FUN_2424_2919 @ file 0x02BD59 Ghidra 0x26B59
// Subsystem: misc | Size: 261 bytes


void __cdecl16far FUN_2424_2919(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 *puVar10;
  undefined2 uVar11;
  
  uVar11 = (undefined2)((ulong)param_1 >> 0x10);
  iVar9 = (int)param_1;
  if (((*(int *)(iVar9 + 8) == 10) || (*(int *)(iVar9 + 8) == 0x4c)) || (*(int *)(iVar9 + 8) == 8))
  {
LAB_2424_29a1:
    FUN_2424_2a1e(iVar9,uVar11,param_2);
  }
  else {
    iVar7 = *(int *)(iVar9 + 0x2e) - DAT_5b41_0925;
    iVar8 = *(int *)(iVar9 + 0x30) - DAT_5b41_0927;
    iVar1 = *(int *)(iVar9 + 0x48);
    iVar2 = *(int *)(iVar9 + 0x4a);
    for (puVar10 = DAT_5b41_04b0; puVar10 != (undefined2 *)0x0; puVar10 = (undefined2 *)*puVar10) {
      iVar3 = puVar10[1];
      iVar4 = puVar10[2];
      iVar5 = puVar10[3];
      iVar6 = puVar10[4];
      if (((iVar3 <= iVar7) && (iVar7 + iVar1 <= iVar5)) &&
         ((iVar4 <= iVar8 && (iVar8 + iVar2 <= iVar6)))) {
        FUN_2424_02ca();
        goto LAB_2424_29a1;
      }
      if (((iVar7 <= iVar5) && (iVar3 <= iVar7 + iVar1)) &&
         ((iVar8 <= iVar6 && (((iVar4 <= iVar8 + iVar2 && (iVar3 < iVar5)) && (iVar4 <= iVar6))))))
      {
        DAT_554c_42c3 = 1;
        DAT_554c_42c4 = iVar3;
        DAT_554c_42c6 = iVar5;
        DAT_554c_42c8 = iVar4;
        DAT_554c_42ca = iVar6;
        FUN_2424_2a1e(iVar9,uVar11,param_2);
      }
    }
    FUN_2424_02ca();
  }
  return;
}

