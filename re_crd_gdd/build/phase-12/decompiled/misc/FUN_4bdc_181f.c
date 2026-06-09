// TIM2.EXE: FUN_4bdc_181f @ file 0x0527DF Ghidra 0x4D5DF
// Subsystem: misc | Size: 221 bytes


undefined4 __cdecl16near FUN_4bdc_181f(void)

{
  byte bVar1;
  char cVar2;
  undefined2 in_AX;
  undefined2 in_CX;
  int iVar3;
  undefined2 in_DX;
  uint uVar5;
  int in_BX;
  undefined2 unaff_BP;
  int unaff_SI;
  int iVar6;
  int iVar7;
  undefined2 unaff_ES;
  undefined1 uVar4;
  
  cRam0004020b = (char)((uint)in_CX >> 8);
  if (((char)in_CX != *(char *)(in_BX + 0x15e)) &&
     (*(char *)(in_BX + 0x15e) = (char)in_CX, unaff_SI != 0xff)) {
    uVar5 = (uint)(byte)((char)unaff_SI << 2);
    iVar6 = 0;
    do {
      bVar1 = *(byte *)(iVar6 + 0x12e);
      if ((bVar1 != 0xff) && ((bVar1 & 0xf0) == (byte)uVar5)) {
        uVar4 = *(undefined1 *)(in_BX + (bVar1 & 0xf) + 0x107);
        FUN_4bdc_2141();
        if (cRam0004020b == '\0') {
          *(undefined1 *)(iVar6 + 0x1ce) = 0xff;
          (*pcRam000556ad)(0x4000,unaff_BP);
        }
        else {
          *(undefined1 *)(iVar6 + 0x1ce) = uVar4;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0x10);
    iVar6 = 0;
    iVar7 = 0;
    do {
      cVar2 = *(char *)(in_BX + iVar7 + 0x8c);
      uVar4 = (undefined1)((uint)iVar6 >> 8);
      iVar3 = CONCAT11(uVar4,cVar2);
      if (cVar2 == -1) break;
      iVar6 = iVar3;
      if (((*(byte *)(in_BX + iVar3 + 0x134) & 2) != 0) && (*(char *)(iVar3 + 0x12e) == -1)) {
        iVar6 = CONCAT11(uVar4,*(undefined1 *)(in_BX + iVar3 + 0x107));
        FUN_4bdc_2141();
        if (cRam0004020b == '\0') {
          iVar6 = 0x700;
          *(undefined1 *)(iVar3 + 0x1ce) = 0xff;
          (*pcRam000556ad)(0x4000,unaff_BP);
        }
        else {
          *(undefined1 *)(iVar3 + 0x1ce) = (char)iVar6;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 != 0x10);
  }
  return CONCAT22(in_DX,in_AX);
}

