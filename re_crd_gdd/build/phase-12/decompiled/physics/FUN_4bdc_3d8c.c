// TIM2.EXE: FUN_4bdc_3d8c @ file 0x054D4C Ghidra 0x4FB4C
// Subsystem: physics | Size: 484 bytes


undefined2 __cdecl16far FUN_4bdc_3d8c(undefined2 param_1,char param_2)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  uint local_10;
  undefined4 local_e;
  undefined2 local_a [2];
  uint local_6;
  int local_4;
  
  FUN_1000_0d10(&local_6,4,1,param_1);
  FUN_1000_0d10(&local_10,2,1,param_1);
  iVar3 = 0x14;
  puVar1 = (undefined2 *)FUN_2e67_0edd(0x14,0,3);
  local_e = (undefined2 *)CONCAT22(iVar3,puVar1);
  if (puVar1 == (undefined2 *)0x0 && iVar3 == 0) {
    return 0;
  }
  puVar1[5] = local_10;
  FUN_1000_0d10(&local_10,1,1,param_1);
  ((undefined2 *)local_e)[6] = local_10 & 0xff;
  FUN_1000_0d10(&local_10,1,1,param_1);
  uVar6 = (undefined2)((ulong)local_e >> 0x10);
  puVar1 = (undefined2 *)local_e;
  puVar1[9] = (uint)(byte)local_10;
  if ((puVar1[9] & 1) == 0) {
    uVar2 = 7;
  }
  else {
    uVar2 = 4;
  }
  uVar4 = local_6 - 4;
  local_4 = local_4 + -1 + (uint)(3 < local_6);
  puVar1[3] = 0;
  puVar1[2] = 0;
  local_6 = uVar4;
  if (param_2 != 'c') {
    if (DAT_554c_5758 == 0) {
      iVar3 = FUN_4bdc_2e9c(param_1,uVar4,local_4,local_a,uVar2);
      uVar6 = (undefined2)((ulong)local_e >> 0x10);
      puVar1 = (undefined2 *)local_e;
      puVar1[3] = uVar4;
      puVar1[2] = iVar3;
      if (iVar3 == 0 && uVar4 == 0) {
        FUN_2e67_10e9(puVar1,uVar6,3);
        return 0;
      }
    }
    else {
      iVar3 = FUN_4bdc_2914(param_1,uVar4,local_4,local_a,uVar2);
      uVar6 = (undefined2)((ulong)local_e >> 0x10);
      puVar1 = (undefined2 *)local_e;
      puVar1[3] = uVar4;
      puVar1[2] = iVar3;
      if (iVar3 == 0 && uVar4 == 0) {
        FUN_2e67_10e9(puVar1,uVar6,3);
        return 0;
      }
    }
LAB_4bdc_3f47:
    uVar6 = (undefined2)((ulong)local_e >> 0x10);
    puVar1 = (undefined2 *)local_e;
    puVar1[1] = DAT_554c_5736;
    *local_e = DAT_554c_5734;
    puVar1[4] = local_a[0];
    DAT_554c_5736 = uVar6;
    DAT_554c_5734 = puVar1;
    return 1;
  }
  iVar3 = FUN_2e67_0edd(uVar4,local_4,uVar2);
  uVar6 = (undefined2)((ulong)local_e >> 0x10);
  puVar1 = (undefined2 *)local_e;
  puVar1[3] = uVar4;
  puVar1[2] = iVar3;
  if (iVar3 != 0 || uVar4 != 0) {
    iVar5 = 1;
    iVar3 = FUN_1000_0de2(puVar1[2],puVar1[3],local_6,local_4,1,0,param_1);
    if ((iVar5 == 0) && (iVar3 == 1)) goto LAB_4bdc_3f47;
  }
  FUN_2e67_10e9((undefined2 *)local_e,local_e._2_2_,3);
  return 0;
}

