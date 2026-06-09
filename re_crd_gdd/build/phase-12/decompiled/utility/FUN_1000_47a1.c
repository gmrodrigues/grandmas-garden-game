// TIM2.EXE: FUN_1000_47a1 @ file 0x0199A1 Ghidra 0x147A1
// Subsystem: utility | Size: 102 bytes


undefined2 FUN_1000_47a1(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  if ((*(byte *)((int)param_1 + 3) & 2) != 0) {
    FUN_1000_4764();
  }
  iVar2 = param_1[3];
  iVar1 = param_1[4];
  param_1[5] = iVar1;
  iVar2 = FUN_1000_509b((int)(char)param_1[2],iVar1,iVar2);
  *param_1 = iVar2;
  if (iVar2 < 1) {
    if (*param_1 == 0) {
      param_1[1] = param_1[1] & 0xfe7fU | 0x20;
    }
    else {
      *param_1 = 0;
      param_1[1] = param_1[1] | 0x10;
    }
    uVar3 = 0xffff;
  }
  else {
    param_1[1] = param_1[1] & 0xffdf;
    uVar3 = 0;
  }
  return uVar3;
}

