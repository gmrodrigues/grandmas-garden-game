// TIM2.EXE: FUN_4340_05b5 @ file 0x048BB5 Ghidra 0x439B5
// Subsystem: misc | Size: 147 bytes


int __cdecl16far FUN_4340_05b5(undefined2 param_1,char param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_DX;
  int iVar3;
  int local_e;
  undefined4 local_a;
  
  iVar1 = FUN_4340_07f3(param_1);
  if ((iVar1 != 0 || in_DX != 0) &&
     ((*(int *)(iVar1 + 0xc) != 0 || (iVar2 = FUN_4340_021b(param_1), iVar2 != 0)))) {
    local_a = (undefined4 *)
              CONCAT22(*(undefined2 *)(iVar1 + 6),(undefined4 *)*(undefined2 *)(iVar1 + 4));
    iVar3 = 1;
    iVar2 = *(int *)(iVar1 + 8) * 1000;
    while ((local_e = iVar2 + 1, iVar3 <= *(int *)(iVar1 + 0xc) &&
           ((*(char *)*local_a != param_2 || (param_3 = param_3 + -1, 0 < param_3))))) {
      local_a = (undefined4 *)CONCAT22(local_a._2_2_,(undefined4 *)local_a + 1);
      iVar3 = iVar3 + 1;
      iVar2 = local_e;
    }
    if (iVar3 < *(int *)(iVar1 + 0xc)) {
      return iVar2 + 2;
    }
  }
  return 0;
}

