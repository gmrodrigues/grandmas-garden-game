// TIM2.EXE: FUN_1a9e_69e9 @ file 0x0265C9 Ghidra 0x213C9
// Subsystem: misc | Size: 105 bytes


int __cdecl16far FUN_1a9e_69e9(undefined2 param_1)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  uint in_DX;
  
  piVar1 = (int *)FUN_1a9e_6886(0);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = FUN_1000_0b20(param_1,0x55a4);
  *piVar1 = iVar2;
  if (iVar2 == 0) {
    return 0;
  }
  FUN_1000_0e6d(*piVar1,0,0,2);
  uVar3 = FUN_1000_0f2a(*piVar1);
  *(uint *)((int)piVar1 + 0x1d) = in_DX | 0x8000;
  *(undefined2 *)((int)piVar1 + 0x1b) = uVar3;
  FUN_1a9e_68b6(piVar1);
  return *piVar1;
}

