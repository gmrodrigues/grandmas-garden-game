// TIM2.EXE: FUN_1000_8db5 @ file 0x01DFB5 Ghidra 0x18DB5
// Subsystem: utility | Size: 373 bytes


int __cdecl16far
FUN_1000_8db5(int param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined2 param_5,
             int param_6,int param_7,int param_8)

{
  int iVar1;
  undefined2 uVar2;
  long lVar3;
  int local_18;
  undefined4 local_16;
  int local_12;
  int local_10;
  undefined2 local_e;
  undefined2 local_c;
  int local_a;
  int local_8;
  undefined2 local_6;
  undefined2 local_4;
  
  local_4 = param_5;
  local_6 = param_4;
  local_8 = param_7;
  local_a = param_6;
  if ((param_1 != 0 || param_2 != 0) &&
     ((param_2 != 0x554c || (local_16 = CONCAT22(local_16._2_2_,(undefined2)local_16), param_1 != 0)
      ))) {
    uVar2 = (undefined2)((ulong)param_3 >> 0x10);
    iVar1 = (int)param_3;
    local_12 = param_1 - *(int *)(iVar1 + -4);
    local_10 = param_2;
    iVar1 = iVar1 - *(int *)(iVar1 + -2);
    local_c = *(undefined2 *)(iVar1 + -6);
    local_e = *(undefined2 *)(iVar1 + -8);
    if (param_6 == 0 && param_7 == 0) {
      return local_12;
    }
    iVar1 = FUN_1000_5f71(param_6,param_7,local_e,local_c);
    if (iVar1 != 0) {
      return local_12;
    }
    iVar1 = FUN_1000_5f71(local_6,local_4,local_e,local_c);
    if (iVar1 == 0) {
      lVar3 = FUN_1000_8b6f(local_12,local_10,local_e,local_c,0,0,local_a,local_8,param_1,param_2,
                            local_6,local_4,&local_18,1,0,0);
      local_16 = 0;
      if (lVar3 != 0) {
        return (int)lVar3;
      }
    }
    lVar3 = FUN_1000_8b6f(local_12,local_10,local_e,local_c,0,0,local_a,local_8,0,0,0,0,&local_18,1,
                          0,0);
    local_16 = lVar3;
    if ((lVar3 != 0) && (local_18 != 0)) {
      return (int)lVar3;
    }
  }
  if (param_8 != 0) {
    FUN_1000_6d2e(0x8f2a,0x1000,0x8aeb,0x554c,0,0,0,0,0,0,0,0);
  }
  return 0;
}

