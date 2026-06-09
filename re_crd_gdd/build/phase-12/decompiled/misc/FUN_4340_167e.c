// TIM2.EXE: FUN_4340_167e @ file 0x049C7E Ghidra 0x44A7E
// Subsystem: misc | Size: 948 bytes


undefined2 __cdecl16far FUN_4340_167e(undefined2 *param_1,byte *param_2,int *param_3)

{
  byte *pbVar1;
  undefined2 *puVar2;
  byte *pbVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  undefined2 in_DX;
  undefined2 *puVar7;
  int iVar8;
  undefined1 local_28 [4];
  int local_24;
  int local_22;
  undefined2 *local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  byte local_17;
  int local_16;
  int local_14;
  int local_12;
  int local_10;
  undefined4 local_e;
  undefined4 local_a;
  undefined2 local_6;
  undefined2 uStack_4;
  
  local_1a = 0;
  if ((undefined2 *)param_1 != (undefined2 *)0x0 || param_1._2_2_ != 0) {
    if (((((byte *)param_2 != (byte *)0x0 || param_2._2_2_ != 0) &&
         (((undefined2 *)param_1)[8] != 0 || ((undefined2 *)param_1)[9] != 0)) &&
        ((byte *)((undefined2 *)param_1)[8] <= (byte *)param_2)) &&
       ((iVar4 = FUN_4340_0a09(((undefined2 *)param_1)[8],((undefined2 *)param_1)[9]),
        (byte *)param_2 <= (byte *)(iVar4 + ((undefined2 *)param_1)[8]) &&
        (iVar4 = FUN_4340_10fe((undefined2 *)param_1,param_1._2_2_,local_28), iVar4 != 0)))) {
      uVar5 = FUN_4340_1eea(*param_1);
      _local_6 = CONCAT22(in_DX,uVar5);
      local_10 = ((undefined2 *)param_1)[2];
      iVar4 = ((undefined2 *)param_1)[3];
      local_1a = 1;
      if ((*(byte *)((int)(undefined2 *)param_1 + 0xd) & 0x11) != 0) {
        local_10 = local_10 + (((undefined2 *)param_1)[4] - local_24) / 2;
      }
      if ((*(byte *)((int)(undefined2 *)param_1 + 0xd) & 2) != 0) {
        iVar4 = iVar4 + (((undefined2 *)param_1)[5] - local_22) / 2;
      }
      local_a = (undefined2 *)CONCAT22(local_1c,local_1e);
      while( true ) {
        uVar5 = (undefined2)((ulong)local_a >> 0x10);
        puVar7 = (undefined2 *)local_a;
        iVar8 = puVar7[3];
        pbVar1 = (byte *)puVar7[2];
        local_e = (byte *)CONCAT22(iVar8,pbVar1);
        if (((pbVar1 == (byte *)0x0 && iVar8 == 0) || (*local_e == 0)) ||
           (((byte *)param_2 <= pbVar1 &&
            (((param_2._2_2_ != iVar8 || ((byte *)param_2 != pbVar1)) || (*param_2 == 0)))))) break;
        local_17 = *local_e;
        *local_e = 0;
        iVar8 = FUN_4340_1640((undefined2 *)param_1,param_1._2_2_,*local_a,puVar7[1]);
        iVar4 = iVar4 + iVar8;
        *local_e = local_17;
        local_a = (undefined2 *)CONCAT22(local_a._2_2_,(undefined2 *)local_a + 2);
      }
      local_e = (byte *)CONCAT22(puVar7[3],(byte *)puVar7[2]);
      if ((byte *)puVar7[2] != (byte *)0x0 || puVar7[3] != 0) {
        do {
          pbVar3 = local_e;
          pbVar1 = (byte *)local_e + -1;
          local_e = (byte *)CONCAT22(local_e._2_2_,pbVar1);
          if (pbVar1 <= (byte *)*local_a) break;
        } while (*local_e < 0x21);
        local_17 = *pbVar3;
        *pbVar3 = 0;
        local_e = pbVar3;
      }
      iVar8 = 0;
      if ((*(byte *)((int)(undefined2 *)param_1 + 0xd) & 0x18) != 0) {
        iVar8 = FUN_4340_1602((undefined2 *)param_1,param_1._2_2_,*local_a,puVar7[1]);
        iVar8 = local_24 - iVar8;
        if ((*(byte *)((int)(undefined2 *)param_1 + 0xd) & 0x10) == 0) {
          if ((*(byte *)((int)(undefined2 *)param_1 + 0xd) & 1) == 0) {
            iVar8 = iVar8 + (((undefined2 *)param_1)[4] - local_24);
          }
        }
        else {
          iVar8 = iVar8 / 2;
        }
      }
      if ((byte *)local_e != (byte *)0x0 || local_e._2_2_ != 0) {
        *local_e = local_17;
      }
      local_17 = *param_2;
      *param_2 = 0;
      puVar2 = (undefined2 *)((int)_local_6 + 0x10);
      iVar6 = (*(code *)*puVar2)(0x4340,(undefined2 *)param_1,param_1._2_2_,*local_a,
                                 ((undefined2 *)local_a)[1]);
      iVar8 = iVar8 + iVar6;
      puVar2 = (undefined2 *)((int)_local_6 + 0x14);
      local_12 = (*(code *)*puVar2)(0x4340,(undefined2 *)param_1,param_1._2_2_,*local_a,
                                    ((undefined2 *)local_a)[1]);
      *param_2 = local_17;
      local_14 = local_24;
      if (((*(byte *)((undefined2 *)param_1 + 6) & 2) == 0) && (local_17 == 0x20)) {
        local_e = param_2;
        puVar2 = (undefined2 *)((int)_local_6 + 8);
        local_16 = (*(code *)*puVar2)(0x4340,(undefined2 *)param_1,param_1._2_2_,*param_2);
        do {
          if (*local_e != 0x20) break;
          local_14 = local_14 + local_16;
          pbVar1 = (byte *)local_e;
          local_e = (byte *)CONCAT22(local_e._2_2_,(byte *)local_e + -1);
        } while ((local_e._2_2_ != ((undefined2 *)local_a)[1]) || (pbVar1 != (byte *)*local_a));
        if ((int)((undefined2 *)param_1)[4] < local_14) {
          local_14 = ((undefined2 *)param_1)[4];
        }
      }
      if ((local_14 <= iVar8) && (0x1f < local_17)) {
        iVar8 = 0;
        iVar4 = iVar4 + local_12;
        local_1a = 2;
      }
      if ((*param_2 == 0) && (((byte *)param_2)[-1] == 10)) {
        iVar4 = iVar4 + local_12;
        local_1a = 2;
        if ((*(byte *)((int)(undefined2 *)param_1 + 0xd) & 0x10) == 0) {
          iVar8 = 0;
          if (((*(byte *)((int)(undefined2 *)param_1 + 0xd) & 8) != 0) &&
             (iVar8 = local_24, (*(byte *)((int)(undefined2 *)param_1 + 0xd) & 1) == 0)) {
            iVar8 = ((undefined2 *)param_1)[4];
          }
        }
        else {
          iVar8 = local_24 / 2;
        }
      }
      else if ((*param_2 == 0) &&
              ((((byte *)param_2)[-1] < 0x21 &&
               (puVar2 = (undefined2 *)((int)_local_6 + 8),
               iVar6 = (*(code *)*puVar2)(0x4340,(undefined2 *)param_1,param_1._2_2_,0x20),
               (int)(((undefined2 *)param_1)[2] + ((undefined2 *)param_1)[4]) <=
               iVar6 + local_10 + iVar8)))) {
        iVar4 = iVar4 + local_12;
        iVar8 = 0;
        local_1a = 2;
      }
      if ((int *)param_3 != (int *)0x0 || param_3._2_2_ != 0) {
        *param_3 = local_10 + iVar8;
        ((int *)param_3)[1] = iVar4;
        puVar2 = (undefined2 *)((int)_local_6 + 8);
        iVar4 = (*(code *)*puVar2)(0x4340,(undefined2 *)param_1,param_1._2_2_,
                                   CONCAT11((char)((uint)(local_10 + iVar8) >> 8),*param_2));
        ((int *)param_3)[2] = iVar4;
        puVar2 = (undefined2 *)((int)_local_6 + 0xc);
        iVar4 = (*(code *)*puVar2)(0x4340,(undefined2 *)param_1,param_1._2_2_,*param_2);
        ((int *)param_3)[3] = iVar4;
      }
    }
  }
  return local_1a;
}

