// TIM2.EXE: FUN_1000_2a9d @ file 0x017C9D Ghidra 0x12A9D
// Subsystem: utility | Size: 53 bytes


uint __cdecl16near FUN_1000_2a9d(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + DAT_554c_0094;
  if (((param_2 + (uint)CARRY2(param_1,DAT_554c_0094) == 0) && (uVar1 < 0xfe00)) &&
     ((undefined1 *)(uVar1 + 0x200) < &stack0xfffa)) {
    LOCK();
    UNLOCK();
    uVar2 = DAT_554c_0094;
    DAT_554c_0094 = uVar1;
  }
  else {
    uRam0005554e = 8;
    uVar2 = 0xffff;
  }
  return uVar2;
}

