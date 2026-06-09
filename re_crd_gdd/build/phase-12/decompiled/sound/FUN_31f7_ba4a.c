// TIM2.EXE: FUN_31f7_ba4a @ file 0x042BBA Ghidra 0x3D9BA
// Subsystem: sound | Size: 2451 bytes


void __cdecl16far FUN_31f7_ba4a(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar2 = *(int *)(iVar3 + 8);
  if (iVar2 == 0x19) {
    if (*(int *)(iVar3 + 0x16) != 0) {
      return;
    }
    if (param_2 != 1) {
      return;
    }
    if ((*(byte *)(iVar3 + 0xc) & 0x10) != 0) {
      iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x19,DAT_5b41_1aca,DAT_5b41_1acc);
      if (iVar2 != 0) goto LAB_31f7_bc70;
      iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x23,DAT_5b41_1aca,DAT_5b41_1acc);
joined_r0x0003dbdb:
      if (iVar2 == 0) {
        return;
      }
LAB_31f7_bc70:
      *(undefined2 *)(iVar3 + 0x16) = 1;
      return;
    }
    iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 10,DAT_5b41_1aca,DAT_5b41_1acc);
    if (iVar2 != 0) goto LAB_31f7_bd12;
    iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x14,DAT_5b41_1aca,DAT_5b41_1acc);
  }
  else {
    if (0x19 < iVar2) {
      if (iVar2 == 0x4e) {
        if (*(int *)(iVar3 + 0x16) != 0) {
          return;
        }
        iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 8,DAT_5b41_1ace,DAT_5b41_1ad0);
        if ((iVar2 == 0) &&
           (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 0x18,DAT_5b41_1ace,DAT_5b41_1ad0),
           iVar2 == 0)) {
          return;
        }
        iVar2 = FUN_2e67_1398(*(undefined2 *)(iVar3 + 0x22),DAT_5b41_1aca,DAT_5b41_1acc);
        if (((iVar2 != 0) ||
            (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 10,DAT_5b41_1aca,DAT_5b41_1acc),
            iVar2 != 0)) ||
           (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x20,DAT_5b41_1aca,DAT_5b41_1acc),
           iVar2 != 0)) goto LAB_31f7_bf8d;
        iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x2e,DAT_5b41_1aca,DAT_5b41_1acc);
      }
      else {
        if (iVar2 < 0x4f) {
          if ((iVar2 != 0x25) && (iVar2 != 0x4d)) {
            return;
          }
          if (*(int *)(iVar3 + 0x16) != 0) {
            return;
          }
          if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
            iVar2 = FUN_2e67_1398(*(undefined2 *)(iVar3 + 0x22),DAT_5b41_1aca,DAT_5b41_1acc);
            if (iVar2 != 0) goto LAB_31f7_bc70;
            iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x16,DAT_5b41_1aca,DAT_5b41_1acc);
            goto joined_r0x0003dbdb;
          }
          iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x20,DAT_5b41_1aca,DAT_5b41_1acc);
          if (iVar2 != 0) goto LAB_31f7_bbcb;
          iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x36,DAT_5b41_1aca,DAT_5b41_1acc);
          goto joined_r0x0003db36;
        }
        if (iVar2 != 0x89) {
          if (iVar2 != 0x8b) {
            return;
          }
          goto LAB_31f7_bfe0;
        }
        if (*(int *)(iVar3 + 0x16) != 0) {
          return;
        }
        iVar2 = FUN_2e67_1398(*(undefined2 *)(iVar3 + 0x24),DAT_5b41_1ace,DAT_5b41_1ad0);
        if ((iVar2 == 0) &&
           (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 10,DAT_5b41_1ace,DAT_5b41_1ad0),
           iVar2 == 0)) {
          return;
        }
        if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
          iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0xb,DAT_5b41_1aca,DAT_5b41_1acc);
          if (iVar2 != 0) goto LAB_31f7_c084;
          iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x16,DAT_5b41_1aca,DAT_5b41_1acc);
          goto joined_r0x0003df48;
        }
        iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x1a,DAT_5b41_1aca,DAT_5b41_1acc);
        if (iVar2 != 0) goto LAB_31f7_bf8d;
        iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x25,DAT_5b41_1aca,DAT_5b41_1acc);
      }
      if (iVar2 == 0) {
        return;
      }
