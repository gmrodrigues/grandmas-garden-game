// TIM2.EXE: FUN_4551_0308 @ file 0x04AA18 Ghidra 0x45818
// Subsystem: misc | Size: 104 bytes


uint __cdecl16far FUN_4551_0308(undefined2 param_1,uint param_2)

{
  int iVar1;
  int in_DX;
  uint *puVar2;
  undefined2 uVar3;
  undefined4 local_a;
  
  iVar1 = FUN_4551_06cf(param_1);
  if (((iVar1 != 0 || in_DX != 0) && (param_2 < *(uint *)(iVar1 + 0xc))) &&
     (*(int *)(iVar1 + 8) != 0 || *(int *)(iVar1 + 10) != 0)) {
    local_a = (uint *)CONCAT22(*(undefined2 *)(iVar1 + 10),(uint *)*(undefined2 *)(iVar1 + 8));
    while( true ) {
      uVar3 = (undefined2)((ulong)local_a >> 0x10);
      puVar2 = (uint *)local_a;
      if ((puVar2[1] == 0) || (*local_a == param_2)) break;
      local_a = (uint *)CONCAT22(uVar3,puVar2 + 2);
    }
    return puVar2[1];
  }
  return 0xffff;
}

