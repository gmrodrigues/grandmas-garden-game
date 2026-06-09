// TIM2.EXE: FUN_4bdc_1efc @ file 0x052EBC Ghidra 0x4DCBC
// Subsystem: misc | Size: 84 bytes


void __cdecl16near FUN_4bdc_1efc(void)

{
  int *piVar1;
  undefined1 uVar2;
  uint in_AX;
  int in_BX;
  undefined1 *unaff_BP;
  uint unaff_SI;
  undefined2 unaff_ES;
  
  uVar2 = *unaff_BP;
  piVar1 = (int *)(in_BX + unaff_SI * 2 + 0xc);
  *piVar1 = *piVar1 + 1;
  if ((((cRam00040204 == '\0') || (*(char *)((in_AX & 0xf) + 0x12e) == -1)) &&
      (*(undefined1 *)(in_BX + (*(byte *)(in_BX + (unaff_SI & 0x7fff) + 0x8c) & 0xf) + 0x116) =
            uVar2, (char)in_AX != -1)) && (cRam0004020f == '\0')) {
    (*pcRam000556ad)(0x4000,unaff_BP + 1);
  }
  return;
}

