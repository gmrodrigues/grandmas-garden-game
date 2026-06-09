// TIM2.EXE: FUN_460e_101b @ file 0x04C2FB Ghidra 0x470FB
// Subsystem: misc | Size: 119 bytes


undefined2 __cdecl16far FUN_460e_101b(undefined2 param_1,int param_2,undefined2 param_3)

{
  int *piVar1;
  int iVar2;
  undefined2 *puVar3;
  int in_DX;
  undefined2 local_8;
  undefined4 local_6;
  
  puVar3 = DAT_5b41_1c0e;
  iVar2 = DAT_5b41_1c10;
  if (param_2 == 0) {
    iVar2 = FUN_460e_0f42(param_1);
    if (iVar2 == 0 && in_DX == 0) {
      local_8 = 0;
    }
    else {
      local_8 = *(undefined2 *)(iVar2 + 0x26);
      *(undefined2 *)(iVar2 + 0x26) = param_3;
    }
  }
  else {
    while (local_6 = (undefined2 *)CONCAT22(iVar2,puVar3), puVar3 != (undefined2 *)0x0 || iVar2 != 0
          ) {
      if (puVar3[8] == param_2) {
        local_8 = puVar3[0x13];
        puVar3[0x13] = param_3;
      }
      piVar1 = puVar3 + 1;
      iVar2 = *piVar1;
      puVar3 = (undefined2 *)*local_6;
    }
  }
  return local_8;
}

