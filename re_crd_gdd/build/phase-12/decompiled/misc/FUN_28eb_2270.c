// TIM2.EXE: FUN_28eb_2270 @ file 0x030320 Ghidra 0x2B120
// Subsystem: misc | Size: 464 bytes


void __cdecl16far FUN_28eb_2270(void)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined4 local_10;
  int local_8;
  int iStack_6;
  byte local_4;
  
  uVar8 = 0x28eb;
  local_10 = 0;
  uVar7 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10);
  iVar5 = (int)DAT_5b41_0567;
  iVar6 = *(int *)(iVar5 + 0x70);
  iVar3 = *(int *)(iVar5 + 0x6e);
  bVar2 = *(byte *)(iVar5 + 0x94);
  *(undefined2 *)(iVar5 + 0x70) = 0;
  *(undefined2 *)(iVar5 + 0x6e) = 0;
  FUN_28eb_4f3d(iVar5,DAT_5b41_0567._2_2_,0x2000,0xfff8,8,0xfff8,8);
  iVar5 = (int)((ulong)DAT_5b41_0567 >> 0x10);
  local_8 = (int)DAT_5b41_0567;
  iStack_6 = iVar5;
  do {
    piVar1 = (int *)(local_8 + 0x8e);
    local_8 = *(int *)(local_8 + 0x8c);
    iStack_6 = *piVar1;
    do {
      if (local_8 == 0 && iStack_6 == 0) {
        if ((iVar3 != 0 || iVar6 != 0) && ((local_10._2_2_ != iVar6 || ((int)local_10 != iVar3)))) {
          iVar5 = iVar3 + (uint)*(byte *)((int)DAT_5b41_0567 + 0x94) * 4;
          *(undefined2 *)(iVar5 + 0x70) = 0;
          *(undefined2 *)(iVar5 + 0x6e) = 0;
          uVar7 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10);
          iVar5 = (int)DAT_5b41_0567;
          *(undefined2 *)(iVar5 + 0x70) = 0;
          *(undefined2 *)(iVar5 + 0x6e) = 0;
          puVar4 = (undefined2 *)(*(int *)(*(int *)(iVar3 + 8) * 2 + 0x302) + 8);
          (*(code *)*puVar4)(0x28eb,iVar3,iVar6);
          *(undefined2 *)(iVar3 + 0xa8) = *(undefined2 *)(iVar3 + 0x10);
          uVar8 = 0x2424;
          FUN_2424_0f94(iVar3,iVar6,3);
        }
        if ((int)local_10 != 0 || local_10._2_2_ != 0) {
          iVar6 = (int)local_10 + (uint)local_4 * 4;
          uVar7 = (undefined2)DAT_5b41_0567;
          *(undefined2 *)(iVar6 + 0x70) = DAT_5b41_0567._2_2_;
          *(undefined2 *)(iVar6 + 0x6e) = uVar7;
          uVar7 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10);
          iVar6 = (int)DAT_5b41_0567;
          *(int *)(iVar6 + 0x70) = local_10._2_2_;
          *(int *)(iVar6 + 0x6e) = (int)local_10;
          *(byte *)(iVar6 + 0x94) = local_4;
          puVar4 = (undefined2 *)(*(int *)(*(int *)((int)local_10 + 8) * 2 + 0x302) + 8);
          (*(code *)*puVar4)(uVar8,(int)local_10,local_10._2_2_);
          *(undefined2 *)((int)local_10 + 0xa8) = *(undefined2 *)((int)local_10 + 0x10);
          FUN_2424_0f94((int)local_10,local_10._2_2_,3);
        }
        return;
      }
      if ((iStack_6 == iVar6) && (local_8 == iVar3)) {
        local_10 = CONCAT22(iVar6,iVar3);
        local_4 = bVar2;
LAB_28eb_232b:
        iStack_6 = 0;
        local_8 = 0;
      }
      else if ((*(byte *)(local_8 + 0xe) & 2) != 0) {
        if (*(int *)(local_8 + 0x6e) == 0 && *(int *)(local_8 + 0x70) == 0) {
          local_10 = CONCAT22(iStack_6,local_8);
          local_4 = 0;
        }
        else {
          if (*(int *)(local_8 + 0x72) != 0 || *(int *)(local_8 + 0x74) != 0) goto LAB_28eb_2335;
          local_10 = CONCAT22(iStack_6,local_8);
          local_4 = 1;
        }
        goto LAB_28eb_232b;
      }
LAB_28eb_2335:
    } while (local_8 == 0 && iStack_6 == 0);
  } while( true );
}

