// TIM2.EXE: FUN_311b_06b8 @ file 0x036A68 Ghidra 0x31868
// Subsystem: misc | Size: 548 bytes


void __cdecl16far FUN_311b_06b8(void)

{
  undefined2 *puVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  int in_DX;
  int iVar5;
  int iVar6;
  undefined2 local_16;
  undefined2 local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int iStack_4;
  
  iVar4 = DAT_5b41_1b96;
  if (DAT_5b41_0d12 != 0) {
    if (iRam000557c0 == 0) {
      uVar2 = 5000;
    }
    else {
      uVar2 = 0x13ec;
    }
    uVar2 = (uint)(uVar2 < DAT_554c_2f1c);
    if (uVar2 != DAT_5b41_0d26) {
      DAT_5b41_0d26 = uVar2;
      if ((DAT_5b41_0d14 == 0) && (uVar2 != 0)) {
        if (DAT_5b41_1b96 != 0) {
          FUN_406b_053a();
        }
        DAT_554c_42d8 = 0xa000;
        FUN_406b_000c(0,0,DAT_554c_49aa,DAT_554c_3e4a,0);
        DAT_554c_42d8 = DAT_554c_42d2;
        if (iVar4 == 0) {
          DAT_554c_42d8 = DAT_554c_42d2;
          return;
        }
        FUN_406b_04d8(0);
        return;
      }
      DAT_5b41_0d14 = 1;
    }
    if ((DAT_5b41_0d14 != 0) && (DAT_554c_3e4a != 0)) {
      DAT_5b41_0d14 = 0;
      uVar3 = FUN_460e_0f42(0,DAT_5b41_0d12,0);
      local_6 = FUN_460e_141e(uVar3,in_DX);
      local_8 = 0;
      local_a = 0;
      iStack_4 = in_DX;
      while (local_6 != 0 || iStack_4 != 0) {
        local_c = *(int *)(local_6 + 10);
        local_e = *(int *)(local_6 + 8);
        *(int *)(local_6 + 10) = local_8;
        *(int *)(local_6 + 8) = local_a;
        local_8 = iStack_4;
        local_a = local_6;
        local_6 = local_e;
        iStack_4 = local_c;
      }
      DAT_554c_42c8 = 0;
      DAT_554c_42ca = DAT_554c_3e4a + -1;
      DAT_554c_42c4 = 0;
      DAT_554c_42c6 = DAT_554c_49aa + -1;
      DAT_554c_42d8 = DAT_554c_42d2;
      iVar4 = local_a;
      iVar5 = local_8;
      if (iRam000557c0 == 0) {
        while (local_6 = iVar4, iStack_4 = iVar5, iVar4 != 0 || iVar5 != 0) {
          iVar6 = *(int *)(iVar4 + 0xe) * 0x12;
          if (*(int *)(iVar6 + 0xda) != 0 || *(int *)(iVar6 + 0xdc) != 0) {
            puVar1 = (undefined2 *)(*(int *)(iVar4 + 0xe) * 0x12 + 0xda);
            (*(code *)*puVar1)(0x460e,iVar4,iVar5);
          }
          iVar5 = *(int *)(local_6 + 10);
          iVar4 = *(int *)(local_6 + 8);
        }
      }
      else {
        func_0x000551c0(0x460e,0);
      }
      if (uVar2 != 0) {
        FUN_406b_000c(0,0,DAT_554c_49aa,DAT_554c_3e4a,0);
      }
      DAT_554c_42d6 = DAT_554c_42d2;
      DAT_554c_42d8 = 0xa000;
      if (DAT_5b41_1b96 != 0) {
        FUN_406b_053a();
      }
      FUN_406b_0880(0,0,DAT_554c_49aa,DAT_554c_3e4a);
      FUN_406b_04d8(0);
      DAT_554c_42d6 = DAT_554c_42d4;
      DAT_554c_42d8 = DAT_554c_42d2;
      local_14 = 0;
      local_16 = 0;
      local_12 = DAT_554c_49aa;
      local_10 = DAT_554c_3e4a;
      FUN_2424_1e00(&local_16);
      FUN_2424_0304();
    }
  }
  return;
}

