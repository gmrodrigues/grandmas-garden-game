// TIM2.EXE: FUN_4bdc_3951 @ file 0x054911 Ghidra 0x4F711
// Subsystem: physics | Size: 225 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * __cdecl16far FUN_4bdc_3951(int param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 1;
  if (param_1 == -3) {
    if (DAT_5b41_287e != (undefined2 *)0x0 || _DAT_5b41_2880 != 0) {
      _DAT_5b41_287e = (undefined2 *)CONCAT22(DAT_5b41_287e[1],(undefined2 *)*_DAT_5b41_287e);
    }
  }
  else {
    DAT_5b41_2882 = param_1;
    _DAT_5b41_287e = (undefined2 *)CONCAT22(DAT_554c_5736,DAT_554c_5734);
  }
  if (DAT_5b41_2882 == -2) {
LAB_4bdc_39a7:
    uVar2 = 1;
  }
  else if (DAT_5b41_2882 != -1) {
    if (DAT_5b41_2882 != 0) {
      if ((DAT_5b41_287e == (undefined2 *)0x0 && _DAT_5b41_2880 == 0) || (param_1 == -3)) {
        _DAT_5b41_287e = (undefined2 *)0x0;
      }
      else {
        while( true ) {
          if ((DAT_5b41_287e == (undefined2 *)0x0 && _DAT_5b41_2880 == 0) ||
             (DAT_5b41_287e[5] == param_1)) break;
          _DAT_5b41_287e = (undefined2 *)CONCAT22(DAT_5b41_287e[1],(undefined2 *)*_DAT_5b41_287e);
        }
      }
      goto LAB_4bdc_3a29;
    }
    uVar3 = 0;
    goto LAB_4bdc_39a7;
  }
  while( true ) {
    if (DAT_5b41_287e == (undefined2 *)0x0 && _DAT_5b41_2880 == 0) break;
    if ((DAT_5b41_287e[9] & uVar3) != uVar2) {
      puVar1 = DAT_5b41_287e;
      return puVar1;
    }
    _DAT_5b41_287e = (undefined2 *)CONCAT22(DAT_5b41_287e[1],(undefined2 *)*_DAT_5b41_287e);
  }
LAB_4bdc_3a29:
  puVar1 = DAT_5b41_287e;
  return puVar1;
}

