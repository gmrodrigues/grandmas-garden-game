// TIM2.EXE: FUN_4340_1602 @ file 0x049C02 Ghidra 0x44A02
// Subsystem: misc | Size: 62 bytes


undefined2 __cdecl16far FUN_4340_1602(undefined2 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined2 uVar2;
  
  if (((undefined2 *)param_1 != (undefined2 *)0x0 || param_1._2_2_ != 0) &&
     (param_2 != 0 || param_3 != 0)) {
    iVar1 = FUN_4340_1eea(*param_1,(undefined2 *)param_1,param_1._2_2_,param_2,param_3);
    uVar2 = (*(code *)*(undefined2 *)(iVar1 + 0x10))(0x4340);
    return uVar2;
  }
  return 0;
}

