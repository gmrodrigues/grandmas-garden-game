// TIM2.EXE: FUN_406b_0880 @ file 0x046130 Ghidra 0x40F30
// Subsystem: sound | Size: 440 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_406b_0880(uint param_1,int param_2,int param_3,int param_4)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 unaff_SS;
  undefined2 local_18 [9];
  int local_6;
  uint local_4;
  
  local_4 = param_1 & 0xfff8;
  local_6 = (param_1 + param_3 + 7 & 0xfff8) - param_1;
  _DAT_53bd_004a = 1;
  if ((((DAT_53bd_0038 == 0) || (DAT_53bd_0006 == -2)) ||
      ((DAT_554c_42d6 != DAT_554c_42d4 && (DAT_554c_42d8 != DAT_554c_42d4)))) ||
     (((((int)(local_4 + local_6) <= DAT_53bd_0008 || (DAT_53bd_0008 + DAT_53bd_000c < (int)local_4)
        ) || (param_2 + param_4 <= DAT_53bd_000a)) || (DAT_53bd_000a + DAT_53bd_000e < param_2)))) {
    FUN_1a9e_48f0(0x406b,param_1,param_2,param_3,param_4);
  }
  else if (((DAT_53bd_0052 & 8) == 0) || (DAT_554c_42d6 == DAT_554c_42d4)) {
    DAT_53bd_0004 = 0xfffe;
    FUN_406b_111b(0);
    FUN_1a9e_48f0(0x406b,param_1,param_2,param_3,param_4);
    DAT_53bd_0004 = DAT_53bd_0042;
    FUN_406b_111b(0);
  }
  else {
    DAT_53bd_0016 = DAT_53bd_0004;
    FUN_406b_111b(1);
    FUN_1a9e_48f0(0x406b,param_1,param_2,param_3,param_4);
    puVar4 = (undefined2 *)0x4;
    puVar5 = local_18;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar5;
      puVar5 = puVar5 + 1;
      puVar1 = puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = *puVar1;
    }
    puVar5 = (undefined2 *)0x16;
    puVar4 = (undefined2 *)0x4;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar4;
      puVar4 = puVar4 + 1;
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      *puVar2 = *puVar1;
    }
    DAT_53bd_0016 = 0xfffe;
    FUN_406b_111b(1);
    puVar5 = local_18;
    puVar4 = (undefined2 *)0x16;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar4;
      puVar4 = puVar4 + 1;
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      *puVar2 = *puVar1;
    }
    DAT_53bd_0018 = 0xfffe;
  }
  _DAT_53bd_004a = 0;
  return;
}

