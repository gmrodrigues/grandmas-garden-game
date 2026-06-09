// TIM2.EXE: FUN_4340_0bf5 @ file 0x0491F5 Ghidra 0x43FF5
// Subsystem: misc | Size: 101 bytes


int __cdecl16far FUN_4340_0bf5(byte *param_1,byte *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  if ((byte *)param_1 == (byte *)0x0 && param_1._2_2_ == 0) {
    if ((byte *)param_2 == (byte *)0x0 && param_2._2_2_ == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = -1;
    }
  }
  else if ((byte *)param_2 == (byte *)0x0 && param_2._2_2_ == 0) {
    iVar1 = 1;
  }
  else {
    if (param_3 != 0) {
      do {
        uVar2 = (uint)*param_1;
        param_1 = (byte *)CONCAT22(param_1._2_2_,(byte *)param_1 + 1);
        uVar3 = (uint)*param_2;
        param_2 = (byte *)CONCAT22(param_2._2_2_,(byte *)param_2 + 1);
        param_3 = param_3 + -1;
        if ((param_3 == 0) || (uVar2 == 0)) break;
      } while (uVar2 == uVar3);
    }
    iVar1 = uVar2 - uVar3;
  }
  return iVar1;
}

