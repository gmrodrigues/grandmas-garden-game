// TIM2.EXE: FUN_28eb_47f3 @ file 0x0328A3 Ghidra 0x2D6A3
// Subsystem: misc | Size: 56 bytes


uint __cdecl16far FUN_28eb_47f3(uint param_1,uint param_2)

{
  int iVar1;
  undefined2 local_6;
  
  local_6 = param_1 + param_2;
  iVar1 = ((int)param_1 >> 0xf) + ((int)param_2 >> 0xf) + (uint)CARRY2(param_1,param_2);
  if ((-1 < iVar1) && ((0 < iVar1 || (32000 < local_6)))) {
    local_6 = 32000;
  }
  return local_6;
}

