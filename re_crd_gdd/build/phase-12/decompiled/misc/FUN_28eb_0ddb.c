// TIM2.EXE: FUN_28eb_0ddb @ file 0x02EE8B Ghidra 0x29C8B
// Subsystem: misc | Size: 861 bytes


int __cdecl16far FUN_28eb_0ddb(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint in_DX;
  uint uVar6;
  undefined4 local_e;
  int local_a;
  uint uStack_8;
  
  local_e = 0;
  DAT_5b41_04ee = 0;
  DAT_5b41_04ec = 0;
  iVar1 = FUN_28eb_3287(0x3000);
  do {
    if (iVar1 == 0 && in_DX == 0) {
      if ((int)local_e == 0 && local_e._2_2_ == 0) {
        return 0;
      }
      return (int)local_e;
    }
    uStack_8 = in_DX;
    local_a = FUN_28eb_0a36(param_1,param_2,iVar1,in_DX);
    uVar2 = uStack_8;
    if (((((local_a != 0 || uStack_8 != 0) && ((*(byte *)(local_a + 0xb) & 0x80) != 0)) &&
         (iRam000557bc != 3)) && (param_1 != 0 || param_2 != 0)) &&
       ((uVar2 = param_2, param_2 != uStack_8 || (param_1 != local_a)))) {
      local_a = 0;
      uStack_8 = 0;
    }
    if (((local_a == 0 && uStack_8 == 0) || (*(int *)(local_a + 0x98) != 0)) ||
       (((int)local_e == 0 && local_e._2_2_ == 0 || (*(int *)((int)local_e + 0x98) != 0)))) {
      if (local_a != 0 || uStack_8 != 0) {
        if ((((int)local_e == 0 && local_e._2_2_ == 0) || (local_e._2_2_ != DAT_5b41_0567._2_2_)) ||
           ((int)local_e != (int)DAT_5b41_0567)) {
          if ((uStack_8 == DAT_5b41_0567._2_2_) && (local_a == (int)DAT_5b41_0567)) {
            iVar5 = FUN_28eb_03ff(0,0,(int)local_e,local_e._2_2_);
            if (iVar5 == 0) {
              DAT_5b41_04ee = uStack_8;
              DAT_5b41_04ec = local_a;
            }
            goto LAB_28eb_10f3;
          }
          if (((int)local_e == 0 && local_e._2_2_ == 0) || ((*(byte *)(local_a + 0xb) & 0x80) != 0))
          {
            DAT_5b41_04ee = uStack_8;
            DAT_5b41_04ec = local_a;
            if ((((((*(byte *)(local_a + 0xb) & 0x80) == 0) || (iRam000557bc == 3)) ||
                 (((int)DAT_5b41_0567 != 0 || DAT_5b41_0567._2_2_ != 0 &&
                  (*(int *)((int)DAT_5b41_0567 + 8) == 10)))) ||
                (((int)DAT_5b41_0567 != 0 || DAT_5b41_0567._2_2_ != 0 &&
                 (*(int *)((int)DAT_5b41_0567 + 8) == 0x4c)))) ||
               ((uVar2 = uStack_8, (int)DAT_5b41_0567 != 0 || DAT_5b41_0567._2_2_ != 0 &&
                (*(int *)((int)DAT_5b41_0567 + 8) == 8)))) {
              local_a = FUN_28eb_0728((int)local_e,local_e._2_2_,local_a,uStack_8);
              goto LAB_28eb_10f3;
            }
          }
          else {
            if ((*(int *)(local_a + 0x98) != 0) &&
               (uVar2 = uStack_8, iVar5 = FUN_28eb_03ff(0,0,local_a,uStack_8), iVar5 == 0)) {
              if ((*(int *)((int)local_e + 0x98) == 0) ||
                 (iVar5 = FUN_28eb_03ff(0,0,(int)local_e,local_e._2_2_), iVar5 != 0))
              goto LAB_28eb_10f9;
              local_a = FUN_28eb_0728((int)local_e,local_e._2_2_,local_a,uStack_8);
              uStack_8 = uVar2;
            }
            local_e = CONCAT22(uStack_8,local_a);
            uVar2 = uStack_8;
            DAT_5b41_04ec = local_a;
            DAT_5b41_04ee = uStack_8;
          }
        }
        else {
          uVar2 = local_e._2_2_;
          iVar5 = FUN_28eb_03ff(0,0,local_a,uStack_8);
          if (iVar5 != 0) {
            DAT_5b41_04ec = FUN_28eb_0728(DAT_5b41_04ec,DAT_5b41_04ee,local_a,uStack_8);
            DAT_5b41_04ee = uVar2;
          }
        }
      }
    }
    else if ((((int)local_e == 0 && local_e._2_2_ == 0) ||
             (uVar2 = local_e._2_2_, local_e._2_2_ != DAT_5b41_0567._2_2_)) ||
            ((int)local_e != (int)DAT_5b41_0567)) {
      uVar6 = uVar2;
      if (((local_a == 0 && uStack_8 == 0) || (uVar6 = uStack_8, uStack_8 != DAT_5b41_0567._2_2_))
         || (local_a != (int)DAT_5b41_0567)) {
        uVar2 = FUN_28eb_0d77(local_a,uStack_8);
        uVar4 = uVar6;
        uVar3 = FUN_28eb_0d77((int)local_e,local_e._2_2_);
        if (((int)uVar6 < (int)uVar4) || (((int)uVar6 <= (int)uVar4 && (uVar3 <= uVar2))))
        goto LAB_28eb_10f9;
        DAT_5b41_04ee = uStack_8;
        DAT_5b41_04ec = local_a;
      }
      else {
        uVar2 = uStack_8;
        uVar4 = FUN_28eb_0d77(local_a,uStack_8);
        uVar6 = uVar2;
        uVar3 = FUN_28eb_0d77((int)local_e,local_e._2_2_);
        if (((int)uVar6 <= (int)uVar2) && (((int)uVar6 < (int)uVar2 || (uVar4 < uVar3)))) {
          DAT_5b41_04ee = uStack_8;
          DAT_5b41_04ec = local_a;
        }
      }
LAB_28eb_10f3:
      local_e = CONCAT22(uStack_8,local_a);
      uVar2 = uStack_8;
    }
    else {
      uVar6 = local_e._2_2_;
      uVar2 = FUN_28eb_0d77(local_a,uStack_8);
      uVar4 = uVar6;
      uVar3 = FUN_28eb_0d77((int)local_e,local_e._2_2_);
      if (((int)uVar4 <= (int)uVar6) && (((int)uVar4 < (int)uVar6 || (uVar2 < uVar3)))) {
        DAT_5b41_04ee = uStack_8;
        DAT_5b41_04ec = local_a;
        uVar2 = uStack_8;
      }
    }
LAB_28eb_10f9:
    iVar1 = FUN_28eb_32d8(iVar1,in_DX,0x1000);
    in_DX = uVar2;
  } while( true );
}

