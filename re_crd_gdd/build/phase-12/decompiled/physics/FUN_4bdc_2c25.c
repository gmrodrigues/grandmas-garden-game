// TIM2.EXE: FUN_4bdc_2c25 @ file 0x053BE5 Ghidra 0x4E9E5
// Subsystem: physics | Size: 228 bytes


int __cdecl16far FUN_4bdc_2c25(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  int local_6;
  char local_3;
  
  local_6 = 0;
  local_8 = 0;
  FUN_1a9e_0f7d(param_1,&local_3);
  iVar1 = local_8;
  iVar3 = local_6;
  while (local_6 = iVar3, local_8 = iVar1, local_3 != -1) {
    iVar3 = 8;
    iVar1 = FUN_2e67_0edd(8,0,9);
    if (iVar1 == 0 && iVar3 == 0) break;
    *(undefined2 *)(iVar1 + 6) = 0;
    *(undefined2 *)(iVar1 + 4) = 0;
    iVar2 = 1;
    FUN_1a9e_109d(param_1,1,0,1);
    FUN_1a9e_0f7d(param_1,iVar1,iVar3,4);
    FUN_1a9e_0f7d(param_1,&local_3);
    if (local_8 != 0 || local_6 != 0) {
      iVar1 = FUN_4bdc_2d09(local_8,local_6,iVar1,iVar3);
      iVar3 = iVar2;
    }
  }
  if (local_3 != -1) {
    FUN_4bdc_2add(local_8,local_6);
  }
  return local_8;
}

