// TIM2.EXE: FUN_2424_2e7d @ file 0x02C2BD Ghidra 0x270BD
// Subsystem: misc | Size: 320 bytes


void __cdecl16far FUN_2424_2e7d(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_16;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  undefined2 local_a;
  int local_8;
  int local_6;
  int local_4;
  
  iVar4 = (int)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 8);
  local_a = *(undefined2 *)(iVar2 + 0x10);
  local_e = *(int *)(iVar1 * 2 + 0x302);
  local_c = *(int *)(iVar1 * 2 + 0x68fe);
  if ((local_c != 0) &&
     (((*(byte *)(local_e + 0x20) == param_2 || (*(byte *)(local_e + 0x21) == param_2)) ||
      ((iVar4 == DAT_5b41_0567._2_2_ && (iVar2 == (int)DAT_5b41_0567)))))) {
    FUN_4551_03eb(local_c,0,&local_16);
    local_4 = *(int *)(iVar2 + 0x22) - DAT_5b41_0925;
    local_6 = *(int *)(iVar2 + 0x24) - DAT_5b41_0927;
    uVar3 = 0;
    if ((*(byte *)(iVar2 + 0xc) & 0x10) != 0) {
      local_4 = local_4 + ((*(int *)(iVar2 + 0x44) - local_16) - local_12);
      uVar3 = 2;
    }
    if ((*(byte *)(iVar2 + 0xc) & 0x20) != 0) {
      local_6 = local_6 + ((*(int *)(iVar2 + 0x46) - local_14) - local_10);
      uVar3 = uVar3 | 1;
    }
    if ((((iVar1 == 0x2d) || (iVar1 == 0x24)) || (iVar1 == 0x46)) &&
       ((*(byte *)(iVar2 + 0xe) & 0x10) != 0)) {
      local_8 = DAT_554c_42ca;
      iVar1 = *(int *)(iVar2 + 0xae) - DAT_5b41_0927;
      if ((iVar1 <= DAT_554c_42ca) && (DAT_554c_42ca = iVar1, iVar1 < DAT_554c_42c8)) {
        DAT_554c_42ca = DAT_554c_42c8 + 1;
      }
      FUN_4551_01dc(local_c,local_a,local_4,local_6,uVar3);
      DAT_554c_42ca = local_8;
    }
    else {
      FUN_4551_01dc(local_c,local_a,local_4,local_6,uVar3);
    }
  }
  return;
}

