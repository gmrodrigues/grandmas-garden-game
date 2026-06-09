// TIM2.EXE: FUN_4bdc_27b2 @ file 0x053772 Ghidra 0x4E572
// Subsystem: physics | Size: 148 bytes


undefined2 __cdecl16far FUN_4bdc_27b2(int param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int in_DX;
  undefined2 local_8;
  
  local_8 = 0;
  iVar1 = FUN_1a9e_6ea7(param_1);
  if (iVar1 == 0) {
    param_1 = FUN_1a9e_69e9(param_1);
  }
  if ((param_1 != 0) &&
     ((iVar2 = FUN_1a9e_6a85(param_1,param_2,param_3), in_DX != -1 || (iVar2 != -1)))) {
    uVar3 = FUN_1a9e_6e3d(param_1,0,1);
    local_8 = FUN_4bdc_2e9c(param_1,uVar3,in_DX);
  }
  if (iVar1 == 0) {
    FUN_1a9e_6e73(param_1);
  }
  return local_8;
}

