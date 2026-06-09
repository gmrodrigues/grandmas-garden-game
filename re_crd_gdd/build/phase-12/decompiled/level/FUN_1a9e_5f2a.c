// TIM2.EXE: FUN_1a9e_5f2a @ file 0x025B0A Ghidra 0x2090A
// Subsystem: level | Size: 345 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte __cdecl16near FUN_1a9e_5f2a(void)

{
  code *pcVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  undefined1 extraout_DH;
  undefined2 in_BX;
  char cVar6;
  bool bVar7;
  
  if (_DAT_554c_4d72 == 0) {
    return DAT_554c_559f;
  }
  if (DAT_554c_559f == 0) {
LAB_1a9e_5f76:
    pcVar1 = (code *)swi(0x10);
    (*pcVar1)();
    if (((char)in_BX == '\a') || ((char)in_BX == '\b')) {
LAB_1a9e_5f99:
      if (DAT_554c_559f == 0) {
        return 8;
      }
      return DAT_554c_559f;
    }
    cVar2 = (char)((uint)in_BX >> 8);
    if ((cVar2 == '\a') || (cVar2 == '\b')) {
      FUN_1a9e_60dc();
      goto LAB_1a9e_5f99;
    }
LAB_1a9e_5fa7:
    pcVar1 = (code *)swi(0x10);
    (*pcVar1)();
    cVar2 = (char)in_BX;
    if (cVar2 == '\a') {
      return 5;
    }
    if (cVar2 == '\b') {
      return 5;
    }
    cVar6 = (char)((uint)in_BX >> 8);
    if ((cVar6 == '\a') || (cVar6 == '\b')) {
LAB_1a9e_5fd6:
      FUN_1a9e_60dc();
      return 5;
    }
    if (cVar2 == '\v') {
      return 5;
    }
    if (cVar2 == '\f') {
      return 5;
    }
    if ((cVar6 == '\v') || (cVar6 == '\f')) goto LAB_1a9e_5fd6;
  }
  else {
    if (DAT_554c_559f == 9) {
      FUN_1a9e_60dc();
      return 9;
    }
    if ((((DAT_554c_559f == 10) || (DAT_554c_559f == 8)) || (DAT_554c_559f == 0xd)) ||
       (((DAT_554c_559f == 0xc || (DAT_554c_559f == 0xe)) ||
        ((DAT_554c_559f == 0xf || (DAT_554c_559f == 0x10)))))) goto LAB_1a9e_5f76;
    if (DAT_554c_559f == 5) goto LAB_1a9e_5fa7;
    if (((DAT_554c_559f != 2) && (DAT_554c_559f != 7)) && (DAT_554c_559f != 0xb))
    goto LAB_1a9e_6008;
  }
  iVar5 = 0x10;
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  if (iVar5 != 0x10) {
    if ((DAT_0000_0487 & 8) != 0) {
      FUN_1a9e_60dc();
      return DAT_554c_559f;
    }
    return DAT_554c_559f;
  }
LAB_1a9e_6008:
  if (((DAT_554c_559f == 0) || (DAT_554c_559f == 1)) || (DAT_554c_559f == 3)) {
    out(0x3d4,0xf);
    out(0x3d5,0x66);
    iVar5 = 100;
    do {
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    cVar2 = in(0x3d5);
    out(0x3d5,0xf);
    if (cVar2 == 'f') {
      FUN_1a9e_60dc();
      cVar2 = FUN_2e67_07ad();
      if ((DAT_554c_559f != 1) && (cVar2 != '\0')) {
        return 3;
      }
      if (DAT_554c_559f == 3) {
        return 0;
      }
      return 1;
    }
  }
  bVar7 = false;
  if (((DAT_554c_559f == 0) || (bVar7 = DAT_554c_559f < 4, DAT_554c_559f == 4)) &&
     (FUN_1a9e_6087(), !bVar7)) {
    bVar3 = in(CONCAT11(extraout_DH,0xba));
    iVar5 = -0x8000;
    do {
      bVar4 = in(CONCAT11(extraout_DH,0xba));
      bVar7 = (bVar3 & 0x80) == (bVar4 & 0x80);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0 && bVar7);
    if (!bVar7) {
      return 4;
    }
  }
  return 0;
}

