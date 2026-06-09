// TIM2.EXE: FUN_2424_0771 @ file 0x029BB1 Ghidra 0x249B1
// Subsystem: misc | Size: 267 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_2424_0771(undefined2 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = 0x2424;
  if (DAT_5b41_0521 != 0) {
    uVar2 = 0x2321;
    FUN_2321_0425(1);
  }
  if ((DAT_5b41_1b90 == 0x1f) && ((_DAT_5b41_1b94 & 2) != 0)) {
    func_0x00054fa0(uVar2,0x2c4);
  }
  FUN_406b_0579(param_1,0);
  FUN_2e67_0a1f();
  FUN_311b_06b8();
  if ((((DAT_5b41_1b9e == 0 && DAT_5b41_1ba0 == 0) && (DAT_5b41_1ba2 == 0 && DAT_5b41_1ba4 == 0)) &&
      (_DAT_5b41_1b94 == 1)) && ((DAT_5b41_1b8e == 0x10 || (DAT_5b41_1b8e == 0x16)))) {
    DAT_5b41_04f7 = 1;
    iVar1 = FUN_406b_03cb(0xfffc,0);
    FUN_406b_04d8(0xffff);
    if (DAT_5b41_1b8e == 0x10) {
      uVar2 = 0x2a;
    }
    else {
      uVar2 = 0x29;
    }
    FUN_406b_03cb(uVar2,0xffff);
    DAT_5b41_1b92 = 0;
    while (((DAT_5b41_1b92 == 0 && (_DAT_5b41_1b88 == 0)) && (DAT_5b41_1b8a == 0))) {
      FUN_2424_000c();
    }
    while (((DAT_5b41_1b92 != 0 || (_DAT_5b41_1b88 != 0)) || (DAT_5b41_1b8a != 0))) {
      FUN_2424_000c();
    }
    DAT_5b41_04f7 = 0;
    if (iVar1 == -2) {
      FUN_406b_053a();
    }
    else {
      FUN_406b_03cb(iVar1,0);
    }
  }
  return;
}

