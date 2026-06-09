// TIM2.EXE: FUN_3e34_08ef @ file 0x043E2F Ghidra 0x3EC2F
// Subsystem: sound | Size: 106 bytes


bool __cdecl16far FUN_3e34_08ef(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_3f2b_09ca(param_1,0xffff);
  iVar2 = FUN_3f2b_0811(param_1);
  uVar3 = iVar2 - 1;
  if ((iVar1 == 0) && (uVar3 < 500)) {
    FUN_3f2b_042f(param_1,1);
    *(undefined2 *)(uVar3 * 8 + 0x74) = 0;
    *(undefined2 *)(uVar3 * 8 + 0x76) = 0;
  }
  return iVar1 == 0;
}

