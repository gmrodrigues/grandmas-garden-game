// TIM2.EXE: FUN_4bdc_175f @ file 0x05271F Ghidra 0x4D51F
// Subsystem: misc | Size: 192 bytes


void __cdecl16near FUN_4bdc_175f(void)

{
  byte bVar1;
  uint uVar2;
  int in_BX;
  undefined2 unaff_ES;
  
  if (*(char *)(in_BX + 0x162) != '\0') {
    *(char *)(in_BX + 0x162) = *(char *)(in_BX + 0x162) + -1;
    return;
  }
  *(undefined1 *)(in_BX + 0x162) = *(undefined1 *)(in_BX + 0x161);
  bVar1 = *(byte *)(in_BX + 0x160) & 0x7f;
  if (bVar1 != *(byte *)(in_BX + 0x15e)) {
    if (bVar1 < *(byte *)(in_BX + 0x15e)) {
      uVar2 = CONCAT11(*(undefined1 *)(in_BX + 0x160),*(undefined1 *)(in_BX + 0x15e)) & 0x7fff;
      if (*(byte *)(in_BX + 0x163) < (byte)((char)uVar2 - (char)(uVar2 >> 8))) {
        FUN_4bdc_181f();
        return;
      }
      FUN_4bdc_181f();
    }
    else {
      if (*(byte *)(in_BX + 0x163) <
          (byte)((*(byte *)(in_BX + 0x160) & 0x7f) - *(char *)(in_BX + 0x15e))) {
        FUN_4bdc_181f();
        return;
      }
      FUN_4bdc_181f();
    }
  }
  *(undefined1 *)(in_BX + 0x158) = 0xfe;
  *(undefined1 *)(in_BX + 0x163) = 0;
  if ((*(byte *)(in_BX + 0x160) & 0x80) != 0) {
    FUN_4bdc_0cf1();
    uRam0004020a = 1;
  }
  return;
}

