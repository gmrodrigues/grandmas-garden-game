// TIM2.EXE: FUN_4bdc_08d7 @ file 0x051897 Ghidra 0x4C697
// Subsystem: misc | Size: 104 bytes


int __cdecl16far FUN_4bdc_08d7(void)

{
  char cVar1;
  int in_AX;
  char in_CL;
  int iVar2;
  int iVar3;
  int unaff_ES;
  int iVar4;
  
  if (unaff_ES == 0 && in_AX == 0) {
    iVar3 = 0;
    do {
      while( true ) {
        iVar4 = (int)((ulong)*(undefined4 *)(iVar3 + 0xe) >> 0x10);
        iVar2 = (int)*(undefined4 *)(iVar3 + 0xe);
        if (iVar4 != 0 || iVar2 != 0) break;
        if (iVar3 != 0) goto LAB_4bdc_0937;
        iVar3 = 4;
      }
      cVar1 = *(char *)(iVar2 + 0x164);
      if (in_CL == '\0') {
        if (cVar1 != '\0') {
          cVar1 = cVar1 + -1;
        }
      }
      else {
        cVar1 = cVar1 + '\x01';
      }
      *(char *)(iVar2 + 0x164) = cVar1;
      iVar3 = iVar3 + 4;
    } while (iVar3 != 0x40);
  }
  else {
    cVar1 = *(char *)(in_AX + 0x164);
    if (in_CL == '\0') {
      if (cVar1 != '\0') {
        cVar1 = cVar1 + -1;
      }
    }
    else {
      cVar1 = cVar1 + '\x01';
    }
    *(char *)(in_AX + 0x164) = cVar1;
  }
LAB_4bdc_0937:
  FUN_4bdc_0da0();
  return in_AX;
}

