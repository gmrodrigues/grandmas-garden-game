// TIM2.EXE: FUN_2e67_0edd @ file 0x03474D Ghidra 0x2F54D
// Subsystem: misc | Size: 524 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * __cdecl16far FUN_2e67_0edd(uint param_1,int param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  int in_DX;
  int *piVar3;
  undefined4 local_6;
  
  local_6 = (undefined2 *)0x0;
  if ((DAT_5b41_0cb8 == '\0') && (iVar1 = FUN_2e67_0cda(), iVar1 == 0)) {
    return (undefined2 *)0x0;
  }
  if (param_3 == 7) {
    param_3 = 4;
  }
  if (((param_3 == 6) || (param_3 == 8)) || (param_3 == 9)) {
    puVar2 = (undefined2 *)FUN_22de_01ec(param_1,param_2,4,0);
    return puVar2;
  }
  if ((DAT_5b41_0cb0 == (undefined2 *)0x0 && DAT_5b41_0cb2 == 0) || (param_3 != 2)) {
    if ((DAT_5b41_0ca8 == (undefined2 *)0x0 && DAT_5b41_0caa == 0) || (param_3 != 3)) {
      if (param_3 == 10) {
        DAT_5b41_0cb4 = (undefined2 *)FUN_22de_01ec(param_1,param_2,0xb,1);
        local_6 = (undefined2 *)CONCAT22(in_DX,DAT_5b41_0cb4);
        DAT_5b41_0cb6 = in_DX;
      }
      goto LAB_2e67_0fcd;
    }
    local_6 = (undefined2 *)CONCAT22(DAT_5b41_0caa,DAT_5b41_0ca8);
    in_DX = DAT_5b41_0ca8[1];
    DAT_5b41_0ca8 = (undefined2 *)*local_6;
    DAT_5b41_0caa = in_DX;
  }
  else {
    local_6 = (undefined2 *)CONCAT22(DAT_5b41_0cb2,DAT_5b41_0cb0);
    in_DX = DAT_5b41_0cb0[0xba];
    DAT_5b41_0cb0 = (undefined2 *)DAT_5b41_0cb0[0xb9];
    DAT_5b41_0cb2 = in_DX;
  }
  FUN_1a9e_5c44((undefined2 *)local_6,local_6._2_2_,0,param_1,param_2);
LAB_2e67_0fcd:
  if ((((DAT_5b41_0ca0 != (undefined2 *)0x0 || DAT_5b41_0ca2 != 0) && (param_3 == 4)) &&
      ((999 < DAT_5b41_0c98 && (in_DX = DAT_554c_2fce, param_2 <= DAT_554c_2fce)))) &&
     (((DAT_554c_2fce != param_2 || (param_1 <= DAT_554c_2fcc)) && (DAT_5b41_0cb9 == 0)))) {
    local_6 = (undefined2 *)CONCAT22(DAT_5b41_0ca2,DAT_5b41_0ca0);
    DAT_5b41_0cb9 = DAT_5b41_0c98;
    in_DX = DAT_5b41_0ca2;
    FUN_1a9e_5c44(DAT_5b41_0ca0,DAT_5b41_0ca2,0,param_1,param_2);
  }
  iVar1 = DAT_5b41_0c9e;
  puVar2 = DAT_5b41_0c9c;
  if (((DAT_5b41_0c9c != (undefined2 *)0x0 || DAT_5b41_0c9e != 0) && (param_3 == 4)) &&
     (DAT_5b41_0c98 < 1000)) {
    in_DX = (int)DAT_554c_2fd0 >> 0xf;
    if ((param_2 <= in_DX) &&
       ((piVar3 = _DAT_554c_2fd2, in_DX != param_2 || (param_1 <= DAT_554c_2fd0)))) {
      for (; (piVar3 != (int *)0x0 && ((*piVar3 != -1 && (*piVar3 != DAT_5b41_0c98))));
          piVar3 = piVar3 + 1) {
      }
      if ((piVar3 == (int *)0x0) || (*piVar3 == DAT_5b41_0c98)) {
        local_6 = (undefined2 *)CONCAT22(DAT_5b41_0c9e,DAT_5b41_0c9c);
        in_DX = DAT_5b41_0c9e;
        if (DAT_5b41_0cbb != 0) {
          FUN_4bdc_32e9(DAT_5b41_0cbb);
        }
        DAT_5b41_0cbb = DAT_5b41_0c98;
        FUN_1a9e_5c44(puVar2,iVar1,0,param_1,param_2);
      }
    }
  }
  if ((undefined2 *)local_6 == (undefined2 *)0x0 && local_6._2_2_ == 0) {
    puVar2 = (undefined2 *)FUN_22de_01ec(param_1,param_2,2,1);
    local_6 = (undefined2 *)CONCAT22(in_DX,puVar2);
    if ((puVar2 != (undefined2 *)0x0 || in_DX != 0) && (param_3 == 4)) {
      DAT_5b41_0c9a = 1;
    }
  }
  return (undefined2 *)local_6;
}

