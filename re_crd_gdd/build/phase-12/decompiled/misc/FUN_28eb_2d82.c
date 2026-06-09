// TIM2.EXE: FUN_28eb_2d82 @ file 0x030E32 Ghidra 0x2BC32
// Subsystem: misc | Size: 406 bytes


void __cdecl16far FUN_28eb_2d82(undefined4 param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  if (DAT_5b41_050f != 0) {
    return;
  }
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if ((((*(int *)(iVar3 + 8) != 0x31) &&
       (*(undefined1 *)(iVar3 + 0x18) = (undefined1)param_2, (*(byte *)(iVar3 + 0xf) & 0x20) != 0))
      && (5000 < DAT_554c_2f1c)) && ((param_2 & 0x80) != 0)) {
    FUN_2424_3746(iVar3,uVar5,param_2 & 0x7f);
  }
  if (*(int *)(iVar3 + 8) == 7) {
    puVar1 = (undefined4 *)*(int *)(iVar3 + 0x78);
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    iVar3 = (int)*puVar1;
    *(undefined1 *)(iVar3 + 0x18) = (undefined1)param_2;
    if (DAT_554c_2f1c < 0x1389) {
      return;
    }
    if ((param_2 & 0x80) == 0) {
      return;
    }
    FUN_2424_0a23(iVar3,*(undefined2 *)((int)puVar1 + 2),param_2);
    return;
  }
  iVar4 = *(int *)(iVar3 + 0x58);
  if (iVar4 == 0) goto LAB_28eb_2e6e;
  if (DAT_5b41_0937 == 0x1000) {
    FUN_28eb_1f9a(iVar4);
    iVar2 = FUN_28eb_1c08(iVar4);
    if (iVar2 != 0) goto LAB_28eb_2e3f;
  }
  else {
LAB_28eb_2e3f:
    *(undefined1 *)((int)*(undefined4 *)(iVar4 + 2) + 0x18) = (undefined1)param_2;
  }
  if ((5000 < DAT_554c_2f1c) && ((param_2 & 0x80) != 0)) {
    FUN_2424_09c2(*(undefined2 *)(iVar4 + 2),*(undefined2 *)(iVar4 + 4),param_2);
  }
LAB_28eb_2e6e:
  if (DAT_5b41_0937 == 0x2000) {
    puVar1 = (undefined4 *)*(int *)(iVar3 + 0x76);
    if (puVar1 != (undefined4 *)0x0) {
      uVar6 = (undefined2)((ulong)*puVar1 >> 0x10);
      iVar4 = (int)*puVar1;
      if ((*(byte *)(iVar4 + 0x18) & 0x7f) == 0) {
        *(undefined1 *)(iVar4 + 0x18) = (undefined1)param_2;
        FUN_28eb_2107(puVar1);
      }
    }
    puVar1 = (undefined4 *)*(int *)(iVar3 + 0x78);
    if (puVar1 != (undefined4 *)0x0) {
      uVar5 = (undefined2)((ulong)*puVar1 >> 0x10);
      iVar3 = (int)*puVar1;
      if ((*(byte *)(iVar3 + 0x18) & 0x7f) == 0) {
        *(undefined1 *)(iVar3 + 0x18) = (undefined1)param_2;
        FUN_28eb_2107(puVar1);
      }
    }
  }
  else {
    for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
      puVar1 = (undefined4 *)*(int *)(iVar3 + iVar4 * 2 + 0x76);
      if (puVar1 != (undefined4 *)0x0) {
        *(undefined1 *)((int)*puVar1 + 0x18) = (undefined1)param_2;
        FUN_28eb_2107(puVar1);
        if ((5000 < DAT_554c_2f1c) && ((param_2 & 0x80) != 0)) {
          FUN_2424_0a23(*(undefined2 *)puVar1,*(undefined2 *)((int)puVar1 + 2),param_2);
        }
      }
    }
  }
  return;
}

