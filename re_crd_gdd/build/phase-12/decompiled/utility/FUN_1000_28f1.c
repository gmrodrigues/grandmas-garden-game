// TIM2.EXE: FUN_1000_28f1 @ file 0x017AF1 Ghidra 0x128F1
// Subsystem: utility | Size: 67 bytes


undefined2 __cdecl16far FUN_1000_28f1(undefined2 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  
  uVar1 = *(undefined2 *)((int)*(undefined4 *)0x16 + 0xe);
  uVar3 = (undefined2)((ulong)*(undefined4 *)0x16 >> 0x10);
  iVar2 = (int)*(undefined4 *)0x16;
  *(undefined2 *)(iVar2 + 0x10) = param_2;
  *(undefined2 *)(iVar2 + 0xe) = param_1;
  *(undefined2 *)((int)*(undefined4 *)0x16 + 0x14) = 0x554c;
  return uVar1;
}

