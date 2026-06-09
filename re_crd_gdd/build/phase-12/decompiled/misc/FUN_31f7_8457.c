// TIM2.EXE: FUN_31f7_8457 @ file 0x03F5C7 Ghidra 0x3A3C7
// Subsystem: misc | Size: 45 bytes


void __cdecl16far FUN_31f7_8457(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)(*(int *)(iVar1 + 0x10) * 2 + *(int *)(DAT_554c_0390 + 0x46));
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

