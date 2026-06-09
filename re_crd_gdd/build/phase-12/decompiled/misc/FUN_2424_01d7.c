// TIM2.EXE: FUN_2424_01d7 @ file 0x029617 Ghidra 0x24417
// Subsystem: misc | Size: 182 bytes


void __cdecl16far FUN_2424_01d7(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_5b41_053d;
  iVar3 = DAT_5b41_053b;
  iVar2 = DAT_5b41_0539;
  iVar1 = DAT_5b41_0537;
  if ((int *)param_1 == (int *)0x0 && param_1._2_2_ == 0) {
    DAT_5b41_053f = DAT_5b41_0537;
    DAT_5b41_0541 = DAT_5b41_0539;
    DAT_5b41_0543 = DAT_5b41_053b;
  }
  else {
    DAT_5b41_053f = *param_1;
    DAT_5b41_0541 = (((int *)param_1)[2] - *param_1) + -1;
    DAT_5b41_0543 = ((int *)param_1)[1];
    DAT_5b41_053d = (((int *)param_1)[3] - ((int *)param_1)[1]) + -1;
  }
  DAT_5b41_0537 = DAT_5b41_053f;
  DAT_5b41_0539 = DAT_5b41_0541;
  DAT_5b41_053b = DAT_5b41_0543;
  DAT_5b41_0545 = DAT_5b41_053d;
  FUN_2424_02e7();
  FUN_2424_0395(0x2424);
  DAT_5b41_0543 = 0;
  DAT_5b41_053f = 0;
  DAT_5b41_0541 = DAT_554c_49aa + -1;
  DAT_5b41_0545 = DAT_554c_49ac + -1;
  DAT_5b41_0537 = iVar1;
  DAT_5b41_0539 = iVar2;
  DAT_5b41_053b = iVar3;
  DAT_5b41_053d = iVar4;
  return;
}

