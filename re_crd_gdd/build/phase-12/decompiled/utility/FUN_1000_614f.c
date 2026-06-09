// TIM2.EXE: FUN_1000_614f @ file 0x01B34F Ghidra 0x1614F
// Subsystem: utility | Size: 372 bytes


undefined2 __cdecl16near
FUN_1000_614f(undefined4 param_1,undefined4 param_2,int param_3,undefined2 param_4,
             undefined2 param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  uint local_6;
  uint local_4;
  
  do {
    if ((param_1._2_2_ == param_2._2_2_) && ((int)param_1 == (int)param_2)) goto LAB_1000_6282;
    uVar1 = *(uint *)((int)param_1 + 2);
    uVar2 = *(uint *)((int)param_2 + 2);
    if ((uVar1 & uVar2 & 0x10) == 0) {
      if ((uVar1 & uVar2 & 0x400) == 0) {
        iVar3 = FUN_1000_5f71((int)param_1,param_1._2_2_,(int)param_2,param_2._2_2_);
        if (iVar3 != 0) goto LAB_1000_6282;
        if ((((uVar1 & 2) != 0) && ((uVar2 & 1) != 0)) && ((*(byte *)((int)param_1 + 8) & 4) != 0))
        {
          uVar4 = FUN_1000_5ffc((int)param_1,param_1._2_2_,(int)param_2,param_2._2_2_,param_4,
                                param_5,1);
          return uVar4;
        }
        goto LAB_1000_62bb;
      }
      if (((*(int *)((int)param_1 + 0xc) != *(int *)((int)param_2 + 0xc)) ||
          (*(int *)((int)param_1 + 10) != *(int *)((int)param_2 + 10))) &&
         ((param_3 != 0 ||
          ((*(int *)((int)param_1 + 10) != 0 || *(int *)((int)param_2 + 10) != 0) ||
           (*(int *)((int)param_1 + 0xc) != 0 || *(int *)((int)param_2 + 0xc) != 0)))))
      goto LAB_1000_62bb;
    }
    else {
      local_4 = uVar1 & 0x3300;
      local_6 = uVar2 & 0x3300;
      if (local_4 != local_6) {
        if (param_3 != 0) goto LAB_1000_62bb;
        if ((uVar1 & 0x300) == (uVar2 & 0x300)) {
LAB_1000_61dd:
          if (((local_4 | 0x3000) == (local_6 | 0x3000)) && ((local_4 & 0x1000) != 0)) {
LAB_1000_6282:
            uVar4 = 1;
          }
          else {
LAB_1000_62bb:
            uVar4 = 0;
          }
          return uVar4;
        }
        if ((~(uVar2 & 0x300) & local_4 & 0x300) != 0) goto LAB_1000_62bb;
        local_4 = local_4 | 0x300;
        local_6 = local_6 | 0x300;
        if (local_4 != local_6) goto LAB_1000_61dd;
      }
    }
    param_3 = 1;
    param_1 = CONCAT22(*(undefined2 *)((int)param_1 + 8),*(undefined2 *)((int)param_1 + 6));
    param_2 = CONCAT22(*(undefined2 *)((int)param_2 + 8),*(undefined2 *)((int)param_2 + 6));
  } while( true );
}

