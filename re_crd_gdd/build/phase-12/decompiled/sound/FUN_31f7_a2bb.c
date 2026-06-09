// TIM2.EXE: FUN_31f7_a2bb @ file 0x04142B Ghidra 0x3C22B
// Subsystem: sound | Size: 43 bytes


void __cdecl16far FUN_31f7_a2bb(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)*(undefined2 *)(*(int *)(*(int *)(iVar1 + 8) * 2 + 0x302) + 0x46);
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

