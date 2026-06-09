// TIM2.EXE: FUN_1000_3fcc @ file 0x0191CC Ghidra 0x13FCC
// Subsystem: utility | Size: 205 bytes


uint FUN_1000_3fcc(undefined2 *param_1,uint *param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  uint local_6;
  undefined2 local_4;
  
  local_4 = 0;
  cVar1 = *param_3;
  if (cVar1 == 'r') {
    uVar2 = 1;
    local_6 = 1;
  }
  else {
    if (cVar1 == 'w') {
      uVar2 = 0x302;
    }
    else {
      if (cVar1 != 'a') {
        return 0;
      }
      uVar2 = 0x902;
    }
    local_4 = 0x80;
    local_6 = 2;
  }
  cVar1 = param_3[1];
  if ((cVar1 == '+') || ((param_3[2] == '+' && ((cVar1 == 't' || (cVar1 == 'b')))))) {
    if (cVar1 == '+') {
      cVar1 = param_3[2];
    }
    uVar2 = uVar2 & 0xfffc | 4;
    local_4 = 0x180;
    local_6 = 3;
  }
  if (cVar1 == 't') {
    uVar2 = uVar2 | 0x4000;
  }
  else {
    if (cVar1 == 'b') {
      uVar2 = uVar2 | 0x8000;
    }
    else {
      uVar2 = uVar2 | DAT_554c_593e & 0xc000;
      if ((DAT_554c_593e & 0x8000) == 0) goto LAB_1000_4075;
    }
    local_6 = local_6 | 0x40;
  }
LAB_1000_4075:
  DAT_554c_57ce = 0x1000;
  DAT_554c_57cc = 0x5b32;
  *param_2 = uVar2;
  *param_1 = local_4;
  return local_6;
}

