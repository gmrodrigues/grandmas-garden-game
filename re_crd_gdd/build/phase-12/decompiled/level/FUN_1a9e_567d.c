// TIM2.EXE: FUN_1a9e_567d @ file 0x02525D Ghidra 0x2005D
// Subsystem: level | Size: 84 bytes


byte __cdecl16far FUN_1a9e_567d(int param_1)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = DAT_554c_515c;
  if (param_1 != 0) {
    cVar1 = DAT_554c_515d;
  }
  bVar2 = 0;
  if (cVar1 != '\0') {
    FUN_2fc8_0364(0x1a9e,param_1,(undefined2 *)&DAT_554c_5173,(undefined2 *)&DAT_554c_5175);
    bVar2 = 0;
    if (DAT_554c_5173 < -0x1e) {
      bVar2 = 4;
    }
    else if (0x1d < DAT_554c_5173) {
      bVar2 = 8;
    }
    if (DAT_554c_5175 < -0x1e) {
      bVar2 = bVar2 | 1;
    }
    else if (0x1d < DAT_554c_5175) {
      bVar2 = bVar2 | 2;
    }
  }
  return bVar2;
}

