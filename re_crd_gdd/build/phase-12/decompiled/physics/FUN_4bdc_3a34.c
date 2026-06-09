// TIM2.EXE: FUN_4bdc_3a34 @ file 0x0549F4 Ghidra 0x4F7F4
// Subsystem: physics | Size: 495 bytes


undefined2 __cdecl16far FUN_4bdc_3a34(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined4 local_a;
  undefined4 local_6;
  
  local_6 = (undefined2 *)CONCAT22(DAT_554c_5736,DAT_554c_5734);
  puVar2 = DAT_554c_5734;
  while( true ) {
    if (((undefined2 *)local_6 == (undefined2 *)0x0 && local_6._2_2_ == 0) ||
       (((undefined2 *)local_6)[5] == param_1)) break;
    puVar2 = (undefined2 *)*local_6;
    local_6 = (undefined2 *)CONCAT22(((undefined2 *)local_6)[1],puVar2);
  }
  if ((undefined2 *)local_6 == (undefined2 *)0x0 && local_6._2_2_ == 0) {
    return 0;
  }
  if ((((((undefined2 *)local_6)[9] & 0x10) != 0) ||
      (((undefined2 *)local_6)[2] == 0 && ((undefined2 *)local_6)[3] == 0)) ||
     (((undefined2 *)local_6)[7] != 0 || ((undefined2 *)local_6)[8] != 0)) {
    return 1;
  }
  if ((((undefined2 *)local_6)[9] & 1) == 0) {
    iVar1 = FUN_4bdc_2636(((undefined2 *)local_6)[2],((undefined2 *)local_6)[3]);
    if (iVar1 != 0 || puVar2 != (undefined2 *)0x0) {
      return 1;
    }
    if ((DAT_554c_574c != 0) && (DAT_554c_574c != -2)) {
      FUN_4bdc_307a(((undefined2 *)local_6)[2],((undefined2 *)local_6)[3],0x7f,
                    (((undefined2 *)local_6)[9] & 2) != 0);
      return 1;
    }
    if ((((undefined2 *)local_6)[9] & 2) != 0) {
      ((undefined2 *)local_6)[9] = ((undefined2 *)local_6)[9] | 0x10;
      return 1;
    }
    return 1;
  }
  local_a = (undefined2 *)CONCAT22(DAT_554c_5736,DAT_554c_5734);
  puVar2 = DAT_554c_5734;
  while( true ) {
    if ((undefined2 *)local_a == (undefined2 *)0x0 && local_a._2_2_ == 0) break;
    if ((((((undefined2 *)local_a)[9] & 1) != 0) &&
        (((undefined2 *)local_a)[7] != 0 || ((undefined2 *)local_a)[8] != 0)) &&
       (((undefined2 *)local_a)[5] != param_1)) {
      FUN_4bdc_3427(((undefined2 *)local_a)[5]);
    }
    puVar2 = (undefined2 *)*local_a;
    local_a = (undefined2 *)CONCAT22(((undefined2 *)local_a)[1],puVar2);
  }
  if ((DAT_554c_574c != 0) && (DAT_554c_574c != -1)) {
    iVar1 = FUN_4bdc_2861(((undefined2 *)local_6)[2],((undefined2 *)local_6)[3]);
    ((undefined2 *)local_6)[8] = puVar2;
    ((undefined2 *)local_6)[7] = iVar1;
    if (iVar1 != 0 || puVar2 != (undefined2 *)0x0) {
      *(bool *)((int)*(undefined4 *)((undefined2 *)local_6 + 7) + 0x15d) =
           (((undefined2 *)local_6)[9] & 2) != 0;
      *(undefined1 *)((int)*(undefined4 *)((undefined2 *)local_6 + 7) + 0x15c) =
           *(undefined1 *)((undefined2 *)local_6 + 6);
      iVar1 = FUN_4bdc_2f5c(((undefined2 *)local_6)[7],((undefined2 *)local_6)[8],0,0x7f);
      if (iVar1 != 0 || puVar2 != (undefined2 *)0x0) {
        return 1;
      }
    }
    return 0;
  }
  ((undefined2 *)local_6)[9] = ((undefined2 *)local_6)[9] | 0x10;
  return 1;
}

