// TIM2.EXE: FUN_31f7_0125 @ file 0x037295 Ghidra 0x32095
// Subsystem: misc | Size: 132 bytes


void __cdecl16far FUN_31f7_0125(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0x10) == 3) {
    *(undefined2 *)(iVar2 + 0x7a) = *(undefined2 *)(*(int *)(iVar2 + 0x10) * 2 + 0x39d8);
    uVar1 = *(undefined2 *)(*(int *)(iVar2 + 0x10) * 2 + 0x39de);
  }
  else {
    *(undefined2 *)(iVar2 + 0x7a) = *(undefined2 *)(*(int *)(iVar2 + 0x10) * 2 + 0x39e4);
    uVar1 = *(undefined2 *)(*(int *)(iVar2 + 0x10) * 2 + 0x39ea);
  }
  *(undefined2 *)(iVar2 + 0x7c) = uVar1;
  *(undefined2 *)(iVar2 + 0x98) =
       *(undefined2 *)
        (*(int *)(*(int *)(*(int *)(iVar2 + 8) * 2 + 0x302) + 0x46) + *(int *)(iVar2 + 0x10) * 2);
  FUN_28eb_3670(iVar2,uVar3);
  return;
}

