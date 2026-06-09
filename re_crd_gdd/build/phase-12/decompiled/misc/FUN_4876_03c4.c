// TIM2.EXE: FUN_4876_03c4 @ file 0x04DD24 Ghidra 0x48B24
// Subsystem: misc | Size: 242 bytes


undefined2 __cdecl16far FUN_4876_03c4(undefined2 param_1,int param_2)

{
  int iVar1;
  undefined2 *puVar2;
  int in_DX;
  int iVar3;
  undefined4 local_e;
  undefined4 local_a;
  
  if (param_2 == 0) {
    iVar1 = FUN_460e_0f42(param_1);
    if (iVar1 == 0 && in_DX == 0) {
      return 0;
    }
    param_2 = *(int *)(iVar1 + 0x10);
  }
  puVar2 = (undefined2 *)FUN_460e_0d51(0,param_2);
  if (puVar2 == (undefined2 *)0x0 && in_DX == 0) {
    return 0;
  }
  local_a = (undefined2 *)CONCAT22(in_DX,puVar2);
  iVar1 = 0;
  iVar3 = in_DX;
  while( true ) {
    if (((undefined2 *)local_a == (undefined2 *)0x0 && local_a._2_2_ == 0) || (iVar1 != 0)) break;
    local_e = (int *)CONCAT22(local_a._2_2_,(undefined2 *)local_a + 0x14);
    iVar1 = *local_e;
    if (iVar1 != 0) {
      FUN_4551_0177(iVar1);
    }
    iVar3 = ((undefined2 *)local_a)[1];
    local_a = (undefined2 *)CONCAT22(iVar3,(undefined2 *)*local_a);
  }
  local_a._0_2_ = (undefined2 *)FUN_460e_141e(puVar2,in_DX,0,2);
  local_a._2_2_ = iVar3;
  while ((undefined2 *)local_a != (undefined2 *)0x0 || local_a._2_2_ != 0) {
    iVar1 = *(int *)((int)(undefined2 *)local_a + 10);
    iVar3 = *(int *)((int)(undefined2 *)local_a + 8);
    FUN_22de_0351((undefined2 *)local_a,local_a._2_2_);
    DAT_5b41_0be0 = DAT_5b41_0be0 + -1;
    local_a._0_2_ = (undefined2 *)iVar3;
    local_a._2_2_ = iVar1;
  }
  if (param_2 == DAT_554c_2f1c) {
    DAT_554c_2f1c = DAT_554c_2f1c + -100;
  }
  return 1;
}

