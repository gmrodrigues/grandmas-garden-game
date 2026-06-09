// TIM2.EXE: FUN_31f7_2a43 @ file 0x039BB3 Ghidra 0x349B3
// Subsystem: misc | Size: 95 bytes


void __cdecl16far FUN_31f7_2a43(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)((uint)(*(int *)(iVar1 + 0x10) != 0) * 2 + *(int *)(iRam000557ee + 0x46));
  iVar2 = *(int *)(iVar1 + 0x10);
  if (4 < iVar2) {
    iVar2 = 4;
  }
  *(undefined1 *)(iVar1 + 0x7a) = 0x12;
  *(undefined1 *)(iVar1 + 0x7b) = *(undefined1 *)(iVar2 + 0x3ad4);
  FUN_28eb_3670(iVar1,uVar3);
  return;
}

