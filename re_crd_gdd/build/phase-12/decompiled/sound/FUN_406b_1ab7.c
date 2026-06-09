// TIM2.EXE: FUN_406b_1ab7 @ file 0x047367 Ghidra 0x42167
// Subsystem: sound | Size: 310 bytes


undefined2 __cdecl16far FUN_406b_1ab7(undefined2 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  FUN_1000_180a();
  FUN_1000_19df();
  uVar3 = FUN_1000_180a();
  uVar2 = DAT_53bd_0079 * 3;
  uVar1 = uVar3 + uVar2;
  FUN_406b_1e45(param_1,0x60,0x53bd,4);
  FUN_406b_1da9(param_1,uVar1 + 0x30,iVar4 + (uint)CARRY2(uVar3,uVar2) + (uint)(0xffcf < uVar1));
  FUN_406b_1e45(param_1,0x65,0x53bd,4);
  FUN_406b_1e45(param_1,0x6a,0x53bd,4);
  FUN_406b_1da9(param_1,0x14,0);
  FUN_406b_1dff(param_1,DAT_554c_49aa);
  FUN_406b_1dff(param_1,DAT_53bd_007d);
  FUN_406b_1dff(param_1,0);
  FUN_406b_1dff(param_1,0);
  FUN_406b_1e2c(param_1,DAT_53bd_007b);
  FUN_406b_1e2c(param_1,0);
  FUN_406b_1e2c(param_1,0);
  FUN_406b_1e2c(param_1,0);
  FUN_406b_1dff(param_1,0);
  FUN_406b_1dff(param_1,0x101);
  FUN_406b_1dff(param_1,DAT_554c_49aa);
  FUN_406b_1dff(param_1,DAT_53bd_007d);
  return 1;
}

