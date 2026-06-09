// TIM2.EXE: FUN_4bdc_1ac4 @ file 0x052A84 Ghidra 0x4D884
// Subsystem: misc | Size: 580 bytes


undefined4 __cdecl16near FUN_4bdc_1ac4(void)

{
  int *piVar1;
  byte bVar2;
  undefined2 in_AX;
  byte bVar3;
  undefined2 in_DX;
  int in_BX;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char unaff_DI;
  undefined2 unaff_ES;
  undefined2 uVar8;
  undefined2 uVar9;
  
  uVar9 = 0x554c;
  bRam00040207 = unaff_DI << 2;
  *(int *)(in_BX + 0x154) = *(int *)(in_BX + 0x154) + 1;
  uVar8 = (undefined2)((ulong)*(undefined4 *)*(undefined4 *)(in_BX + 8) >> 0x10);
  iRam000401fd = (int)*(undefined4 *)*(undefined4 *)(in_BX + 8);
  uVar5 = 0;
  do {
    bVar3 = *(byte *)(in_BX + uVar5 + 0x8c);
    if (bVar3 == 0xff) break;
    uVar7 = uVar5;
    if (bVar3 != 0xfe) {
      bRam00040203 = 0xff;
      uRam00040204 = 0;
      if ((*(byte *)(in_BX + (uint)bVar3 + 0x134) & 2) == 0) {
        iVar6 = 0;
        do {
          if (*(byte *)(iVar6 + 0x12e) == (bVar3 & 0xf | bRam00040207)) {
            bRam00040203 = (byte)iVar6;
            break;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 != 0x10);
      }
      else {
        uRam00040204 = 1;
        bRam00040203 = bVar3;
      }
      iVar6 = uVar5 * 2;
      pbVar4 = (byte *)(iRam000401fd + *(int *)(iRam000401fd + iVar6) +
                       *(int *)(in_BX + iVar6 + 0xc));
      if (*(int *)(in_BX + iVar6 + 0xc) == 0) {
        uVar7 = uVar5 & 0x7fff;
      }
      else {
        iVar6 = uVar5 * 2;
        if (*(int *)(in_BX + iVar6 + 0x4c) == 0) {
          uVar7 = uVar5 & 0x7fff;
          do {
            bVar3 = *pbVar4;
            piVar1 = (int *)(in_BX + uVar5 * 2 + 0xc);
            *piVar1 = *piVar1 + 1;
            if (bVar3 < 0x80) {
              bVar3 = *(byte *)(in_BX + uVar7 + 0x9c);
              piVar1 = (int *)(in_BX + uVar5 * 2 + 0xc);
              *piVar1 = *piVar1 + -1;
            }
            else {
              *(byte *)(in_BX + uVar7 + 0x9c) = bVar3;
              pbVar4 = pbVar4 + 1;
            }
            bVar2 = bVar3 & 0xf0;
            if (bVar3 == 0xfc) {
              *(undefined2 *)(in_BX + uVar5 * 2 + 0xc) = 0;
              goto LAB_4bdc_1c8c;
            }
            if ((bVar3 & 0xf) == 0xf) {
              FUN_4bdc_1ff4();
              if (*(int *)(in_BX + uVar5 * 2 + 0xc) == 0) goto LAB_4bdc_1c8c;
            }
            else if (bVar2 == 0x80) {
              FUN_4bdc_1d08();
            }
            else if (bVar2 == 0x90) {
              FUN_4bdc_1d57();
            }
            else if (bVar2 == 0xa0) {
              FUN_4bdc_1dca();
            }
            else if (bVar2 == 0xb0) {
              FUN_4bdc_1dfb();
            }
            else if (bVar2 == 0xc0) {
              FUN_4bdc_1efc();
            }
            else if (bVar2 == 0xd0) {
              FUN_4bdc_1f50();
            }
            else if (bVar2 == 0xe0) {
              FUN_4bdc_1f74();
            }
            else {
              if (bVar2 != 0xf0) {
                *(undefined2 *)(in_BX + uVar5 * 2 + 0xc) = 0;
                goto LAB_4bdc_1c8c;
              }
              FUN_4bdc_1ff0(uVar9);
            }
            bVar3 = *pbVar4;
            pbVar4 = pbVar4 + 1;
            piVar1 = (int *)(in_BX + uVar5 * 2 + 0xc);
            *piVar1 = *piVar1 + 1;
          } while (bVar3 == 0);
          if (bVar3 == 0xf8) {
            *(undefined2 *)(in_BX + uVar5 * 2 + 0x4c) = 0x80ef;
          }
          else {
            *(uint *)(in_BX + uVar5 * 2 + 0x4c) = (uint)(byte)(bVar3 - 1);
          }
        }
        else {
          piVar1 = (int *)(in_BX + iVar6 + 0x4c);
          *piVar1 = *piVar1 + -1;
          if (*(int *)(in_BX + iVar6 + 0x4c) == -0x8000) {
            bVar3 = *pbVar4;
            uVar7 = (uint)bVar3;
            piVar1 = (int *)(in_BX + uVar5 * 2 + 0xc);
            *piVar1 = *piVar1 + 1;
            if (bVar3 == 0xf8) {
              uVar7 = 0x80f0;
            }
            *(uint *)(in_BX + uVar5 * 2 + 0x4c) = uVar7;
          }
          uVar7 = uVar5 & 0x7fff;
        }
      }
    }
LAB_4bdc_1c8c:
    uVar5 = uVar7 + 1;
  } while (uVar5 != 0x10);
  uVar5 = 0;
  do {
    if (*(char *)(in_BX + uVar5 + 0x8c) == -1) break;
    if (*(int *)(in_BX + uVar5 * 2 + 0xc) != 0) goto LAB_4bdc_1cff;
    uVar5 = (uVar5 & 0x7fff) + 1;
  } while (uVar5 != 0x10);
  if ((*(char *)(in_BX + 0x15a) == '\0') && (*(char *)(in_BX + 0x15d) == '\0')) {
    FUN_4bdc_0cf1();
    uRam0004020a = 1;
  }
  else {
    *(undefined2 *)(in_BX + 0x154) = *(undefined2 *)(in_BX + 0x156);
    uVar5 = 0;
    do {
      *(undefined2 *)(in_BX + uVar5 + 0xc) = *(undefined2 *)(in_BX + uVar5 + 0x2c);
      *(undefined2 *)(in_BX + uVar5 + 0x4c) = *(undefined2 *)(in_BX + uVar5 + 0x6c);
      uVar5 = uVar5 >> 1;
      *(undefined1 *)(in_BX + uVar5 + 0x9c) = *(undefined1 *)(in_BX + uVar5 + 0xac);
      uVar5 = uVar5 * 2 + 2;
    } while (uVar5 != 0x20);
  }
LAB_4bdc_1cff:
  return CONCAT22(in_DX,in_AX);
}

