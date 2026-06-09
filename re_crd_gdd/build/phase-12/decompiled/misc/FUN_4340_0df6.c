// TIM2.EXE: FUN_4340_0df6 @ file 0x0493F6 Ghidra 0x441F6
// Subsystem: misc | Size: 93 bytes


undefined2 __cdecl16far FUN_4340_0df6(char *param_1,char param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_6;
  
  if (((char *)param_1 == (char *)0x0 && param_1._2_2_ == 0) || (param_2 == '\0')) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_4340_0a09((char *)param_1,param_1._2_2_);
    local_6 = (char *)CONCAT22(param_1._2_2_,(char *)param_1 + iVar2 + 1);
    iVar2 = iVar2 + 1;
    while (iVar2 != 0) {
      uVar1 = (undefined2)((ulong)local_6 >> 0x10);
      *local_6 = ((char *)local_6)[-1];
      local_6 = (char *)CONCAT22(uVar1,(char *)local_6 + -1);
      iVar2 = iVar2 + -1;
    }
    *param_1 = param_2;
    uVar1 = 1;
  }
  return uVar1;
}

