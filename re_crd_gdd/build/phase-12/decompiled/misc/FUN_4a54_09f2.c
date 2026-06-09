// TIM2.EXE: FUN_4a54_09f2 @ file 0x050132 Ghidra 0x4AF32
// Subsystem: misc | Size: 150 bytes


void __cdecl16far FUN_4a54_09f2(int param_1,int param_2,int param_3,undefined2 param_4)

{
  int iVar1;
  
  if ((DAT_554c_42c3 == '\0') ||
     ((((param_2 <= DAT_554c_42c6 && (DAT_554c_42c4 <= param_2 + *(int *)(param_1 + 6))) &&
       (param_3 <= DAT_554c_42ca)) && (DAT_554c_42c8 <= param_3 + *(int *)(param_1 + 8))))) {
    iVar1 = *(int *)(param_1 + 4);
    if (iVar1 == -3) {
      FUN_1a9e_211a(0x4a54,param_1,param_2,param_3);
      return;
    }
    if (iVar1 == -2) {
      FUN_1a9e_3960(0x4a54,param_1,param_2,param_3,param_4);
      return;
    }
    if (iVar1 == -1) {
      FUN_4a54_058b(param_1,param_2,param_3,param_4);
      return;
    }
    FUN_1a9e_2116(0x4a54,param_1,param_2,param_3,param_4);
  }
  return;
}

