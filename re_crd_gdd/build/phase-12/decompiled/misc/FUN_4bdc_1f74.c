// TIM2.EXE: FUN_4bdc_1f74 @ file 0x052F34 Ghidra 0x4DD34
// Subsystem: misc | Size: 124 bytes


void __cdecl16near FUN_4bdc_1f74(void)

{
  int *piVar1;
  undefined1 uVar2;
  byte bVar3;
  uint in_AX;
  byte bVar5;
  uint uVar4;
  int in_BX;
  undefined1 *unaff_BP;
  uint unaff_SI;
  int iVar6;
  undefined2 unaff_ES;
  
  uVar2 = *unaff_BP;
  piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
  *piVar1 = *piVar1 + 1;
  bVar3 = unaff_BP[1];
  piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
  *piVar1 = *piVar1 + 1;
  if ((cRam00040204 == '\0') || (*(char *)((in_AX & 0xf) + 0x12e) == -1)) {
    bVar5 = bVar3 >> 1;
    uVar4 = CONCAT11(bVar5,uVar2);
    if ((bool)(bVar3 & 1)) {
      uVar4 = CONCAT11(bVar5,uVar2) | 0x80;
    }
    iVar6 = (*(byte *)(in_BX + (unaff_SI & 0x7fff) + 0x8c) & 0xf) * 2;
    if (0x7fff < *(uint *)(in_BX + iVar6 + 0xbc)) {
      uVar4 = uVar4 | 0x8000;
    }
    *(uint *)(in_BX + iVar6 + 0xbc) = uVar4;
    if (((char)in_AX != -1) && (cRam0004020f == '\0')) {
      (*pcRam000556ad)(0x4000,unaff_BP + 2);
    }
  }
  return;
}

