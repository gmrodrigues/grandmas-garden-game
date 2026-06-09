// TIM2.EXE decompiled function: FUN_31f7_13f1
// Source: file offset 0x055353 → Ghidra 0x50153
// Body: 0x33361 - 0x33903
// Size: 1431 bytes


void __cdecl16far FUN_31f7_13f1(undefined4 param_1)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  int local_16;
  int iStack_14;
  int local_12;
  int local_10;
  int local_a;
  int local_8;
  
  iVar10 = (int)((ulong)param_1 >> 0x10);
  iVar8 = (int)param_1;
  uVar3 = *(int *)(iVar8 + 0x24) - *(int *)(iVar8 + 0x2c);
  uVar7 = (int)uVar3 >> 0xf;
  uVar9 = (uint)(DAT_5b41_0975 <= *(int *)(iVar8 + 0x10));
  if ((*(byte *)(iVar8 + 0xc) & 0x20) != 0) {
    if ((*(byte *)(iVar8 + 10) & 2) == 0) {
      if (*(int *)(iVar8 + 0x10) == ((undefined2 *)&DAT_5b41_0977)[uVar9]) {
        *(int *)(iVar8 + 0x10) = *(int *)(iVar8 + 0x10) + 1;
      }
    }
    else {
      *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) & 0xffdf;
      *(undefined2 *)(iVar8 + 0x10) = 0;
    }
    goto LAB_31f7_1977;
  }
  if (*(int *)(iVar8 + 0x10) == ((undefined2 *)&DAT_5b41_0973)[uVar9]) {
    if (((DAT_5b41_051f & 1) != 0) && (DAT_554c_3a4e = DAT_554c_3a4e + -1, DAT_554c_3a4e < 1)) {
      uVar4 = FUN_460e_1a42();
      DAT_554c_3a4e = uVar4 % 0x8c + 0x50;
      uVar4 = FUN_460e_1a42();
      uVar4 = uVar4 % 3;
      if (uVar4 == 0) {
        uVar11 = ((undefined2 *)&DAT_5b41_197a)[uVar9];
      }
      else if (uVar4 == 1) {
        uVar11 = ((undefined2 *)&DAT_5b41_197e)[uVar9];
      }
      else {
        if (uVar4 != 2) goto LAB_31f7_1526;
        uVar11 = ((undefined2 *)&DAT_5b41_1982)[uVar9];
      }
LAB_31f7_151f:
      *(undefined2 *)(iVar8 + 0x10) = uVar11;
    }
  }
  else if ((*(int *)(iVar8 + 0x10) != 0) &&
          (*(int *)(iVar8 + 0x10) < (int)((undefined2 *)&DAT_5b41_0977)[uVar9])) {
    *(int *)(iVar8 + 0x10) = *(int *)(iVar8 + 0x10) + 1;
    iVar6 = FUN_4551_0308(DAT_5b41_09c6,*(undefined2 *)(iVar8 + 0x10));
    if (iVar6 != 0) {
      uVar11 = ((undefined2 *)&DAT_5b41_0973)[uVar9];
      goto LAB_31f7_151f;
    }
  }
