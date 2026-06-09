// TIM2.EXE: FUN_406b_000c @ file 0x0458BC Ghidra 0x406BC
// Subsystem: sound | Size: 396 bytes


void __cdecl16far FUN_406b_000c(int param_1,uint param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined2 uVar8;
  
  param_3 = param_3 + (param_1 % 8 - param_3 % 8);
  uVar7 = param_1 - param_1 % 8;
  if (DAT_554c_42c3 != '\0') {
    if ((int)uVar7 < (int)DAT_554c_42c4) {
      param_3 = param_3 - (DAT_554c_42c4 - uVar7);
      uVar7 = DAT_554c_42c4;
    }
    if (DAT_554c_42c6 < (int)(uVar7 + param_3 + -1)) {
      param_3 = (DAT_554c_42c6 - uVar7) + 1;
    }
    if ((int)param_2 < (int)DAT_554c_42c8) {
      param_4 = param_4 - (DAT_554c_42c8 - param_2);
      param_2 = DAT_554c_42c8;
    }
    if (DAT_554c_42ca < (int)(param_2 + param_4 + -1)) {
      param_4 = (DAT_554c_42ca - param_2) + 1;
    }
  }
  if ((int)uVar7 < 0) {
    param_3 = param_3 + uVar7;
    uVar7 = 0;
  }
  if (DAT_554c_49aa < (int)(uVar7 + param_3)) {
    param_3 = DAT_554c_49aa - uVar7;
  }
  if ((int)param_2 < 0) {
    param_4 = param_4 + param_2;
    param_2 = 0;
  }
  if (DAT_554c_49ac < (int)(param_2 + param_4)) {
    param_4 = DAT_554c_49ac - param_2;
  }
  if ((0 < param_3) && (0 < param_4)) {
    uVar8 = 8;
    iVar6 = DAT_554c_49aa >> 0xf;
    uVar1 = FUN_1000_180a(8,0);
    pbVar2 = (byte *)FUN_1000_18f0(0x1000,uVar1 + uVar7,
                                   iVar6 + ((int)uVar7 >> 0xf) + (uint)CARRY2(uVar1,uVar7),uVar8);
    uVar8 = DAT_554c_42d8;
    iVar6 = (param_3 + 7) / 8;
    iVar3 = DAT_554c_49aa / 8 - iVar6;
    if ((param_2 & 1) == 0) {
      bVar4 = 0xaa;
    }
    else {
      bVar4 = 0x55;
    }
    FUN_1a9e_2122();
    if (param_5 == 0) {
      do {
        out(0x3ce,CONCAT11(bVar4,8));
        bVar4 = bVar4 ^ 0xff;
        iVar5 = iVar6;
        do {
          *pbVar2 = 0;
          pbVar2 = pbVar2 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        pbVar2 = pbVar2 + iVar3;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
    else {
      do {
        out(0x3ce,CONCAT11(bVar4,8));
        bVar4 = bVar4 ^ 0xff;
        iVar5 = iVar6;
        do {
          *pbVar2 = *pbVar2 | 0xf;
          pbVar2 = pbVar2 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        pbVar2 = pbVar2 + iVar3;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
  }
  return;
}

