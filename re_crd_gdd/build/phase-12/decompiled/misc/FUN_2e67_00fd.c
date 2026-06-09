// TIM2.EXE: FUN_2e67_00fd @ file 0x03396D Ghidra 0x2E76D
// Subsystem: misc | Size: 226 bytes


undefined2 __cdecl16far FUN_2e67_00fd(int param_1,int param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  undefined2 uVar2;
  bool bVar3;
  undefined2 local_6;
  
  local_6 = 0x2000;
  if ((param_1 == -2) && (param_2 == -2)) {
    uVar2 = 1;
  }
  else {
    DAT_5b41_0c98 = 0;
    DAT_5b41_0c9a = 0;
    DAT_554c_2fca = 0x14;
    DAT_554c_2fcc = 44000;
    DAT_554c_2fd0 = 0;
    if (DAT_5b41_0503 != 0) {
      DAT_554c_2fcc = 22000;
      local_6 = 0x1000;
    }
    DAT_554c_2fce = 0;
    iVar1 = FUN_4bdc_3c26(param_2,param_1,0,param_3);
    bVar3 = iVar1 == 0;
    if (!bVar3) {
      iVar1 = FUN_460e_1ef0(local_6);
      if ((iVar1 == 0) && (param_1 != -2)) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
    }
    uVar2 = DAT_5b41_0bec;
    if (!bVar3) {
      DAT_5b41_0bec = 1;
      if ((param_2 == 0) || (DAT_554c_5740 == 0 && DAT_554c_5742 == 0)) {
        DAT_5b41_0c40 = 0;
      }
      else {
        DAT_5b41_0c40 = 1;
      }
      DAT_5b41_0c42 = (uint)(DAT_554c_5744 != 0 || DAT_554c_5746 != 0);
      FUN_2e67_0231(param_4);
      uVar2 = DAT_5b41_0bec;
    }
  }
  return uVar2;
}

