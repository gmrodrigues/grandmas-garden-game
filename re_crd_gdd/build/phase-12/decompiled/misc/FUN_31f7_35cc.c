// TIM2.EXE: FUN_31f7_35cc @ file 0x03A73C Ghidra 0x3553C
// Subsystem: misc | Size: 608 bytes


void __cdecl16far FUN_31f7_35cc(undefined4 param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_12;
  int local_e;
  int iStack_c;
  int local_a;
  int local_8;
  uint local_6;
  int local_4;
  
  FUN_28eb_4f3d((int)param_1,param_1._2_2_,0x3000,0xffe0,0x20,0,0);
  local_12 = 0;
  bVar1 = false;
  local_4 = 0;
  local_6 = 400;
  local_e = (int)param_1;
  iVar4 = param_1._2_2_;
LAB_31f7_37d4:
  iStack_c = *(int *)(local_e + 0x8e);
  local_e = *(int *)(local_e + 0x8c);
  do {
    if (local_e == 0 && iStack_c == 0) {
      if (!bVar1) {
        local_12 = 0;
      }
      *(int *)((int)param_1 + 0x70) = local_12._2_2_;
      *(int *)((int)param_1 + 0x6e) = (int)local_12;
      if ((int)local_12 != 0 || local_12._2_2_ != 0) {
        *(int *)((int)local_12 + 0xb4) = *(int *)((int)local_12 + 0xb4) + 1;
        FUN_28eb_374a((int)param_1,param_1._2_2_);
      }
      return;
    }
    if ((((((*(int *)(local_e + 8) == 0x19) || (*(int *)(local_e + 8) == 0x1d)) ||
          (*(int *)(local_e + 8) == 0x22)) ||
         ((*(int *)(local_e + 8) == 0x2d || (*(int *)(local_e + 8) == 0x4b)))) ||
        ((*(int *)(local_e + 8) == 0x4e ||
         ((*(int *)(local_e + 8) == 0x4f || (*(int *)(local_e + 8) == 0x8a)))))) &&
       (*(int *)(local_e + 0x10) != 0)) {
      if (!bVar1) {
        if ((*(byte *)((int)param_1 + 0xc) & 0x10) == 0) {
          if (*(int *)(local_e + 0x90) < 0) goto LAB_31f7_367e;
        }
        else if (0 < *(int *)(local_e + 0x90)) {
LAB_31f7_367e:
          bVar1 = true;
        }
        if (*(int *)(local_e + 8) == 0x19) {
          if (((*(uint *)(local_e + 0xc) ^ *(uint *)((int)param_1 + 0xc)) & 0x10) != 0)
          goto LAB_31f7_36e8;
        }
        else if (*(int *)(local_e + 8) == 0x4b) {
          if (*(int *)(local_e + 0x10) < DAT_5b41_09a5) goto LAB_31f7_36e8;
        }
        else if (*(int *)(local_e + 8) == 0x4e) {
          if (*(int *)(local_e + 0x10) < DAT_5b41_09a7) {
LAB_31f7_36e8:
            bVar1 = false;
          }
        }
        else if ((*(int *)(local_e + 8) == 0x4f) && (*(int *)(local_e + 0x16) != 1))
        goto LAB_31f7_36e8;
      }
    }
    else if ((((*(byte *)(local_e + 0xe) & 4) != 0) && (*(int *)(local_e + 0x16) == 0)) &&
            (local_4 == 0)) {
      bVar2 = false;
      if ((*(byte *)((int)param_1 + 0xc) & 0x10) == 0) {
        if (0 < *(int *)(local_e + 0x90)) goto LAB_31f7_3731;
      }
      else if (*(int *)(local_e + 0x90) < 0) {
LAB_31f7_3731:
        bVar2 = true;
      }
      FUN_31f7_3867((int)param_1,param_1._2_2_,local_e,iStack_c,&local_8,&local_a);
      if ((0x2f < local_8) || (local_8 < local_a)) {
        bVar2 = false;
      }
      if (bVar2) {
        if ((*(int *)((int)param_1 + 0x70) == iStack_c) &&
           (*(int *)((int)param_1 + 0x6e) == local_e)) {
          local_12 = CONCAT22(iStack_c,local_e);
          local_4 = 1;
        }
        else {
          uVar3 = (int)*(uint *)(local_e + 0x90) >> 0xf;
          if ((int)((*(uint *)(local_e + 0x90) ^ uVar3) - uVar3) <
              (int)((local_6 ^ (int)local_6 >> 0xf) - ((int)local_6 >> 0xf))) {
            local_6 = *(uint *)(local_e + 0x90);
            local_12 = CONCAT22(iStack_c,local_e);
          }
        }
      }
    }
    iVar4 = iStack_c;
    if ((!bVar1) || (local_4 == 0)) goto LAB_31f7_37d4;
    local_e = 0;
    iStack_c = 0;
  } while( true );
}

