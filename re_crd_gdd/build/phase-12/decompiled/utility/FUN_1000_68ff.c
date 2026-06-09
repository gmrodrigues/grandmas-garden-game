// TIM2.EXE: FUN_1000_68ff @ file 0x01BAFF Ghidra 0x168FF
// Subsystem: utility | Size: 185 bytes


void __cdecl16near
FUN_1000_68ff(undefined2 param_1,undefined2 param_2,code *param_3,undefined2 param_4,uint param_5)

{
  undefined2 uVar1;
  undefined2 unaff_SS;
  uint local_6;
  
  uVar1 = *(undefined2 *)((int)*(undefined4 *)0x16 + 6);
  local_6 = param_5 & 1;
  if ((param_5 & 4) != 0) {
    local_6 = local_6 | 2;
  }
  if ((param_5 & 2) != 0) {
    local_6 = local_6 | 4;
  }
  if ((param_5 & 0x20) != 0) {
    local_6 = local_6 | 8;
  }
  switch(local_6) {
  case 0:
    (*param_3)(param_1);
    break;
  case 1:
    (*param_3)(0x1000,param_1);
    break;
  case 2:
    (*param_3)(param_1,param_2);
    break;
  case 3:
    (*param_3)(0x1000,param_1,param_2);
    break;
  case 4:
    (*param_3)(param_1);
    break;
  case 5:
    (*param_3)(0x1000,param_1);
    break;
  case 6:
  case 10:
    (*param_3)(param_1,param_2);
    break;
  case 7:
  case 0xb:
    (*param_3)(0x1000,param_1,param_2);
    break;
  case 8:
    (*param_3)();
    break;
  case 9:
    (*param_3)(0x1000,0x554c);
  }
  return;
}

