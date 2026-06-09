// TIM2.EXE: FUN_2424_087c @ file 0x029CBC Ghidra 0x24ABC
// Subsystem: misc | Size: 78 bytes


bool __cdecl16far FUN_2424_087c(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((DAT_5b41_04ae == (int *)0x0) && (param_1 != 0)) {
    piVar1 = (int *)FUN_1000_12bf(0xe,param_1);
    DAT_5b41_04ae = piVar1;
    DAT_5b41_04b2 = piVar1;
    for (iVar2 = 0; iVar2 < param_1 + -1; iVar2 = iVar2 + 1) {
      *piVar1 = (int)(piVar1 + 7);
      piVar1 = piVar1 + 7;
    }
  }
  return DAT_5b41_04ae != (int *)0x0;
}

