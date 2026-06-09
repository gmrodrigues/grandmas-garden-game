// TIM2.EXE: FUN_1a9e_68b6 @ file 0x026496 Ghidra 0x21296
// Subsystem: misc | Size: 78 bytes


void __cdecl16far FUN_1a9e_68b6(undefined2 *param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  int iVar5;
  
  uVar1 = *param_1;
  uVar2 = *(undefined2 *)((int)param_1 + 0x1d);
  uVar3 = *(undefined2 *)((int)param_1 + 0x1b);
  puVar4 = param_1;
  iVar5 = 0x43;
  while (0 < iVar5) {
    *(undefined1 *)puVar4 = 0;
    puVar4 = (undefined2 *)((int)puVar4 + 1);
    iVar5 = iVar5 + -1;
  }
  *(undefined2 *)((int)param_1 + 0x1d) = uVar2;
  *(undefined2 *)((int)param_1 + 0x1b) = uVar3;
  *param_1 = uVar1;
  FUN_1000_0fc7(uVar1);
  return;
}

