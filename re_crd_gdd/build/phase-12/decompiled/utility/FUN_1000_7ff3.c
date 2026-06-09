// TIM2.EXE: FUN_1000_7ff3 @ file 0x01D1F3 Ghidra 0x17FF3
// Subsystem: utility | Size: 129 bytes


void __cdecl16far
FUN_1000_7ff3(int param_1,undefined2 param_2,int *param_3,int *param_4,undefined2 param_5,
             undefined2 param_6,int param_7,undefined2 param_8)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_6;
  
  while (piVar3 = (int *)param_3, piVar1 = (int *)param_3 + -4,
        param_3 = (int *)CONCAT22(param_3._2_2_,piVar1), param_4 <= piVar1) {
    local_6 = (undefined2 *)CONCAT22(param_2,(undefined2 *)(param_1 + piVar3[-2]));
    if (param_7 != 0) {
      local_6 = (undefined2 *)CONCAT22(param_2,(undefined2 *)*local_6);
    }
    iVar2 = piVar3[-3];
    if ((*(byte *)(*param_3 + 8) & 2) != 0) {
      FUN_1000_8074((undefined2 *)local_6,local_6._2_2_,*param_3,iVar2,param_6,0,0,param_8);
      param_6 = 0;
    }
  }
  return;
}

