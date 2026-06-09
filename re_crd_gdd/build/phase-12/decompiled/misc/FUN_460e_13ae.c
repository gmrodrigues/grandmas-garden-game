// TIM2.EXE: FUN_460e_13ae @ file 0x04C68E Ghidra 0x4748E
// Subsystem: misc | Size: 112 bytes


undefined2 * __cdecl16far FUN_460e_13ae(undefined2 param_1,uint param_2)

{
  int iVar1;
  undefined2 *puVar2;
  int in_DX;
  undefined4 local_6;
  
  puVar2 = (undefined2 *)FUN_460e_0f42(param_1);
  local_6 = (undefined2 *)CONCAT22(in_DX,puVar2);
  if (puVar2 != (undefined2 *)0x0 || in_DX != 0) {
    if (param_2 == 0) {
      return (undefined2 *)*local_6;
    }
    do {
      iVar1 = ((undefined2 *)local_6)[1];
      puVar2 = (undefined2 *)*local_6;
      local_6 = (undefined2 *)CONCAT22(iVar1,puVar2);
      if (puVar2 == (undefined2 *)0x0 && iVar1 == 0) break;
    } while (param_2 < (uint)puVar2[8]);
    if ((puVar2 != (undefined2 *)0x0 || iVar1 != 0) && (puVar2[8] == param_2)) {
      return puVar2;
    }
  }
  return (undefined2 *)0x0;
}

