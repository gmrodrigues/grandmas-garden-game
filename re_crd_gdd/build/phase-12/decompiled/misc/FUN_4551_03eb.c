// TIM2.EXE: FUN_4551_03eb @ file 0x04AAFB Ghidra 0x458FB
// Subsystem: misc | Size: 177 bytes


undefined2 __cdecl16far FUN_4551_03eb(undefined2 param_1,uint param_2,undefined2 *param_3)

{
  int *piVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  int in_DX;
  int iVar4;
  undefined4 local_a;
  undefined4 local_6;
  
  piVar1 = (int *)FUN_4551_06cf(param_1);
  local_6 = (int *)CONCAT22(in_DX,piVar1);
  if (((piVar1 == (int *)0x0 && in_DX == 0) ||
      ((undefined2 *)param_3 == (undefined2 *)0x0 && param_3._2_2_ == 0)) ||
     ((uint)piVar1[6] <= param_2)) {
    uVar2 = 0;
  }
  else {
    if (*local_6 == 0 && piVar1[1] == 0) {
      iVar4 = piVar1[3];
      puVar3 = (undefined2 *)(piVar1[2] + param_2 * 0xc);
    }
    else {
      iVar4 = piVar1[3];
      puVar3 = (undefined2 *)(*(int *)((int)*(undefined4 *)local_6 + param_2 * 2) * 0xc + piVar1[2])
      ;
    }
    local_a = (undefined2 *)CONCAT22(iVar4,puVar3);
    *param_3 = *local_a;
    ((undefined2 *)param_3)[1] = puVar3[1];
    ((undefined2 *)param_3)[2] = puVar3[2];
    ((undefined2 *)param_3)[3] = puVar3[3];
    uVar2 = 1;
  }
  return uVar2;
}

