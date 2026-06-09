// TIM2.EXE: FUN_1000_8b6f @ file 0x01DD6F Ghidra 0x18B6F
// Subsystem: utility | Size: 582 bytes


undefined2 * __cdecl16near
FUN_1000_8b6f(int param_1,undefined2 param_2,undefined4 param_3,undefined2 *param_4,int param_5,
             undefined2 param_6,undefined2 param_7,int param_8,int param_9,int param_10,int param_11
             ,uint *param_12,int param_13,int param_14,int param_15)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  long lVar7;
  int local_1a;
  int local_18;
  undefined4 local_16;
  uint local_12;
  int local_10;
  undefined2 *local_e;
  int local_c;
  uint local_a;
  undefined4 local_6;
  
  local_a = 0;
  local_c = 0;
  local_e = (undefined2 *)0x0;
  local_10 = 0;
  if (((param_10 == 0 && param_11 == 0) ||
      (iVar3 = FUN_1000_5f71(param_10,param_11,(int)param_3,param_3._2_2_), iVar3 == 0)) &&
     ((*(byte *)((int)param_3 + 8) & 4) != 0)) {
    bVar2 = false;
    iVar3 = *(int *)((int)param_3 + 0xc);
    do {
      local_6 = (int *)CONCAT22(param_3._2_2_,(int *)((int)param_3 + iVar3));
      while( true ) {
        uVar6 = (undefined2)((ulong)local_6 >> 0x10);
        piVar5 = (int *)local_6;
        iVar3 = piVar5[1];
        iVar1 = *local_6;
        if (iVar1 == 0 && iVar3 == 0) break;
        if ((*(byte *)(piVar5 + 3) & 8) == 0) {
          if ((param_13 == 0) || ((piVar5[3] & 3U) != 3)) {
            local_12 = 0;
          }
          else {
            local_12 = 1;
          }
          local_16 = (undefined2 *)CONCAT22(param_2,(undefined2 *)(param_1 + piVar5[2]));
          local_18 = param_15;
          local_1a = param_14;
          if ((*(byte *)(piVar5 + 3) & 4) != 0) {
            local_16 = (undefined2 *)CONCAT22(param_2,(undefined2 *)*local_16);
            local_1a = iVar1;
            local_18 = iVar3;
          }
          iVar4 = FUN_1000_5f71(param_6,param_7,iVar1,iVar3);
          if (iVar4 == 0) {
            if (((*(byte *)(iVar1 + 8) & 4) != 0) &&
               (local_16 = (undefined2 *)
                           FUN_1000_8b6f((undefined2 *)local_16,local_16._2_2_,iVar1,iVar3,param_4,
                                         param_5,param_6,param_7,param_8,param_9,param_10,param_11,
                                         param_12,local_12,local_1a,local_18),
               local_16 != (undefined2 *)0x0)) {
              local_12 = *param_12;
LAB_1000_8d3d:
              if (((local_10 == 0) || (local_16._2_2_ != local_c)) ||
                 ((undefined2 *)local_16 != local_e)) {
                local_10 = local_10 + 1;
                local_c = local_16._2_2_;
                local_e = (undefined2 *)local_16;
                local_a = local_12;
              }
              else {
                local_a = local_a | local_12;
              }
            }
          }
          else if (param_4 == (undefined2 *)0x0 && param_5 == 0) {
            if ((param_8 == 0 && param_9 == 0) ||
               (lVar7 = FUN_1000_8b6f((undefined2 *)local_16,local_16._2_2_,iVar1,iVar3,param_8,
                                      param_9,param_10,param_11,0,0,0,0,param_12,0,0,0), lVar7 != 0)
               ) goto LAB_1000_8d3d;
          }
          else if ((param_5 == local_16._2_2_) && (param_4 == (undefined2 *)local_16))
          goto LAB_1000_8daf;
        }
        local_6 = (int *)CONCAT22(uVar6,piVar5 + 4);
      }
      if (bVar2) goto LAB_1000_8d90;
      bVar2 = true;
      iVar3 = *(int *)((int)param_3 + 10);
    } while( true );
  }
  local_16._2_2_ = 0;
  local_16._0_2_ = (undefined2 *)0x0;
LAB_1000_8daf:
  return (undefined2 *)CONCAT22(local_16._2_2_,(undefined2 *)local_16);
LAB_1000_8d90:
  *param_12 = local_a;
  local_16._0_2_ = local_e;
  local_16._2_2_ = local_c;
  if (local_10 != 1) {
    local_c = 0;
    local_e = (undefined2 *)0x0;
    local_16._0_2_ = local_e;
    local_16._2_2_ = local_c;
  }
  goto LAB_1000_8daf;
}

