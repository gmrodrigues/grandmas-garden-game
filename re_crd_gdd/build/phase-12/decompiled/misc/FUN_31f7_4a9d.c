// TIM2.EXE: FUN_31f7_4a9d @ file 0x03BC0D Ghidra 0x36A0D
// Subsystem: misc | Size: 304 bytes


void __cdecl16far FUN_31f7_4a9d(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  undefined2 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined2 uVar13;
  int iVar14;
  undefined2 uVar15;
  int local_20;
  int local_1e;
  int local_1c;
  int iStack_1a;
  undefined4 local_18;
  int local_14;
  int local_12;
  int iStack_10;
  int iStack_e;
  int iStack_c;
  int iStack_a;
  undefined2 uStack_8;
  uint local_6;
  uint local_4;
  
  puVar9 = DAT_5b41_054f;
  uVar15 = DAT_5b41_0551;
  do {
    local_18 = (undefined2 *)CONCAT22(uVar15,puVar9);
    do {
      if ((undefined2 *)local_18 == (undefined2 *)0x0 && local_18._2_2_ == 0) {
        return;
      }
      uVar15 = (undefined2)((ulong)param_1 >> 0x10);
      iVar14 = (int)param_1;
      if (((*(int *)(iVar14 + 8) == 0x4d) && (((undefined2 *)local_18)[4] == 0x4c)) ||
         (((undefined2 *)local_18)[4] == 10)) {
        puVar9 = (undefined2 *)((undefined2 *)local_18)[0x3b];
        iVar1 = puVar9[3];
        iVar2 = puVar9[2];
        iVar3 = puVar9[5];
        iVar4 = puVar9[4];
        local_4 = (uint)*(byte *)(puVar9 + 10);
        local_6 = 0;
        local_20 = iVar2 + local_4 * 4;
        local_1c = iVar2;
        iStack_1a = iVar1;
        do {
          local_1e = *(int *)(local_20 + 0x60);
          local_20 = *(int *)(local_20 + 0x5e);
          while( true ) {
            while( true ) {
              if ((local_1c == 0 && iStack_1a == 0) || (local_20 == 0 && local_1e == 0))
              goto LAB_31f7_4f80;
              if ((iStack_1a != iVar1) || (local_1c != iVar2)) {
                local_4 = 1;
              }
              local_14 = (*(int *)(local_1c + 0x2e) + (int)*(char *)(local_1c + local_4 * 2 + 0x7a))
                         - *(int *)(iVar14 + 0x22);
              local_12 = (*(int *)(local_1c + 0x30) + (int)*(char *)(local_1c + local_4 * 2 + 0x7b))
                         - *(int *)(iVar14 + 0x24);
              if ((local_1e == iVar3) && (local_20 == iVar4)) {
                local_6 = (uint)*(byte *)((int)puVar9 + 0x15);
              }
              iStack_10 = (*(int *)(local_20 + 0x2e) + (int)*(char *)(local_20 + local_6 * 2 + 0x7a)
                          ) - *(int *)(iVar14 + 0x22);
              iVar10 = (*(int *)(local_20 + 0x30) + (int)*(char *)(local_20 + local_6 * 2 + 0x7b)) -
                       *(int *)(iVar14 + 0x24);
              iStack_e = iVar10;
              iVar5 = FUN_2e67_13d4(param_2,&local_14,&iStack_c);
              if (iVar5 == 0) break;
              uStack_8 = DAT_5b41_0937;
              DAT_5b41_0937 = 0x1000;
              FUN_2424_0a23(*puVar9,puVar9[1],3);
              DAT_5b41_0937 = uStack_8;
              iVar5 = FUN_2321_0f22(0x31);
              if (iVar5 == 0 && iVar10 == 0) {
                return;
              }
              iVar11 = iVar10;
              iVar6 = FUN_2321_0f22(0x31);
              if (iVar6 == 0 && iVar11 == 0) {
                return;
              }
              iVar12 = iVar11;
              iVar7 = FUN_2321_0ff6(((undefined2 *)local_18)[4]);
              if (iVar7 == 0 && iVar12 == 0) {
                return;
              }
              FUN_28eb_2a59(iVar5,iVar10,(undefined2 *)&DAT_5b41_0557,0);
              *(uint *)(iVar5 + 10) = *(uint *)(iVar5 + 10) | 0x10;
              *(int *)(iVar5 + 0x22) = *(int *)(iVar14 + 0x22) + iStack_c;
              *(int *)(iVar5 + 0x24) = *(int *)(iVar14 + 0x24) + iStack_a;
              FUN_28eb_2a59(iVar6,iVar11,(undefined2 *)&DAT_5b41_0557,0);
              *(uint *)(iVar6 + 10) = *(uint *)(iVar6 + 10) | 0x10;
              uVar13 = *(undefined2 *)(iVar5 + 0x22);
              *(undefined2 *)(iVar6 + 0x24) = *(undefined2 *)(iVar5 + 0x24);
              *(undefined2 *)(iVar6 + 0x22) = uVar13;
              FUN_28eb_2a59(iVar7,iVar12,(undefined2 *)&DAT_5b41_054f,0);
              *(uint *)(iVar7 + 10) = *(uint *)(iVar7 + 10) | 0x10;
              iVar12 = *(int *)(iVar7 + 0x76);
              *(int *)(iVar12 + 6) = iVar11;
              *(int *)(iVar12 + 4) = iVar6;
              *(int *)(iVar12 + 10) = iVar3;
              *(int *)(iVar12 + 8) = iVar4;
              *(undefined1 *)(iVar12 + 0x14) = 0;
              *(undefined1 *)(iVar12 + 0x15) = *(undefined1 *)((int)puVar9 + 0x15);
              *(int *)(iVar6 + 0x60) = local_1e;
              *(int *)(iVar6 + 0x5e) = local_20;
              *(int *)(iVar6 + 0x76) = iVar12;
              if (*(int *)(local_20 + 8) == 7) {
                *(int *)(local_20 + 0x78) = iVar12;
                *(int *)(local_20 + 100) = iVar11;
                *(int *)(local_20 + 0x62) = iVar6;
              }
              else {
                *(int *)(local_20 + local_6 * 2 + 0x76) = iVar12;
                local_20 = local_20 + local_6 * 4;
                *(int *)(local_20 + 0x60) = iVar11;
                *(int *)(local_20 + 0x5e) = iVar6;
              }
              *(int *)(iVar4 + (uint)*(byte *)(iVar12 + 0x15) * 2 + 0x76) = iVar12;
              puVar9[5] = iVar10;
              puVar9[4] = iVar5;
              *(undefined1 *)((int)puVar9 + 0x15) = 0;
              *(int *)(iVar5 + 0x60) = iStack_1a;
              *(int *)(iVar5 + 0x5e) = local_1c;
              *(int *)(iVar5 + 0x76) = (int)puVar9;
              if (*(int *)(local_1c + 8) != 7) {
                local_1c = local_1c + local_4 * 4;
              }
              *(int *)(local_1c + 0x60) = iVar10;
              *(int *)(local_1c + 0x5e) = iVar5;
              uVar13 = *(undefined2 *)(iVar5 + 0x22);
              *(undefined2 *)(iVar5 + 0x26) = uVar13;
              *(undefined2 *)(iVar5 + 0x2a) = uVar13;
              iVar7 = *(int *)(iVar5 + 0x22);
              *(int *)(iVar5 + 0x1c) = iVar7 >> 0xf;
              *(int *)(iVar5 + 0x1a) = iVar7;
              uVar13 = *(undefined2 *)(iVar5 + 0x1c);
              uVar8 = FUN_1000_199e();
              *(undefined2 *)(iVar5 + 0x1c) = uVar13;
              *(undefined2 *)(iVar5 + 0x1a) = uVar8;
              uVar13 = *(undefined2 *)(iVar5 + 0x24);
              *(undefined2 *)(iVar5 + 0x28) = uVar13;
              *(undefined2 *)(iVar5 + 0x2c) = uVar13;
              iVar7 = *(int *)(iVar5 + 0x24);
              *(int *)(iVar5 + 0x20) = iVar7 >> 0xf;
              *(int *)(iVar5 + 0x1e) = iVar7;
              uVar13 = *(undefined2 *)(iVar5 + 0x20);
              uVar8 = FUN_1000_199e();
              *(undefined2 *)(iVar5 + 0x20) = uVar13;
              *(undefined2 *)(iVar5 + 0x1e) = uVar8;
              FUN_28eb_3328(iVar5,iVar10);
              uVar13 = *(undefined2 *)(iVar6 + 0x22);
              *(undefined2 *)(iVar6 + 0x26) = uVar13;
              *(undefined2 *)(iVar6 + 0x2a) = uVar13;
              iVar5 = *(int *)(iVar6 + 0x22);
              *(int *)(iVar6 + 0x1c) = iVar5 >> 0xf;
              *(int *)(iVar6 + 0x1a) = iVar5;
              uVar13 = *(undefined2 *)(iVar6 + 0x1c);
              uVar8 = FUN_1000_199e();
              *(undefined2 *)(iVar6 + 0x1c) = uVar13;
              *(undefined2 *)(iVar6 + 0x1a) = uVar8;
              uVar13 = *(undefined2 *)(iVar6 + 0x24);
              *(undefined2 *)(iVar6 + 0x28) = uVar13;
              *(undefined2 *)(iVar6 + 0x2c) = uVar13;
              iVar5 = *(int *)(iVar6 + 0x24);
              *(int *)(iVar6 + 0x20) = iVar5 >> 0xf;
              *(int *)(iVar6 + 0x1e) = iVar5;
              uVar13 = *(undefined2 *)(iVar6 + 0x20);
              uVar8 = FUN_1000_199e();
              *(undefined2 *)(iVar6 + 0x20) = uVar13;
              *(undefined2 *)(iVar6 + 0x1e) = uVar8;
              FUN_28eb_3328(iVar6,iVar11);
              DAT_5b41_0937 = 0x1000;
              FUN_28eb_2107(puVar9);
              for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
                uVar13 = puVar9[iVar5 * 2 + 0x10];
                uVar8 = puVar9[iVar5 * 2 + 0xf];
                puVar9[iVar5 * 2 + 0x14] = uVar13;
                puVar9[iVar5 * 2 + 0x13] = uVar8;
                puVar9[iVar5 * 2 + 0x18] = uVar13;
                puVar9[iVar5 * 2 + 0x17] = uVar8;
              }
              FUN_28eb_2107(iVar12);
              for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
                uVar13 = *(undefined2 *)(iVar5 * 4 + iVar12 + 0x20);
                uVar8 = *(undefined2 *)(iVar5 * 4 + iVar12 + 0x1e);
                *(undefined2 *)(iVar5 * 4 + iVar12 + 0x28) = uVar13;
                *(undefined2 *)(iVar5 * 4 + iVar12 + 0x26) = uVar8;
                *(undefined2 *)(iVar5 * 4 + iVar12 + 0x30) = uVar13;
                *(undefined2 *)(iVar5 * 4 + iVar12 + 0x2e) = uVar8;
              }
              DAT_5b41_0937 = uStack_8;
              local_18 = (undefined2 *)0x0;
              local_20 = 0;
              local_1e = 0;
              iStack_1a = 0;
              local_1c = 0;
            }
            if ((local_1e != iVar3) || (local_20 != iVar4)) break;
            local_20 = 0;
            local_1e = 0;
            iStack_1a = 0;
            local_1c = 0;
          }
          local_1c = local_20;
          iStack_1a = local_1e;
        } while( true );
      }
LAB_31f7_4f80:
    } while ((undefined2 *)local_18 == (undefined2 *)0x0 && local_18._2_2_ == 0);
    uVar15 = ((undefined2 *)local_18)[1];
    puVar9 = (undefined2 *)*local_18;
  } while( true );
}

