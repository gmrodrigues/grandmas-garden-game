// TIM2.EXE: FUN_1a9e_6988 @ file 0x026568 Ghidra 0x21368
// Subsystem: misc | Size: 97 bytes


undefined2 __cdecl16far FUN_1a9e_6988(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    piVar3 = (int *)FUN_1a9e_6886(*param_1);
    if (piVar3 != (int *)0x0) {
      piVar5 = piVar3;
      for (iVar4 = 0x21; iVar4 != 0; iVar4 = iVar4 + -1) {
        piVar2 = piVar5;
        piVar5 = piVar5 + 1;
        piVar1 = param_1;
        param_1 = param_1 + 1;
        *piVar2 = *piVar1;
      }
      *(char *)piVar5 = (char)*param_1;
      FUN_1000_0e6d(*piVar3,*(undefined2 *)((int)piVar3 + 0x3b),*(undefined2 *)((int)piVar3 + 0x3d),
                    0);
      return 1;
    }
  }
  return 0;
}

