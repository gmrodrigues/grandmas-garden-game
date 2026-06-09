// TIM2.EXE: FUN_311b_033a @ file 0x0366EA Ghidra 0x314EA
// Subsystem: misc | Size: 894 bytes


undefined2 __cdecl16far FUN_311b_033a(int param_1)

{
  undefined2 uVar1;
  undefined2 in_DX;
  undefined2 *puVar2;
  int iVar3;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined4 local_6;
  
  if (((iRam000557bc == 1) || (iRam000557bc == 6)) && ((DAT_5b41_0939._1_1_ & 0x80) == 0)) {
    local_6._0_2_ = (undefined2 *)FUN_460e_0f42(0x2329);
    if ((param_1 == 0) &&
       (((((DAT_5b41_0d10 != 0 || ((DAT_5b41_1b88 & 2) == 0)) ||
          ((iRam000557bc != 1 && (iRam000557bc != 6)))) ||
         ((DAT_5b41_1b84 < *(int *)((int)(undefined2 *)local_6 + 0x14) ||
          (*(int *)((int)(undefined2 *)local_6 + 0x14) + *(int *)((int)(undefined2 *)local_6 + 0x18)
           <= DAT_5b41_1b84)))) ||
        ((DAT_5b41_1b86 < *(int *)((int)(undefined2 *)local_6 + 0x16) ||
         (((*(int *)((int)(undefined2 *)local_6 + 0x16) +
            *(int *)((int)(undefined2 *)local_6 + 0x1a) <= DAT_5b41_1b86 || (5000 < DAT_554c_2f1c))
          || ((DAT_5b41_1ae4 == 0x554c && (DAT_5b41_1ae2 == (undefined2 *)&DAT_5b41_0cbe)))))))))) {
      if ((DAT_5b41_1ae4 == 0x554c) && (DAT_5b41_1ae2 == (undefined2 *)&DAT_5b41_0cbe)) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      DAT_554c_42d8 = DAT_554c_42d2;
      DAT_554c_42d6 = 0xa000;
      local_6._2_2_ = in_DX;
      FUN_406b_053a();
      FUN_406b_0880(0,0,DAT_554c_49aa,DAT_554c_3e4a);
      FUN_406b_04d8(0);
      DAT_554c_42d6 = DAT_554c_42d4;
      DAT_5b41_0cc0 = 0;
      DAT_5b41_0cbe = 0;
      DAT_5b41_0cc4 = 0;
      DAT_5b41_0cc2 = 0;
      DAT_5b41_0cca = 65000;
      DAT_5b41_0ccc = 4;
      DAT_5b41_0cce = 65000;
      DAT_5b41_0cd0 = 0xfffd;
      DAT_5b41_0cd2 = *(undefined2 *)((int)(undefined2 *)local_6 + 0x14);
      DAT_5b41_0cd4 = *(int *)((int)(undefined2 *)local_6 + 0x16) + 1;
      DAT_5b41_0cd6 = *(undefined2 *)((int)(undefined2 *)local_6 + 0x18);
      DAT_5b41_0cd8 = *(undefined2 *)((int)(undefined2 *)local_6 + 0x1a);
      DAT_5b41_0cdc = DAT_51a7_0124;
      DAT_5b41_0cda = DAT_51a7_0122;
      DAT_5b41_0ce0 = DAT_51a7_0128;
      DAT_5b41_0cde = DAT_51a7_0126;
      DAT_5b41_0ce2 = 0;
      DAT_5b41_0ce4 = 2;
      DAT_5b41_0ce6 = 0;
      DAT_5b41_0ce8 = 3;
      DAT_5b41_0d0a = 0;
      DAT_5b41_0d0c = 5;
      DAT_5b41_0d0e = DAT_5b41_0535;
      DAT_5b41_0cf2 = 0;
      DAT_5b41_0cf4 = DAT_5b41_0535;
      DAT_5b41_0d00 = 5;
      DAT_5b41_0cfe = 0x702;
      DAT_5b41_0d04 = 0x554c;
      DAT_5b41_0d02 = (undefined1 *)&DAT_5b41_05b9;
      DAT_5b41_0d06 = 400;
      local_6 = &DAT_5b41_0cbe;
      DAT_5b41_0cf6 = DAT_5b41_0cd2;
      DAT_5b41_0cf8 = DAT_5b41_0cd4;
      DAT_5b41_0cfa = DAT_5b41_0cd6;
      DAT_5b41_0cfc = DAT_5b41_0cd8;
      FUN_460e_0b44((undefined2 *)&DAT_5b41_0cbe,0x554c);
      DAT_5b41_1b8e = 0;
      DAT_5b41_1b90 = 0;
      DAT_5b41_1b92 = 0;
      if (param_1 != 0) {
        FUN_460e_14c4(DAT_5b41_0cca,400,0,0);
      }
      do {
        DAT_5b41_0d10 = 1;
        FUN_460e_1092(65000,0,0);
        if (DAT_5b41_1b92 != 0) {
          DAT_554c_02e6 = 1;
        }
        DAT_554c_42d8 = DAT_554c_42d2;
        (*(code *)((undefined2 *)local_6)[0xe])(0x460e,(undefined2 *)local_6,local_6._2_2_);
        if ((DAT_5450_000e == 0) && (DAT_5450_0010 == 0)) {
          DAT_554c_42d6 = DAT_554c_42d2;
          DAT_554c_42d8 = 0xa000;
          for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
            if (((undefined2 *)&DAT_5b41_0d1c)[iVar3 * 4] != 0) {
              if (DAT_5b41_1b96 != 0) {
                FUN_406b_053a();
              }
              FUN_406b_0880(((undefined2 *)&DAT_5b41_0d16)[iVar3 * 4] + -2,
                            ((undefined2 *)&DAT_5b41_0d18)[iVar3 * 4] + -1,
                            ((undefined2 *)&DAT_5b41_0d1a)[iVar3 * 4] + 4,
                            ((undefined2 *)&DAT_5b41_0d1c)[iVar3 * 4] + 2);
              ((undefined2 *)&DAT_5b41_0d1c)[iVar3 * 4] = 0;
            }
          }
          uVar1 = 0xffff;
        }
        else {
          DAT_554c_42d6 = DAT_554c_42d2;
          DAT_554c_42d8 = 0xa000;
          if (DAT_5b41_1b96 != 0) {
            FUN_406b_053a();
          }
          uVar1 = (undefined2)((ulong)local_6 >> 0x10);
          puVar2 = (undefined2 *)local_6;
          FUN_406b_0880(puVar2[10],puVar2[0xb],puVar2[0xc],puVar2[0xd]);
          uVar1 = 0;
        }
        FUN_406b_04d8(uVar1);
        DAT_554c_42d6 = DAT_554c_42d4;
        FUN_2321_0597(3);
        FUN_2424_000c();
        if (DAT_5b41_1b98 == 0) {
          DAT_5b41_1b86 = DAT_554c_49ac;
        }
      } while (DAT_5b41_1ae2 != (undefined2 *)0x0 || DAT_5b41_1ae4 != 0);
      local_c = 0;
      local_e = 0;
      local_a = DAT_554c_49aa;
      local_8 = DAT_554c_3e4a;
      FUN_2424_1e00(&local_e);
      FUN_460e_0d51(((undefined2 *)local_6)[6],0);
      DAT_554c_42d8 = DAT_554c_42d2;
      FUN_2424_01b2();
      DAT_5b41_0d10 = 0;
      DAT_5b41_0d14 = 1;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

