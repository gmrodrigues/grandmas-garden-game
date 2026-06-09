// TIM2.EXE: FUN_3f2b_0fa3 @ file 0x045453 Ghidra 0x40253
// Subsystem: sound | Size: 86 bytes


undefined1 * __cdecl16far
FUN_3f2b_0fa3(undefined1 *param_1,undefined1 *param_2,undefined2 param_3,uint param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if ((DAT_554c_3d56 != '\0') && (DAT_554c_3d57 != '\0')) {
    if (param_1 == param_2) {
      if ((param_1 != (undefined1 *)0x0) && (param_1 == (undefined1 *)0xffff)) {
        return (undefined1 *)0xffff;
      }
    }
    else if ((param_2 == (undefined1 *)0x0) &&
            (puVar1 = (undefined1 *)FUN_3f2b_12db(param_1), puVar1 != param_2)) {
      puVar2 = puVar1;
      if ((param_4 & 1) == 0) {
        return puVar1;
      }
      for (; param_1 != (undefined1 *)0x0; param_1 = param_1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
      return puVar1;
    }
  }
  return (undefined1 *)0x0;
}

