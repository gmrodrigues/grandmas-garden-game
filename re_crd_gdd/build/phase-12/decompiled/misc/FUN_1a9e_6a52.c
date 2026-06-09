// TIM2.EXE: FUN_1a9e_6a52 @ file 0x026632 Ghidra 0x21432
// Subsystem: misc | Size: 51 bytes


undefined2 __cdecl16far FUN_1a9e_6a52(undefined2 *param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  puVar4 = (undefined2 *)&DAT_5b41_26de;
  puVar5 = param_1;
  for (iVar3 = 0x21; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar5;
    puVar5 = puVar5 + 1;
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar2 = *puVar1;
  }
  *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
  FUN_1000_0e6d(*param_1,*(undefined2 *)((int)param_1 + 0x3b),*(undefined2 *)((int)param_1 + 0x3d),0
               );
  return 0xffff;
}

