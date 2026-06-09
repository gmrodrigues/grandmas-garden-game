// TIM2.EXE: FUN_1a9e_3f10 @ file 0x023AF0 Ghidra 0x1E8F0
// Subsystem: level | Size: 31 bytes


bool __cdecl16far FUN_1a9e_3f10(char param_1)

{
  byte bVar1;
  bool bVar2;
  
  bVar2 = (param_1 - 1U & 0xf0) == 0;
  if (bVar2) {
    bVar1 = (param_1 - 1U & 0x1f) % 0x11;
    DAT_554c_4f2b = DAT_554c_4f2b & ((uint)(0x1fffe << bVar1) | (uint)(0x1fffe >> 0x11 - bVar1));
  }
  return bVar2;
}

