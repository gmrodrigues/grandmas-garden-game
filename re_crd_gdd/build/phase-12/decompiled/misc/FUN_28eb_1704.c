// TIM2.EXE: FUN_28eb_1704 @ file 0x02F7B4 Ghidra 0x2A5B4
// Subsystem: misc | Size: 1150 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far FUN_28eb_1704(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int local_1a;
  int local_18;
  int local_16;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  _DAT_5b41_058f = FUN_28eb_12a3((int)param_1,param_1._2_2_);
  FUN_28eb_1599((int)param_1,param_1._2_2_,&local_1a);
  local_c = local_1a - DAT_5b41_0925;
  local_e = local_c + local_16;
  local_10 = local_18 - DAT_5b41_0927;
  local_12 = local_10 + local_14;
  local_1a = local_1a - DAT_5b41_0925;
  local_4 = local_16 / 2 + local_1a;
  local_16 = local_1a + local_16;
  local_6 = local_18 - DAT_5b41_0927;
  local_8 = local_14 / 2 + local_6;
  local_a = local_6 + local_14;
  if (((((_DAT_5b41_058f & 0x410) == 0) || (DAT_5b41_1b84 <= DAT_5b41_0513)) ||
      (DAT_5b41_0513 + 0x24 <= DAT_5b41_1b84)) ||
     ((DAT_5b41_1b86 < DAT_5b41_0515 || (DAT_5b41_0515 + 0x24 <= DAT_5b41_1b86)))) {
    if (((((_DAT_5b41_058f & 0x40) == 0) ||
         ((DAT_5b41_1b84 < local_1a + -0x24 || (local_1a <= DAT_5b41_1b84)))) ||
        (DAT_5b41_1b86 < local_6 + -0x24)) || (local_6 <= DAT_5b41_1b86)) {
      if (((((_DAT_5b41_058f & 0x1000) == 0) || (DAT_5b41_1b84 < local_16)) ||
          (local_16 + 0x24 <= DAT_5b41_1b84)) ||
         ((DAT_5b41_1b86 < local_6 + -0x24 || (local_6 <= DAT_5b41_1b86)))) {
        if ((((_DAT_5b41_058f & 0x2000) == 0) ||
            ((DAT_5b41_1b84 < local_16 || (local_16 + 0x24 <= DAT_5b41_1b84)))) ||
           ((DAT_5b41_1b86 < local_a || (local_a + 0x24 <= DAT_5b41_1b86)))) {
          if ((_DAT_5b41_058f & 1) != 0) {
            if ((((local_1a + -0x24 <= DAT_5b41_1b84) && (DAT_5b41_1b84 < local_1a)) &&
                (local_8 + -9 <= DAT_5b41_1b86)) && (DAT_5b41_1b86 < local_8 + 9)) {
              FUN_28eb_1283(9);
              return 3;
            }
            if (((local_16 < DAT_5b41_1b84) && (DAT_5b41_1b84 < local_16 + 0x24)) &&
               ((local_8 + -9 <= DAT_5b41_1b86 && (DAT_5b41_1b86 < local_8 + 9)))) {
              FUN_28eb_1283(9);
              return 4;
            }
          }
          if ((_DAT_5b41_058f & 2) != 0) {
            if (((local_6 + -0x24 <= DAT_5b41_1b86) && (DAT_5b41_1b86 < local_6)) &&
               ((local_4 + -9 <= DAT_5b41_1b84 && (DAT_5b41_1b84 < local_4 + 9)))) {
              FUN_28eb_1283(9);
              return 5;
            }
            if ((((local_a < DAT_5b41_1b86) && (DAT_5b41_1b86 < local_a + 0x24)) &&
                (local_4 + -9 <= DAT_5b41_1b84)) && (DAT_5b41_1b84 < local_4 + 9)) {
              FUN_28eb_1283(9);
              return 6;
            }
          }
          if ((((_DAT_5b41_058f & 0xc) == 0) || (DAT_5b41_1b84 < local_1a + -0x24)) ||
             ((local_1a <= DAT_5b41_1b84 ||
              ((DAT_5b41_1b86 <= local_a || (local_a + 0x24 <= DAT_5b41_1b86)))))) {
            if ((((_DAT_5b41_058f & 0x20) == 0) ||
                (((DAT_5b41_1b84 <= local_16 || (local_16 + 0x29 <= DAT_5b41_1b84)) ||
                 (DAT_5b41_1b86 <= local_a)))) || (local_a + 0x29 <= DAT_5b41_1b86)) {
              if ((((_DAT_5b41_058f & 0x200) == 0) || (DAT_5b41_1b86 < local_6 + -0x24)) ||
                 ((local_6 <= DAT_5b41_1b86 ||
                  ((DAT_5b41_1b84 < local_4 + -0x12 || (local_4 + 0x12 <= DAT_5b41_1b84)))))) {
                if (((_DAT_5b41_058f & 0x80) == 0) ||
                   ((((DAT_5b41_1b84 <= local_16 || (local_16 + 0x24 <= DAT_5b41_1b84)) ||
                     (DAT_5b41_1b86 < local_8 + -0x12)) || (local_8 + 0x12 <= DAT_5b41_1b86)))) {
                  if ((((_DAT_5b41_058f & 0x800) == 0) || (DAT_5b41_1b84 < local_1a + -0x24)) ||
                     ((local_1a <= DAT_5b41_1b84 ||
                      ((DAT_5b41_1b86 <= local_a || (local_a + 0x24 <= DAT_5b41_1b86)))))) {
                    if ((((_DAT_5b41_058f & 0x100) == 0) ||
                        ((((DAT_5b41_1b84 < local_c || (local_e <= DAT_5b41_1b84)) ||
                          (DAT_5b41_1b86 < local_10)) || (local_12 <= DAT_5b41_1b86)))) ||
                       ((((DAT_5b41_04ec != 0 || DAT_5b41_04ee != 0 &&
                          ((DAT_5b41_04ee != param_1._2_2_ || (DAT_5b41_04ec != (int)param_1)))) &&
                         (((*(byte *)((int)param_1 + 0xf) & 0x10) != 0 ||
                          (iVar1 = FUN_28eb_03ff(0,0,(int)param_1,param_1._2_2_), iVar1 == 0)))) &&
                        (((*(int *)((int)param_1 + 8) != 10 && (*(int *)((int)param_1 + 8) != 0x4c))
                         && (*(int *)((int)param_1 + 8) != 8)))))) {
                      uVar2 = 10;
                    }
                    else {
                      iVar1 = *(int *)((int)param_1 + 8);
                      if (iVar1 == 8) {
                        uVar2 = 5;
                      }
                      else if (iVar1 == 10) {
                        uVar2 = 6;
                      }
                      else if (iVar1 == 0x4c) {
                        uVar2 = 0x26;
                      }
                      else {
                        uVar2 = 4;
                      }
                      FUN_28eb_1283(uVar2);
                      uVar2 = 7;
                    }
                  }
                  else {
                    FUN_28eb_1283(0xb);
                    uVar2 = 0xd;
                  }
                }
                else {
                  FUN_28eb_1283(0xb);
                  uVar2 = 0xd;
                }
              }
              else {
                FUN_28eb_1283(0x1c);
                uVar2 = 0xe;
              }
            }
            else {
              FUN_28eb_1283(0xc);
              uVar2 = 0xc;
            }
          }
          else {
            FUN_28eb_1283(8);
            if ((*(uint *)((int)param_1 + 10) & 0x600) == 0x400) {
              uVar2 = 1;
            }
            else if ((*(uint *)((int)param_1 + 10) & 0x600) == 0x200) {
              uVar2 = 2;
            }
            else {
              uVar2 = 0xf;
            }
          }
        }
        else {
          FUN_28eb_1283(0x2d);
          uVar2 = 0x11;
        }
      }
      else {
        FUN_28eb_1283(0x2c);
        uVar2 = 0x10;
      }
    }
    else {
      FUN_28eb_1283(7);
      uVar2 = 8;
    }
  }
  else {
    if ((*(byte *)((int)param_1 + 0xe) & 0x40) == 0) {
      uVar2 = 10;
    }
    else {
      uVar2 = 0x1d;
    }
    FUN_28eb_1283(uVar2);
    uVar2 = 0xb;
  }
  return uVar2;
}

