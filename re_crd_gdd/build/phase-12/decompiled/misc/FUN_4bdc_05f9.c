// TIM2.EXE: FUN_4bdc_05f9 @ file 0x0515B9 Ghidra 0x4C3B9
// Subsystem: misc | Size: 724 bytes


void __cdecl16far FUN_4bdc_05f9(void)

{
  byte *pbVar1;
  byte bVar2;
  int in_AX;
  int in_CX;
  int *piVar3;
  int *piVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int unaff_ES;
  undefined2 uVar11;
  
  iVar10 = 0;
  do {
    if ((*(int *)(iVar10 + 0xe) == in_AX) && (*(int *)(iVar10 + 0x10) == unaff_ES)) {
      FUN_4bdc_0cf1();
      in_AX = FUN_4bdc_0da0();
      break;
    }
    iVar10 = iVar10 + 4;
  } while (iVar10 != 0x40);
  *(undefined1 *)(in_AX + 0x159) = 1;
  if (in_CX != 0) {
    *(char *)(in_AX + 0x159) = *(char *)(in_AX + 0x159) + '\x01';
  }
  iVar10 = FUN_4bdc_217b();
  uVar6 = 0;
  do {
    iVar7 = uVar6 * 2;
    *(undefined2 *)(iVar10 + iVar7 + 0xc) = 0xd;
    *(undefined2 *)(iVar10 + iVar7 + 0x2c) = 3;
    *(undefined2 *)(iVar10 + iVar7 + 0x4c) = 0;
    *(undefined2 *)(iVar10 + iVar7 + 0x6c) = 0;
    *(undefined2 *)(iVar10 + iVar7 + 0xbc) = 0x2000;
    uVar6 = uVar6 & 0x7fff;
    *(undefined1 *)(iVar10 + uVar6 + 0x8c) = 0xff;
    *(undefined1 *)(iVar10 + uVar6 + 0x9c) = 0;
    *(undefined1 *)(iVar10 + uVar6 + 0xac) = 0;
    *(undefined1 *)(iVar10 + uVar6 + 0xda) = 0xff;
    *(undefined1 *)(iVar10 + uVar6 + 0xe9) = 0;
    *(undefined1 *)(iVar10 + uVar6 + 0x116) = 0xff;
    *(undefined1 *)(iVar10 + uVar6 + 0x107) = 0xff;
    *(undefined1 *)(iVar10 + uVar6 + 0xf8) = 0xff;
    *(undefined1 *)(iVar10 + uVar6 + 0x125) = 0xff;
    *(undefined1 *)(iVar10 + uVar6 + 0x134) = 0;
    *(undefined1 *)(iVar10 + uVar6 + 0x143) = 0;
    uVar6 = uVar6 + 1;
  } while (uVar6 != 0xf);
  *(undefined1 *)(iVar10 + 0x9b) = 0xff;
  *(undefined1 *)(iVar10 + 0xab) = 0;
  *(undefined1 *)(iVar10 + 0xbb) = 0;
  *(undefined1 *)(iVar10 + 0x165) = 0;
  *(undefined1 *)(iVar10 + 0x15a) = 0;
  *(undefined1 *)(iVar10 + 0x15f) = 0x7f;
  *(undefined2 *)(iVar10 + 0x2a) = 0xd;
  *(undefined2 *)(iVar10 + 0x4a) = 3;
  *(undefined2 *)(iVar10 + 0x6a) = 0;
  *(undefined2 *)(iVar10 + 0x156) = 0;
  uVar6 = 0;
  uVar11 = (undefined2)((ulong)*(int **)*(undefined4 *)(iVar10 + 8) >> 0x10);
  piVar3 = (int *)*(int **)*(undefined4 *)(iVar10 + 8);
  piVar4 = piVar3;
  if (((char)piVar3[0x10] != -1) && (*(char *)(iVar10 + 0x15b) == '\0')) {
    *(undefined1 *)(iVar10 + 0x15c) = (char)piVar3[0x10];
  }
  do {
    if (*piVar4 == 0) break;
    pbVar5 = (byte *)((int)piVar3 + *piVar4);
    bVar2 = *pbVar5;
    if (bVar2 == 0xfe) {
      if (cRam00040206 != '\0') {
        *(char *)(iVar10 + 0x165) = (char)uVar6 + '\x01';
        break;
      }
      *(undefined2 *)(iVar10 + uVar6 * 2 + 0xc) = 0;
      *(undefined2 *)(iVar10 + uVar6 * 2 + 0x2c) = 0;
      *(undefined1 *)(iVar10 + uVar6 + 0x8c) = 0xfe;
    }
    else {
      *(byte *)(iVar10 + uVar6 + 0x8c) = bVar2;
      *(byte *)(iVar10 + uVar6 + 0x9c) = bVar2 | 0xb0;
      uVar8 = (uint)pbVar5[0xc];
      if (pbVar5[0xc] == 0xf8) {
        uVar8 = 0x80f0;
      }
      *(uint *)(iVar10 + uVar6 * 2 + 0x4c) = uVar8;
      bVar2 = *(byte *)(iVar10 + uVar6 + 0x8c);
      pbVar1 = (byte *)(iVar10 + uVar6 + 0x8c);
      *pbVar1 = *pbVar1 & 0xf;
      if ((bVar2 & 0x10) == 0) {
        uVar8 = bVar2 & 0xf;
        if ((bVar2 & 0x20) != 0) {
          pbVar1 = (byte *)(iVar10 + uVar8 + 0x134);
          *pbVar1 = *pbVar1 | 1;
        }
        if ((bVar2 & 0x40) != 0) {
          *(undefined1 *)(iVar10 + uVar8 + 0x143) = 1;
        }
        if (uVar8 == 0xf) {
          if (*(char *)(iVar10 + 0x15f) == '\x7f') {
            *(byte *)(iVar10 + 0x15f) = pbVar5[8];
            goto LAB_4bdc_0810;
          }
        }
        else {
          if (*(char *)(iVar10 + uVar8 + 0xda) == -1) {
            *(byte *)(iVar10 + uVar8 + 0xda) = pbVar5[1];
          }
          if (*(char *)(iVar10 + uVar8 + 0x116) == -1) {
            *(byte *)(iVar10 + uVar8 + 0x116) = pbVar5[4];
          }
          if (*(char *)(iVar10 + uVar8 + 0x107) == -1) {
            *(byte *)(iVar10 + uVar8 + 0x107) = pbVar5[8];
          }
        }
        if (*(char *)(iVar10 + uVar8 + 0xf8) == -1) {
          *(byte *)(iVar10 + uVar8 + 0xf8) = pbVar5[0xb];
        }
      }
      else {
        *(undefined2 *)(iVar10 + uVar6 * 2 + 0xc) = 3;
        *(undefined2 *)(iVar10 + uVar6 * 2 + 0x4c) = 0;
        pbVar1 = (byte *)(iVar10 + (bVar2 & 0xf) + 0x134);
        *pbVar1 = *pbVar1 | 2;
      }
    }
LAB_4bdc_0810:
    piVar4 = piVar3 + uVar6 + 1;
    uVar6 = uVar6 + 1 & 0x7fff;
  } while (uVar6 != 0x10);
  if (*(char *)(iVar10 + 0x159) == '\x02') {
    iVar7 = 0xe;
    do {
      pbVar1 = (byte *)(iVar10 + iVar7 + 0x134);
      *pbVar1 = *pbVar1 | 1;
      iVar7 = iVar7 + -1;
    } while (-1 < iVar7);
  }
  iVar7 = 0;
  while( true ) {
    if (*(int *)(iVar7 + 0x10) == 0) goto LAB_4bdc_0886;
    if (*(byte *)((int)*(undefined4 *)(iVar7 + 0xe) + 0x15c) <= *(byte *)(iVar10 + 0x15c)) break;
    iVar7 = iVar7 + 4;
    if (iVar7 == 0x40) {
      return;
    }
  }
  for (iVar9 = 0x38; iVar9 + 4 != iVar7; iVar9 = iVar9 + -4) {
    *(undefined2 *)(iVar9 + 0x12) = *(undefined2 *)(iVar9 + 0xe);
    *(undefined2 *)(iVar9 + 0x14) = *(undefined2 *)(iVar9 + 0x10);
  }
LAB_4bdc_0886:
  *(int *)(iVar7 + 0xe) = iVar10;
  *(int *)(iVar7 + 0x10) = unaff_ES;
  if (cRam0004020f == '\0') {
    *(undefined2 *)(iVar10 + 0x152) = 0;
    *(undefined2 *)(iVar10 + 0x154) = 0;
    *(undefined1 *)(iVar10 + 0x158) = 0;
    *(undefined1 *)(iVar10 + 0x160) = 0;
    *(undefined1 *)(iVar10 + 0x161) = 0;
    *(undefined1 *)(iVar10 + 0x162) = 0;
    *(undefined1 *)(iVar10 + 0x163) = 0;
    *(undefined1 *)(iVar10 + 0x164) = 0;
    FUN_4bdc_0da0();
  }
  return;
}

