// TIM2.EXE: FUN_4a54_058b @ file 0x04FCCB Ghidra 0x4AACB
// Subsystem: misc | Size: 217 bytes


void __cdecl16far FUN_4a54_058b(int *param_1,int param_2,int param_3,undefined2 param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  
  uVar3 = DAT_554c_42ce;
  uVar2 = DAT_554c_42cd;
  uVar1 = DAT_554c_42c3;
  iVar4 = *param_1 + ((uint)param_1[1] >> 4);
  DAT_5b41_2858 = FUN_4a54_0005(iVar4 >> 0xf,iVar4);
  if (DAT_5b41_2858 != 0) {
    if ((((param_2 < DAT_554c_42c4) || (param_3 < DAT_554c_42c8)) ||
        (DAT_554c_42c6 < param_2 + param_1[3])) || (DAT_554c_42ca < param_3 + param_1[4])) {
      DAT_554c_566e = 0x1a9e;
      DAT_554c_566c = (char *)s_Cross_device_link_554c_5d81 + 0x11;
      DAT_554c_42c3 = 1;
    }
    else {
      DAT_554c_566e = DAT_554c_4dd0;
      DAT_554c_566c = DAT_554c_4dce;
    }
    DAT_5b41_285e = 0;
    DAT_5b41_2856 = param_4;
    FUN_4a54_005b(param_2,param_3,param_1[3],param_1[4]);
    FUN_4a54_0037();
  }
  DAT_554c_42c3 = uVar1;
  DAT_554c_42ce = uVar3;
  DAT_554c_42cd = uVar2;
  return;
}

