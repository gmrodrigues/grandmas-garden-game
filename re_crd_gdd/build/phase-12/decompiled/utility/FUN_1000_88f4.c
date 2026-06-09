// TIM2.EXE: FUN_1000_88f4 @ file 0x01DAF4 Ghidra 0x188F4
// Subsystem: utility | Size: 85 bytes


undefined2 __cdecl16far FUN_1000_88f4(int param_1)

{
  int iVar1;
  undefined2 unaff_SS;
  
  if ((param_1 != -1) &&
     (iVar1 = FUN_1000_a32d(*(int *)(param_1 + 2) + -8,*(undefined2 *)(param_1 + 4),0x5e43,0x554c,8)
     , iVar1 == 0)) {
    return *(undefined2 *)(param_1 + 0xc);
  }
  return 0xffff;
}

