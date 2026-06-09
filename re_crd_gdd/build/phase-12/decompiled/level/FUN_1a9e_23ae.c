// TIM2.EXE: FUN_1a9e_23ae @ file 0x021F8E Ghidra 0x1CD8E
// Subsystem: level | Size: 78 bytes


void __cdecl16far FUN_1a9e_23ae(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != 0 || param_2 != 0) {
    for (iVar1 = 1; iVar1 < 10; iVar1 = iVar1 + 1) {
      if ((((undefined2 *)&DAT_554c_4460)[iVar1 * 2] == param_2) &&
         (((undefined2 *)&DAT_554c_445e)[iVar1 * 2] == param_1)) {
        FUN_1a9e_5415(((undefined2 *)&DAT_554c_445e)[iVar1 * 2],
                      ((undefined2 *)&DAT_554c_4460)[iVar1 * 2]);
        ((undefined2 *)&DAT_554c_4460)[iVar1 * 2] = 0;
        ((undefined2 *)&DAT_554c_445e)[iVar1 * 2] = 0;
      }
    }
  }
  return;
}

