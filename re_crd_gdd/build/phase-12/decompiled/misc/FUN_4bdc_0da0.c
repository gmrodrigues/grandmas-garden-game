// TIM2.EXE: FUN_4bdc_0da0 @ file 0x051D60 Ghidra 0x4CB60
// Subsystem: misc | Size: 2495 bytes


undefined4 __cdecl16near FUN_4bdc_0da0(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  byte bVar5;
  undefined2 in_AX;
  byte bVar7;
  uint uVar6;
  byte bVar8;
  byte bVar9;
  char cVar10;
  undefined2 in_DX;
  int iVar11;
  uint uVar12;
  uint uVar14;
  int unaff_BP;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar13;
  
  cRam000401ff = cRam000401ff + '\x01';
  uRam0004020a = 0;
  uRam0004012e = 0xffff;
  uRam00040130 = 0xffff;
  uRam00040132 = 0xffff;
  uRam00040134 = 0xffff;
  uRam00040136 = 0xffff;
  uRam00040138 = 0xffff;
  uRam0004013a = 0xffff;
  uRam0004013c = 0xffff;
  uRam0004015e = 0;
  uRam00040160 = 0;
  uRam00040162 = 0;
  uRam00040164 = 0;
  uRam00040166 = 0;
  uRam00040168 = 0;
  uRam0004016a = 0;
  uRam0004016c = 0;
  uRam0004013e = 0;
  uRam00040140 = 0;
  uRam00040142 = 0;
  uRam00040144 = 0;
  uRam00040146 = 0;
  uRam00040148 = 0;
  uRam0004014a = 0;
  uRam0004014c = 0;
  uRam0004014e = 0;
  uRam00040150 = 0;
  uRam00040152 = 0;
  uRam00040154 = 0;
  uRam00040156 = 0;
  uRam00040158 = 0;
  uRam0004015a = 0;
  uRam0004015c = 0;
  uRam0004016e = 0xffff;
  uRam00040170 = 0xffff;
  uRam00040172 = 0xffff;
  uRam00040174 = 0xffff;
  uRam00040176 = 0xffff;
  uRam00040178 = 0xffff;
  uRam0004017a = 0xffff;
  uRam0004017c = 0xffff;
  iRam0004004e = 0;
  iRam00040050 = 0;
  if ((int)((ulong)uRam0004000e >> 0x10) == 0 && (int)uRam0004000e == 0) {
    uRam0004012e = 0xffff;
    uRam00040130 = 0xffff;
    uRam00040132 = 0xffff;
    uRam00040134 = 0xffff;
    uRam00040136 = 0xffff;
    uRam00040138 = 0xffff;
    uRam0004013a = 0xffff;
    uRam0004013c = 0xffff;
  }
  else {
    (*pcRam000556ad)(0x4000);
    unaff_BP = 0;
    iVar15 = 0;
    bVar5 = bRam00040205;
    do {
      uVar14 = (uint)((ulong)*(undefined4 *)(iVar15 + 0xe) >> 0x10) |
               (uint)*(undefined4 *)(iVar15 + 0xe);
      if (uVar14 == 0) break;
      iVar18 = (int)((ulong)*(undefined4 *)(iVar15 + 0xe) >> 0x10);
      iVar11 = (int)*(undefined4 *)(iVar15 + 0xe);
      iVar17 = iRam0004004e;
      iVar4 = iRam00040050;
      if (*(char *)(iVar11 + 0x164) == '\0') {
        if (*(char *)(iVar11 + 0x165) == '\0') {
          uRam000401ae = uRam0004016e;
          uRam000401b0 = uRam00040170;
          uRam000401b2 = uRam00040172;
          uRam000401b4 = uRam00040174;
          uRam000401b6 = uRam00040176;
          uRam000401b8 = uRam00040178;
          uRam000401ba = uRam0004017a;
          uRam000401bc = uRam0004017c;
          uRam0004018e = uRam0004014e;
          uRam00040190 = uRam00040150;
          uRam00040192 = uRam00040152;
          uRam00040194 = uRam00040154;
          uRam00040196 = uRam00040156;
          uRam00040198 = uRam00040158;
          uRam0004019a = uRam0004015a;
          uRam0004019c = uRam0004015c;
          uRam0004019e = uRam0004015e;
          uRam000401a0 = uRam00040160;
          uRam000401a2 = uRam00040162;
          uRam000401a4 = uRam00040164;
          uRam000401a6 = uRam00040166;
          uRam000401a8 = uRam00040168;
          uRam000401aa = uRam0004016a;
          uRam000401ac = uRam0004016c;
          uRam0004017e = uRam0004013e;
          uRam00040180 = uRam00040140;
          uRam00040182 = uRam00040142;
          uRam00040184 = uRam00040144;
          uRam00040186 = uRam00040146;
          uRam00040188 = uRam00040148;
          uRam0004018a = uRam0004014a;
          uRam0004018c = uRam0004014c;
          iVar16 = 0;
          bRam00040209 = bVar5;
          do {
            bVar1 = *(byte *)(iVar11 + iVar16 + 0x8c);
            if ((((bVar1 != 0xff) && (bVar1 != 0xfe)) && (bVar1 != 0xf)) &&
               (((*(byte *)(iVar11 + (uint)bVar1 + 0x134) & 2) == 0 &&
                (*(char *)(iVar11 + (uint)bVar1 + 0x143) == '\0')))) {
              bVar9 = (char)iVar15 << 2 | bVar1;
              bVar7 = *(byte *)(iVar11 + (uint)bVar1 + 0xda) & 0xf;
              bVar8 = *(byte *)(iVar11 + (uint)bVar1 + 0xda) >> 4;
              cVar10 = '\0';
              if (bVar8 != 0) {
                cVar10 = ('\x10' - bVar8) + (char)unaff_BP;
              }
              if (((*(byte *)(iVar11 + (uint)bVar1 + 0x134) & 1) == 0) ||
                 (*(char *)(bVar1 + 0x16e) != -1)) {
                uVar14 = CONCAT11(0xff,bVar9);
                uVar12 = 0;
                do {
                  bVar8 = (byte)uVar12;
                  if (*(char *)(uVar12 + 0x16e) == -1) {
                    if ((bRam00040200 <= bVar8) && (bVar8 <= bRam00040201)) {
                      uVar14 = CONCAT11(bVar8,(char)uVar14);
                    }
                  }
                  else if (*(char *)(uVar12 + 0x16e) == (char)uVar14) goto LAB_4bdc_12a2;
                  uVar12 = (uint)(byte)(bVar8 + 1);
                } while ((byte)(bVar8 + 1) != 0x10);
                if ((char)(uVar14 >> 8) != -1) goto LAB_4bdc_1138;
                iVar17 = iRam0004004e;
                iVar4 = iRam00040050;
                if (cVar10 == '\0') {
                  uVar14 = CONCAT11(0xff,(char)uVar14);
                  bVar8 = 0;
                  iVar17 = 0;
                  do {
                    if (bVar8 < *(byte *)(iVar17 + 0x14e)) {
                      bVar8 = *(byte *)(iVar17 + 0x14e);
                      uVar14 = CONCAT11((char)iVar17,(char)uVar14);
                    }
                    iVar17 = iVar17 + 1;
                  } while (iVar17 != 0x10);
                  bVar8 = (byte)(uVar14 >> 8);
                  if (bVar8 != 0xff) {
                    uVar12 = (uint)bVar8;
                    bVar5 = bVar5 + *(char *)(uVar12 + 0x15e);
                    *(undefined1 *)(uVar12 + 0x16e) = 0xff;
                    *(undefined1 *)(uVar12 + 0x15e) = 0;
                    *(undefined1 *)(uVar12 + 0x14e) = 0;
                    *(undefined1 *)(uVar12 + 0x13e) = 0;
                    goto LAB_4bdc_1138;
                  }
LAB_4bdc_12ae:
                  uRam0004016e = uRam000401ae;
                  uRam00040170 = uRam000401b0;
                  uRam00040172 = uRam000401b2;
                  uRam00040174 = uRam000401b4;
                  uRam00040176 = uRam000401b6;
                  uRam00040178 = uRam000401b8;
                  uRam0004017a = uRam000401ba;
                  uRam0004017c = uRam000401bc;
                  uRam0004014e = uRam0004018e;
                  uRam00040150 = uRam00040190;
                  uRam00040152 = uRam00040192;
                  uRam00040154 = uRam00040194;
                  uRam00040156 = uRam00040196;
                  uRam00040158 = uRam00040198;
                  uRam0004015a = uRam0004019a;
                  uRam0004015c = uRam0004019c;
                  uRam0004015e = uRam0004019e;
                  uRam00040160 = uRam000401a0;
                  uRam00040162 = uRam000401a2;
                  uRam00040164 = uRam000401a4;
                  uRam00040166 = uRam000401a6;
                  uRam00040168 = uRam000401a8;
                  uRam0004016a = uRam000401aa;
                  uRam0004016c = uRam000401ac;
                  uRam0004013e = uRam0004017e;
                  uRam00040140 = uRam00040180;
                  uRam00040142 = uRam00040182;
                  uRam00040144 = uRam00040184;
                  uRam00040146 = uRam00040186;
                  uRam00040148 = uRam00040188;
                  uRam0004014a = uRam0004018a;
                  uRam0004014c = uRam0004018c;
                  iVar17 = iRam0004004e;
                  iVar4 = iRam00040050;
                  bVar5 = bRam00040209;
                }
                break;
              }
              uVar14 = CONCAT11(bVar1,bVar9);
LAB_4bdc_1138:
              if (bVar5 < bVar7) {
                if (cVar10 != '\0') goto LAB_4bdc_12a2;
                do {
                  uVar14 = CONCAT11(0xff,(char)uVar14);
                  bVar8 = 0;
                  iVar17 = 0;
                  do {
                    if (bVar8 < *(byte *)(iVar17 + 0x14e)) {
                      bVar8 = *(byte *)(iVar17 + 0x14e);
                      uVar14 = CONCAT11((char)iVar17,(char)uVar14);
                    }
                    iVar17 = iVar17 + 1;
                  } while (iVar17 != 0x10);
                  bVar8 = (byte)(uVar14 >> 8);
                  if (bVar8 == 0xff) goto LAB_4bdc_12ae;
                  uVar12 = (uint)bVar8;
                  bVar5 = bVar5 + *(char *)(uVar12 + 0x15e);
                  *(undefined1 *)(uVar12 + 0x16e) = 0xff;
                  *(undefined1 *)(uVar12 + 0x15e) = 0;
                  *(undefined1 *)(uVar12 + 0x14e) = 0;
                  *(undefined1 *)(uVar12 + 0x13e) = 0;
                } while (bVar5 < bVar7);
              }
              bVar8 = (byte)(uVar14 >> 8);
              uVar12 = (uint)bVar8;
              *(undefined1 *)(uVar12 + 0x16e) = (char)uVar14;
              *(byte *)(uVar12 + 0x15e) = bVar7;
              bVar5 = bVar5 - bVar7;
              *(char *)(uVar12 + 0x14e) = cVar10;
              if ((*(byte *)(iVar11 + (uint)bVar1 + 0x134) & 1) == 0) {
                *(undefined1 *)(uVar12 + 0x13e) = 0;
              }
              else {
                *(undefined1 *)(uVar12 + 0x13e) = 1;
                if (bVar8 != bVar1) {
                  uVar6 = (uint)bVar1;
                  if (*(char *)(uVar6 + 0x13e) == '\0') {
                    uVar2 = *(undefined1 *)(uVar12 + 0x16e);
                    *(undefined1 *)(uVar12 + 0x16e) = *(undefined1 *)(uVar6 + 0x16e);
                    *(undefined1 *)(uVar6 + 0x16e) = uVar2;
                    uVar2 = *(undefined1 *)(uVar12 + 0x14e);
                    *(undefined1 *)(uVar12 + 0x14e) = *(undefined1 *)(uVar6 + 0x14e);
                    *(undefined1 *)(uVar6 + 0x14e) = uVar2;
                    uVar2 = *(undefined1 *)(uVar12 + 0x15e);
                    *(undefined1 *)(uVar12 + 0x15e) = *(undefined1 *)(uVar6 + 0x15e);
                    *(undefined1 *)(uVar6 + 0x15e) = uVar2;
                    uVar2 = *(undefined1 *)(uVar12 + 0x13e);
                    *(undefined1 *)(uVar12 + 0x13e) = *(undefined1 *)(uVar6 + 0x13e);
                    *(undefined1 *)(uVar6 + 0x13e) = uVar2;
                  }
                  else if (cVar10 == '\0') {
                    if (*(char *)(uVar6 + 0x14e) == '\0') goto LAB_4bdc_12ae;
                    cVar10 = *(char *)(uVar6 + 0x15e);
                    *(undefined1 *)(uVar12 + 0x16e) = 0xff;
                    *(undefined1 *)(uVar12 + 0x15e) = 0;
                    *(undefined1 *)(uVar12 + 0x14e) = 0;
                    *(undefined1 *)(uVar12 + 0x13e) = 0;
                    *(undefined1 *)(uVar6 + 0x16e) = (char)uVar14;
                    *(undefined1 *)(uVar6 + 0x14e) = 0;
                    *(byte *)(uVar6 + 0x15e) = bVar7;
                    bVar5 = (bVar5 + cVar10) - bVar7;
                  }
                  else {
                    *(undefined1 *)(uVar12 + 0x16e) = 0xff;
                    *(undefined1 *)(uVar12 + 0x14e) = 0;
                    *(undefined1 *)(uVar12 + 0x15e) = 0;
                    *(undefined1 *)(uVar12 + 0x13e) = 0;
                    bVar5 = bVar5 + bVar7;
                  }
                }
              }
            }
LAB_4bdc_12a2:
            iVar16 = iVar16 + 1;
            iVar17 = iRam0004004e;
            iVar4 = iRam00040050;
          } while (iVar16 != 0x10);
        }
        else if ((iRam0004004e == 0) && (iVar17 = iVar11, iVar4 = iVar18, iRam00040050 != 0)) {
          iVar17 = iRam0004004e;
          iVar4 = iRam00040050;
        }
      }
      iRam00040050 = iVar4;
      iRam0004004e = iVar17;
      unaff_BP = unaff_BP + 0x10;
      iVar15 = iVar15 + 4;
    } while (iVar15 != 0x40);
    iVar15 = 0;
    do {
      if (*(char *)(iVar15 + 0x16e) != -1) {
        if (*(char *)(iVar15 + 0x13e) == '\0') {
          uVar3 = *(undefined4 *)(((*(byte *)(iVar15 + 0x16e) & 0xf0) >> 2) + 0xe);
          uVar12 = (uint)bRam00040200 << 2;
          do {
            if ((*(int *)(uVar12 + 0x8e) == (int)uVar3) &&
               (*(int *)(uVar12 + 0x90) == (int)((ulong)uVar3 >> 0x10))) {
              uVar12 = uVar12 >> 2;
              if (*(byte *)(uVar12 + 0x1be) == (*(byte *)(iVar15 + 0x16e) & 0xf)) {
                if (*(char *)(uVar12 + 0x13e) == '\0') {
                  *(undefined1 *)(uVar12 + 0x12e) = *(undefined1 *)(iVar15 + 0x16e);
                  *(undefined1 *)(iVar15 + 0x16e) = 0xff;
                }
                break;
              }
              uVar12 = uVar12 << 2;
            }
            uVar12 = uVar12 + 4;
          } while (bRam00040201 != (byte)(((byte)uVar12 >> 2) - 1));
        }
        else {
          bVar5 = *(byte *)(iVar15 + 0x16e);
          *(undefined1 *)(iVar15 + 0x16e) = 0xff;
          *(byte *)(iVar15 + 0x12e) = bVar5;
          uVar3 = *(undefined4 *)(((bVar5 & 0xf0) >> 2) + 0xe);
          if (((*(byte *)(iVar15 + 0x1be) != (bVar5 & 0xf)) ||
              (*(int *)(iVar15 * 4 + 0x8e) != (int)uVar3)) ||
             (*(int *)(iVar15 * 4 + 0x90) != (int)((ulong)uVar3 >> 0x10))) {
            (*pcRam000556ad)(0x4000,unaff_BP,iVar15,uVar14,bVar5 & 0xf);
            (*pcRam000556ad)(0x4000);
            iVar17 = (*pcRam000556ad)(0x4000);
            *(undefined1 *)(iVar17 + 0x1ce) = 0xff;
            FUN_4bdc_2141();
            (*pcRam000556ad)(0x4000);
            (*pcRam000556ad)(0x4000);
            (*pcRam000556ad)(0x4000);
            (*pcRam000556ad)(0x4000);
            (*pcRam000556ad)(0x4000);
            (*pcRam000556ad)(0x4000);
          }
        }
      }
      iVar15 = iVar15 + 1;
    } while (iVar15 != 0x10);
    uVar12 = (uint)(byte)(bRam00040201 + 1);
    uVar6 = 0;
    iVar15 = 0;
    do {
      if (*(char *)(iVar15 + 0x16e) != -1) {
        do {
          uVar13 = uVar12;
          uVar12 = uVar13 - 1;
        } while (*(char *)(uVar13 + 0x12d) != -1);
        uVar2 = *(undefined1 *)(iVar15 + 0x16e);
        *(undefined1 *)(uVar13 + 0x12d) = uVar2;
        uVar6 = CONCAT11((char)(uVar6 >> 8),uVar2) & 0xff0f;
        (*pcRam000556ad)(0x4000,unaff_BP,uVar12,uVar14,uVar6);
        (*pcRam000556ad)(0x4000);
        iVar17 = (*pcRam000556ad)(0x4000);
        *(undefined1 *)(iVar17 + 0x1ce) = 0xff;
        FUN_4bdc_2141();
        (*pcRam000556ad)(0x4000);
        (*pcRam000556ad)(0x4000);
        (*pcRam000556ad)(0x4000);
        (*pcRam000556ad)(0x4000);
        (*pcRam000556ad)(0x4000);
        (*pcRam000556ad)(0x4000);
      }
      iVar15 = iVar15 + 1;
    } while (iVar15 != 0x10);
  }
  iVar15 = 0xf;
  do {
    if ((*(char *)(iVar15 + 0x1be) != '\x0f') && (*(char *)(iVar15 + 0x12e) == -1)) {
      (*pcRam000556ad)(0x4000,unaff_BP);
      (*pcRam000556ad)(0x4000);
      (*pcRam000556ad)(0x4000);
    }
    iVar15 = iVar15 + -1;
  } while (-1 < iVar15);
  uRam000401be = uRam0004012e & 0xf0f;
  uRam000401c0 = uRam00040130 & 0xf0f;
  uRam000401c2 = uRam00040132 & 0xf0f;
  uRam000401c4 = uRam00040134 & 0xf0f;
  uRam000401c6 = uRam00040136 & 0xf0f;
  uRam000401c8 = uRam00040138 & 0xf0f;
  uRam000401ca = uRam0004013a & 0xf0f;
  uRam000401cc = uRam0004013c & 0xf0f;
  iVar15 = 0;
  iVar17 = 0;
  do {
    if (*(byte *)(iVar15 + 0x12e) == 0xff) {
      *(undefined2 *)(iVar17 + 0x8e) = 0;
      *(undefined2 *)(iVar17 + 0x90) = 0;
    }
    else {
      uVar14 = (*(byte *)(iVar15 + 0x12e) & 0xf0) >> 2;
      *(undefined2 *)(iVar17 + 0x8e) = *(undefined2 *)(uVar14 + 0xe);
      *(undefined2 *)(iVar17 + 0x90) = *(undefined2 *)(uVar14 + 0x10);
    }
    iVar17 = iVar17 + 4;
    iVar15 = iVar15 + 1;
  } while (iVar15 != 0x10);
  cRam000401ff = cRam000401ff + -1;
  return CONCAT22(in_DX,in_AX);
}

