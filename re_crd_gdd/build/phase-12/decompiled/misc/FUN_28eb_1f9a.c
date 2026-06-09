// TIM2.EXE: FUN_28eb_1f9a @ file 0x03004A Ghidra 0x2AE4A
// Subsystem: misc | Size: 365 bytes


void __cdecl16far FUN_28eb_1f9a(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_1a;
  int iStack_18;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 6);
  local_1a = *(int *)(param_1 + 10);
  iStack_18 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 10) == 0 && *(int *)(param_1 + 0xc) == 0) {
    local_1a = iVar2;
    iStack_18 = iVar1;
  }
  *(int *)(param_1 + 0xe) =
       (*(int *)(iVar2 + 0x22) + (uint)*(byte *)(iVar2 + 0x5a)) - *(int *)(iVar2 + 0x5c);
  *(int *)(param_1 + 0x10) =
       (*(int *)(iVar2 + 0x24) + (uint)*(byte *)(iVar2 + 0x5b)) - *(int *)(iVar2 + 0x5c);
  *(int *)(param_1 + 0x12) =
       (*(int *)(local_1a + 0x22) + (uint)*(byte *)(local_1a + 0x5a)) - *(int *)(local_1a + 0x5c);
  *(int *)(param_1 + 0x14) =
       (*(int *)(local_1a + 0x24) + (uint)*(byte *)(local_1a + 0x5b)) - *(int *)(local_1a + 0x5c);
  uVar3 = *(int *)(param_1 + 0xe) - *(int *)(param_1 + 0x12);
  uVar5 = (int)uVar3 >> 0xf;
  uVar4 = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0x14);
  uVar6 = (int)uVar4 >> 0xf;
  uVar4 = (uint)((int)((uVar3 ^ uVar5) - uVar5) < (int)((uVar4 ^ uVar6) - uVar6));
  uVar3 = (uint)(uVar4 == 0);
  if (uVar4 == 0) {
    local_e = 0;
    local_6 = 0;
    local_a = *(int *)(iVar2 + 0x5c) * 2;
    local_8 = local_a >> 1;
    local_12 = *(int *)(local_1a + 0x5c) * 2;
    local_10 = local_12 >> 1;
    local_c = local_10;
    local_4 = local_8;
  }
  else {
    local_c = 0;
    local_4 = 0;
    local_8 = *(int *)(iVar2 + 0x5c) * 2;
    local_a = local_8 >> 1;
    local_10 = *(int *)(local_1a + 0x5c) * 2;
    local_12 = local_10 >> 1;
    local_e = local_12;
    local_6 = local_a;
  }
  *(int *)(param_1 + 0x16) = *(int *)(param_1 + 0xe) + local_8 + uVar4;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x10) + local_a + uVar3;
  *(int *)(param_1 + 0x1a) = *(int *)(param_1 + 0x12) + local_10 + uVar4;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x14) + local_12 + uVar3;
  *(int *)(param_1 + 0xe) = *(int *)(param_1 + 0xe) + (local_4 - uVar4);
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + (local_6 - uVar3);
  *(int *)(param_1 + 0x12) = *(int *)(param_1 + 0x12) + (local_c - uVar4);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (local_e - uVar3);
  return;
}

