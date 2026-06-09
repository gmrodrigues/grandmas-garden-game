// TIM2.EXE: FUN_406b_0579 @ file 0x045E29 Ghidra 0x40C29
// Subsystem: sound | Size: 775 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void __cdecl16far FUN_406b_0579(int param_1,int param_2)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  undefined2 local_14 [9];
  
  uVar6 = 0x406b;
  FUN_406b_03cb(0xffff,0xffff);
  DAT_53bd_0054 = 1;
  if ((DAT_5b41_1b96 == 0) &&
     ((((DAT_53bd_0052 & 8) == 0 || (param_2 != 0)) || (DAT_53bd_0046 != 0 || DAT_53bd_0048 != 0))))
  {
    DAT_53bd_0016 = DAT_53bd_0004;
    DAT_53bd_0018 = -2;
    FUN_406b_111b(1);
  }
  if ((DAT_53bd_0052 & 8) == 0) {
    _DAT_53bd_004a = 1;
    if ((DAT_53bd_0046 == 0 && DAT_53bd_0048 == 0) && (param_1 != 0)) {
      uVar6 = 1;
    }
    else {
      uVar6 = 0;
    }
    FUN_1a9e_4d29(0x406b,uVar6);
    if (DAT_5b41_1b96 == 0) {
      puVar4 = (undefined2 *)0x4;
      puVar5 = local_14;
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
      puVar5 = local_14;
      puVar4 = (undefined2 *)0x16;
      for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        puVar2 = puVar4;
        puVar4 = puVar4 + 1;
        puVar1 = puVar5;
        puVar5 = puVar5 + 1;
        *puVar2 = *puVar1;
      }
    }
    _DAT_53bd_004a = 0;
    DAT_554c_42d6 = DAT_554c_42d4;
    DAT_554c_42d8 = DAT_554c_42d2;
    if (DAT_53bd_0046 != 0 || DAT_53bd_0048 != 0) {
      FUN_1a9e_2342(DAT_53bd_0046,DAT_53bd_0048);
      DAT_53bd_0048 = 0;
      DAT_53bd_0046 = 0;
    }
    if ((param_2 == 0) && (DAT_5b41_1b96 == 0)) {
      if (DAT_53bd_0018 != -2) {
        FUN_1a9e_5dc4(0x1a9e,DAT_53bd_0024,DAT_53bd_0026,DAT_53bd_001a,DAT_53bd_001c,DAT_53bd_001e,
                      DAT_53bd_0020);
      }
    }
    else if (param_2 != 0) {
      _DAT_53bd_004a = 1;
      FUN_1a9e_48f0(0x1a9e,0,0,DAT_554c_49aa,DAT_554c_49ac);
      if ((DAT_53bd_0006 != -2) && (DAT_5b41_1b96 == 0)) {
        FUN_1a9e_5dc4(0x1a9e,DAT_53bd_0012,DAT_53bd_0014,DAT_53bd_0008,DAT_53bd_000a,DAT_53bd_000c,
                      DAT_53bd_000e);
      }
      _DAT_53bd_004a = 0;
    }
  }
  else if ((param_2 != 0) || (DAT_53bd_0046 != 0 || DAT_53bd_0048 != 0)) {
    _DAT_53bd_004a = 1;
    if (param_2 != 0) {
      DAT_554c_42d8 = DAT_554c_42d4;
      DAT_554c_42d6 = DAT_554c_42d2;
      uVar6 = 0x1a9e;
      FUN_1a9e_48f0(0x406b,0,0,DAT_554c_49aa,DAT_554c_49ac);
      DAT_554c_42d8 = DAT_554c_42d2;
      DAT_554c_42d6 = DAT_554c_42d4;
    }
    if ((DAT_53bd_0018 != -2) && (DAT_5b41_1b96 == 0)) {
      FUN_1a9e_5dc4(uVar6,DAT_53bd_0024,DAT_53bd_0026,DAT_53bd_001a,DAT_53bd_001c,DAT_53bd_001e,
                    DAT_53bd_0020);
    }
    _DAT_53bd_004a = 0;
    if (DAT_53bd_0046 != 0 || DAT_53bd_0048 != 0) {
      FUN_1a9e_2342(DAT_53bd_0046,DAT_53bd_0048);
      DAT_53bd_0048 = 0;
      DAT_53bd_0046 = 0;
    }
  }
  DAT_53bd_0054 = 0;
  return;
}

