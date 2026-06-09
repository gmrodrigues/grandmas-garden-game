// TIM2.EXE: FUN_2424_19b4 @ file 0x02ADF4 Ghidra 0x25BF4
// Subsystem: misc | Size: 80 bytes


void __cdecl16far FUN_2424_19b4(uint param_1)

{
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  undefined2 local_4;
  
  local_8 = 0;
  local_a = 0;
  local_6 = DAT_554c_49aa;
  local_4 = DAT_554c_49ac;
  FUN_2424_0304();
  if ((param_1 & 1) != 0) {
    FUN_2424_1e00(&local_a);
  }
  if ((param_1 & 2) != 0) {
    FUN_2424_1e00(&local_a);
  }
  return;
}

