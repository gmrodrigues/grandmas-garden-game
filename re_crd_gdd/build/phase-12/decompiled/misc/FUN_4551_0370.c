// TIM2.EXE: FUN_4551_0370 @ file 0x04AA80 Ghidra 0x45880
// Subsystem: misc | Size: 123 bytes


undefined2 __cdecl16far FUN_4551_0370(undefined2 param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  int in_DX;
  undefined2 *puVar3;
  undefined4 local_a;
  
  iVar1 = FUN_4551_06cf(param_1);
  if (param_2 == -1) {
    if (iVar1 == 0 && in_DX == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined2 *)(iVar1 + 0xc);
    }
  }
  else if ((iVar1 == 0 && in_DX == 0) || (*(int *)(iVar1 + 8) == 0 && *(int *)(iVar1 + 10) == 0)) {
    uVar2 = 0;
  }
  else {
    local_a = (undefined2 *)
              CONCAT22(*(undefined2 *)(iVar1 + 10),(undefined2 *)*(undefined2 *)(iVar1 + 8));
    while( true ) {
      uVar2 = (undefined2)((ulong)local_a >> 0x10);
      puVar3 = (undefined2 *)local_a;
      if ((puVar3[1] == 0) || (puVar3[1] == param_2)) break;
      local_a = (undefined2 *)CONCAT22(uVar2,puVar3 + 2);
    }
    uVar2 = *local_a;
  }
  return uVar2;
}

