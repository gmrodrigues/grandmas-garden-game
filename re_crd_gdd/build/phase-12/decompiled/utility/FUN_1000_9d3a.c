// TIM2.EXE: FUN_1000_9d3a @ file 0x01EF3A Ghidra 0x19D3A
// Subsystem: utility | Size: 349 bytes


void FUN_1000_9d3a(char param_1,char param_2,char param_3,char param_4,char param_5,char param_6)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  undefined1 local_b6 [160];
  uint local_16;
  uint local_14;
  uint local_12;
  uint local_10;
  uint local_e;
  uint local_c;
  uint local_a;
  uint local_8;
  uint local_6;
  uint local_4;
  
  if (((DAT_554c_5e55 == '\0') && (DAT_554c_5e5b != 0)) && (param_1 == '\x01')) {
    bVar1 = param_5 + 1;
    bVar2 = param_4 + 1;
    param_3 = param_3 + '\x01';
    bVar3 = param_2 + 1;
    if (param_6 == '\x06') {
      local_4 = (uint)bVar2;
      local_6 = (uint)bVar1;
      FUN_1000_9881(local_6,local_4 + 1,param_3,bVar3,local_6,local_4);
      local_8 = (uint)bVar3;
      local_a = (uint)bVar1;
      FUN_1000_9709(local_a,local_8,local_a,local_8,local_b6);
      FUN_1000_9d12(param_3,bVar1,local_b6);
      uVar4 = (uint)bVar3;
      local_c = uVar4;
    }
    else {
      local_e = (uint)bVar2;
      local_10 = (uint)bVar1;
      FUN_1000_9881(local_10,local_e,param_3,bVar3 - 1,local_10,local_e + 1);
      local_12 = (uint)bVar2;
      local_14 = (uint)bVar1;
      FUN_1000_9709(local_14,local_12,local_14,local_12,local_b6);
      FUN_1000_9d12(param_3,bVar1,local_b6);
      uVar4 = (uint)bVar2;
      local_16 = uVar4;
    }
    FUN_1000_976b(bVar1,uVar4,param_3,uVar4,local_b6);
  }
  else {
    FUN_1000_913e();
  }
  return;
}