LAB_31f7_bf8d:
      *(undefined2 *)(iVar3 + 0x16) = 1;
      return;
    }
    if (iVar2 == 0x10) {
      if (*(int *)(iVar3 + 0x16) != 0) {
        return;
      }
      if ((*(byte *)(iVar3 + 0xc) & 0x10) != 0) {
        iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x19,DAT_5b41_1aca,DAT_5b41_1acc);
        if ((iVar2 == 0) &&
           (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x2d,DAT_5b41_1aca,DAT_5b41_1acc),
           iVar2 == 0)) {
          return;
        }
        *(undefined2 *)(iVar3 + 0x16) = 1;
        return;
      }
      iVar2 = FUN_2e67_1398(*(undefined2 *)(iVar3 + 0x22),DAT_5b41_1aca,DAT_5b41_1acc);
      if (iVar2 != 0) goto LAB_31f7_bbcb;
      iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x14,DAT_5b41_1aca,DAT_5b41_1acc);
joined_r0x0003db36:
      if (iVar2 == 0) {
        return;
      }
LAB_31f7_bbcb:
      *(undefined2 *)(iVar3 + 0x16) = 1;
      return;
    }
    if (iVar2 < 0x11) {
      if (iVar2 != 3) {
        if (iVar2 == 6) {
          FUN_31f7_111e(iVar3,uVar4);
          return;
        }
        if (iVar2 != 0xf) {
          return;
        }
        FUN_31f7_1e38(iVar3,uVar4);
        return;
      }
LAB_31f7_bfe0:
      if (param_2 == 1) {
        iVar2 = *(int *)(iVar3 + 0x10);
        if (iVar2 == 0) {
          iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x34,DAT_5b41_1aca,DAT_5b41_1acc);
          if ((iVar2 == 0) &&
             (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x4f,DAT_5b41_1aca,DAT_5b41_1acc),
             iVar2 == 0)) {
            return;
          }
          iVar2 = FUN_2e67_1398(*(undefined2 *)(iVar3 + 0x24),DAT_5b41_1ace,DAT_5b41_1ad0);
          if (iVar2 != 0) goto LAB_31f7_c084;
          iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 0xe,DAT_5b41_1ace,DAT_5b41_1ad0);
joined_r0x0003df48:
          if (iVar2 == 0) {
            return;
          }
