// TIM2.EXE: FUN_406b_19d7 @ file 0x047287 Ghidra 0x42087
// Subsystem: sound | Size: 224 bytes


undefined2 __cdecl16far FUN_406b_19d7(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  
  uVar6 = 0;
  if ((param_1 != 0) &&
     (iVar4 = FUN_1000_0b20(param_1,0x3e4e), uVar3 = DAT_554c_42d8, uVar2 = DAT_554c_42d6,
     uVar1 = DAT_554c_42c3, DAT_554c_42c3 = uVar1, DAT_554c_42d6 = uVar2, DAT_554c_42d8 = uVar3,
     iVar4 != 0)) {
    DAT_554c_42d8 = DAT_554c_42d6;
    DAT_554c_42c3 = 0;
    if (DAT_554c_42e1 == -1) {
      DAT_53bd_0079 = 0x100;
    }
    else {
      DAT_53bd_0079 = 0x10;
    }
    if (DAT_53bd_0079 == 0x100) {
      DAT_53bd_007b = 8;
    }
    else {
      DAT_53bd_007b = 4;
    }
    DAT_53bd_007d = DAT_554c_49ac + DAT_5b41_1ae0;
    iVar5 = FUN_406b_1ab7(iVar4);
    if (((iVar5 == 0) || (iVar5 = FUN_406b_1bed(iVar4), iVar5 == 0)) ||
       (iVar5 = FUN_406b_1c8b(iVar4), iVar5 == 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
    FUN_1000_0c9d(iVar4);
    DAT_554c_42c3 = uVar1;
    DAT_554c_42d6 = uVar2;
    DAT_554c_42d8 = uVar3;
  }
  return uVar6;
}

