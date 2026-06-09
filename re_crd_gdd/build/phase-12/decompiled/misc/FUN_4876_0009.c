// TIM2.EXE: FUN_4876_0009 @ file 0x04D969 Ghidra 0x48769
// Subsystem: misc | Size: 955 bytes


int __cdecl16far FUN_4876_0009(undefined2 param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  int in_DX;
  undefined2 *puVar7;
  undefined2 uVar8;
  undefined1 local_70 [80];
  int local_20;
  int local_1e;
  int local_1c;
  uint local_1a;
  int local_18;
  int local_16;
  undefined2 *local_14;
  int local_12;
  int local_10;
  undefined4 local_e;
  undefined2 *local_a;
  int iStack_8;
  undefined4 local_6;
  
  iVar3 = FUN_1a9e_69e9(param_1);
  if (iVar3 == 0) {
    DAT_5b41_1ad2 = 2;
    iVar3 = 0;
  }
  else {
    iVar4 = FUN_1a9e_6a85(iVar3,0x3fe4,param_2);
    if ((((in_DX == -1) && (iVar4 == -1)) || (cVar2 = FUN_42da_0498(iVar3), cVar2 != 'T')) ||
       (cVar2 = FUN_42da_0498(iVar3), cVar2 != 'B')) {
      DAT_5b41_1ad2 = 4;
      FUN_1a9e_6e73(iVar3);
      iVar3 = 0;
    }
    else {
      DAT_5b41_1d04 = FUN_42da_04d6(iVar3);
      FUN_42da_0536(iVar3,local_70);
      local_16 = FUN_42da_04d6(iVar3);
      if (DAT_5b41_1d04 < 0x450) {
        local_10 = FUN_4551_0002(local_70);
        local_18 = local_16 * 0x28;
        for (iVar4 = local_16; iVar4 != 0; iVar4 = iVar4 + -1) {
          local_1a = FUN_42da_04d6(iVar3);
          if (DAT_51a7_00d0 <= local_1a) {
            DAT_5b41_1ad2 = 0x11;
            FUN_1a9e_6e73(iVar3);
            FUN_4551_0177(local_10);
            return 0;
          }
          local_18 = local_18 + *(int *)(local_1a * 0x12 + 0xe2);
        }
        local_14 = (undefined2 *)FUN_22de_01ec(local_18,0,0xb,1);
        if (local_14 == (undefined2 *)0x0 && in_DX == 0) {
          FUN_1a9e_6e73(iVar3);
          FUN_4551_0177(local_10);
          iVar3 = 0;
        }
        else {
          DAT_554c_2f1c = DAT_554c_2f1c + 100;
          local_12 = in_DX;
          local_a = local_14;
          iStack_8 = in_DX;
          for (iVar4 = local_16; iVar4 != 0; iVar4 = iVar4 + -1) {
            local_6 = (undefined2 *)CONCAT22(local_12,local_14);
            uVar5 = FUN_42da_04d6(iVar3);
            ((undefined2 *)local_6)[7] = uVar5;
            uVar5 = FUN_42da_04d6(iVar3);
            ((undefined2 *)local_6)[6] = uVar5;
            uVar5 = FUN_42da_04d6(iVar3);
            ((undefined2 *)local_6)[9] = uVar5;
            uVar5 = FUN_42da_04d6(iVar3);
            ((undefined2 *)local_6)[10] = uVar5;
            uVar5 = FUN_42da_04d6(iVar3);
            ((undefined2 *)local_6)[0xb] = uVar5;
            uVar5 = FUN_42da_04d6(iVar3);
            ((undefined2 *)local_6)[0xc] = uVar5;
            uVar5 = FUN_42da_04d6(iVar3);
            uVar8 = (undefined2)((ulong)local_6 >> 0x10);
            puVar7 = (undefined2 *)local_6;
            puVar7[0xd] = uVar5;
            puVar7[8] = DAT_554c_2f1c;
            uVar5 = *(undefined2 *)(puVar7[7] * 0x12 + 0xda);
            puVar7[0xf] = *(undefined2 *)(puVar7[7] * 0x12 + 0xdc);
            puVar7[0xe] = uVar5;
            uVar5 = *(undefined2 *)(puVar7[7] * 0x12 + 0xde);
            puVar7[0x11] = *(undefined2 *)(puVar7[7] * 0x12 + 0xe0);
            puVar7[0x10] = uVar5;
            puVar7[0x13] = 2;
            if (puVar7[9] == 0) {
              puVar7[9] = 0xfffd;
            }
            local_e = (int *)CONCAT22(uVar8,puVar7 + 0x14);
            if (DAT_5b41_1d04 < 0x44f) {
              local_20 = 1;
            }
            else {
              local_20 = FUN_42da_04d6(iVar3);
            }
            uVar5 = 0x42da;
            local_1c = FUN_42da_04d6(iVar3);
            *local_e = 0;
            iVar6 = local_1c;
            if (local_1c == -1) {
              iVar6 = 0;
            }
            ((int *)local_e)[1] = iVar6;
            if (((local_1c != 0) && (local_10 != 0)) && (local_20 != 0)) {
              local_1e = FUN_4551_0370(local_10,local_1c);
              uVar5 = (undefined2)((ulong)local_e >> 0x10);
              ((int *)local_e)[1] = local_1e;
              *local_e = local_10;
              ((int *)local_e)[2] = 1;
              while( true ) {
                local_1e = local_1e + 1;
                uVar5 = 0x4551;
                iVar6 = FUN_4551_0308(local_10,local_1e);
                if (iVar6 != 0) break;
                ((int *)local_e)[2] = ((int *)local_e)[2] + 1;
              }
            }
            if (DAT_5b41_1d04 < 0x44e) {
              uVar8 = (undefined2)((ulong)local_6 >> 0x10);
              ((int *)local_e)[4] = -((undefined2 *)local_6)[10];
              iVar6 = -((undefined2 *)local_6)[0xb];
            }
            else {
              iVar6 = FUN_42da_04b8(iVar3);
              ((int *)local_e)[4] = iVar6;
              uVar5 = 0x42da;
              iVar6 = FUN_42da_04b8(iVar3);
            }
            ((int *)local_e)[5] = iVar6;
            uVar8 = (undefined2)((ulong)local_6 >> 0x10);
            puVar7 = (undefined2 *)local_6;
            if (*(int *)(puVar7[7] * 0x12 + 0xd2) != 0 || *(int *)(puVar7[7] * 0x12 + 0xd4) != 0) {
              puVar1 = (undefined2 *)(puVar7[7] * 0x12 + 0xd2);
              (*(code *)*puVar1)(uVar5,puVar7,uVar8,iVar3);
            }
            uVar5 = (undefined2)((ulong)local_6 >> 0x10);
            local_14 = (undefined2 *)
                       ((int)local_14 + *(int *)(((undefined2 *)local_6)[7] * 0x12 + 0xe2) + 0x28);
            ((undefined2 *)local_6)[1] = local_12;
            *local_6 = local_14;
          }
          ((undefined2 *)local_6)[1] = 0;
          *local_6 = 0;
          FUN_1a9e_6e73(iVar3);
          local_a[0x12] = local_a[0x12] | 2;
          FUN_460e_0b44(local_a,iStack_8);
          DAT_5b41_0be0 = DAT_5b41_0be0 + 1;
          iVar3 = DAT_554c_2f1c;
        }
      }
      else {
        FUN_1a9e_6e73(iVar3);
        iVar3 = 0;
      }
    }
  }
  return iVar3;
}

