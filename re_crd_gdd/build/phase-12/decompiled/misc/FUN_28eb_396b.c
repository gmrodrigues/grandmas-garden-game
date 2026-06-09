// TIM2.EXE: FUN_28eb_396b @ file 0x031A1B Ghidra 0x2C81B
// Subsystem: misc | Size: 50 bytes


undefined2 __cdecl16far FUN_28eb_396b(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else if ((*(int *)(param_3 + 6) == param_2) && (*(int *)(param_3 + 4) == param_1)) {
    uVar1 = *(undefined2 *)(param_3 + 8);
  }
  else {
    uVar1 = *(undefined2 *)(param_3 + 4);
  }
  return uVar1;
}

