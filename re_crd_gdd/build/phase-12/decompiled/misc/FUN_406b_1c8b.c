// TIM2.EXE: FUN_406b_1c8b @ file 0x04753B Ghidra 0x4233B
// Subsystem: misc | Size: 286 bytes


undefined2 __cdecl16far FUN_406b_1c8b(undefined2 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined1 *puVar7;
  uint uVar8;
  int local_c;
  
  iVar2 = (DAT_554c_49aa / 8) * DAT_53bd_007b;
  FUN_1000_180a();
  FUN_1000_19df();
  uVar6 = 0;
  uVar3 = FUN_1000_180a();
  FUN_406b_1e45(param_1,0x74,0x53bd,4);
  FUN_406b_1da9(param_1,uVar3,uVar6);
  puVar4 = (undefined1 *)FUN_1000_127a(DAT_554c_49aa * 2);
  if (puVar4 == (undefined1 *)0x0) {
    uVar3 = 0;
  }
  else {
    for (uVar8 = 0; uVar8 < DAT_53bd_007d; uVar8 = uVar8 + 1) {
      if (uVar8 == DAT_554c_49ac) {
        DAT_554c_42d8 = 0xa000;
        DAT_554c_42d6 = 0xa000;
      }
      puVar7 = puVar4;
      for (local_c = 0; local_c < DAT_554c_49aa; local_c = local_c + 1) {
        uVar5 = uVar8;
        if ((int)DAT_554c_49ac <= (int)uVar8) {
          uVar5 = uVar8 - DAT_554c_49ac;
        }
        uVar1 = FUN_1a9e_5d60(local_c,uVar5);
        *puVar7 = uVar1;
        puVar7 = puVar7 + 1;
      }
      FUN_406b_17ef(puVar4,0x554c,puVar7,0x554c,DAT_554c_49aa);
      FUN_406b_1e45(param_1,puVar7,0x554c,iVar2);
    }
    FUN_1000_130c(puVar4);
    uVar3 = 1;
  }
  return uVar3;
}

