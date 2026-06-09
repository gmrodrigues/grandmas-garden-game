// TIM2.EXE: FUN_1a9e_7d9a @ file 0x02797A Ghidra 0x2277A
// Subsystem: physics | Size: 446 bytes


undefined2 __cdecl16far FUN_1a9e_7d9a(undefined2 param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int in_DX;
  int iVar3;
  undefined2 *local_e;
  int *local_c;
  int local_a;
  int local_8;
  undefined2 *local_6;
  undefined2 *local_4;
  
  local_e = (undefined2 *)0x0;
  *param_3 = 0;
  iVar1 = FUN_1a9e_6a85(param_1,0x5640,0);
  if ((in_DX == -1) && (iVar1 == -1)) {
    return 0;
  }
  iVar1 = FUN_1000_0d10(param_2,2,1,param_1);
  if (iVar1 != 1) {
    return 0;
  }
  iVar1 = FUN_1000_12bf((*param_2 + 1) * 2,1);
  *param_3 = iVar1;
  if (iVar1 != 0) {
    iVar1 = FUN_1000_12bf(10,*param_2);
    *(int *)*param_3 = iVar1;
    if (iVar1 != 0) {
      uVar2 = FUN_1a9e_6e3d(param_1);
      iVar1 = in_DX + -1 + (uint)(1 < uVar2);
      iVar3 = (*param_2 << 2) >> 0xf;
      if ((iVar3 < iVar1) || ((iVar3 <= iVar1 && ((uint)(*param_2 << 2) <= uVar2 - 2)))) {
        local_a = *param_2;
      }
      else {
        local_a = 1;
      }
      local_e = (undefined2 *)FUN_1000_127a(local_a << 2);
      if ((local_e != (undefined2 *)0x0) &&
         (iVar1 = FUN_1000_0d10(local_e,local_a << 2,1,param_1), iVar1 == 1)) {
        local_6 = local_e + local_a;
        iVar1 = *(int *)*param_3;
        local_c = (int *)*param_3;
        local_4 = local_e;
        for (local_8 = 0; local_8 < *param_2; local_8 = local_8 + 1) {
          *local_c = iVar1;
          *(undefined2 *)(iVar1 + 6) = *local_4;
          *(undefined2 *)(iVar1 + 8) = *local_6;
          if (*param_2 == local_a) {
            local_4 = local_4 + 1;
            local_6 = local_6 + 1;
          }
          iVar1 = iVar1 + 10;
          local_c = local_c + 1;
        }
        *local_c = 0;
        FUN_1000_130c(local_e);
        return 1;
      }
    }
  }
  if (local_e != (undefined2 *)0x0) {
    FUN_1000_130c(local_e);
  }
  if (*param_3 != 0) {
    if (*(int *)*param_3 != 0) {
      FUN_1000_130c(*(undefined2 *)*param_3);
    }
    FUN_1000_130c(*param_3);
  }
  return 0;
}

