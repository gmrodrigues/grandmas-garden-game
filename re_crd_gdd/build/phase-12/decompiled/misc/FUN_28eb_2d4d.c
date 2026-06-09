// TIM2.EXE: FUN_28eb_2d4d @ file 0x030DFD Ghidra 0x2BBFD
// Subsystem: misc | Size: 53 bytes


void __cdecl16far FUN_28eb_2d4d(undefined4 param_1)

{
  undefined2 *puVar1;
  
  FUN_28eb_2a23((int)param_1,param_1._2_2_);
  if ((*(byte *)((int)param_1 + 0xb) & 0x40) == 0) {
    puVar1 = (undefined2 *)&DAT_5b41_0557;
  }
  else {
    puVar1 = (undefined2 *)&DAT_5b41_054f;
  }
  FUN_28eb_2a59((int)param_1,param_1._2_2_,puVar1,0);
  return;
}

