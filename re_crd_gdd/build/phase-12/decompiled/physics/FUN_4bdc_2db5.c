// TIM2.EXE: FUN_4bdc_2db5 @ file 0x053D75 Ghidra 0x4EB75
// Subsystem: physics | Size: 231 bytes


undefined2 __cdecl16far
FUN_4bdc_2db5(undefined2 param_1,int *param_2,undefined1 *param_3,undefined2 param_4,int param_5,
             undefined1 param_6)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  undefined4 local_a;
  undefined1 *local_6;
  
  local_a = (undefined2 *)CONCAT22(param_4,param_3);
  local_6 = param_3 + param_5;
  *(undefined1 *)local_a = 0x84;
  local_a = (undefined2 *)CONCAT22(param_4,param_3 + 1);
  *(undefined1 *)local_a = 0;
  local_a = (undefined2 *)CONCAT22(param_4,param_3 + 2);
  *(undefined1 *)local_a = param_6;
  local_a = (undefined2 *)CONCAT22(param_4,param_3 + 3);
  while( true ) {
    if ((int *)param_2 == (int *)0x0 && param_2._2_2_ == 0) {
      *local_a = 0xffff;
      return 1;
    }
    uVar3 = (undefined2)((ulong)local_a >> 0x10);
    puVar2 = (undefined2 *)local_a;
    *(undefined1 *)local_a = 0;
    *(undefined1 *)((int)puVar2 + 1) = 0;
    puVar2[1] = local_6 + (-2 - (int)param_3);
    puVar2[2] = ((int *)param_2)[1];
    FUN_1a9e_109d(param_1,*param_2 + 2,0,0);
    iVar1 = FUN_1a9e_0f7d(param_1,local_6,param_4,((int *)param_2)[1]);
    if (iVar1 != ((int *)param_2)[1]) break;
    local_6 = local_6 + ((int *)param_2)[1];
    param_2 = (int *)CONCAT22(((int *)param_2)[3],(int *)((int *)param_2)[2]);
    local_a = (undefined2 *)CONCAT22(uVar3,puVar2 + 3);
  }
  return 0;
}

