// TIM2.EXE: FUN_1000_4d6f @ file 0x019F6F Ghidra 0x14D6F
// Subsystem: utility | Size: 337 bytes


uint __cdecl16far FUN_1000_4d6f(byte param_1,int *param_2)

{
  byte *pbVar1;
  int iVar2;
  
  DAT_5b41_2a72 = param_1;
  if (*param_2 < -1) {
    *param_2 = *param_2 + 1;
    pbVar1 = (byte *)param_2[5];
    param_2[5] = param_2[5] + 1;
    *pbVar1 = param_1;
    if (((*(byte *)(param_2 + 1) & 8) == 0) || ((DAT_5b41_2a72 != 10 && (DAT_5b41_2a72 != 0xd))))
    goto LAB_1000_4eb7;
    iVar2 = FUN_1000_3e17(param_2);
  }
  else {
    if (((*(byte *)(param_2 + 1) & 0x90) != 0) || ((*(byte *)(param_2 + 1) & 2) == 0)) {
      param_2[1] = param_2[1] | 0x10;
      return 0xffff;
    }
    param_2[1] = param_2[1] | 0x100;
    if (param_2[3] == 0) {
      if ((*(byte *)((char)param_2[2] * 2 + 0x5917) & 8) != 0) {
        FUN_1000_1c50((int)(char)param_2[2],0,0,2);
      }
      if (((((DAT_5b41_2a72 == 10) && ((*(byte *)(param_2 + 1) & 0x40) == 0)) &&
           (iVar2 = FUN_1000_5924((int)(char)param_2[2],0x5e00,1), iVar2 != 1)) ||
          (iVar2 = FUN_1000_5924((int)(char)param_2[2],(undefined1 *)&DAT_5b41_2a72,1), iVar2 != 1))
         && ((*(byte *)((int)param_2 + 3) & 2) == 0)) {
        param_2[1] = param_2[1] | 0x10;
        return 0xffff;
      }
      goto LAB_1000_4eb7;
    }
    if ((*param_2 != 0) && (iVar2 = FUN_1000_3e17(param_2), iVar2 != 0)) {
      return 0xffff;
    }
    *param_2 = -param_2[3];
    pbVar1 = (byte *)param_2[5];
    param_2[5] = param_2[5] + 1;
    *pbVar1 = DAT_5b41_2a72;
    if (((*(byte *)(param_2 + 1) & 8) == 0) || ((DAT_5b41_2a72 != 10 && (DAT_5b41_2a72 != 0xd))))
    goto LAB_1000_4eb7;
    iVar2 = FUN_1000_3e17(param_2);
  }
  if (iVar2 != 0) {
    return 0xffff;
  }
LAB_1000_4eb7:
  return (uint)DAT_5b41_2a72;
}

