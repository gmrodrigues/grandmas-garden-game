// TIM2.EXE: FUN_1000_6348 @ file 0x01B548 Ghidra 0x16348
// Subsystem: utility | Size: 156 bytes


uint __cdecl16near
FUN_1000_6348(undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
             byte param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_1000_614f((int)param_1,param_1._2_2_,(int)param_4,param_4._2_2_,0,param_2,param_3);
  if (iVar2 == 0) {
    uVar3 = *(uint *)((int)param_1 + 2);
    uVar1 = *(uint *)((int)param_4 + 2);
    if ((uVar1 & 0x20) != 0) {
      uVar3 = FUN_1000_614f((int)param_1,param_1._2_2_,*(undefined2 *)((int)param_4 + 6),
                            *(undefined2 *)((int)param_4 + 8),1,param_2,param_3);
      return uVar3;
    }
    if ((uVar1 & 0x10) != 0) {
      if ((param_5 & 1) != 0) goto LAB_1000_63ad;
      if (((uVar3 & 0x10) != 0) &&
         ((((uVar3 & 0x2000) == 0 || ((uVar1 & 0x2000) != 0)) && ((uVar1 & 0x40) != 0)))) {
        return (uint)((uVar3 & 0x300) == (uVar1 & 0x300));
      }
    }
    uVar3 = 0;
  }
  else {
LAB_1000_63ad:
    uVar3 = 1;
  }
  return uVar3;
}

