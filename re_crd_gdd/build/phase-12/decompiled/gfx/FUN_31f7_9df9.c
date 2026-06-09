// TIM2.EXE: FUN_31f7_9df9 @ file 0x040F69 Ghidra 0x3BD69
// Subsystem: gfx | Size: 326 bytes


void __cdecl16far FUN_31f7_9df9(undefined4 param_1)

{
  undefined2 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  int iVar7;
  undefined2 local_4;
  
  iVar7 = (int)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  if (*(int *)(iVar5 + 0x16) == 0) {
    return;
  }
  iVar3 = *(int *)(iVar5 + 0x10);
  if ((*(byte *)(iVar5 + 0xc) & 0x20) == 0) {
    if (0 < *(int *)(iVar5 + 0x16)) goto LAB_31f7_9e2f;
LAB_31f7_9e38:
    *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + -1;
  }
  else {
    if (0 < *(int *)(iVar5 + 0x16)) goto LAB_31f7_9e38;
LAB_31f7_9e2f:
    *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 1;
  }
  if ((*(int *)(iVar5 + 0x10) == 9) || (*(int *)(iVar5 + 0x10) == 0)) {
    *(undefined2 *)(iVar5 + 0x16) = 0;
    *(undefined2 *)(iVar5 + 0x10) = 0;
    goto LAB_31f7_9f2e;
  }
  if (*(int *)(iVar5 + 0x10) < 0) {
    *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 9;
  }
  if ((*(byte *)(iVar5 + 0xc) & 0x20) == 0) {
    if (*(char *)(*(int *)(iVar5 + 0x10) + 0x3cb2) <= *(char *)(iVar3 + 0x3cb2)) goto LAB_31f7_9e98;
LAB_31f7_9e93:
    uVar6 = 1;
  }
  else {
    if (*(char *)(iVar3 + 0x3cbb) < *(char *)(*(int *)(iVar5 + 0x10) + 0x3cbb)) goto LAB_31f7_9e93;
LAB_31f7_9e98:
    uVar6 = 0;
  }
  iVar3 = *(int *)(iVar5 + 0x76);
  if (iVar3 != 0) {
    iVar4 = *(int *)(iVar3 + 6);
    if ((iVar4 == iVar7) && (*(int *)(iVar3 + 4) == iVar5)) {
      local_4 = 0;
      uVar2 = *(undefined1 *)(iVar3 + 0x15);
    }
    else {
      local_4 = 1;
      uVar2 = *(undefined1 *)(iVar3 + 0x14);
    }
    uVar6 = FUN_28eb_37bb(iVar3,local_4,uVar6);
    iVar3 = FUN_28eb_396b(iVar5,iVar7,iVar3);
    puVar1 = (undefined2 *)(*(int *)(*(int *)(iVar3 + 8) * 2 + 0x302) + 0x14);
    (*(code *)*puVar1)(0x28eb,iVar5,iVar7,iVar3,iVar4,uVar2,uVar6,0,0x8000,0x88b);
  }
LAB_31f7_9f2e:
  FUN_31f7_9d07(iVar5,iVar7);
  return;
}

