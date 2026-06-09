// TIM2.EXE: FUN_1000_7f88 @ file 0x01D188 Ghidra 0x17F88
// Subsystem: utility | Size: 89 bytes


void __cdecl16far
FUN_1000_7f88(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined2 local_20;
  
  FUN_1000_27ad();
  uVar2 = (undefined2)((ulong)param_3 >> 0x10);
  iVar1 = (int)param_3;
  FUN_1000_6732(param_1,param_2,*(undefined2 *)(iVar1 + 0x1e),*(undefined2 *)(iVar1 + 0x20),
                *(undefined2 *)(iVar1 + 0x22),param_4);
  *(undefined2 *)0x14 = local_20;
  return;
}

