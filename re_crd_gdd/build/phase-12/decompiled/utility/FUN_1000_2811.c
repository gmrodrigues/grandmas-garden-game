// TIM2.EXE: FUN_1000_2811 @ file 0x017A11 Ghidra 0x12811
// Subsystem: utility | Size: 67 bytes


undefined2 __cdecl16far FUN_1000_2811(undefined2 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  
  uVar1 = *(undefined2 *)((int)*(undefined4 *)0x16 + 10);
  uVar3 = (undefined2)((ulong)*(undefined4 *)0x16 >> 0x10);
  iVar2 = (int)*(undefined4 *)0x16;
  *(undefined2 *)(iVar2 + 0xc) = param_2;
  *(undefined2 *)(iVar2 + 10) = param_1;
  *(undefined2 *)((int)*(undefined4 *)0x16 + 0x12) = 0x554c;
  return uVar1;
}