LAB_31f7_1526:
  if (((int)((uVar3 ^ uVar7) - uVar7) < 2) ||
     ((int)((undefined2 *)&DAT_5b41_1986)[uVar9] <= *(int *)(iVar8 + 0x10))) {
    if ((*(int *)(iVar8 + 0x10) < (int)((undefined2 *)&DAT_5b41_0977)[uVar9]) ||
       ((int)((undefined2 *)&DAT_5b41_1986)[uVar9] <= *(int *)(iVar8 + 0x10))) {
      if (*(int *)(iVar8 + 0x10) < (int)((undefined2 *)&DAT_5b41_1986)[uVar9]) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
        *(int *)(iVar8 + 0x10) = *(int *)(iVar8 + 0x10) + 1;
        if (*(int *)(iVar8 + 0x10) == ((undefined2 *)&DAT_5b41_198a)[uVar9]) {
          *(undefined2 *)(iVar8 + 0x10) = ((undefined2 *)&DAT_5b41_0973)[uVar9];
        }
      }
      if (((*(byte *)(iVar8 + 10) & 1) != 0) &&
         ((*(int *)(iVar8 + 0x10) < (int)((undefined2 *)&DAT_5b41_0977)[uVar9] ||
          ((int)((undefined2 *)&DAT_5b41_1986)[uVar9] <= *(int *)(iVar8 + 0x10))))) {
        if ((*(byte *)(iVar8 + 0xc) & 0x10) == 0) {
          uVar12 = 400;
          uVar11 = 0;
        }
        else {
          uVar12 = 0;
          uVar11 = 0xfe70;
        }
        FUN_28eb_4f3d(iVar8,iVar10,0x3000,uVar11,uVar12,0,0);
        local_16 = iVar8;
        iStack_14 = iVar10;
LAB_31f7_195c:
        piVar1 = (int *)(local_16 + 0x8e);
        local_16 = *(int *)(local_16 + 0x8c);
        iStack_14 = *piVar1;
        do {
          if (local_16 == 0 && iStack_14 == 0) break;
          iVar6 = *(int *)(local_16 + 8);
          if (iVar6 == 0xf) {
            if (*(int *)(local_16 + 0x10) < DAT_5b41_099f) {
              local_12 = 0x60;
            }
            else {
              local_12 = 0x124;
            }
          }
          else {
            if (iVar6 == 0x2a) {
              iVar6 = (*(int *)(local_16 + 0x22) - *(int *)(iVar8 + 0x22)) + 0x10;
              iVar5 = *(int *)(local_16 + 0x24) - *(int *)(iVar8 + 0x24);
              if ((*(byte *)(iVar8 + 0xc) & 0x10) == 0) {
                local_8 = 0x22;
                if (*(int *)(iVar8 + 0x10) < ((undefined2 *)&DAT_5b41_198a)[uVar9] + -1)
                goto LAB_31f7_17d3;
                local_a = 0x56;
              }
              else {
                if (*(int *)(iVar8 + 0x10) < ((undefined2 *)&DAT_5b41_198a)[uVar9] + -1) {
                  local_8 = -4;
                }
                else {
                  local_8 = -0x1e;
                }
LAB_31f7_17d3:
                local_a = 0x36;
              }
              if ((((local_8 < iVar6) && (iVar6 < local_a)) && (10 < iVar5)) && (iVar5 < 0x28)) {
                FUN_2424_0f94(local_16,iStack_14,3);
                *(uint *)(local_16 + 0xc) = *(uint *)(local_16 + 0xc) | 0x2000;
                if (uVar9 == 0) {
                  uVar9 = 1;
                  *(int *)(iVar8 + 0x10) = (*(int *)(iVar8 + 0x10) + DAT_5b41_0975) - DAT_5b41_0973;
                  if (DAT_5b41_198c <= *(int *)(iVar8 + 0x10)) {
                    *(int *)(iVar8 + 0x10) = DAT_5b41_0975;
                  }
                }
              }
              else if (10 < iVar5) {
                if (bVar2) {
                  local_12 = 400;
                }
                else {
                  local_12 = 0x154;
                }
                goto LAB_31f7_1885;
              }
            }
            else if ((iVar6 == 0x43) && (*(int *)(local_16 + 0x10) == DAT_5b41_09a1)) {
              local_12 = 0xe0;
              goto LAB_31f7_1885;
            }
            local_12 = -1;
          }
LAB_31f7_1885:
          uVar3 = (int)*(uint *)(local_16 + 0x90) >> 0xf;
          if ((local_12 <= (int)((*(uint *)(local_16 + 0x90) ^ uVar3) - uVar3)) ||
             ((int)((undefined2 *)&DAT_5b41_0977)[uVar9] <= *(int *)(iVar8 + 0x10)))
          goto LAB_31f7_195c;
          if ((*(byte *)(iVar8 + 0xc) & 0x10) == 0) {
            local_10 = 0x2c;
          }
          else {
            local_10 = -0x2c;
          }
          *(undefined2 *)(iVar8 + 0xae) = 0;
          *(int *)(iVar8 + 0x22) = *(int *)(iVar8 + 0x22) + local_10;
          FUN_28eb_3328(iVar8,iVar10);
          iVar6 = FUN_28eb_0119(iVar8,iVar10);
          if (iVar6 == 0) {
            *(undefined2 *)(iVar8 + 0x10) = ((undefined2 *)&DAT_5b41_1986)[uVar9];
          }
          else {
            *(int *)(iVar8 + 0x22) = *(int *)(iVar8 + 0x22) - local_10;
            FUN_28eb_3328(iVar8,iVar10);
            *(undefined2 *)(iVar8 + 0x10) = 0;
          }
          local_16 = 0;
          iStack_14 = 0;
          iVar6 = *(int *)(iVar8 + 0x22);
          *(int *)(iVar8 + 0x1c) = iVar6 >> 0xf;
          *(int *)(iVar8 + 0x1a) = iVar6;
          uVar11 = *(undefined2 *)(iVar8 + 0x1c);
          uVar12 = FUN_1000_199e();
          *(undefined2 *)(iVar8 + 0x1c) = uVar11;
          *(undefined2 *)(iVar8 + 0x1a) = uVar12;
        } while( true );
      }
    }
    else {
      *(int *)(iVar8 + 0x10) = *(int *)(iVar8 + 0x10) + 1;
      if (*(int *)(iVar8 + 0x10) == ((undefined2 *)&DAT_5b41_1986)[uVar9]) {
        *(int *)(iVar8 + 0x10) = ((undefined2 *)&DAT_5b41_0977)[uVar9] + 1;
      }
      *(int *)(iVar8 + 0xae) = *(int *)(iVar8 + 0xae) + 1;
      if (0xc < *(int *)(iVar8 + 0xae)) {
        if ((*(byte *)(iVar8 + 0xc) & 0x10) == 0) {
          local_10 = 0x2c;
        }
        else {
          local_10 = -0x2c;
        }
        *(undefined2 *)(iVar8 + 0xae) = 0;
        *(int *)(iVar8 + 0x22) = *(int *)(iVar8 + 0x22) + local_10;
        FUN_28eb_3328(iVar8,iVar10);
        iVar6 = FUN_28eb_0119(iVar8,iVar10);
        if (iVar6 == 0) {
          *(undefined2 *)(iVar8 + 0x10) = ((undefined2 *)&DAT_5b41_1986)[uVar9];
        }
        else {
          *(int *)(iVar8 + 0x22) = *(int *)(iVar8 + 0x22) + local_10 * -2;
          FUN_28eb_3328(iVar8,iVar10);
          iVar6 = FUN_28eb_0119(iVar8,iVar10);
          if (iVar6 == 0) {
            *(undefined2 *)(iVar8 + 0x10) = ((undefined2 *)&DAT_5b41_1986)[uVar9];
            *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) ^ 0x10;
          }
          else {
            *(int *)(iVar8 + 0x22) = *(int *)(iVar8 + 0x22) + local_10;
            FUN_28eb_3328(iVar8,iVar10);
            *(undefined2 *)(iVar8 + 0x10) = 0;
          }
        }
        iVar6 = *(int *)(iVar8 + 0x22);
        *(int *)(iVar8 + 0x1c) = iVar6 >> 0xf;
        *(int *)(iVar8 + 0x1a) = iVar6;
        uVar11 = *(undefined2 *)(iVar8 + 0x1c);
        uVar12 = FUN_1000_199e();
        *(undefined2 *)(iVar8 + 0x1c) = uVar11;
        *(undefined2 *)(iVar8 + 0x1a) = uVar12;
      }
    }
  }
  else if (*(int *)(iVar8 + 0xae) < 5) {
    *(int *)(iVar8 + 0xae) = *(int *)(iVar8 + 0xae) + 1;
  }
  else {
    *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) | 0x20;
    *(undefined2 *)(iVar8 + 0x10) = ((undefined2 *)&DAT_5b41_0977)[uVar9];
    *(undefined2 *)(iVar8 + 0xae) = 0;
  }
LAB_31f7_1977:
  if (*(int *)(iVar8 + 0x10) != *(int *)(iVar8 + 0x12)) {
    FUN_28eb_3328(iVar8,iVar10);
  }
  return;
}


