// TIM2.EXE: FUN_1000_752b @ file 0x01C72B Ghidra 0x1752B
// Subsystem: utility | Size: 204 bytes


undefined2 __cdecl16near
FUN_1000_752b(int *param_1,int param_2,undefined2 param_3,undefined2 param_4,int *param_5)

{
  int iVar1;
  int *piVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  undefined4 local_a;
  int local_6;
  int iStack_4;
  
  while( true ) {
    uVar3 = (undefined2)((ulong)param_1 >> 0x10);
    piVar2 = (int *)param_1;
    iStack_4 = piVar2[1];
    local_6 = *param_1;
    if (local_6 == 0 && iStack_4 == 0) {
      return 0;
    }
    local_a = (undefined2 *)CONCAT22(param_5[1],(undefined2 *)(*param_5 + piVar2[2]));
    if (param_2 != 0) {
      local_a = (undefined2 *)CONCAT22(param_5[1],(undefined2 *)*local_a);
    }
    iVar1 = FUN_1000_5f71(local_6,iStack_4,param_3,param_4);
    if ((iVar1 != 0) ||
       ((((*(byte *)(local_6 + 2) & 2) != 0 &&
         (iVar1 = local_6 + *(int *)(local_6 + 10), iVar1 != 0 || iStack_4 != 0)) &&
        (iVar1 = FUN_1000_752b(iVar1,iStack_4,0,param_3,param_4,&local_a), iVar1 != 0)))) break;
    param_1 = (int *)CONCAT22(uVar3,piVar2 + 4);
  }
  param_5[1] = local_a._2_2_;
  *param_5 = (int)(undefined2 *)local_a;
  return 1;
}

