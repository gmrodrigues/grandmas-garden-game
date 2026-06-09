// TIM2.EXE: FUN_31f7_b22f @ file 0x04239F Ghidra 0x3D19F
// Subsystem: sound | Size: 98 bytes


undefined2 __cdecl16far FUN_31f7_b22f(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar3 + 0x9c);
  iVar2 = *(int *)(iVar3 + 0x9a);
  if (*(int *)(iVar3 + 0xa2) == 0) {
    if (*(int *)(iVar2 + 0x16) == 0) {
      if (*(int *)(iVar2 + 0x16) == 0) {
        FUN_2e67_045f(0xc40,0,1,1);
      }
      *(undefined2 *)(iVar2 + 0x16) = 1;
      *(undefined1 *)(iVar2 + 0x18) = 2;
      *(undefined2 *)(iVar2 + 0x10) = 1;
    }
  }
  return 1;
}

