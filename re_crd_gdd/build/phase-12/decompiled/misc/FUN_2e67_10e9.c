// TIM2.EXE: FUN_2e67_10e9 @ file 0x034959 Ghidra 0x2F759
// Subsystem: misc | Size: 242 bytes


void __cdecl16far FUN_2e67_10e9(undefined2 *param_1,int param_2)

{
  if (((param_2 != 6) && (param_2 != 8)) && (param_2 != 9)) {
    if (((param_2 == 2) && (DAT_5b41_0cac != (undefined2 *)0x0 || DAT_5b41_0cae != 0)) &&
       ((DAT_5b41_0cac <= (undefined2 *)param_1 && ((undefined2 *)param_1 < DAT_5b41_0cac + 0x5e8)))
       ) {
      ((undefined2 *)param_1)[0xba] = DAT_5b41_0cb2;
      ((undefined2 *)param_1)[0xb9] = DAT_5b41_0cb0;
      DAT_5b41_0cb0 = (undefined2 *)param_1;
      DAT_5b41_0cb2 = param_1._2_2_;
      return;
    }
    if (((param_2 == 3) && (DAT_5b41_0ca4 != (undefined2 *)0x0 || DAT_5b41_0ca6 != 0)) &&
       ((DAT_5b41_0ca4 <= (undefined2 *)param_1 &&
        ((undefined2 *)param_1 < DAT_5b41_0ca4 + DAT_554c_2fca * 10)))) {
      ((undefined2 *)param_1)[1] = DAT_5b41_0caa;
      *param_1 = DAT_5b41_0ca8;
      DAT_5b41_0ca8 = (undefined2 *)param_1;
      DAT_5b41_0caa = param_1._2_2_;
      return;
    }
    if ((param_1._2_2_ == DAT_5b41_0ca2) && ((undefined2 *)param_1 == DAT_5b41_0ca0)) {
      DAT_5b41_0cb9 = 0;
      return;
    }
    if ((param_1._2_2_ == DAT_5b41_0c9e) && ((undefined2 *)param_1 == DAT_5b41_0c9c)) {
      DAT_5b41_0cbb = 0;
      return;
    }
  }
  FUN_22de_0351((undefined2 *)param_1,param_1._2_2_);
  return;
}

