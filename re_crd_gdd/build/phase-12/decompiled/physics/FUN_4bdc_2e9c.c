// TIM2.EXE: FUN_4bdc_2e9c @ file 0x053E5C Ghidra 0x4EC5C
// Subsystem: physics | Size: 192 bytes


int __cdecl16far
FUN_4bdc_2e9c(undefined2 param_1,undefined2 param_2,undefined2 param_3,int *param_4,
             undefined2 param_5)

{
  int iVar1;
  int iVar2;
  int in_DX;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  local_8 = 0;
  local_a = 0;
  iVar1 = FUN_1a9e_0c49(0,param_1,0x572c,param_2,param_3);
  if (-1 < iVar1) {
    local_6 = FUN_1a9e_1079(iVar1);
    local_8 = in_DX;
    local_a = FUN_2e67_0edd(local_6,in_DX,param_5);
    if (local_a != 0 || local_8 != 0) {
      iVar2 = FUN_1a9e_0f7d(iVar1,local_a,local_8,local_6);
      if ((in_DX != 0) || (iVar2 != local_6)) {
        FUN_2e67_10e9(local_a,local_8,param_5);
        local_8 = 0;
        local_a = 0;
      }
    }
    FUN_1a9e_0eab(iVar1);
    local_4 = in_DX;
  }
  if ((param_4 != (int *)0x0) && (local_a != 0 || local_8 != 0)) {
    param_4[1] = local_4;
    *param_4 = local_6;
  }
  return local_a;
}

