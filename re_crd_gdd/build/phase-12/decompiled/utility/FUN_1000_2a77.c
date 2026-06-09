// TIM2.EXE: FUN_1000_2a77 @ file 0x017C77 Ghidra 0x12A77
// Subsystem: utility | Size: 38 bytes


undefined2 __cdecl16near FUN_1000_2a77(undefined1 *param_1)

{
  undefined2 uVar1;
  undefined1 auStack_206 [512];
  
  if (param_1 < auStack_206) {
    DAT_554c_0094 = param_1;
    uVar1 = 0;
  }
  else {
    uRam0005554e = 8;
    uVar1 = 0xffff;
  }
  return uVar1;
}

