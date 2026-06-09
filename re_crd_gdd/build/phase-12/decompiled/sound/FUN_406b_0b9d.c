// TIM2.EXE: FUN_406b_0b9d @ file 0x04644D Ghidra 0x4124D
// Subsystem: sound | Size: 197 bytes


void __cdecl16far FUN_406b_0b9d(int *param_1,int *param_2)

{
  int iVar1;
  
  FUN_1a9e_5a16((undefined2 *)&DAT_5b41_1b66,(undefined2 *)&DAT_5b41_1b68);
  if (DAT_5b41_1b9a == 0) {
    if (DAT_53bd_0054 == 0) {
      if ((DAT_554c_3e4a == 0) || (DAT_5b41_1b68 < DAT_554c_49ac)) {
        DAT_5b41_1b96 = 0;
      }
      else {
        DAT_5b41_1b96 = 1;
      }
    }
  }
  else {
    DAT_5b41_1b96 = 0;
  }
  if (DAT_5b41_1b96 != 0) {
    iVar1 = DAT_5b41_1b68;
    if (DAT_554c_49ac <= DAT_5b41_1b68) {
      iVar1 = DAT_554c_49ac;
    }
    DAT_5b41_1b68 = DAT_5b41_1b68 - iVar1;
    if (DAT_554c_3e4a <= DAT_5b41_1b68) {
      DAT_5b41_1b68 = DAT_554c_3e4a + -1;
    }
  }
  if (param_1 != (int *)0x0) {
    if (DAT_5b41_1b66 < 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = DAT_5b41_1b66;
      if (DAT_554c_49aa <= DAT_5b41_1b66) {
        iVar1 = DAT_554c_49aa + -1;
      }
    }
    *param_1 = iVar1;
  }
  if (param_2 != (int *)0x0) {
    if (DAT_5b41_1b68 < 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = DAT_5b41_1b68;
      if (DAT_554c_49ac <= DAT_5b41_1b68) {
        iVar1 = DAT_554c_49ac + -1;
      }
    }
    *param_2 = iVar1;
  }
  return;
}

