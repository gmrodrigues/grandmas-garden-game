// TIM2.EXE: FUN_4bdc_0507 @ file 0x0514C7 Ghidra 0x4C2C7
// Subsystem: misc | Size: 144 bytes


int __cdecl16far FUN_4bdc_0507(void)

{
  byte *pbVar1;
  undefined1 uVar2;
  int in_AX;
  uint extraout_DX;
  int iVar3;
  int iVar4;
  undefined2 unaff_ES;
  
  iVar4 = 0xe;
  do {
    *(byte *)(iVar4 + 0x1de) = *(byte *)(in_AX + iVar4 + 0x143) & 0xf0;
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4);
  uRam0004020f = 1;
  iVar3 = in_AX;
  FUN_4bdc_05f9();
  iVar4 = *(int *)(iVar3 + 0x154);
  *(undefined2 *)(iVar3 + 0x154) = 0;
  uVar2 = *(undefined1 *)(iVar3 + 0x15d);
  *(undefined1 *)(iVar3 + 0x15d) = 1;
  if (iVar4 != 0) {
    do {
      uVar2 = FUN_4bdc_1ac4();
      if (*(uint *)(iVar3 + 0x154) <= extraout_DX) {
        if (extraout_DX == *(uint *)(iVar3 + 0x154)) break;
        iVar4 = iVar4 - (extraout_DX - *(int *)(iVar3 + 0x154));
      }
    } while (iVar4 != *(int *)(iVar3 + 0x154));
  }
  *(undefined1 *)(iVar3 + 0x15d) = uVar2;
  uRam0004020f = 0;
  iVar4 = 0xe;
  do {
    pbVar1 = (byte *)(iVar3 + iVar4 + 0x143);
    *pbVar1 = *pbVar1 | *(byte *)(iVar4 + 0x1de);
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4);
  FUN_4bdc_0da0();
  return in_AX;
}

