// TIM2.EXE: FUN_2e67_0a1f @ file 0x03428F Ghidra 0x2F08F
// Subsystem: misc | Size: 636 bytes


void __cdecl16far FUN_2e67_0a1f(void)

{
  undefined2 uVar1;
  int in_DX;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined4 local_a;
  undefined4 local_6;
  
  uVar1 = DAT_5b41_0bee;
  if (DAT_5b41_0bec != 0) {
    DAT_5b41_0bee = 0;
    local_6 = &DAT_5b41_0c48;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      uVar5 = (undefined2)((ulong)local_6 >> 0x10);
      piVar2 = (int *)local_6;
      if ((*local_6 != 0) && (piVar2[3] == 1)) {
        local_a = &DAT_5b41_0c48;
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          if ((*local_a == *local_6) && (((uint *)local_a)[3] == 0)) {
            *local_6 = 0;
            *local_a = 0;
            break;
          }
          local_a = (uint *)CONCAT22(local_a._2_2_,(uint *)local_a + 4);
        }
      }
      if ((*local_6 != 0) && (piVar2[3] == 1)) {
        local_a = &DAT_5b41_0c48;
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          if ((*local_a == *local_6) && (((uint *)local_a)[3] == 2)) {
            FUN_2e67_03fe(*local_6);
            *local_6 = 0;
            *local_a = 0;
            break;
          }
          local_a = (uint *)CONCAT22(local_a._2_2_,(uint *)local_a + 4);
        }
      }
      if ((*local_6 != 0) && (piVar2[3] == 1)) {
        *local_6 = 0;
      }
      local_6 = (uint *)CONCAT22(uVar5,piVar2 + 4);
    }
    local_6 = &DAT_5b41_0c48;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      uVar5 = (undefined2)((ulong)local_6 >> 0x10);
      if (((*local_6 != 0) && (*local_6 < 1000)) && (((uint *)local_6)[3] == 2)) {
        local_a = &DAT_5b41_0c48;
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          if ((*local_a == *local_6) && (((uint *)local_a)[3] == 0)) {
            ((uint *)local_a)[2] = 0;
            break;
          }
          local_a = (uint *)CONCAT22(local_a._2_2_,(uint *)local_a + 4);
        }
        if (iVar3 == 0) {
          FUN_2e67_06ab(*local_6);
          *local_6 = 0;
        }
      }
      local_6 = (uint *)CONCAT22(uVar5,(uint *)local_6 + 4);
    }
    local_6 = &DAT_5b41_0c48;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      uVar5 = (undefined2)((ulong)local_6 >> 0x10);
      piVar2 = (int *)local_6;
      if ((*local_6 != 0) && (piVar2[3] == 0)) {
        local_a = &DAT_5b41_0c48;
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          if ((*local_a == *local_6) && (((uint *)local_a)[3] == 2)) {
            if (piVar2[2] != 0) {
              FUN_2e67_06ab(*local_6);
              FUN_2e67_045f(*local_6,piVar2[1],piVar2[2],1);
            }
            *local_6 = 0;
            break;
          }
          local_a = (uint *)CONCAT22(local_a._2_2_,(uint *)local_a + 4);
        }
      }
      if ((*local_6 != 0) && (piVar2[3] == 0)) {
        FUN_2e67_045f(*local_6,piVar2[1],piVar2[2],1);
        piVar2[3] = 2;
      }
      local_6 = (uint *)CONCAT22(uVar5,piVar2 + 4);
    }
    local_6 = &DAT_5b41_0c48;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      uVar5 = (undefined2)((ulong)local_6 >> 0x10);
      if (((*local_6 != 0) && (((int *)local_6)[3] == 2)) &&
         (iVar3 = FUN_2e67_07f1(*local_6), iVar3 == 0 && in_DX == 0)) {
        FUN_2e67_03fe(*local_6);
        *local_6 = 0;
      }
      local_6 = (uint *)CONCAT22(uVar5,(int *)local_6 + 4);
    }
  }
  DAT_5b41_0bee = uVar1;
  return;
}

