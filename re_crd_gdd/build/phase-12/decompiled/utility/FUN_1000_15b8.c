// TIM2.EXE: FUN_1000_15b8 @ file 0x0167B8 Ghidra 0x115B8
// Subsystem: utility | Size: 280 bytes


int FUN_1000_15b8(int *param_1,int param_2,int *param_3)

{
  undefined2 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 *local_8;
  uint local_6;
  int *local_4;
  
  local_6 = 1;
  local_4 = param_3;
  if (param_3 != (int *)0x0) {
    local_6 = 0;
    while ((*local_4 != 0 && (*(char *)*local_4 != '\0'))) {
      iVar2 = FUN_1000_54d4(*local_4);
      local_6 = local_6 + iVar2 + 1;
      local_4 = local_4 + 1;
    }
  }
  local_6 = local_6 + 1;
  if (param_2 != 0) {
    iVar2 = FUN_1000_54d4(param_2);
    local_6 = local_6 + iVar2 + 3;
  }
  if ((local_6 < 0x2000) && (iVar2 = FUN_1000_3226(local_6 + 0xf), iVar2 != 0)) {
    *param_1 = iVar2;
    local_8 = (undefined2 *)(iVar2 + 0xfU & 0xfff0);
    local_4 = param_3;
    if ((param_3 == (int *)0x0) || (*param_3 == 0)) {
      *(undefined1 *)local_8 = 0;
      local_8 = (undefined2 *)((int)local_8 + 1);
    }
    else {
      while ((*local_4 != 0 && (*(char *)*local_4 != '\0'))) {
        puVar3 = (undefined1 *)FUN_1000_140a(local_8,*local_4);
        *puVar3 = 0;
        local_8 = (undefined2 *)(puVar3 + 1);
        local_4 = local_4 + 1;
      }
    }
    *(undefined1 *)local_8 = 0;
    puVar1 = (undefined2 *)((int)local_8 + 1);
    if (param_2 != 0) {
      *(undefined2 *)((int)local_8 + 1) = 1;
      puVar3 = (undefined1 *)FUN_1000_140a((undefined1 *)((int)local_8 + 3),param_2);
      *puVar3 = 0;
      puVar1 = (undefined2 *)(puVar3 + 1);
    }
    local_8 = puVar1;
    iVar2 = (int)local_8 - local_6;
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

