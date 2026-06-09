// TIM2.EXE: FUN_1a9e_2342 @ file 0x021F22 Ghidra 0x1CD22
// Subsystem: level | Size: 108 bytes


int __cdecl16far FUN_1a9e_2342(int param_1,int param_2)

{
  int iVar1;
  
  DAT_554c_4e94 = *(int *)(DAT_554c_42dd * 2 + 0x4e96);
  if ((DAT_554c_445e == 0 && DAT_554c_4460 == 0) && (DAT_554c_4e94 != 0)) {
    iVar1 = (DAT_554c_4e94 << 1) >> 0xf;
    DAT_554c_445e = FUN_1a9e_539c(DAT_554c_4e94 << 1,iVar1,0,0);
    DAT_554c_4460 = iVar1;
  }
  if (param_1 == 0 && param_2 == 0) {
    return DAT_554c_4ef6;
  }
  DAT_554c_4ef8 = param_2;
  DAT_554c_4ef6 = param_1;
  (*DAT_554c_4dc6)(0x1a9e,param_1,param_2);
  return param_1;
}

