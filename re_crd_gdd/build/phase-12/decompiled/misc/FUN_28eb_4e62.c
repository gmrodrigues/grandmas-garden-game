// TIM2.EXE: FUN_28eb_4e62 @ file 0x032F12 Ghidra 0x2DD12
// Subsystem: misc | Size: 62 bytes


void __cdecl16far FUN_28eb_4e62(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(*(int *)(*(int *)(iVar1 + 8) * 2 + 0x302) + 0x46) != 0) {
    *(undefined2 *)(iVar1 + 0x98) =
         *(undefined2 *)*(undefined2 *)(*(int *)(*(int *)(iVar1 + 8) * 2 + 0x302) + 0x46);
    FUN_28eb_3670(iVar1,uVar2);
  }
  return;
}

