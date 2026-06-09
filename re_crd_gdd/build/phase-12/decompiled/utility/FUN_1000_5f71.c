// TIM2.EXE: FUN_1000_5f71 @ file 0x01B171 Ghidra 0x15F71
// Subsystem: utility | Size: 139 bytes


undefined2 __cdecl16far FUN_1000_5f71(int *param_1,int *param_2)

{
  char cVar1;
  char cVar2;
  undefined4 local_a;
  undefined4 local_6;
  
  if ((param_1._2_2_ != param_2._2_2_) || ((int *)param_1 != (int *)param_2)) {
    if ((((int *)param_1)[1] != ((int *)param_2)[1]) || (*param_1 != *param_2)) {
      return 0;
    }
    local_6 = (char *)CONCAT22(param_1._2_2_,(char *)((int)(int *)param_1 + ((int *)param_1)[2]));
    local_a = (char *)CONCAT22(param_2._2_2_,(char *)((int)(int *)param_2 + ((int *)param_2)[2]));
    do {
      cVar1 = *local_6;
      local_6 = (char *)CONCAT22(local_6._2_2_,(char *)local_6 + 1);
      cVar2 = *local_a;
      local_a = (char *)CONCAT22(local_a._2_2_,(char *)local_a + 1);
      if (cVar1 != cVar2) {
        return 0;
      }
    } while (cVar1 != '\0');
  }
  return 1;
}

