// TIM2.EXE: FUN_1a9e_416a @ file 0x023D4A Ghidra 0x1EB4A
// Subsystem: level | Size: 617 bytes


void __cdecl16far
FUN_1a9e_416a(undefined2 *param_1,int param_2,int param_3,uint param_4,uint param_5,uint param_6)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 unaff_SS;
  bool bVar4;
  uint local_22;
  int local_20;
  uint local_1e;
  int local_1c;
  int local_1a;
  int local_18;
  int local_16;
  int local_14;
  uint local_12;
  uint local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  undefined2 local_6;
  undefined2 local_4;
  
  puVar3 = &stack0xfffe;
  if ((int)param_5 < 0) {
    param_5 = (param_5 ^ (int)param_5 >> 0xf) - ((int)param_5 >> 0xf);
    param_4 = param_4 | 2;
  }
  if ((int)param_6 < 0) {
    param_6 = (param_6 ^ (int)param_6 >> 0xf) - ((int)param_6 >> 0xf);
    param_4 = param_4 | 1;
  }
  local_10 = param_5;
  if (0x27f < (int)param_5) {
    local_10 = 0x280;
  }
  local_12 = param_6;
  if (399 < (int)param_6) {
    local_12 = 400;
  }
  if ((param_4 & 2) == 0) {
    local_20 = 0;
    local_1c = param_1[3] + -1;
  }
  else {
    local_20 = param_1[3] + -1;
    local_1c = 0;
  }
  FUN_1a9e_40b3(&local_22,param_5 - 1);
  for (local_8 = 0; local_8 < (int)local_10; local_8 = local_8 + 1) {
    ((undefined2 *)&DAT_5b41_20c2)[local_8] = local_20;
    bVar4 = CARRY2(local_22,local_1e);
    local_22 = local_22 + local_1e;
    local_20 = local_20 + local_1c + (uint)bVar4;
  }
  ((undefined2 *)&DAT_5b41_20c2)[local_8] = ((undefined2 *)&DAT_5b41_20c2)[local_8] + 1;
  local_20 = 0;
  local_1c = param_1[4] + -1;
  FUN_1a9e_40b3(&local_22,param_6 - 1);
  local_c = (int)param_1[3] >> (*(byte *)(DAT_554c_42dd + 0x4fae) & 0x1f);
  local_e = param_1[4] * local_c;
  local_18 = 0;
  local_16 = 0;
  for (local_a = 0; local_a < (int)local_12; local_a = local_a + 1) {
    local_14 = local_20;
    bVar4 = CARRY2(local_22,local_1e);
    local_22 = local_22 + local_1e;
    for (; local_16 < local_20; local_16 = local_16 + 1) {
      local_18 = local_18 + local_c;
    }
    if ((param_4 & 1) == 0) {
      *(int *)(local_a * 2 + 0x7cf2) = local_18;
    }
    else {
      *(int *)((local_12 - local_a) * 2 + 0x7cf0) = local_18;
    }
    local_20 = local_20 + local_1c + (uint)bVar4;
  }
  local_12 = local_12 + param_3;
  local_10 = local_10 + param_2;
  local_18 = param_3;
  local_1a = param_2;
  local_16 = 0;
  if (DAT_554c_42c3 != '\0') {
    if (DAT_554c_42c6 < (int)local_10) {
      local_10 = DAT_554c_42c6 + 1;
    }
    if (DAT_554c_42ca < (int)local_12) {
      local_12 = DAT_554c_42ca + 1;
    }
    if (param_3 < DAT_554c_42c8) {
      local_18 = DAT_554c_42c8;
    }
    if (param_2 < DAT_554c_42c4) {
      local_16 = DAT_554c_42c4 - param_2;
      local_1a = DAT_554c_42c4;
    }
  }
  local_6 = param_1[1];
  local_4 = *param_1;
  if ((local_18 < (int)local_12) && (1 < (int)(local_10 - local_1a))) {
    if (DAT_554c_42e1 == '\x10') {
      out(0x3ce,1);
      out(0x3ce,5);
      out(0x3ce,8);
    }
    local_a = local_18;
    do {
      (*(code *)*(undefined2 *)0x4e0a)(0x1a9e);
      iVar1 = *(int *)(puVar3 + -8);
      iVar2 = *(int *)(puVar3 + -0x10);
      *(int *)(puVar3 + -8) = iVar1 + 1;
    } while (iVar1 + 1 < iVar2);
    FUN_1a9e_2122();
  }
  return;
}

