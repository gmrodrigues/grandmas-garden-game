// TIM2.EXE: FUN_4340_0648 @ file 0x048C48 Ghidra 0x43A48
// Subsystem: misc | Size: 167 bytes


int __cdecl16far FUN_4340_0648(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int in_DX;
  int iVar5;
  undefined4 local_a;
  
  iVar4 = FUN_4340_07f3(param_1);
  if ((iVar4 != 0 || in_DX != 0) && (*(int *)(iVar4 + 0xc) != 0)) {
    param_1 = param_1 % 1000;
    iVar2 = *(int *)(iVar4 + 0xc);
    if ((int)param_1 <= iVar2) {
      if (param_1 < 2) {
        return iVar2;
      }
      puVar1 = (undefined4 *)(*(int *)(iVar4 + 4) + param_1 * 4 + -8);
      local_a = (undefined4 *)CONCAT22(*(undefined2 *)(iVar4 + 6),puVar1);
      pcVar3 = (char *)*local_a;
      iVar5 = 1;
      local_a = (undefined4 *)CONCAT22(*(undefined2 *)(iVar4 + 6),puVar1 + 1);
      while ((iVar5 <= (int)((iVar2 - param_1) + 1) && (*(char *)*local_a != *pcVar3))) {
        iVar5 = iVar5 + 1;
        local_a = (undefined4 *)CONCAT22(local_a._2_2_,(undefined4 *)local_a + 1);
      }
      return iVar5 + -1;
    }
  }
  return 0;
}

