// TIM2.EXE: FUN_31f7_b5ec @ file 0x04275C Ghidra 0x3D55C
// Subsystem: sound | Size: 29 bytes


void __cdecl16far FUN_31f7_b5ec(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 uVar2;
  undefined2 unaff_SS;
  
  uVar2 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
  iVar1 = (int)*(undefined4 *)(unaff_BP + 6);
  if (*(int *)(iVar1 + 0x10) != *(int *)(iVar1 + 0x12)) {
    FUN_28eb_3328(iVar1,*(undefined2 *)(unaff_BP + 8));
  }
  return;
}

