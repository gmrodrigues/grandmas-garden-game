// TIM2.EXE: FUN_1a9e_4d2d @ file 0x02490D Ghidra 0x1F70D
// Subsystem: level | Size: 216 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl16far FUN_1a9e_4d2d(int param_1)

{
  int iVar1;
  int iVar2;
  int *local_4;
  
  if (param_1 == 0) {
    if (DAT_5b41_25d6 == 0 && DAT_5b41_25d8 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
      for (local_4 = (int *)&DAT_5b41_25da;
          (iVar2 < 0x14 && ((local_4[1] != DAT_5b41_25d8 || (*local_4 != DAT_5b41_25d6))));
          local_4 = local_4 + 2) {
        iVar2 = iVar2 + 1;
      }
    }
  }
  else {
    iVar1 = FUN_1a9e_4e6b(param_1);
    iVar2 = 0;
    if (iVar1 != 0) {
      DAT_5b41_25c2 = ((undefined1 *)&DAT_5b41_25c2)[param_1];
      DAT_554c_42f4._0_1_ = *(undefined1 *)((int)(undefined2 *)&DAT_554c_42f4 + param_1);
      DAT_554c_4308._0_1_ = *(undefined1 *)((int)(undefined2 *)&DAT_554c_4308 + param_1);
      DAT_5b41_26c6 = ((undefined1 *)&DAT_5b41_26c6)[param_1];
      DAT_554c_431c._0_1_ = *(undefined1 *)((int)(undefined2 *)&DAT_554c_431c + param_1);
      DAT_554c_4330._0_1_ = *(undefined1 *)((int)(undefined2 *)&DAT_554c_4330 + param_1);
      DAT_5b41_25d8 = ((undefined2 *)&DAT_5b41_25d8)[param_1 * 2];
      DAT_5b41_25d6 = ((undefined2 *)&DAT_5b41_25d6)[param_1 * 2];
      DAT_5b41_2678 = ((undefined2 *)&DAT_5b41_2678)[param_1 * 2];
      DAT_5b41_2676 = ((undefined2 *)&DAT_5b41_2676)[param_1 * 2];
      _DAT_5b41_2628 = *(undefined2 *)((undefined *)&DAT_5b41_2628 + param_1 * 4);
      DAT_5b41_2626 = ((undefined2 *)&DAT_5b41_2626)[param_1 * 2];
      iVar2 = param_1;
    }
  }
  return iVar2;
}

