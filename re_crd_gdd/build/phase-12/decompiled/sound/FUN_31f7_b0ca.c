// TIM2.EXE: FUN_31f7_b0ca @ file 0x04223A Ghidra 0x3D03A
// Subsystem: sound | Size: 91 bytes


void __cdecl16far FUN_31f7_b0ca(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (param_2 == 0xf) {
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
    if (*(int *)(iVar1 + 0x10) == 8) {
      *(undefined2 *)(iVar1 + 0x10) = 0;
    }
  }
  *(undefined2 *)(iVar1 + 0xa8) = *(undefined2 *)(iVar1 + 0x10);
  FUN_31f7_b097(iVar1,param_1._2_2_);
  FUN_28eb_3328(iVar1,param_1._2_2_);
  FUN_2424_0f94(iVar1,param_1._2_2_,3);
  FUN_28eb_2d82(iVar1,param_1._2_2_,2);
  return;
}

