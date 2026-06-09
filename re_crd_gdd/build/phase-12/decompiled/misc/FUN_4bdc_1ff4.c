// TIM2.EXE: FUN_4bdc_1ff4 @ file 0x052FB4 Ghidra 0x4DDB4
// Subsystem: misc | Size: 272 bytes


void __cdecl16near FUN_4bdc_1ff4(void)

{
  int *piVar1;
  byte bVar2;
  undefined2 in_AX;
  char cVar3;
  char cVar4;
  int in_BX;
  char *unaff_BP;
  uint unaff_SI;
  uint uVar5;
  int iVar6;
  undefined2 unaff_ES;
  undefined2 uVar7;
  
  uVar7 = 0x4bdc;
  cVar3 = (char)((uint)in_AX >> 8);
  if (cVar3 == -0x40) {
    cVar3 = *unaff_BP;
    piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
    *piVar1 = *piVar1 + 1;
    if (cVar3 == '\x7f') {
      bVar2 = unaff_BP[1];
      piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
      *piVar1 = *piVar1 + 1;
      uVar5 = (uint)bVar2;
      if (bVar2 == 0xf8) {
        uVar5 = 0x80f0;
      }
      *(uint *)(in_BX + unaff_SI * 2 + 0x4c) = uVar5;
      *(undefined1 *)(in_BX + (unaff_SI & 0x7fff) + 0x9c) = 0xcf;
      uVar5 = 0;
      do {
        iVar6 = uVar5 * 2;
        *(undefined2 *)(in_BX + iVar6 + 0x2c) = *(undefined2 *)(in_BX + iVar6 + 0xc);
        *(undefined2 *)(in_BX + iVar6 + 0x6c) = *(undefined2 *)(in_BX + iVar6 + 0x4c);
        uVar5 = uVar5 & 0x7fff;
        *(undefined1 *)(in_BX + uVar5 + 0xac) = *(undefined1 *)(in_BX + uVar5 + 0x9c);
        uVar5 = uVar5 + 1;
      } while (uVar5 != 0x10);
      *(undefined2 *)(in_BX + 0x156) = *(undefined2 *)(in_BX + 0x154);
      piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
      *piVar1 = *piVar1 + -1;
      *(undefined2 *)(in_BX + unaff_SI * 2 + 0x4c) = 0;
    }
    else if (cRam0004020f == '\0') {
      *(char *)(in_BX + 0x158) = cVar3;
    }
  }
  else if (cVar3 == -0x50) {
    cVar3 = *unaff_BP;
    piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
    *piVar1 = *piVar1 + 1;
    cVar4 = unaff_BP[1];
    piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
    *piVar1 = *piVar1 + 1;
    if (cVar3 == 'P') {
      if (cVar4 == '\x7f') {
        uVar7 = 0x4000;
        cVar4 = cRam00040208;
      }
      *(char *)(in_BX + 0x15f) = cVar4;
      (*pcRam000556ad)(uVar7,unaff_BP + 2);
    }
    else if (cVar3 == '`') {
      if (cRam0004020f == '\0') {
        *(int *)(in_BX + 0x152) = *(int *)(in_BX + 0x152) + 1;
      }
    }
    else if ((cVar3 == 'R') && (*(char *)(in_BX + 0x15a) == cVar4)) {
      iVar6 = 0;
      do {
        *(undefined2 *)(in_BX + iVar6 + 0xc) = 0;
        iVar6 = iVar6 + 2;
      } while (iVar6 != 0x20);
    }
  }
  else {
    FUN_4bdc_2104();
  }
  return;
}

