// TIM2.EXE: FUN_1a9e_5604 @ file 0x0251E4 Ghidra 0x1FFE4
// Subsystem: level | Size: 72 bytes


void __cdecl16far FUN_1a9e_5604(int param_1,undefined2 *param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  
  if (param_1 == 0) {
    if (DAT_554c_515c == '\0') {
      return;
    }
    func_0x0002fe0c();
    DAT_554c_516f = FUN_2fc8_01f3();
    uVar1 = FUN_2fc8_01f3();
  }
  else {
    if (DAT_554c_515d == '\0') {
      return;
    }
    func_0x0002fe0c();
    DAT_554c_516f = FUN_2fc8_01f3();
    uVar1 = FUN_2fc8_01f3();
  }
  *param_3 = uVar1;
  *param_2 = DAT_554c_516f;
  return;
}

