// TIM2.EXE decompiled function: FUN_4bdc_32e9
// Source: file offset 0x0543BB → Ghidra 0x4F1BB
// Body: 0x4F0A9 - 0x4F1E6
// Size: 313 bytes


undefined2 __cdecl16far FUN_4bdc_32e9(int param_1)

{
  undefined2 uVar1;
  undefined2 unaff_SS;
  undefined2 local_1e [10];
  undefined4 local_a;
  undefined2 *local_6;
  
  uVar1 = 0;
  _local_6 = (undefined2 *)CONCAT22(unaff_SS,local_1e);
  local_a = (undefined2 *)CONCAT22(DAT_554c_5736,DAT_554c_5734);
  if ((param_1 == 0) || (param_1 == -2)) {
    FUN_4bdc_3165();
  }
  do {
    if ((undefined2 *)local_a == (undefined2 *)0x0 && local_a._2_2_ == 0) {
      return uVar1;
    }
    if ((((param_1 == 0) || (((undefined2 *)local_a)[5] == param_1)) ||
        ((param_1 == -1 && ((((undefined2 *)local_a)[9] & 1) != 0)))) ||
       ((param_1 == -2 && ((((undefined2 *)local_a)[9] & 1) == 0)))) {
      FUN_4bdc_3427(((undefined2 *)local_a)[5]);
      if ((local_a._2_2_ == DAT_554c_5736) && ((undefined2 *)local_a == DAT_554c_5734)) {
        DAT_554c_5736 = ((undefined2 *)local_a)[1];
        DAT_554c_5734 = (undefined2 *)*local_a;
      }
      uVar1 = *local_a;
      ((undefined2 *)_local_6)[1] = ((undefined2 *)local_a)[1];
      *_local_6 = uVar1;
      if ((((undefined2 *)local_a)[9] & 1) == 0) {
        FUN_2e67_10e9(((undefined2 *)local_a)[2],((undefined2 *)local_a)[3],7);
      }
      else {
        FUN_2e67_10e9(((undefined2 *)local_a)[2],((undefined2 *)local_a)[3],4);
      }
      FUN_2e67_10e9((undefined2 *)local_a,local_a._2_2_,3);
      uVar1 = 1;
      if (0 < param_1) {
        return 1;
      }
    }
    else {
      _local_6 = local_a;
    }
    local_a = (undefined2 *)CONCAT22(((undefined2 *)_local_6)[1],(undefined2 *)*_local_6);
  } while( true );
}


