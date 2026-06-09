// TIM2.EXE: FUN_1000_97e3 @ file 0x01E9E3 Ghidra 0x197E3
// Subsystem: utility | Size: 158 bytes


undefined2 __cdecl16near
FUN_1000_97e3(code *param_1,undefined2 param_2,undefined2 param_3,int param_4,uint param_5)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 local_8;
  int local_6;
  int local_4;
  
  iVar1 = FUN_1000_3b5a(param_5 | 2,param_2);
  if (iVar1 == 0) {
    uRam0005554e = 2;
  }
  else {
    local_4 = FUN_1000_14fb(param_3);
    if (local_4 == 0) {
      uRam0005554e = 8;
    }
    else {
      if (param_4 == 0) {
        param_4 = DAT_554c_5ea6;
      }
      local_6 = FUN_1000_15b8(&local_8,iVar1,param_4);
      if (local_6 != 0) {
        (*DAT_554c_57c8)(0x1000);
        uVar2 = (*param_1)(iVar1,local_4,local_6);
        FUN_1000_3157(local_8);
        FUN_1000_3157(local_4);
        return uVar2;
      }
      uRam0005554e = 8;
      FUN_1000_3157(local_4);
    }
  }
  return 0xffff;
}

