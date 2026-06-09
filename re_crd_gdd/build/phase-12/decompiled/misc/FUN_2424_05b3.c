// TIM2.EXE: FUN_2424_05b3 @ file 0x0299F3 Ghidra 0x247F3
// Subsystem: misc | Size: 207 bytes


void __cdecl16far FUN_2424_05b3(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  int in_DX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  int iStack_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int iStack_4;
  
  FUN_2424_0304();
  if (param_1 == 0) {
    iVar1 = 0;
    iVar3 = 0;
    iVar4 = DAT_554c_49aa;
    iVar5 = DAT_554c_49ac;
  }
  else {
    iVar1 = FUN_460e_0f42(param_1);
    _local_6 = CONCAT22(in_DX,iVar1);
    if (iVar1 != 0 || in_DX != 0) {
      uVar2 = FUN_460e_0f42(0,*(undefined2 *)(iVar1 + 0x10),0);
      uVar2 = FUN_460e_141e(uVar2,in_DX);
      _local_6 = CONCAT22(in_DX,uVar2);
    }
    if (local_6 == 0 && iStack_4 == 0) {
      return;
    }
    local_e = *(int *)(local_6 + 0x14);
    local_c = *(int *)(local_6 + 0x16);
    local_a = *(int *)(local_6 + 0x18);
    local_8 = *(int *)(local_6 + 0x1a);
    while( true ) {
      iVar1 = local_e;
      iVar3 = local_c;
      iVar4 = local_a;
      iVar5 = local_8;
      if (local_6 == 0 && iStack_4 == 0) break;
      if (*(int *)(local_6 + 0x14) < local_e) {
        local_a = local_a + (local_e - *(int *)(local_6 + 0x14));
        local_e = *(int *)(local_6 + 0x14);
      }
      if (*(int *)(local_6 + 0x16) < local_c) {
        local_8 = local_8 + (local_c - *(int *)(local_6 + 0x16));
        local_c = *(int *)(local_6 + 0x16);
      }
      if (local_e + local_a < *(int *)(local_6 + 0x14) + *(int *)(local_6 + 0x18)) {
        local_a = (*(int *)(local_6 + 0x14) + *(int *)(local_6 + 0x18)) - local_e;
      }
      if (local_c + local_8 < *(int *)(local_6 + 0x16) + *(int *)(local_6 + 0x1a)) {
        local_8 = (*(int *)(local_6 + 0x16) + *(int *)(local_6 + 0x1a)) - local_c;
      }
      FUN_4876_04b6(*(undefined2 *)(local_6 + 0xc),1,&iStack_16);
      if ((iStack_12 != 0) && (iStack_10 != 0)) {
        if (iStack_16 < local_e) {
          local_a = local_a + (local_e - iStack_16);
          local_e = iStack_16;
        }
        if (iStack_14 < local_c) {
          local_8 = local_8 + (local_c - iStack_14);
          local_c = iStack_14;
        }
        if (local_e + local_a < iStack_16 + iStack_12) {
          local_a = (iStack_16 + iStack_12) - local_e;
        }
        if (local_c + local_8 < iStack_14 + iStack_10) {
          local_8 = (iStack_14 + iStack_10) - local_c;
        }
      }
      uVar2 = (undefined2)((ulong)_local_6 >> 0x10);
      _local_6 = CONCAT22(*(undefined2 *)((int)_local_6 + 10),*(undefined2 *)((int)_local_6 + 8));
    }
  }
  FUN_406b_000c(iVar1,iVar3,iVar4,iVar5,0);
  return;
}

