// TIM2.EXE: FUN_2424_2ce0 @ file 0x02C120 Ghidra 0x26F20
// Subsystem: misc | Size: 413 bytes


void __cdecl16far FUN_2424_2ce0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined1 local_18 [4];
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar1 = *(int *)(*(int *)(iVar3 + 8) * 2 + 0x68fe);
  if (iVar1 != 0) {
    local_4 = *(int *)(iVar3 + 0x22) - DAT_5b41_0925;
    local_6 = *(int *)(iVar3 + 0x24) - DAT_5b41_0927;
    local_a = 0;
    local_8 = 0;
    local_10 = 0;
    if ((*(byte *)(iVar3 + 0xc) & 0x30) != 0) {
      if (*(int *)(iVar3 + 0x48) < *(int *)(iVar3 + 0x4a)) {
        local_10 = 2;
      }
      else {
        local_10 = 1;
      }
    }
    if (*(int *)(iVar3 + 0x48) < *(int *)(iVar3 + 0x4a)) {
      iVar5 = 1;
      while (iVar4 = FUN_4551_0308(iVar1,iVar5), iVar4 == 0) {
        iVar5 = iVar5 + 1;
      }
      iVar4 = 1;
      while (iVar2 = FUN_4551_0308(iVar1,iVar5 + iVar4), iVar2 == 0) {
        iVar4 = iVar4 + 1;
      }
      FUN_4551_03eb(iVar1,iVar5,local_18);
      local_a = local_12;
      if (local_12 == 0) {
        return;
      }
      local_c = *(int *)(iVar3 + 0x4a) / local_12;
      if ((*(int *)(iVar3 + 8) == 0x76) && (local_10 != 0)) {
        local_4 = local_4 + local_14 + -0x10;
      }
    }
    else {
      iVar5 = 0;
      iVar4 = 1;
      while (iVar2 = FUN_4551_0308(iVar1,iVar4), iVar2 == 0) {
        iVar4 = iVar4 + 1;
      }
      FUN_4551_03eb(iVar1,0,local_18);
      local_8 = local_14;
      if (local_14 == 0) {
        return;
      }
      local_c = *(int *)(iVar3 + 0x48) / local_14;
    }
    for (local_e = 0; local_e < local_c; local_e = local_e + 1) {
      iVar3 = iVar5;
      if (local_e != 0) {
        if (local_c + -1 == local_e) {
          iVar3 = iVar5 + iVar4 + -1;
        }
        else {
          iVar3 = (local_e + -1) % (iVar4 + -2) + iVar5 + 1;
        }
      }
      FUN_4551_01dc(iVar1,iVar3,local_4,local_6,local_10);
      local_4 = local_4 + local_8;
      local_6 = local_6 + local_a;
    }
  }
  return;
}

