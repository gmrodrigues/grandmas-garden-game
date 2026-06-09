// TIM2.EXE: FUN_31f7_20c8 @ file 0x039238 Ghidra 0x34038
// Subsystem: misc | Size: 53 bytes


void __cdecl16far FUN_31f7_20c8(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined1 *)(iVar1 + 0x7a) = 0x12;
  *(undefined1 *)(iVar1 + 0x7b) = 1;
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)*(undefined2 *)(*(int *)(*(int *)(iVar1 + 8) * 2 + 0x302) + 0x46);
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

