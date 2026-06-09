// TIM2.EXE: FUN_1000_84f2 @ file 0x01D6F2 Ghidra 0x184F2
// Subsystem: utility | Size: 1026 bytes


void __cdecl16near FUN_1000_84f2(int *param_1,uint param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined2 uVar6;
  int unaff_SS;
  bool bVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined4 local_22;
  int *local_1e;
  int iVar10;
  int *local_1a;
  int iVar11;
  ulong local_18;
  uint uStack_16;
  int local_14;
  int iStack_12;
  int local_10;
  undefined4 local_e;
  uint local_a;
  int local_8;
  uint local_6;
  int local_4;
  
  local_10 = 0;
  if ((int *)param_1 != (int *)0xffff) {
    local_4 = *(int *)(param_4 + 0x1c);
    local_6 = *(uint *)(param_4 + 0x1a);
    uVar3 = *(uint *)0x10 - local_6;
    local_a = uVar3 - param_2;
    local_8 = (((*(int *)0x12 - local_4) - (uint)(*(uint *)0x10 < local_6)) - param_3) -
              (uint)(uVar3 < param_2);
    uVar6 = (undefined2)((ulong)param_1 >> 0x10);
    if ((*(byte *)((int *)param_1 + 2) & 0x20) != 0) {
      uVar2 = *(undefined4 *)((int)*(undefined4 *)param_1 + 6);
      local_a = *(uint *)((int)uVar2 + 0x1a);
      local_8 = 0;
    }
    if ((local_8 < 1) && ((local_8 != 0 || (local_a == 0)))) {
      if ((((int *)param_1)[2] & 3U) != 3) {
        return;
      }
      local_e = param_1;
      local_10 = 1;
    }
    else {
      local_e = param_1;
      while( true ) {
        uVar6 = (undefined2)((ulong)local_e >> 0x10);
        piVar5 = (int *)local_e;
        if (*local_e == 0 && piVar5[1] == 0) break;
        uStack_16 = piVar5[1];
        local_14 = *local_e;
        local_1a = (int *)0x1;
        if ((*(byte *)(local_14 + 2) & 0x10) != 0) {
          iStack_12 = *(int *)(local_14 + 8);
          local_14 = *(int *)(local_14 + 6);
          uStack_16 = iStack_12;
          if ((((*(byte *)(local_14 + 2) & 2) != 0) && ((*(byte *)(local_14 + 8) & 0x20) != 0)) &&
             ((*(byte *)(piVar5 + 2) & 8) != 0)) {
            if ((*(byte *)(piVar5 + 2) & 4) == 0) {
              iVar10 = piVar5[4];
              piVar4 = (int *)piVar5[3];
            }
            else {
              piVar4 = (int *)(piVar5[3] + param_5);
              iVar10 = unaff_SS;
            }
            local_22 = (int *)CONCAT22(iVar10,piVar4);
            if ((*(byte *)(piVar5 + 2) & 0x80) == 0) {
              iVar11 = *local_22;
              iVar10 = 0x554c;
            }
            else {
              iVar10 = piVar4[1];
              iVar11 = *local_22;
            }
            if ((*(byte *)(piVar5 + 2) & 0x40) != 0) {
              iVar11 = iVar11 + 4;
            }
            FUN_1000_8441(iVar11,iVar10,&local_14);
            uStack_16 = iStack_12;
          }
        }
        iVar11 = local_14;
        if ((*(byte *)(local_14 + 3) & 4) != 0) {
          local_1a = (int *)*(int *)(local_14 + 10);
          iVar11 = *(int *)(local_14 + 6);
          uStack_16 = *(int *)(local_14 + 8);
        }
        uVar3 = *(int *)(iVar11 + 0x1a) * (int)local_1a;
        if ((local_8 == 0) && (local_a <= uVar3)) goto LAB_1000_86f1;
        bVar7 = local_a < uVar3;
        local_a = local_a - uVar3;
        local_8 = local_8 - (uint)bVar7;
        local_e = (int *)CONCAT22(local_e._2_2_,(int *)local_e + 5);
      }
      local_e = (int *)CONCAT22(uVar6,piVar5 + -5);
    }
LAB_1000_86f1:
    do {
      uVar6 = (undefined2)((ulong)local_e >> 0x10);
      piVar5 = (int *)local_e;
      iStack_12 = piVar5[1];
      local_14 = *local_e;
      uVar3 = piVar5[2];
      if ((uVar3 & 4) == 0) {
        iVar10 = piVar5[4];
        local_1a = (int *)piVar5[3];
      }
      else {
        local_1a = (int *)(piVar5[3] + param_5);
        iVar10 = unaff_SS;
      }
      local_18 = CONCAT22(uVar3,iVar10);
      if ((uVar3 & 0x11) != 0) {
        iVar1 = *(int *)(local_14 + 8);
        local_14 = *(int *)(local_14 + 6);
        _local_1e = (int *)CONCAT22(iVar10,local_1a);
        if ((uVar3 & 0x80) == 0) {
          local_1a = (int *)*_local_1e;
          iVar11 = 0x554c;
        }
        else {
          iVar11 = local_1a[1];
          local_1a = (int *)*_local_1e;
        }
        local_18 = CONCAT22(uVar3,iVar11);
        local_22 = (int *)CONCAT22(iVar11,local_1a);
        if ((uVar3 & 0x48) == 0x40) {
          local_1a = local_1a + 2;
        }
        iStack_12 = iVar1;
        if ((((*(byte *)(local_14 + 2) & 2) != 0) && ((*(byte *)(local_14 + 8) & 0x20) != 0)) &&
           ((uVar3 & 8) != 0)) {
          local_1a = (int *)FUN_1000_8441(local_1a,iVar11,&local_14);
          local_18 = CONCAT22(uVar3,iVar11);
        }
      }
      if (local_10 == 0) {
        if ((*(byte *)(local_14 + 3) & 4) == 0) {
          FUN_1000_8074(local_1a,iVar11,local_14,iStack_12,local_a,local_8,1,param_5);
        }
        else {
          FUN_1000_833f(local_1a,iVar11,local_14,iStack_12,local_a,local_8,param_5);
        }
      }
      if ((uStack_16 & 3) == 3) {
        if ((uStack_16 & 0x48) == 0x48) {
          local_22 = (int *)CONCAT22(local_22._2_2_,(int *)local_22 + -2);
        }
        if ((*(byte *)(local_14 + 3) & 4) == 0) {
          if (*(int *)(local_14 + 0xe) != 0 || *(int *)(local_14 + 0x10) != 0) {
            uVar6 = *(undefined2 *)(local_14 + 0x12);
            uVar9 = *(undefined2 *)(local_14 + 0x10);
            uVar8 = *(undefined2 *)(local_14 + 0xe);
            goto LAB_1000_88a9;
          }
          if ((local_18 & 0x800000) == 0) {
            FUN_1000_1499((int *)local_22);
          }
          else {
            FUN_1000_14bd((int *)local_22,local_22._2_2_);
          }
        }
        else {
          iVar10 = *(int *)(local_14 + 8);
          local_14 = *(int *)(local_14 + 6);
          iStack_12 = iVar10;
          if (*(int *)(local_14 + 0x16) == 0 && *(int *)(local_14 + 0x18) == 0) {
            if ((local_18 & 0x800000) == 0) {
              FUN_1000_14ab((int *)local_22);
            }
            else {
              FUN_1000_14e5((int *)local_22,local_22._2_2_);
            }
          }
          else {
            uVar6 = *(undefined2 *)(local_14 + 0x14);
            uVar9 = *(undefined2 *)(local_14 + 0x18);
            uVar8 = *(undefined2 *)(local_14 + 0x16);
LAB_1000_88a9:
            FUN_1000_68ff((int *)local_22,local_22._2_2_,uVar8,uVar9,uVar6);
          }
        }
      }
      local_8 = 0;
      local_a = 0;
      piVar5 = (int *)local_e;
      local_e = (int *)CONCAT22(local_e._2_2_,(int *)local_e + -5);
    } while ((int *)param_1 < piVar5);
  }
  return;
}

