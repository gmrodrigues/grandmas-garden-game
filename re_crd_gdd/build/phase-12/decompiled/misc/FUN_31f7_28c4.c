// TIM2.EXE: FUN_31f7_28c4 @ file 0x039A34 Ghidra 0x34834
// Subsystem: misc | Size: 121 bytes


void __cdecl16far FUN_31f7_28c4(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)
        (*(int *)(*(int *)(*(int *)(iVar1 + 8) * 2 + 0x302) + 0x46) +
        (uint)(3 < *(int *)(iVar1 + 0x10)) * 2);
  *(undefined2 *)(iVar1 + 0x96) = 4;
  FUN_28eb_3670(iVar1,uVar2);
  *(undefined2 *)(iVar1 + 0x96) = 1;
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 4;
  if (*(int *)(iVar1 + 0x6e) != 0 || *(int *)(iVar1 + 0x70) != 0) {
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 1;
  }
  if (*(int *)(iVar1 + 0x72) != 0 || *(int *)(iVar1 + 0x74) != 0) {
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 2;
  }
  return;
}

