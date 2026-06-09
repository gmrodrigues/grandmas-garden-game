// TIM2.EXE: FUN_31f7_60af @ file 0x03D21F Ghidra 0x3801F
// Subsystem: misc | Size: 56 bytes


void __cdecl16far FUN_31f7_60af(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)
        (*(int *)(*(int *)(*(int *)(iVar1 + 8) * 2 + 0x302) + 0x46) + *(int *)(iVar1 + 0x10) * 2);
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

