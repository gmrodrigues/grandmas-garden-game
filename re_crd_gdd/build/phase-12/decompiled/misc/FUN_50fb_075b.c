// TIM2.EXE: FUN_50fb_075b @ file 0x05690B Ghidra 0x5170B
// Subsystem: misc | Size: 338 bytes


void __cdecl16far FUN_50fb_075b(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  undefined2 unaff_SS;
  int local_22;
  undefined2 local_20;
  
  FUN_1000_27ad();
  iVar1 = (*(int *)(param_1 + 4) + param_5) - param_3;
  uVar2 = FUN_50fb_071e(iVar1);
  if (*(uint *)(param_1 + 6) < uVar2) {
    FUN_50fb_06d0(param_1,uVar2);
  }
  else if ((DAT_554c_5eb2 < *(int *)(param_1 + 6) - uVar2) && ((*(byte *)(param_1 + 8) & 1) == 0)) {
    local_22 = FUN_1000_3226(uVar2 + 1);
    if (*(int *)(param_1 + 2) == 0) {
      FUN_1000_59e3(0x59aa);
    }
    if (param_2 != 0) {
      FUN_1000_49eb(local_22,*(undefined2 *)(param_1 + 2),param_2);
    }
    *(uint *)(param_1 + 6) = uVar2;
    goto LAB_50fb_0801;
  }
  local_22 = *(int *)(param_1 + 2);
LAB_50fb_0801:
  if ((*(int *)(param_1 + 2) != local_22) || (param_5 != param_3)) {
    FUN_1000_4a97(local_22 + param_2 + param_5,*(int *)(param_1 + 2) + param_2 + param_3,
                  (*(int *)(param_1 + 4) - param_2) - param_3);
  }
  if (param_5 != 0) {
    if (param_4 == 0) {
      FUN_1000_4a32(local_22 + param_2,0x20,param_5);
    }
    else {
      FUN_1000_4a97(local_22 + param_2,param_4,param_5);
    }
  }
  *(int *)(param_1 + 4) = iVar1;
  *(undefined1 *)(*(int *)(param_1 + 4) + local_22) = 0;
  if (*(int *)(param_1 + 2) != local_22) {
    FUN_1000_3157(*(int *)(param_1 + 2));
    *(int *)(param_1 + 2) = local_22;
  }
  *(undefined2 *)0x14 = local_20;
  return;
}

