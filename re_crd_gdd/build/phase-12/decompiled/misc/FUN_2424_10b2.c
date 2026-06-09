// TIM2.EXE: FUN_2424_10b2 @ file 0x02A4F2 Ghidra 0x252F2
// Subsystem: misc | Size: 579 bytes


void __cdecl16far FUN_2424_10b2(void)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  undefined4 local_6;
  
  DAT_5b41_04b4 = 0;
  local_14 = 0;
  do {
    if (1 < local_14) {
      return;
    }
    if (local_14 == 0) {
      puVar2 = (undefined2 *)&DAT_5b41_054f;
    }
    else {
      puVar2 = (undefined2 *)&DAT_5b41_0557;
    }
    local_6 = (undefined2 *)CONCAT22(0x554c,puVar2);
LAB_2424_12ce:
    iVar1 = ((undefined2 *)local_6)[1];
    puVar2 = (undefined2 *)*local_6;
    local_6 = (undefined2 *)CONCAT22(iVar1,puVar2);
    if (puVar2 != (undefined2 *)0x0 || iVar1 != 0) {
      if (DAT_5b41_04b4 != 0) {
        DAT_5b41_04b4 = 0;
        local_14 = 0;
        local_6 = &DAT_5b41_054f;
        goto LAB_2424_12ce;
      }
      if (*(char *)(puVar2 + 0xc) == -0x80) {
        *(undefined1 *)(puVar2 + 0xc) = 0;
      }
      if ((*(byte *)((int)puVar2 + 0xf) & 0x20) == 0) {
        iVar3 = 0;
        local_a = 0;
      }
      else {
        local_a = puVar2[0x57];
        iVar3 = puVar2[0x5a];
      }
      if (((*(char *)(puVar2 + 0xc) == '\0') && ((*(byte *)((int)puVar2 + 0xd) & 0x20) == 0)) &&
         ((*(byte *)((int)puVar2 + 0xf) & 0x40) == 0)) {
        if ((puVar2[4] == 10) || (puVar2[4] == 0x4c)) {
          FUN_2424_12f5(puVar2,iVar1);
        }
        else if (puVar2[4] != 0x31) {
          if (puVar2[4] == 8) {
            iVar5 = puVar2[0x2c];
            if (((iVar5 == 0) || (iVar4 = FUN_28eb_1c08(iVar5), iVar4 == 0)) ||
               ((DAT_5b41_0939 == 9 &&
                ((((*(int *)(iVar5 + 8) == DAT_5b41_0567._2_2_ &&
                   (*(int *)(iVar5 + 6) == (int)DAT_5b41_0567)) ||
                  ((*(int *)(iVar5 + 0xc) == DAT_5b41_0567._2_2_ &&
                   (*(int *)(iVar5 + 10) == (int)DAT_5b41_0567)))) &&
                 (iVar4 = FUN_28eb_4d94(), iVar4 == 0)))))) goto LAB_2424_12ce;
            if (*(int *)(iVar5 + 0xe) < *(int *)(iVar5 + 0x12)) {
              local_c = *(int *)(iVar5 + 0xe) - DAT_5b41_0925;
              local_10 = *(int *)(iVar5 + 0x1a) - *(int *)(iVar5 + 0xe);
            }
            else {
              local_c = *(int *)(iVar5 + 0x12) - DAT_5b41_0925;
              local_10 = *(int *)(iVar5 + 0x16) - *(int *)(iVar5 + 0x12);
            }
            local_10 = local_c + local_10;
            puVar6 = DAT_5b41_04ac;
            if (*(int *)(iVar5 + 0x10) < *(int *)(iVar5 + 0x14)) {
              local_e = *(int *)(iVar5 + 0x10) - DAT_5b41_0927;
              local_12 = local_e + (*(int *)(iVar5 + 0x1c) - *(int *)(iVar5 + 0x10));
            }
            else {
              local_e = *(int *)(iVar5 + 0x14) - DAT_5b41_0927;
              local_12 = local_e + (*(int *)(iVar5 + 0x18) - *(int *)(iVar5 + 0x14));
            }
          }
          else {
            local_c = puVar2[0x17] - DAT_5b41_0925;
            local_e = puVar2[0x18] - DAT_5b41_0927;
            local_10 = puVar2[0x24] + local_c;
            local_12 = puVar2[0x25] + local_e;
            puVar6 = DAT_5b41_04ac;
          }
          for (; puVar6 != (undefined2 *)0x0; puVar6 = (undefined2 *)*puVar6) {
            if ((puVar6[6] == 1) &&
               ((((((int)puVar6[1] < local_10 && (local_c <= (int)puVar6[3])) &&
                  ((int)puVar6[2] < local_12)) && (local_e <= (int)puVar6[4])) ||
                (((iVar3 != 0 || (local_a != 0)) &&
                 (iVar5 = FUN_2424_36fe(puVar2,iVar1,puVar6), iVar5 != 0)))))) {
              FUN_28eb_2d82(puVar2,iVar1,0x81);
              break;
            }
          }
        }
      }
      goto LAB_2424_12ce;
    }
    local_14 = local_14 + 1;
  } while( true );
}

