// TIM2.EXE: FUN_28eb_0a36 @ file 0x02EAE6 Ghidra 0x298E6
// Subsystem: misc | Size: 833 bytes


int __cdecl16far FUN_28eb_0a36(int param_1,int param_2,undefined4 param_3)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_30;
  int local_2e;
  int local_2c;
  int local_2a;
  int local_28;
  int local_26;
  int local_24;
  int local_22;
  int local_20;
  int local_1e;
  int *local_1c;
  int *local_1a;
  int local_18;
  int local_16;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  if ((((DAT_554c_02e4 != 0) || ((*(byte *)((int)param_3 + 0xf) & 0x10) == 0)) &&
      ((DAT_554c_02e4 == 0 || ((*(byte *)((int)param_3 + 0xf) & 0x10) != 0)))) &&
     (((((DAT_554c_02e4 == 0 || ((DAT_5b41_051f & 4) != 0)) ||
        ((*(byte *)((int)param_3 + 0xe) & 0x80) == 0)) &&
       ((DAT_5b41_04f0 != 1 || ((*(byte *)((int)param_3 + 0xc) & 4) != 0)))) &&
      ((DAT_5b41_04f0 != 2 || ((*(byte *)((int)param_3 + 0xc) & 1) != 0)))))) {
    local_4 = DAT_5b41_1b84;
    local_8 = DAT_5b41_1b84;
    local_6 = DAT_5b41_1b86;
    local_a = DAT_5b41_1b86;
    FUN_28eb_1599((int)param_3,param_3._2_2_,&local_30);
    local_16 = local_30;
    local_14 = local_2e;
    local_c = local_2e;
    local_e = local_30 + local_2c;
    local_10 = local_2e + local_2a;
    local_18 = *(int *)((int)param_3 + 0x58);
    if (local_18 == 0) {
      local_1e = 0;
      local_20 = 0;
    }
    else {
      local_1e = *(int *)(local_18 + 4);
      local_20 = *(int *)(local_18 + 2);
    }
    local_1a = (int *)*(int *)((int)param_3 + 0x76);
    if (local_1a == (int *)0x0) {
      local_22 = 0;
      local_24 = 0;
    }
    else {
      local_22 = local_1a[1];
      local_24 = *local_1a;
    }
    local_1c = (int *)*(undefined2 *)((int)param_3 + 0x78);
    if (local_1c == (int *)0x0) {
      local_26 = 0;
      local_28 = 0;
    }
    else {
      local_26 = local_1c[1];
      local_28 = *local_1c;
    }
    iVar5 = local_30;
    if ((param_1 != 0 || param_2 != 0) &&
       ((((param_2 == param_3._2_2_ && (param_1 == (int)param_3)) ||
         (((param_2 == local_1e && (param_1 == local_20)) ||
          ((param_2 == local_22 && (param_1 == local_24)))))) ||
        ((param_2 == local_26 && (param_1 == local_28)))))) {
      iVar5 = local_30 + -0x23;
      local_c = local_2e + -0x23;
      local_e = local_e + 0x23;
      local_10 = local_10 + 0x23;
    }
    if ((((iVar5 <= local_8) && (local_4 < local_e)) && (local_c <= local_a)) &&
       (local_6 < local_10)) {
      if ((local_18 != 0) && (DAT_5b41_0939 != 9)) {
        iVar5 = ((uint)*(byte *)((int)param_3 + 0x5a) + local_30) - *(int *)((int)param_3 + 0x5c);
        local_c = ((uint)*(byte *)((int)param_3 + 0x5b) + local_2e) - *(int *)((int)param_3 + 0x5c);
        local_e = *(int *)((int)param_3 + 0x5c) * 2 + iVar5;
        iVar2 = *(int *)((int)param_3 + 0x5c) * 2 + local_c;
        if ((*(int *)(local_18 + 4) == param_2) && (*(int *)(local_18 + 2) == param_1)) {
          iVar5 = iVar5 + -0x23;
          local_c = local_c + -0x23;
          local_e = local_e + 0x23;
        }
        if (((iVar5 <= local_8) && (local_4 < local_e)) &&
           ((local_c <= local_a && (local_6 < iVar2)))) {
          if ((*(int *)(local_18 + 8) == param_3._2_2_) && (*(int *)(local_18 + 6) == (int)param_3))
          {
            uVar1 = *(undefined2 *)(local_18 + 10);
            *(undefined2 *)(local_18 + 8) = *(undefined2 *)(local_18 + 0xc);
            *(undefined2 *)(local_18 + 6) = uVar1;
            *(int *)(local_18 + 0xc) = param_3._2_2_;
            *(int *)(local_18 + 10) = (int)param_3;
          }
          return *(int *)(local_18 + 2);
        }
      }
      local_12 = 0;
      piVar4 = local_1a;
      do {
        if (1 < local_12) {
          return (int)param_3;
        }
        if (((piVar4 != (int *)0x0) && (DAT_5b41_0939 != 9)) && (*(int *)((int)param_3 + 8) != 7)) {
          iVar3 = (int)param_3 + local_12 * 2;
          iVar5 = *(char *)(iVar3 + 0x7a) + local_30;
          iVar2 = iVar5 + -8;
          iVar3 = *(char *)(iVar3 + 0x7b) + local_2e;
          local_c = iVar3 + -4;
          local_e = iVar5 + 8;
          local_10 = iVar3 + 4;
          if ((piVar4[1] == param_2) && (*piVar4 == param_1)) {
            iVar2 = iVar5 + -0x2b;
            local_c = iVar3 + -0x27;
            local_e = iVar5 + 0x2b;
          }
          if (((iVar2 <= local_8) && (local_4 < local_e)) &&
             ((local_c <= local_a && (local_6 < local_10)))) {
            if ((piVar4[3] == param_3._2_2_) && (piVar4[2] == (int)param_3)) {
              FUN_28eb_08be(piVar4);
            }
            return *piVar4;
          }
        }
        local_12 = local_12 + 1;
        piVar4 = local_1c;
      } while( true );
    }
  }
  return 0;
}

