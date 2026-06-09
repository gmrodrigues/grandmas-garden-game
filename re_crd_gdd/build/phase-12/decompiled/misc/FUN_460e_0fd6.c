// TIM2.EXE: FUN_460e_0fd6 @ file 0x04C2B6 Ghidra 0x470B6
// Subsystem: misc | Size: 69 bytes


undefined2 __cdecl16far FUN_460e_0fd6(int param_1,uint param_2)

{
  int iVar1;
  undefined2 uVar2;
  int in_DX;
  
  iVar1 = FUN_460e_0f42(param_1);
  if ((param_1 == 0) || (iVar1 == 0 && in_DX == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined2 *)(iVar1 + 0x24);
    *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & ~(param_2 & 0xfff9);
  }
  return uVar2;
}

