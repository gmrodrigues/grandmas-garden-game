// TIM2.EXE: FUN_4a54_0346 @ file 0x04FA86 Ghidra 0x4A886
// Subsystem: misc | Size: 568 bytes


void __cdecl16near FUN_4a54_0346(int param_1,int param_2,uint param_3,uint param_4)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined1 local_112 [256];
  int local_12;
  int local_10;
  undefined1 *local_e;
  char local_b;
  undefined4 local_a;
  int local_6;
  int local_4;
  
  if ((param_3 != 0) && (param_4 != 0)) {
    if ((param_3 == 1) && (param_4 == 1)) {
      local_b = (*DAT_554c_5670)(8);
      if ((local_b != '\0') || (DAT_5b41_285e != 0)) {
        (*DAT_554c_566c)(0x4000,param_1,param_2,local_b);
        return;
      }
    }
    else {
      local_a = (ulong)param_3 * (ulong)param_4;
      local_12 = 8;
      if (((int)((ulong)local_a >> 0x10) == 0) && ((char)((ulong)local_a >> 8) == '\0')) {
        local_12 = 0;
        for (bVar1 = (char)local_a - 1; bVar1 != 0; bVar1 = bVar1 >> 1) {
          local_12 = local_12 + 1;
        }
      }
      bVar1 = (*DAT_554c_5670)(local_12);
      DAT_5b41_2848 = 0;
      uVar3 = (uint)bVar1;
      for (; bVar1 != 0; bVar1 = bVar1 >> 1) {
        DAT_5b41_2848 = DAT_5b41_2848 + 1;
      }
      local_10 = uVar3 + 1;
      iVar6 = local_a._2_2_;
      uVar3 = FUN_1000_180a();
      uVar4 = local_10 * 8;
      uVar5 = uVar3 + uVar4;
      uVar7 = iVar6 + ((int)uVar4 >> 0xf) + (uint)CARRY2(uVar3,uVar4);
      uVar3 = local_a._2_2_;
      uVar4 = FUN_1000_199e();
      if ((uVar3 <= uVar7) && ((uVar7 != uVar3 || (uVar4 <= uVar5)))) {
        local_6 = param_1 + param_3;
        local_4 = param_2 + param_4;
        if (DAT_5b41_285c != (code *)0x0) {
          DAT_5b41_2848 = 8;
          DAT_5b41_285a = DAT_554c_5670;
          (*DAT_5b41_285c)(param_1,param_2,local_6,local_4);
          return;
        }
        for (; iVar6 = param_2, param_1 < local_6; param_1 = param_1 + 1) {
          for (; iVar6 < local_4; iVar6 = iVar6 + 1) {
            local_b = FUN_4a54_1054(8);
            if (local_b != '\0') {
              FUN_1a9e_5d92(param_1,iVar6,local_b);
            }
          }
        }
        return;
      }
      if (local_10 == 1) {
        DAT_554c_42cd = (*DAT_554c_5670)(8);
        if ((DAT_554c_42cd != '\0') || (DAT_5b41_285e != 0)) {
          DAT_554c_42ce = DAT_554c_42cd;
          (*DAT_554c_5668)(0x4000,param_1,param_2,param_3,param_4);
          return;
        }
        DAT_554c_42cd = 0;
        DAT_554c_42ce = 0;
      }
      else {
        DAT_5b41_284a = local_112;
        local_e = DAT_5b41_284a;
        while (iVar6 = local_10 + -1, 0 < local_10) {
          local_10 = iVar6;
          uVar2 = (*DAT_554c_5670)(8);
          *local_e = uVar2;
          local_e = local_e + 1;
        }
        local_6 = param_1 + param_3;
        local_4 = param_2 + param_4;
        local_10 = iVar6;
        if (DAT_5b41_285c != (code *)0x0) {
          DAT_5b41_285a = (code *)0x42;
          (*DAT_5b41_285c)(param_1,param_2,local_6,local_4);
          return;
        }
        for (; iVar6 = param_2, param_1 < local_6; param_1 = param_1 + 1) {
          for (; iVar6 < local_4; iVar6 = iVar6 + 1) {
            bVar1 = FUN_4a54_1054(DAT_5b41_2848);
            local_b = DAT_5b41_284a[bVar1];
            if (local_b != '\0') {
              FUN_1a9e_5d92(param_1,iVar6,local_b);
            }
          }
        }
      }
    }
  }
  return;
}

