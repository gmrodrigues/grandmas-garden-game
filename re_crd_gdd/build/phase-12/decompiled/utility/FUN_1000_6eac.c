// TIM2.EXE: FUN_1000_6eac @ file 0x01C0AC Ghidra 0x16EAC
// Subsystem: utility | Size: 71 bytes


void __cdecl16far FUN_1000_6eac(undefined2 param_1,undefined2 *param_2)

{
  undefined2 unaff_SS;
  undefined2 local_4e;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined2 local_48;
  undefined2 local_40;
  
  if (param_2 == (undefined2 *)0x0) {
    local_4c = 0;
    local_4e = 0x26;
    local_48 = 0;
    local_4a = 2;
    local_40 = 0;
    param_2 = &local_4e;
  }
  param_2[2] = param_2[2] | 2;
  FUN_1000_6e27(param_2,0,0,param_1);
  return;
}

