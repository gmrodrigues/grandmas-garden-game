// TIM2.EXE: FUN_31f7_ac91 @ file 0x041E01 Ghidra 0x3CC01
// Subsystem: sound | Size: 51 bytes


void __cdecl16far FUN_31f7_ac91(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)((*(int *)(iVar1 + 0x10) / 7) * 2 + *(int *)(DAT_554c_03ec + 0x46));
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

