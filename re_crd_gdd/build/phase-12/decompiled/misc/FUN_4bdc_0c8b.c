// TIM2.EXE: FUN_4bdc_0c8b @ file 0x051C4B Ghidra 0x4CA4B
// Subsystem: misc | Size: 102 bytes


int __cdecl16far FUN_4bdc_0c8b(void)

{
  int in_AX;
  uint in_CX;
  uint extraout_DX;
  int unaff_SI;
  int iVar1;
  int iVar2;
  undefined2 unaff_ES;
  
  iVar2 = in_AX;
  FUN_4bdc_2159();
  if (unaff_SI != 0xff) {
    iVar1 = (extraout_DX & 0xff) * 2;
    if (0x7f < *(byte *)(iVar2 + iVar1 + 0xbd)) {
      in_CX = in_CX | 0x8000;
    }
    *(uint *)(iVar2 + iVar1 + 0xbc) = in_CX;
    iVar2 = 0;
    do {
      if (*(byte *)(iVar2 + 0x12e) == (byte)((byte)extraout_DX | (byte)(unaff_SI << 2))) {
        (*pcRam000556ad)(0x4000);
        return in_AX;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x10);
  }
  return in_AX;
}

