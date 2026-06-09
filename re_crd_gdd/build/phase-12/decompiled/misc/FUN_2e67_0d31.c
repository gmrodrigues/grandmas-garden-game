// TIM2.EXE: FUN_2e67_0d31 @ file 0x0345A1 Ghidra 0x2F3A1
// Subsystem: misc | Size: 246 bytes


undefined1 __cdecl16far FUN_2e67_0d31(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_DX;
  int iVar4;
  int unaff_BP;
  int iVar5;
  int unaff_SI;
  undefined2 uVar6;
  undefined2 unaff_SS;
  
  iVar5 = *(int *)(unaff_BP + unaff_SI + 1) * 0x6a;
  iVar2 = FUN_22de_01ec(0xbd0);
  DAT_5b41_0cac = iVar2;
  DAT_5b41_0cae = in_DX;
  DAT_5b41_0cb0 = iVar2;
  DAT_5b41_0cb2 = in_DX;
  *(int *)(iVar5 + -6) = in_DX;
  *(int *)(iVar5 + -8) = iVar2;
  if (iVar2 != 0 || in_DX != 0) {
    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
      in_DX = *(int *)(iVar5 + -6);
      iVar3 = *(int *)(iVar5 + -8);
      uVar6 = (undefined2)((ulong)*(undefined4 *)(iVar5 + -8) >> 0x10);
      iVar4 = (int)*(undefined4 *)(iVar5 + -8);
      *(int *)(iVar4 + 0x174) = in_DX;
      *(int *)(iVar4 + 0x172) = iVar3 + 0x17a;
      *(int *)(iVar5 + -8) = *(int *)(iVar5 + -8) + 0x17a;
    }
  }
  if (DAT_554c_2fca != 0) {
    iVar3 = FUN_22de_01ec(DAT_554c_2fca * 0x14);
    DAT_5b41_0ca4 = iVar3;
    DAT_5b41_0ca6 = in_DX;
    DAT_5b41_0ca8 = iVar3;
    DAT_5b41_0caa = in_DX;
    *(int *)(iVar5 + -2) = in_DX;
    *(int *)(iVar5 + -4) = iVar3;
    iVar2 = DAT_554c_2fca;
    if (iVar3 != 0 || in_DX != 0) {
      while (iVar2 + -1 != 0) {
        iVar3 = *(int *)(iVar5 + -4);
        piVar1 = (int *)*(undefined4 *)(iVar5 + -4);
        ((int *)piVar1)[1] = *(int *)(iVar5 + -2);
        *piVar1 = iVar3 + 0x14;
        *(int *)(iVar5 + -4) = *(int *)(iVar5 + -4) + 0x14;
        iVar2 = iVar2 + -1;
      }
    }
  }
  if (((((DAT_554c_2fcc == 0 && DAT_554c_2fce == 0) || (DAT_5b41_0ca0 != 0 || DAT_5b41_0ca2 != 0))
       && ((DAT_554c_2fd0 == 0 || (DAT_5b41_0c9c != 0 || DAT_5b41_0c9e != 0)))) &&
      (DAT_5b41_0cac != 0 || DAT_5b41_0cae != 0)) &&
     ((DAT_554c_2fca == 0 || (DAT_5b41_0ca4 != 0 || DAT_5b41_0ca6 != 0)))) {
    DAT_5b41_0cb8 = 1;
  }
  else {
    FUN_2e67_0e27();
  }
  return DAT_5b41_0cb8;
}

