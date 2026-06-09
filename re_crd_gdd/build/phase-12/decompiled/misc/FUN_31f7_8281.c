// TIM2.EXE: FUN_31f7_8281 @ file 0x03F3F1 Ghidra 0x3A1F1
// Subsystem: misc | Size: 148 bytes


void __cdecl16far FUN_31f7_8281(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (param_2 == 0xf) {
    *(undefined2 *)(iVar1 + 0x10) =
         ((undefined2 *)&DAT_5b41_0987)
         [((uint)(DAT_5b41_0989 <= *(int *)(iVar1 + 0xa8)) +
           (uint)(DAT_5b41_098b <= *(int *)(iVar1 + 0xa8)) + 1) % 3];
  }
  *(undefined2 *)(iVar1 + 0xa8) = *(undefined2 *)(iVar1 + 0x10);
  FUN_31f7_818e(iVar1,param_1._2_2_);
  FUN_28eb_3328(iVar1,param_1._2_2_);
  FUN_2424_0f94(iVar1,param_1._2_2_,3);
  FUN_28eb_2d82(iVar1,param_1._2_2_,2);
  return;
}

