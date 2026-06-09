// TIM2.EXE: FUN_4340_0006 @ file 0x048606 Ghidra 0x43406
// Subsystem: misc | Size: 160 bytes


undefined2 __cdecl16far FUN_4340_0006(int param_1,int param_2)

{
  undefined2 uVar1;
  int in_DX;
  
  if ((DAT_53c6_0000 == 0) && (param_1 != 0)) {
    DAT_53c6_0002 = FUN_22de_01ec(param_1 * 0xe,0,9,1);
    DAT_53c6_0004 = in_DX;
    if (DAT_53c6_0002 != 0 || in_DX != 0) {
      DAT_53c6_0000 = param_1;
      goto LAB_4340_005e;
    }
LAB_4340_0091:
    uVar1 = 0;
  }
  else {
LAB_4340_005e:
    if ((DAT_53c6_0006 == 0) && (param_2 != 0)) {
      DAT_53c6_000a = FUN_1000_12bf(param_2,0x100);
      if (DAT_53c6_000a == 0) goto LAB_4340_0091;
      DAT_53c6_0006 = param_2;
    }
    uVar1 = 1;
  }
  return uVar1;
}

