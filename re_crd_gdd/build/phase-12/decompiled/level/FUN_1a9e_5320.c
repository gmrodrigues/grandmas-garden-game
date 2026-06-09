// TIM2.EXE: FUN_1a9e_5320 @ file 0x024F00 Ghidra 0x1FD00
// Subsystem: level | Size: 116 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far FUN_1a9e_5320(int param_1,uint *param_2,uint *param_3)

{
  byte bVar1;
  uint local_4;
  
  param_1 = param_1 - (uint)(byte)DAT_554c_431c;
  if ((-1 < param_1) && (param_1 < (int)(uint)(byte)DAT_554c_4330)) {
    bVar1 = (byte)DAT_554c_42f4;
    if (DAT_5b41_2676 != 0 || DAT_5b41_2678 != 0) {
      bVar1 = *(byte *)((int)_DAT_5b41_2626 + param_1);
    }
    local_4 = (uint)(byte)DAT_554c_4308;
    if (param_2 != (uint *)0x0) {
      *param_2 = (uint)bVar1;
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = local_4;
    }
    return 1;
  }
  return 0;
}

