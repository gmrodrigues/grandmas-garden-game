// TIM2.EXE: FUN_1000_43c4 @ file 0x0195C4 Ghidra 0x143C4
// Subsystem: utility | Size: 109 bytes


undefined2 __cdecl16far FUN_1000_43c4(int *param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  int in_DX;
  bool bVar4;
  
  iVar1 = FUN_1000_3e17(param_1);
  if (iVar1 == 0) {
    if ((param_4 == 1) && (0 < *param_1)) {
      uVar3 = FUN_1000_4354(param_1);
      in_DX = (int)uVar3 >> 0xf;
      bVar4 = param_2 < uVar3;
      param_2 = param_2 - uVar3;
      param_3 = (param_3 - in_DX) - (uint)bVar4;
    }
    param_1[1] = param_1[1] & 0xfe5f;
    *param_1 = 0;
    param_1[5] = param_1[4];
    iVar1 = FUN_1000_1c50((int)(char)param_1[2],param_2,param_3,param_4);
    if ((in_DX == -1) && (iVar1 == -1)) {
      uVar2 = 0xffff;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffff;
  }
  return uVar2;
}

