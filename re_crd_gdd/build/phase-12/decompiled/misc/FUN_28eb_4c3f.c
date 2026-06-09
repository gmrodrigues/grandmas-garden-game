// TIM2.EXE: FUN_28eb_4c3f @ file 0x032CEF Ghidra 0x2DAEF
// Subsystem: misc | Size: 146 bytes


void FUN_28eb_4c3f(void)

{
  undefined2 in_DX;
  int iVar1;
  int unaff_BP;
  undefined2 uVar2;
  undefined2 unaff_SS;
  
  uVar2 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -6) >> 0x10);
  iVar1 = (int)*(undefined4 *)(unaff_BP + -6);
  if (*(int *)(iVar1 + 8) == 8) {
    FUN_28eb_1f9a(*(undefined2 *)(iVar1 + 0x58));
  }
  else {
    uVar2 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -6) >> 0x10);
    iVar1 = (int)*(undefined4 *)(unaff_BP + -6);
    if ((*(int *)(iVar1 + 8) == 10) || (*(int *)(iVar1 + 8) == 0x4c)) {
      iVar1 = *(int *)((int)*(undefined4 *)(unaff_BP + -6) + 0x76);
      uVar2 = *(undefined2 *)(iVar1 + 0xc);
      *(undefined2 *)(iVar1 + 6) = *(undefined2 *)(iVar1 + 0xe);
      *(undefined2 *)(iVar1 + 4) = uVar2;
      uVar2 = *(undefined2 *)(iVar1 + 0x10);
      *(undefined2 *)(iVar1 + 10) = *(undefined2 *)(iVar1 + 0x12);
      *(undefined2 *)(iVar1 + 8) = uVar2;
      *(undefined1 *)(iVar1 + 0x14) = *(undefined1 *)(iVar1 + 0x16);
      *(undefined1 *)(iVar1 + 0x15) = *(undefined1 *)(iVar1 + 0x17);
      *(int *)((int)*(undefined4 *)(iVar1 + 4) + (uint)*(byte *)(iVar1 + 0x14) * 2 + 0x76) = iVar1;
      *(int *)((int)*(undefined4 *)(iVar1 + 8) + (uint)*(byte *)(iVar1 + 0x15) * 2 + 0x76) = iVar1;
      uVar2 = *(undefined2 *)(iVar1 + 4);
      *(undefined2 *)(unaff_BP + -0xc) = *(undefined2 *)(iVar1 + 6);
      *(undefined2 *)(unaff_BP + -0xe) = uVar2;
      FUN_28eb_4d0a();
      return;
    }
  }
  uVar2 = FUN_28eb_32d8(*(undefined2 *)(unaff_BP + -6),*(undefined2 *)(unaff_BP + -4),0x1000);
  *(undefined2 *)(unaff_BP + -4) = in_DX;
  *(undefined2 *)(unaff_BP + -6) = uVar2;
  if (*(int *)(unaff_BP + -6) == 0 && *(int *)(unaff_BP + -4) == 0) {
    return;
  }
  FUN_28eb_4c3f();
  return;
}

