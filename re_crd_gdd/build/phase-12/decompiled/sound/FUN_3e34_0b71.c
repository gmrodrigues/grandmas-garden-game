// TIM2.EXE: FUN_3e34_0b71 @ file 0x0440B1 Ghidra 0x3EEB1
// Subsystem: sound | Size: 67 bytes


undefined2 __cdecl16far FUN_3e34_0b71(undefined2 param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  
  iVar1 = FUN_3f2b_0811(param_1);
  uVar2 = iVar1 - 1;
  if ((uVar2 < 500) && (*(int *)(uVar2 * 8 + 0x74) != 0)) {
    if (*(int *)(uVar2 * 8 + 0x76) == 0) {
      FUN_3e34_0959(param_1);
    }
    uVar3 = *(undefined2 *)(uVar2 * 8 + 0x76);
  }
  else {
    DAT_5b41_1ad2 = 0xd;
    uVar3 = 0;
  }
  return uVar3;
}

