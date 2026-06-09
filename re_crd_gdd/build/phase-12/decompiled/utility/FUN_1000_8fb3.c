// TIM2.EXE: FUN_1000_8fb3 @ file 0x01E1B3 Ghidra 0x18FB3
// Subsystem: utility | Size: 291 bytes


undefined1 FUN_1000_8fb3(undefined2 param_1,int param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  byte bVar3;
  undefined2 unaff_SS;
  undefined4 uVar4;
  undefined2 local_a;
  undefined1 local_7;
  uint local_6;
  uint local_4;
  
  local_7 = 0;
  bVar3 = FUN_1000_a02d();
  local_4 = (uint)bVar3;
  local_6 = FUN_1000_a02d();
  local_6 = local_6 >> 8;
  while (iVar2 = param_2 + -1, param_2 != 0) {
    puVar1 = param_3 + 1;
    local_7 = *param_3;
    switch(local_7) {
    case 7:
      FUN_1000_913e();
      break;
    case 8:
      if ((int)(uint)DAT_554c_5e4c < (int)local_4) {
        local_4 = local_4 - 1;
      }
      break;
    default:
      if ((DAT_554c_5e55 == '\0') && (DAT_554c_5e5b != 0)) {
        local_a = CONCAT11(DAT_554c_5e50,local_7);
        uVar4 = FUN_1000_270f(local_6 + 1,local_4 + 1);
        FUN_1000_2733(1,&local_a,unaff_SS,uVar4);
      }
      else {
        FUN_1000_913e();
        FUN_1000_913e();
      }
      local_4 = local_4 + 1;
      break;
    case 10:
      local_6 = local_6 + 1;
      break;
    case 0xd:
      local_4 = (uint)DAT_554c_5e4c;
    }
    if ((int)(uint)DAT_554c_5e4e < (int)local_4) {
      local_4 = (uint)DAT_554c_5e4c;
      local_6 = local_6 + DAT_554c_5b2a;
    }
    param_2 = iVar2;
    param_3 = puVar1;
    if ((int)(uint)DAT_554c_5e4f < (int)local_6) {
      FUN_1000_9d3a(1,CONCAT11(DAT_554c_5e50,DAT_554c_5e4f),CONCAT11(DAT_554c_5e4f,DAT_554c_5e4e),
                    CONCAT11(DAT_554c_5e4e,DAT_554c_5e4d),CONCAT11(DAT_554c_5e4d,DAT_554c_5e4c),6);
      local_6 = local_6 - 1;
    }
  }
  FUN_1000_913e();
  return local_7;
}

