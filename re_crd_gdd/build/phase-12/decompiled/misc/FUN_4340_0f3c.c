// TIM2.EXE: FUN_4340_0f3c @ file 0x04953C Ghidra 0x4433C
// Subsystem: misc | Size: 389 bytes


void __cdecl16far FUN_4340_0f3c(undefined2 *param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 in_DX;
  int *piVar6;
  int iVar7;
  undefined2 uVar8;
  undefined1 local_22 [4];
  int local_1e;
  int local_1c;
  int local_1a;
  int *local_18;
  undefined2 local_16;
  byte local_13;
  int local_12;
  int local_10;
  undefined4 local_e;
  undefined4 local_a;
  undefined2 *local_6;
  undefined2 uStack_4;
  
  iVar3 = FUN_4340_10fe((undefined2 *)param_1,param_1._2_2_,local_22);
  if (iVar3 != 0) {
    puVar4 = (undefined2 *)FUN_4340_1eea(*param_1);
    _local_6 = (undefined2 *)CONCAT22(in_DX,puVar4);
    local_10 = ((undefined2 *)param_1)[2];
    iVar3 = ((undefined2 *)param_1)[3];
    if ((*(byte *)((int)(undefined2 *)param_1 + 0xd) & 0x11) != 0) {
      local_10 = local_10 + (((undefined2 *)param_1)[4] - local_1e) / 2;
    }
    if ((*(byte *)((int)(undefined2 *)param_1 + 0xd) & 2) != 0) {
      iVar3 = iVar3 + (((undefined2 *)param_1)[5] - local_1c) / 2;
    }
    local_a = (int *)CONCAT22(local_16,local_18);
    local_12 = local_1a;
    while( true ) {
      uVar8 = (undefined2)((ulong)local_a >> 0x10);
      piVar6 = (int *)local_a;
      if ((*local_a == 0 && piVar6[1] == 0) || (iVar5 = local_12 + -1, local_12 == 0)) break;
      local_e = (byte *)CONCAT22(piVar6[3],(byte *)piVar6[2]);
      if ((byte *)piVar6[2] != (byte *)0x0 || piVar6[3] != 0) {
        do {
          pbVar2 = local_e;
          pbVar1 = (byte *)local_e + -1;
          local_e = (byte *)CONCAT22(local_e._2_2_,pbVar1);
          if (pbVar1 <= (byte *)*local_a) break;
        } while (*local_e < 0x21);
        local_13 = *pbVar2;
        *pbVar2 = 0;
        local_e = pbVar2;
      }
      iVar7 = 0;
      local_12 = iVar5;
      if ((*(byte *)((int)(undefined2 *)param_1 + 0xd) & 0x18) != 0) {
        iVar7 = FUN_4340_1602((undefined2 *)param_1,param_1._2_2_,*local_a,piVar6[1]);
        iVar7 = local_1e - iVar7;
        if ((*(byte *)((int)(undefined2 *)param_1 + 0xd) & 0x10) == 0) {
          if ((*(byte *)((int)(undefined2 *)param_1 + 0xd) & 1) == 0) {
            iVar7 = iVar7 + (((undefined2 *)param_1)[4] - local_1e);
          }
        }
        else {
          iVar7 = iVar7 / 2;
        }
      }
      (*(code *)*(undefined2 *)_local_6)
                (0x4340,(undefined2 *)param_1,param_1._2_2_,*local_a,((int *)local_a)[1],
                 local_10 + iVar7,iVar3);
      iVar5 = FUN_4340_1640((undefined2 *)param_1,param_1._2_2_,*local_a,((int *)local_a)[1]);
      iVar3 = iVar3 + iVar5;
      if ((byte *)local_e != (byte *)0x0 || local_e._2_2_ != 0) {
        *local_e = local_13;
      }
      local_a = (int *)CONCAT22(local_a._2_2_,(int *)local_a + 2);
    }
  }
  return;
}

