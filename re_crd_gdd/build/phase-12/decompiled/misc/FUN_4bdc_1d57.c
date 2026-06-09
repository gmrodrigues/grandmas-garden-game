// TIM2.EXE: FUN_4bdc_1d57 @ file 0x052D17 Ghidra 0x4DB17
// Subsystem: misc | Size: 115 bytes


void __cdecl16near FUN_4bdc_1d57(void)

{
  int *piVar1;
  char cVar2;
  char cVar3;
  char in_AL;
  int in_BX;
  char *unaff_BP;
  uint unaff_SI;
  uint uVar4;
  undefined2 unaff_ES;
  
  cVar2 = *unaff_BP;
  piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
  *piVar1 = *piVar1 + 1;
  cVar3 = unaff_BP[1];
  piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
  *piVar1 = *piVar1 + 1;
  uVar4 = *(byte *)(in_BX + (unaff_SI & 0x7fff) + 0x8c) & 0xf;
  if (cVar3 == '\0') {
    if (*(char *)(in_BX + uVar4 + 0x125) == cVar2) {
      *(undefined1 *)(in_BX + uVar4 + 0x125) = 0xff;
    }
    if ((in_AL != -1) && (cRam0004020f == '\0')) {
      (*pcRam000556ad)(0x4000,unaff_BP + 2);
    }
  }
  else {
    *(char *)(in_BX + uVar4 + 0x125) = cVar2;
    if ((in_AL != -1) && (cRam0004020f == '\0')) {
      (*pcRam000556ad)(0x4000,unaff_BP + 2);
    }
  }
  return;
}

