// TIM2.EXE: FUN_31f7_b097 @ file 0x042207 Ghidra 0x3D007
// Subsystem: sound | Size: 51 bytes


void __cdecl16far FUN_31f7_b097(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)((*(int *)(iVar1 + 0x10) % 8) * 2 + *(int *)(DAT_554c_03f0 + 0x46));
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

