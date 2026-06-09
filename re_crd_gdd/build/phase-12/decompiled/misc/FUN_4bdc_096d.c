// TIM2.EXE: FUN_4bdc_096d @ file 0x05192D Ghidra 0x4C72D
// Subsystem: misc | Size: 61 bytes


void __cdecl16far FUN_4bdc_096d(void)

{
  int in_AX;
  int in_CX;
  byte bVar1;
  int iVar2;
  undefined2 unaff_ES;
  
  cRam000401ff = cRam000401ff + '\x01';
  iVar2 = 0xe;
  do {
    bVar1 = *(byte *)(in_AX + iVar2 + 0x143);
    if (in_CX == 0) {
      if (0xf < bVar1) {
        bVar1 = bVar1 - 0x10;
      }
    }
    else if (bVar1 < 0xf0) {
      bVar1 = bVar1 + 0x10;
    }
    *(byte *)(in_AX + iVar2 + 0x143) = bVar1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  FUN_4bdc_0da0();
  cRam000401ff = cRam000401ff + -1;
  return;
}

