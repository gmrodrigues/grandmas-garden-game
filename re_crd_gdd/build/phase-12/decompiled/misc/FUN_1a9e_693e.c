// TIM2.EXE: FUN_1a9e_693e @ file 0x02651E Ghidra 0x2131E
// Subsystem: misc | Size: 74 bytes


undefined2 * __cdecl16far FUN_1a9e_693e(undefined2 *param_1,int param_2)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined2 *puVar5;
  
  if ((param_2 != 0) && (param_1 != (undefined2 *)0x0)) {
    puVar3 = (undefined2 *)FUN_1a9e_6886(param_2);
    if (puVar3 != (undefined2 *)0x0) {
      puVar5 = param_1;
      for (iVar4 = 0x21; iVar4 != 0; iVar4 = iVar4 + -1) {
        puVar2 = puVar5;
        puVar5 = puVar5 + 1;
        puVar1 = puVar3;
        puVar3 = puVar3 + 1;
        *puVar2 = *puVar1;
      }
      *(undefined1 *)puVar5 = *(undefined1 *)puVar3;
      return param_1;
    }
  }
  return (undefined2 *)0x0;
}

