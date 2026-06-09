// TIM2.EXE: FUN_4bdc_18fc @ file 0x0528BC Ghidra 0x4D6BC
// Subsystem: misc | Size: 72 bytes


void __cdecl16near FUN_4bdc_18fc(void)

{
  char cVar1;
  undefined2 unaff_BP;
  uint uVar2;
  
  cVar1 = '\0';
  uVar2 = (uint)bRam0004020c;
  do {
    if (*(char *)(uVar2 + 0x1ce) != -1) {
      *(undefined1 *)(uVar2 + 0x1ce) = 0xff;
      (*pcRam000556ad)(0x4000,unaff_BP);
      cVar1 = cVar1 + '\x01';
      if (cVar1 == '\x02') break;
    }
    uVar2 = uVar2 + 1;
    if (uVar2 == 0x10) {
      uVar2 = 0;
    }
  } while (uVar2 != bRam0004020c);
  bRam0004020c = (char)uVar2;
  return;
}

