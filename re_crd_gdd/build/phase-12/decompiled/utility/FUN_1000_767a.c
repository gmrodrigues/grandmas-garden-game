// TIM2.EXE: FUN_1000_767a @ file 0x01C87A Ghidra 0x1767A
// Subsystem: utility | Size: 678 bytes


void __cdecl16near
FUN_1000_767a(undefined4 param_1,undefined2 param_2,undefined4 param_3,int *param_4,int param_5)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  bool bVar10;
  undefined4 local_10;
  int local_a;
  int iStack_8;
  
  uVar8 = (undefined2)((ulong)param_1 >> 0x10);
  iVar6 = (int)param_1;
  iVar3 = *(int *)(iVar6 + 6);
  local_a = *(int *)(iVar6 + 4);
  uVar9 = (undefined2)((ulong)param_3 >> 0x10);
  iVar7 = (int)param_3;
  *(int *)(iVar7 + 0x30) = iVar3;
  *(int *)(iVar7 + 0x2e) = local_a;
  if (local_a == 0 && iVar3 == 0) {
    return;
  }
  if ((*(byte *)(iVar6 + 8) & 0x80) != 0) {
    return;
  }
  bVar10 = (*(uint *)(iVar6 + 8) & 1) == 0;
  local_10 = (undefined2 *)CONCAT22(uVar9,(undefined2 *)(iVar7 + 0x36));
  *(undefined1 *)(iVar7 + 0x35) = 1;
  *(int *)(iVar7 + 0x32) = *param_4 + param_5;
  uVar1 = *(uint *)(local_a + 2);
  uVar5 = uVar1;
  iStack_8 = iVar3;
  if ((uVar1 & 0x30) != 0) {
    iStack_8 = *(int *)(local_a + 8);
    local_a = *(int *)(local_a + 6);
    uVar5 = *(uint *)(local_a + 2);
  }
  if (((uVar1 & 0x10) != 0) && ((*(byte *)(iVar7 + 0xc) & 1) != 0)) {
    FUN_1000_a39f(*(undefined2 *)(iVar7 + 0x32));
    goto LAB_1000_787d;
  }
  if (((uVar5 & 1) == 0) || ((uVar1 & 0x30) == 0)) {
    if ((*(byte *)(iVar7 + 0x14) & 1) == 0) {
      if ((uVar1 & 0x20) != 0) {
        FUN_1000_a355(*(undefined2 *)(iVar7 + 0x32));
        goto LAB_1000_787d;
      }
    }
    else {
      iVar3 = FUN_1000_5f71(*(undefined2 *)(iVar7 + 0x10),*(undefined2 *)(iVar7 + 0x12),local_a,
                            iStack_8);
      if (iVar3 == 0) {
        puVar4 = (undefined2 *)
                 FUN_1000_75f7((undefined2 *)(iVar7 + 0x36),uVar9,*(undefined2 *)(iVar7 + 0x10),
                               *(undefined2 *)(iVar7 + 0x12),local_a,iStack_8);
        local_10 = (undefined2 *)CONCAT22(uVar5,puVar4);
      }
      bVar10 = iVar3 == 0 || bVar10;
      if ((*(byte *)(local_a + 8) & 1) != 0) {
        FUN_1000_63e4(*(undefined2 *)(iVar7 + 0x32));
LAB_1000_787d:
        bVar10 = true;
        goto LAB_1000_78e4;
      }
    }
  }
  else {
    if ((uVar1 & 0x20) == 0) {
      puVar4 = (undefined2 *)*local_10;
      local_10 = (undefined2 *)CONCAT22(*(undefined2 *)(iVar7 + 0x38),puVar4);
      if ((*(byte *)(iVar7 + 0x15) & 0x10) != 0) {
        local_10 = (undefined2 *)CONCAT22(0x554c,puVar4);
        goto LAB_1000_778c;
      }
    }
    else {
LAB_1000_778c:
      bVar10 = true;
    }
    iVar3 = FUN_1000_5f71(*(undefined2 *)(iVar7 + 0x10),*(undefined2 *)(iVar7 + 0x12),local_a,
                          iStack_8);
    if (iVar3 == 0) {
      iVar3 = local_10._2_2_;
      puVar4 = (undefined2 *)local_10;
      puVar2 = (undefined2 *)
               FUN_1000_75f7((undefined2 *)local_10,local_10._2_2_,*(undefined2 *)(iVar7 + 0x10),
                             *(undefined2 *)(iVar7 + 0x12),local_a,iStack_8);
      local_10 = (undefined2 *)CONCAT22(local_10._2_2_,puVar2);
      if ((local_10._2_2_ != iVar3) || (puVar2 != puVar4)) {
        bVar10 = true;
      }
    }
  }
  FUN_1000_a355(*(undefined2 *)(iVar7 + 0x32));
LAB_1000_78e4:
  if (!bVar10) {
    if ((*(byte *)(local_a + 8) & 2) != 0) {
      FUN_1000_73a3((undefined2 *)local_10,local_10._2_2_,*(undefined2 *)(local_a + 0x1e),
                    *(undefined2 *)(local_a + 0x20),*(undefined2 *)(local_a + 0x22));
    }
    *(undefined1 *)(iVar7 + 0x34) = 0;
  }
  return;
}

