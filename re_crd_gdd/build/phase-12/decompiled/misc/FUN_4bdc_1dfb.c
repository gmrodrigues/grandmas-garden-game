// TIM2.EXE: FUN_4bdc_1dfb @ file 0x052DBB Ghidra 0x4DBBB
// Subsystem: misc | Size: 257 bytes


void __cdecl16near FUN_4bdc_1dfb(void)

{
  int *piVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  uint in_AX;
  uint uVar5;
  uint uVar6;
  int in_BX;
  char *unaff_BP;
  uint unaff_SI;
  uint uVar7;
  undefined2 unaff_ES;
  
  cVar2 = *unaff_BP;
  piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
  *piVar1 = *piVar1 + 1;
  cVar3 = unaff_BP[1];
  piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
  *piVar1 = *piVar1 + 1;
  if ((cRam00040204 == '\0') || (*(char *)((in_AX & 0xf) + 0x12e) == -1)) {
    uVar7 = *(byte *)(in_BX + (unaff_SI & 0x7fff) + 0x8c) & 0xf;
    bVar4 = (byte)in_AX;
    if (cVar2 == '\a') {
      *(char *)(in_BX + uVar7 + 0x107) = cVar3;
      bVar4 = FUN_4bdc_2141();
      if (0x1f < bVar4) {
        return;
      }
      *(undefined1 *)(bVar4 + 0x1ce) = 0xff;
    }
    else if (cVar2 == '\n') {
      *(char *)(in_BX + uVar7 + 0xf8) = cVar3;
    }
    else if (cVar2 == '\x01') {
      *(char *)(in_BX + uVar7 + 0xe9) = cVar3;
    }
    else if (cVar2 == '@') {
      uVar5 = *(uint *)(in_BX + uVar7 * 2 + 0xbc);
      uVar6 = uVar5 | 0x8000;
      if (cVar3 == '\0') {
        uVar6 = CONCAT11((char)(uVar6 >> 8),(char)uVar5) & 0x7fff;
      }
      *(uint *)(in_BX + uVar7 * 2 + 0xbc) = uVar6;
    }
    else if (cVar2 == 'K') {
      uVar5 = CONCAT11(*(undefined1 *)(in_BX + uVar7 + 0xda),cVar3) & 0xf0ff;
      *(byte *)(in_BX + uVar7 + 0xda) = (byte)(uVar5 >> 8) | (byte)uVar5;
      uRam0004020a = 1;
    }
    else if (cVar2 == 'N') {
      *(byte *)(in_BX + uVar7 + 0x143) = *(byte *)(in_BX + uVar7 + 0x143) & 0xf0 | cVar3 != '\0';
      uRam0004020a = 1;
    }
    if ((bVar4 != 0xff) && (cRam0004020f == '\0')) {
      (*pcRam000556ad)(0x4000,unaff_BP + 2);
    }
  }
  return;
}

