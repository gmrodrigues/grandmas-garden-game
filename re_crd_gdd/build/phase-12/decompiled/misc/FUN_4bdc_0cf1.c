// TIM2.EXE: FUN_4bdc_0cf1 @ file 0x051CB1 Ghidra 0x4CAB1
// Subsystem: misc | Size: 175 bytes


int __cdecl16near FUN_4bdc_0cf1(void)

{
  int in_AX;
  int iVar1;
  int iVar2;
  int unaff_ES;
  
  iVar1 = 0;
  while ((in_AX != *(int *)(iVar1 + 0xe) || (unaff_ES != *(int *)(iVar1 + 0x10)))) {
    iVar1 = iVar1 + 4;
    if (iVar1 == 0x40) {
      return in_AX;
    }
  }
  *(undefined2 *)(iVar1 + 0xe) = 0;
  *(undefined2 *)(iVar1 + 0x10) = 0;
  if (iVar1 != 0x3c) {
    do {
      iVar2 = iVar1;
      *(undefined2 *)(iVar2 + 0xe) = *(undefined2 *)(iVar2 + 0x12);
      *(undefined2 *)(iVar2 + 0x10) = *(undefined2 *)(iVar2 + 0x14);
      iVar1 = iVar2 + 4;
    } while (iVar2 + 4 != 0x3c);
    *(undefined2 *)(iVar2 + 0x12) = 0;
    *(undefined2 *)(iVar2 + 0x14) = 0;
  }
  *(undefined1 *)(in_AX + 0x158) = 0xff;
  *(undefined1 *)(in_AX + 0x159) = 0;
  if ((*(char *)(in_AX + 0x165) != '\0') && (0x7f < *(byte *)(in_AX + 0x165))) {
    FUN_4bdc_31c9(5,0);
  }
  return in_AX;
}

