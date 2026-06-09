// TIM2.EXE: FUN_28eb_2107 @ file 0x0301B7 Ghidra 0x2AFB7
// Subsystem: misc | Size: 361 bytes


void __cdecl16far FUN_28eb_2107(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (param_1 != (undefined4 *)0x0) {
    iVar7 = *(int *)((int)param_1 + 6);
    iVar5 = *(int *)(param_1 + 1);
    if (iVar5 != 0 || iVar7 != 0) {
      uVar3 = (uint)*(byte *)(param_1 + 5);
      *(int *)((int)param_1 + 0x1e) =
           *(int *)(iVar5 + 0x22) + (int)*(char *)(iVar5 + uVar3 * 2 + 0x7a);
      *(int *)(param_1 + 8) = *(int *)(iVar5 + 0x24) + (int)*(char *)(iVar5 + uVar3 * 2 + 0x7b);
      iVar2 = *(int *)((int)param_1 + 10);
      iVar6 = *(int *)(param_1 + 2);
      if (iVar6 != 0 || iVar2 != 0) {
        bVar1 = *(byte *)((int)param_1 + 0x15);
        *(int *)((int)param_1 + 0x22) =
             *(int *)(iVar6 + 0x22) + (int)*(char *)(iVar6 + (uint)bVar1 * 2 + 0x7a);
        *(int *)(param_1 + 9) =
             *(int *)(iVar6 + 0x24) + (int)*(char *)(iVar6 + (uint)bVar1 * 2 + 0x7b);
      }
      iVar5 = iVar5 + uVar3 * 4;
      while( true ) {
        iVar2 = *(int *)(iVar5 + 0x60);
        iVar5 = *(int *)(iVar5 + 0x5e);
        if ((iVar5 == 0 && iVar2 == 0) || (*(int *)(iVar5 + 8) != 7)) break;
        for (iVar6 = 0; iVar7 = iVar2, iVar6 < 2; iVar6 = iVar6 + 1) {
          *(int *)(*(int *)(iVar5 + 0x76) + iVar6 * 4 + 0x1e) =
               *(int *)(iVar5 + 0x22) + (int)*(char *)(iVar5 + iVar6 * 2 + 0x7a);
          *(int *)(*(int *)(iVar5 + 0x76) + iVar6 * 4 + 0x20) =
               *(int *)(iVar5 + 0x24) + (int)*(char *)(iVar5 + iVar6 * 2 + 0x7b);
        }
      }
      if (DAT_5b41_0937 != 0x2000) {
        uVar4 = FUN_28eb_399d(param_1,3,0);
        *(undefined2 *)((int)*param_1 + 0xae) = uVar4;
        uVar4 = FUN_28eb_399d(param_1,3,1);
        *(undefined2 *)((int)*param_1 + 0xb4) = uVar4;
      }
    }
  }
  return;
}