LAB_31f7_c084:
          *(undefined2 *)(iVar3 + 0x16) = 1;
          return;
        }
        if (iVar2 == 1) {
          iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 0x10,DAT_5b41_1ace,DAT_5b41_1ad0);
          if ((iVar2 == 0) &&
             (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 0x17,DAT_5b41_1ace,DAT_5b41_1ad0),
             iVar2 == 0)) {
            return;
          }
          iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x34,DAT_5b41_1aca,DAT_5b41_1acc);
          if ((iVar2 != 0) ||
             (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x4f,DAT_5b41_1aca,DAT_5b41_1acc),
             iVar2 != 0)) {
            *(undefined2 *)(iVar3 + 0x16) = 1;
          }
          iVar2 = FUN_2e67_1398(*(undefined2 *)(iVar3 + 0x22),DAT_5b41_1aca,DAT_5b41_1acc);
          if (iVar2 != 0) goto LAB_31f7_c3d0;
          iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x16,DAT_5b41_1aca,DAT_5b41_1acc);
        }
        else {
          if (iVar2 != 2) {
            return;
          }
          iVar2 = FUN_2e67_1398(*(undefined2 *)(iVar3 + 0x22),DAT_5b41_1aca,DAT_5b41_1acc);
          if ((iVar2 == 0) &&
             (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x16,DAT_5b41_1aca,DAT_5b41_1acc),
             iVar2 == 0)) {
            return;
          }
          iVar2 = FUN_2e67_1398(*(undefined2 *)(iVar3 + 0x24),DAT_5b41_1ace,DAT_5b41_1ad0);
          if (iVar2 != 0) goto LAB_31f7_c3d0;
          iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 0xe,DAT_5b41_1ace,DAT_5b41_1ad0);
        }
      }
      else {
        iVar2 = *(int *)(iVar3 + 0x10);
        if (iVar2 == 0) {
          iVar2 = FUN_2e67_1398(*(undefined2 *)(iVar3 + 0x22),DAT_5b41_1aca,DAT_5b41_1acc);
          if ((iVar2 == 0) &&
             (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x16,DAT_5b41_1aca,DAT_5b41_1acc),
             iVar2 == 0)) {
            return;
          }
          iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 0x1b,DAT_5b41_1ace,DAT_5b41_1ad0);
          if ((iVar2 == 0) &&
             (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 0x26,DAT_5b41_1ace,DAT_5b41_1ad0),
             iVar2 == 0)) {
            return;
          }
          *(undefined2 *)(iVar3 + 0x16) = 1;
          return;
        }
        if (iVar2 == 1) {
          iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 0x10,DAT_5b41_1ace,DAT_5b41_1ad0);
          if ((iVar2 == 0) &&
             (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 0x17,DAT_5b41_1ace,DAT_5b41_1ad0),
             iVar2 == 0)) {
            return;
          }
          iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x34,DAT_5b41_1aca,DAT_5b41_1acc);
          if ((iVar2 != 0) ||
             (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x4f,DAT_5b41_1aca,DAT_5b41_1acc),
             iVar2 != 0)) {
            *(undefined2 *)(iVar3 + 0x16) = 0xffff;
          }
          iVar2 = FUN_2e67_1398(*(undefined2 *)(iVar3 + 0x22),DAT_5b41_1aca,DAT_5b41_1acc);
          if ((iVar2 == 0) &&
             (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x16,DAT_5b41_1aca,DAT_5b41_1acc),
             iVar2 == 0)) {
            return;
          }
          *(undefined2 *)(iVar3 + 0x16) = 1;
          return;
        }
        if (iVar2 != 2) {
          return;
        }
        iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x34,DAT_5b41_1aca,DAT_5b41_1acc);
        if ((iVar2 == 0) &&
           (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x4f,DAT_5b41_1aca,DAT_5b41_1acc),
           iVar2 == 0)) {
          return;
        }
        iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 0x1b,DAT_5b41_1ace,DAT_5b41_1ad0);
        if (iVar2 != 0) goto LAB_31f7_c3d0;
        iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 0x26,DAT_5b41_1ace,DAT_5b41_1ad0);
      }
      if (iVar2 == 0) {
        return;
      }
LAB_31f7_c3d0:
      *(undefined2 *)(iVar3 + 0x16) = 0xffff;
      return;
    }
    if (iVar2 == 0x15) {
      bVar1 = false;
      iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 4,DAT_5b41_1aca,DAT_5b41_1acc);
      if ((iVar2 == 0) &&
         (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0xc,DAT_5b41_1aca,DAT_5b41_1acc),
         iVar2 == 0)) {
        return;
      }
      if ((*(int *)(iVar3 + 0x10) < 4) &&
         ((param_2 == 1 &&
          (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 7,DAT_5b41_1ace,DAT_5b41_1ad0), iVar2 != 0
          )))) {
        bVar1 = true;
      }
      if (((3 < *(int *)(iVar3 + 0x10)) && (param_2 == 0)) &&
         (iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x24) + 0x19,DAT_5b41_1ace,DAT_5b41_1ad0),
         iVar2 != 0)) {
        bVar1 = true;
      }
      if (!bVar1) {
        return;
      }
      if (*(int *)(iVar3 + 0x10) < 4) {
        *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 4;
      }
      else {
        *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + -4;
      }
      FUN_31f7_28c4(iVar3,uVar4);
      FUN_2e67_045f(0xbcd,0,1,1);
      if (*(int *)(iVar3 + 0x10) != *(int *)(iVar3 + 0xa8)) {
        *(undefined2 *)(iVar3 + 0x16) = 1;
        return;
      }
      *(undefined2 *)(iVar3 + 0x16) = 0;
      return;
    }
    if (iVar2 != 0x16) {
      return;
    }
    if (*(int *)(iVar3 + 0x16) != 0) {
      return;
    }
    if (param_2 != 1) {
      return;
    }
    iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0xb,DAT_5b41_1aca,DAT_5b41_1acc);
    if (iVar2 != 0) goto LAB_31f7_bd12;
    iVar2 = FUN_2e67_1398(*(int *)(iVar3 + 0x22) + 0x1b,DAT_5b41_1aca,DAT_5b41_1acc);
  }
  if (iVar2 == 0) {
    return;
  }
LAB_31f7_bd12:
  *(undefined2 *)(iVar3 + 0x16) = 1;
  return;
}

