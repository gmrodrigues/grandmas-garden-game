// TIM2.EXE: FUN_1a9e_7240 @ file 0x026E20 Ghidra 0x21C20
// Subsystem: misc | Size: 199 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_1a9e_7240(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_2e67_11db(param_1);
  if (iVar1 != 0) {
    if ((((undefined2 *)&DAT_5b41_25d8)[param_1 * 2] == DAT_5b41_25d8) &&
       (((undefined2 *)&DAT_5b41_25d6)[param_1 * 2] == DAT_5b41_25d6)) {
      DAT_5b41_25c2 = 0;
      DAT_554c_4330._0_1_ = 0;
      DAT_554c_431c._0_1_ = 0;
      DAT_5b41_26c6 = 0;
      DAT_554c_4308._0_1_ = 0;
      DAT_554c_42f4._0_1_ = 0;
      DAT_5b41_2678 = 0;
      DAT_5b41_2676 = 0;
      _DAT_5b41_2628 = 0;
      DAT_5b41_2626 = 0;
      DAT_5b41_25d8 = 0;
      DAT_5b41_25d6 = 0;
    }
    if (((undefined2 *)&DAT_5b41_2676)[param_1 * 2] == 0 &&
        ((undefined2 *)&DAT_5b41_2678)[param_1 * 2] == 0) {
      FUN_1000_130c(((undefined2 *)&DAT_5b41_25d6)[param_1 * 2]);
    }
    else {
      func_0x0002fdf5(0x1a9e,((undefined2 *)&DAT_5b41_2676)[param_1 * 2],
                      ((undefined2 *)&DAT_5b41_2678)[param_1 * 2]);
    }
    ((undefined1 *)&DAT_5b41_25c2)[param_1] = 0;
    ((undefined2 *)&DAT_5b41_25d8)[param_1 * 2] = 0;
    ((undefined2 *)&DAT_5b41_25d6)[param_1 * 2] = 0;
    ((undefined2 *)&DAT_5b41_2678)[param_1 * 2] = 0;
    ((undefined2 *)&DAT_5b41_2676)[param_1 * 2] = 0;
    *(undefined2 *)((undefined *)&DAT_5b41_2628 + param_1 * 4) = 0;
    ((undefined2 *)&DAT_5b41_2626)[param_1 * 2] = 0;
  }
  return;
}

