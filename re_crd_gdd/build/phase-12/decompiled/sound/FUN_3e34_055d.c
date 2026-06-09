// TIM2.EXE: FUN_3e34_055d @ file 0x043A9D Ghidra 0x3E89D
// Subsystem: sound | Size: 729 bytes


void __cdecl16far FUN_3e34_055d(int *param_1)

{
  int *piVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined1 local_2e [2];
  int local_2c;
  undefined1 *local_2a;
  int local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined4 local_22;
  undefined4 local_1e;
  undefined1 *local_1a;
  int local_18;
  uint local_16;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  uint local_a;
  int local_8;
  uint local_6;
  int local_4;
  
  if (*(int *)(*param_1 + 4) == -2) {
    iVar4 = 0;
    uVar2 = FUN_1000_199e();
    local_6 = uVar2 + *(uint *)(*param_1 + 2);
    local_4 = iVar4 + (uint)CARRY2(uVar2,*(uint *)(*param_1 + 2));
    for (piVar7 = param_1; piVar7[1] != 0; piVar7 = piVar7 + 1) {
    }
    iVar5 = 0;
    uVar2 = FUN_1000_199e();
    iVar4 = *piVar7;
    local_a = uVar2 + *(uint *)(iVar4 + 2);
    local_8 = iVar5 + (uint)CARRY2(uVar2,*(uint *)(iVar4 + 2));
    FUN_1a9e_5398(0x1000,*(undefined2 *)(iVar4 + 6),*(undefined2 *)(iVar4 + 8));
    uVar6 = 0;
    uVar2 = FUN_1000_180a();
    uVar2 = uVar2 >> 1 | (uint)((uVar6 & 1) != 0) << 0xf;
    uVar8 = CONCAT22((uVar6 >> 1) + ((local_8 - local_4) - (uint)(local_a < local_6)) +
                     (uint)CARRY2(uVar2,local_a - local_6),uVar2 + (local_a - local_6));
  }
  else {
    uVar8 = (*DAT_554c_4daa)(0x3e34,param_1,local_2e);
  }
  local_16 = (uint)uVar8;
  if (((int)((ulong)uVar8 >> 0x10) == 0) && (local_16 < 0xffdd)) {
    local_18 = 0;
    local_1a = (undefined1 *)0x0;
    local_14 = 0;
    for (local_2c = 1;
        ((local_2c < 0x32 && (local_1a == (undefined1 *)0x0 && local_18 == 0)) &&
        (*(int *)(local_2c * 2) != 0)); local_2c = local_2c + 1) {
      iVar4 = local_18;
      FUN_3f2b_0e3a(*(undefined2 *)(local_2c * 2));
      local_1a = (undefined1 *)FUN_3f2b_0fa3(local_16,local_14,0,0);
      local_18 = iVar4;
    }
    if ((local_1a == (undefined1 *)0x0 && local_18 == 0) && (local_2c < 0x32)) {
      FUN_3f2b_1159(4);
      uVar3 = FUN_3f2b_0e8f(4);
      iVar4 = 0x52bc;
      *(undefined2 *)(local_2c * 2) = uVar3;
      if (*(int *)(local_2c * 2) != 0) {
        FUN_3f2b_0e3a(*(undefined2 *)(local_2c * 2));
        local_1a = (undefined1 *)FUN_3f2b_0fa3(local_16,local_14,0,0);
        local_18 = iVar4;
        if (local_1a == (undefined1 *)0x0 && iVar4 == 0) {
          FUN_3f2b_0f46(*(undefined2 *)(local_2c * 2));
          *(undefined2 *)(local_2c * 2) = 0;
        }
      }
    }
    else {
      local_2c = local_2c + -1;
    }
    if (local_1a == (undefined1 *)0x0 && local_18 == 0) {
      FUN_3f2b_118f();
      DAT_5b41_1ade = local_14;
      DAT_5b41_1adc = local_16;
      DAT_5b41_1ad2 = 8;
    }
    else {
      local_22 = (undefined1 *)CONCAT22(local_18,local_1a);
      local_1e = (undefined1 *)
                 CONCAT22(*(undefined2 *)*param_1,(undefined1 *)((undefined2 *)*param_1)[1]);
      while( true ) {
        iVar4 = local_14 - (uint)(local_16 == 0);
        if (local_16 == 0 && local_14 == 0) break;
        *local_22 = *local_1e;
        local_1e = (undefined1 *)CONCAT22(local_1e._2_2_,(undefined1 *)local_1e + 1);
        local_22 = (undefined1 *)CONCAT22(local_22._2_2_,(undefined1 *)local_22 + 1);
        local_16 = local_16 - 1;
        local_14 = iVar4;
      }
      local_16 = local_16 - 1;
      local_14 = iVar4;
      FUN_3f2b_118f();
      local_28 = DAT_554c_3d5a + local_2c;
      local_2a = local_1a;
      local_24 = *(undefined2 *)*param_1;
      local_26 = ((undefined2 *)*param_1)[1];
      iVar4 = 0;
      uVar2 = FUN_1000_199e();
      local_6 = uVar2 + *(uint *)(*param_1 + 2);
      local_4 = iVar4 + (uint)CARRY2(uVar2,*(uint *)(*param_1 + 2));
      for (piVar7 = param_1; *piVar7 != 0; piVar7 = piVar7 + 1) {
        iVar4 = 0;
        uVar2 = FUN_1000_199e();
        local_e = uVar2 + *(uint *)(*piVar7 + 2);
        local_c = iVar4 + (uint)CARRY2(uVar2,*(uint *)(*piVar7 + 2));
        iVar4 = 0;
        uVar2 = FUN_1000_199e();
        piVar1 = (int *)*piVar7;
        local_12 = uVar2 + piVar1[2];
        local_10 = iVar4 + (uint)CARRY2(uVar2,piVar1[2]);
        *piVar1 = local_28;
        piVar1[1] = (int)(local_2a + (local_e - local_6));
        if (*(int *)(*param_1 + 4) != -2) {
          *(undefined2 *)(*piVar7 + 4) = local_2a + (local_12 - local_6);
        }
      }
      FUN_22de_0351(local_26,local_24);
    }
  }
  else {
    DAT_5b41_1ad2 = 5;
  }
  return;
}

