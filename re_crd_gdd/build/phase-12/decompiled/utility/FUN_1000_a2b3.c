// TIM2.EXE: FUN_1000_a2b3 @ file 0x01F4B3 Ghidra 0x1A2B3
// Subsystem: utility | Size: 61 bytes


undefined2 __cdecl16far FUN_1000_a2b3(int param_1,byte param_2)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  
  if (param_1 == 0) {
    uVar3 = 0;
  }
  else {
    piVar1 = (int *)0x10;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    *(int *)0x12 = *(int *)0x12 - (uint)(iVar2 == 0);
    uVar3 = FUN_1000_5ced(param_1,0);
    if ((param_2 & 1) != 0) {
      uVar3 = FUN_1000_1499(param_1);
    }
  }
  return uVar3;
}

