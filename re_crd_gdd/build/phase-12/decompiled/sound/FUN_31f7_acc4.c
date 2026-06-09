// TIM2.EXE: FUN_31f7_acc4 @ file 0x041E34 Ghidra 0x3CC34
// Subsystem: sound | Size: 433 bytes


void __cdecl16far FUN_31f7_acc4(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int *piVar6;
  int *piVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 unaff_SS;
  int local_5e [16];
  int local_3e [16];
  int local_1e;
  int local_1c;
  int local_1a;
  int local_18;
  undefined2 local_16;
  int local_14;
  int local_12;
  int local_10;
  undefined4 local_e;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  piVar6 = (int *)&DAT_554c_3cec;
  piVar7 = local_3e;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    piVar2 = piVar7;
    piVar7 = piVar7 + 1;
    piVar1 = piVar6;
    piVar6 = piVar6 + 1;
    *piVar2 = *piVar1;
  }
  piVar6 = (int *)&DAT_554c_3d0c;
  piVar7 = local_5e;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    piVar2 = piVar7;
    piVar7 = piVar7 + 1;
    piVar1 = piVar6;
    piVar6 = piVar6 + 1;
    *piVar2 = *piVar1;
  }
  uVar8 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  if (*(int *)(iVar4 + 0x16) != 0) {
    if (*(int *)(iVar4 + 0x10) % 7 == 6) {
      *(undefined2 *)(iVar4 + 0x16) = 0;
    }
    else {
      *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
      if (*(int *)(iVar4 + 0x10) % 7 == 3) {
        local_10 = *(int *)(iVar4 + 0x10) / 7;
        local_6 = local_3e[local_10 * 2] + *(int *)(iVar4 + 0x22);
        local_4 = local_3e[local_10 * 2 + 1] + *(int *)(iVar4 + 0x24);
        puVar5 = DAT_5b41_0557;
        iVar3 = DAT_5b41_0559;
        while (local_e = (undefined2 *)CONCAT22(iVar3,puVar5),
              puVar5 != (undefined2 *)0x0 || iVar3 != 0) {
          if ((*(byte *)((int)puVar5 + 0xd) & 0x20) == 0) {
            local_a = local_5e[local_10 * 2] + *(int *)(iVar4 + 0x22);
            local_8 = local_5e[local_10 * 2 + 1] + *(int *)(iVar4 + 0x24);
            iVar3 = FUN_31f7_aed1(*(undefined2 *)(local_10 * 2 + 0x3d2c),puVar5,iVar3,&local_6,
                                  &local_a);
            if (iVar3 != 0) {
              uVar9 = (undefined2)((ulong)local_e >> 0x10);
              puVar5 = (undefined2 *)local_e;
              local_12 = puVar5[0x11] + ((int)puVar5[0x24] >> 1);
              local_14 = puVar5[0x12] + ((int)puVar5[0x25] >> 1);
              local_1a = local_a - local_12;
              local_18 = local_1a >> 0xf;
              local_1e = local_14 - local_8;
              local_1c = local_1e >> 0xf;
              local_16 = FUN_2e67_1277(local_1a,local_18,local_1e,local_1c);
              FUN_28eb_3c0f(0x2e67,(undefined2 *)local_e,local_e._2_2_,local_16,0x1c00);
              uVar9 = (undefined2)((ulong)local_e >> 0x10);
              puVar5 = (undefined2 *)local_e;
              if ((puVar5[4] == 0x36) && ((int)puVar5[8] < DAT_5b41_09a3)) {
                puVar5[8] = DAT_5b41_09a3;
              }
            }
          }
          iVar3 = ((undefined2 *)local_e)[1];
          puVar5 = (undefined2 *)*local_e;
        }
      }
      FUN_28eb_3328(iVar4,uVar8);
    }
  }
  return;
}

