// TIM2.EXE: FUN_4bdc_2409 @ file 0x0533C9 Ghidra 0x4E1C9
// Subsystem: physics | Size: 213 bytes


int __cdecl16far FUN_4bdc_2409(undefined2 param_1,int *param_2,undefined2 param_3)

{
  undefined2 uVar1;
  int iVar2;
  int in_DX;
  int iVar3;
  
  iVar3 = 1;
  if (*param_2 != 0xff) {
    DAT_554c_56b8 = (char)(*param_2 / 100) + '0';
    DAT_554c_56b9 = (char)((*param_2 / 10) % 10) + '0';
    DAT_554c_56ba = (char)(*param_2 % 10) + '0';
    in_DX = CONCAT11((char)((uint)(*param_2 % 10) >> 8),DAT_554c_56ba);
    if (DAT_554c_5730 != 0 || DAT_554c_5732 != 0) {
      FUN_2e67_10e9(DAT_554c_5730,DAT_554c_5732,1);
    }
    DAT_554c_5730 = FUN_4bdc_27b2(param_1,0x56b4,param_3);
    DAT_554c_5732 = in_DX;
    if (DAT_554c_5730 == 0 && in_DX == 0) {
      iVar3 = 0;
    }
  }
  if (iVar3 != 0) {
    uVar1 = FUN_4bdc_2846(DAT_554c_5730,DAT_554c_5732);
    iVar2 = FUN_4bdc_22e6(uVar1,in_DX);
    if (iVar2 == -1) {
      iVar3 = 0;
    }
  }
  if (DAT_554c_5730 != 0 || DAT_554c_5732 != 0) {
    FUN_2e67_10e9(DAT_554c_5730,DAT_554c_5732,1);
    DAT_554c_5732 = 0;
    DAT_554c_5730 = 0;
  }
  return iVar3;
}

