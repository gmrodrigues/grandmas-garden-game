// TIM2.EXE: FUN_31f7_9f89 @ file 0x0410F9 Ghidra 0x3BEF9
// Subsystem: gfx | Size: 80 bytes


void __cdecl16far FUN_31f7_9f89(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (param_2 == 0xf) {
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
    if (*(int *)(iVar1 + 0x10) == 4) {
      *(undefined2 *)(iVar1 + 0x10) = 0;
    }
  }
  *(undefined2 *)(iVar1 + 0xa8) = *(undefined2 *)(iVar1 + 0x10);
  FUN_31f7_9f5c(iVar1,param_1._2_2_);
  FUN_2424_0f94(iVar1,param_1._2_2_,3);
  FUN_28eb_2d82(iVar1,param_1._2_2_,2);
  return;
}

