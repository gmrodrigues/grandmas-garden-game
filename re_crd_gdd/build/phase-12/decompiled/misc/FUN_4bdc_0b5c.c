// TIM2.EXE: FUN_4bdc_0b5c @ file 0x051B1C Ghidra 0x4C91C
// Subsystem: misc | Size: 222 bytes


int __cdecl16far FUN_4bdc_0b5c(void)

{
  byte bVar1;
  int in_AX;
  uint uVar2;
  undefined2 in_CX;
  char cVar3;
  char cVar4;
  uint extraout_DX;
  uint uVar5;
  int unaff_SI;
  int iVar6;
  undefined2 unaff_ES;
  
  iVar6 = in_AX;
  FUN_4bdc_2159();
  if (unaff_SI == 0xff) {
    return in_AX;
  }
  uVar5 = extraout_DX & 0xff;
  cVar3 = (char)((uint)in_CX >> 8);
  cVar4 = (char)in_CX;
  if (cVar3 == '\a') {
    *(char *)(iVar6 + uVar5 + 0x107) = cVar4;
    FUN_4bdc_2141();
  }
  else if (cVar3 == '\n') {
    *(char *)(iVar6 + uVar5 + 0xf8) = cVar4;
  }
  else if (cVar3 == '\x01') {
    *(char *)(iVar6 + uVar5 + 0xe9) = cVar4;
  }
  else if (cVar3 == '@') {
    uVar2 = *(uint *)(iVar6 + uVar5 * 2 + 0xbc) & 0x7fff;
    if (cVar4 != '\0') {
      uVar2 = uVar2 | 0x8000;
    }
    *(uint *)(iVar6 + uVar5 * 2 + 0xbc) = uVar2;
  }
  else {
    if (cVar3 == 'N') {
      bVar1 = *(byte *)(iVar6 + uVar5 + 0x143);
      if (cVar4 == '\0') {
        if (bVar1 < 0x10) {
          return in_AX;
        }
        cVar4 = bVar1 - 0x10;
      }
      else {
        if (0xef < bVar1) {
          return in_AX;
        }
        cVar4 = bVar1 + 0x10;
      }
      *(char *)(iVar6 + uVar5 + 0x143) = cVar4;
      FUN_4bdc_0da0(uVar5);
      return in_AX;
    }
    if (cVar3 == '\x7f') {
      *(char *)(iVar6 + uVar5 + 0x116) = cVar4;
    }
  }
  iVar6 = 0;
  do {
    if (*(byte *)(iVar6 + 0x12e) == (byte)((char)unaff_SI << 2 | (byte)extraout_DX)) {
      if ((char)((uint)in_CX >> 8) == '\x7f') {
        (*pcRam000556ad)(0x4000);
        return in_AX;
      }
      (*pcRam000556ad)(0x4000);
      return in_AX;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x10);
  return in_AX;
}

