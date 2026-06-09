// TIM2.EXE: FUN_4876_1775 @ file 0x04F0D5 Ghidra 0x49ED5
// Subsystem: misc | Size: 239 bytes


void __cdecl16far FUN_4876_1775(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 local_6;
  
  if (param_1 != (int *)0x0 || param_2 != 0) {
    local_6 = (int *)CONCAT22(param_2,param_1);
    while (*local_6 != 0) {
      iVar1 = FUN_460e_0f42(*local_6);
      if (iVar1 != 0 || param_2 != 0) {
        if ((*(byte *)((int *)local_6 + 1) & 1) != 0) {
          *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + param_3;
        }
        if ((*(byte *)((int *)local_6 + 1) & 2) != 0) {
          *(int *)(iVar1 + 0x16) = *(int *)(iVar1 + 0x16) + param_4;
        }
        if ((*(byte *)((int *)local_6 + 1) & 4) != 0) {
          *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + param_3;
        }
        if ((*(byte *)((int *)local_6 + 1) & 8) != 0) {
          *(int *)(iVar1 + 0x1a) = *(int *)(iVar1 + 0x1a) + param_4;
        }
      }
      if ((iVar1 != 0 || param_2 != 0) && (*(int *)(iVar1 + 0xe) == 4)) {
        if ((*(byte *)((int *)local_6 + 1) & 1) != 0) {
          *(int *)(iVar1 + 0x38) = *(int *)(iVar1 + 0x38) + param_3;
        }
        if ((*(byte *)((int *)local_6 + 1) & 2) != 0) {
          *(int *)(iVar1 + 0x3a) = *(int *)(iVar1 + 0x3a) + param_4;
        }
        if ((*(byte *)((int *)local_6 + 1) & 4) != 0) {
          *(int *)(iVar1 + 0x3c) = *(int *)(iVar1 + 0x3c) + param_3;
        }
        if ((*(byte *)((int *)local_6 + 1) & 8) != 0) {
          *(int *)(iVar1 + 0x3e) = *(int *)(iVar1 + 0x3e) + param_4;
        }
      }
      local_6 = (int *)CONCAT22(local_6._2_2_,(int *)local_6 + 2);
    }
  }
  return;
}

