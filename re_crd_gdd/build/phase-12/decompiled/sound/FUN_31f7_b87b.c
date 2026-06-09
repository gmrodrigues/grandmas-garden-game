// TIM2.EXE: FUN_31f7_b87b @ file 0x0429EB Ghidra 0x3D7EB
// Subsystem: sound | Size: 330 bytes


void __cdecl16far FUN_31f7_b87b(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined1 local_14 [4];
  int local_10;
  int local_e;
  undefined2 local_c;
  uint local_a;
  uint local_8;
  int local_6;
  int local_4;
  
  if ((DAT_5b41_051f & 4) != 0) {
    DAT_554c_42c3 = 1;
    local_4 = DAT_554c_42c8;
    local_6 = DAT_554c_42ca;
    local_a = DAT_554c_42c6;
    local_8 = DAT_554c_42c4;
    uVar6 = (undefined2)((ulong)param_1 >> 0x10);
    iVar4 = (int)param_1;
    if ((int)DAT_554c_42c4 < (int)*(uint *)(iVar4 + 0x22)) {
      DAT_554c_42c4 = *(uint *)(iVar4 + 0x22);
    }
    if (*(int *)(iVar4 + 0x22) + *(int *)(iVar4 + 0x48) + -1 < (int)DAT_554c_42c6) {
      DAT_554c_42c6 = (*(int *)(iVar4 + 0x22) + *(int *)(iVar4 + 0x48)) - 1;
    }
    if (DAT_554c_42c8 < *(int *)(iVar4 + 0x24)) {
      DAT_554c_42c8 = *(int *)(iVar4 + 0x24);
    }
    if (*(int *)(iVar4 + 0x24) + *(int *)(iVar4 + 0x4a) + -1 < DAT_554c_42ca) {
      DAT_554c_42ca = *(int *)(iVar4 + 0x24) + *(int *)(iVar4 + 0x4a) + -1;
    }
    DAT_554c_42c4 = DAT_554c_42c4 & 0xfff8;
    DAT_554c_42c6 = DAT_554c_42c6 | 7;
    if (((int)DAT_554c_42c4 <= (int)DAT_554c_42c6) && (DAT_554c_42c8 <= DAT_554c_42ca)) {
      local_c = *(undefined2 *)(*(int *)(iVar4 + 8) * 2 + 0x68fe);
      FUN_4551_03eb(local_c,0,local_14);
      iVar1 = DAT_554c_42c6 + 1;
      iVar2 = DAT_554c_42c8 / local_e;
      iVar3 = DAT_554c_42ca + 1;
      for (iVar4 = ((int)DAT_554c_42c4 / local_10) * local_10; iVar5 = iVar2 * local_e,
          iVar4 < iVar1; iVar4 = iVar4 + local_10) {
        for (; iVar5 < iVar3; iVar5 = iVar5 + local_e) {
          FUN_4551_01dc(local_c,0,iVar4,iVar5,0);
        }
      }
    }
    DAT_554c_42c8 = local_4;
    DAT_554c_42ca = local_6;
    DAT_554c_42c6 = local_a;
    DAT_554c_42c4 = local_8;
  }
  return;
}

