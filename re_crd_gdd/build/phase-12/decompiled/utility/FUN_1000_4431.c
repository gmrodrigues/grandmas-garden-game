// TIM2.EXE: FUN_1000_4431 @ file 0x019631 Ghidra 0x14431
// Subsystem: utility | Size: 214 bytes


int __cdecl16far FUN_1000_4431(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_DX;
  int local_6;
  
  iVar1 = FUN_1000_1c50((int)(char)param_1[2],0,0,1);
  if ((in_DX == -1) && (iVar1 == -1)) {
    iVar1 = -1;
  }
  else if (*param_1 < 0) {
    local_6 = iVar1;
    if ((*(byte *)((char)param_1[2] * 2 + 0x5917) & 8) != 0) {
      iVar2 = in_DX;
      local_6 = FUN_1000_1c50((int)(char)param_1[2],0,0,2);
      if ((iVar2 == -1) && (local_6 == -1)) {
        return -1;
      }
      iVar1 = FUN_1000_1c50((int)(char)param_1[2],iVar1,in_DX,0);
      if ((iVar2 == -1) && (iVar1 == -1)) {
        return -1;
      }
    }
    iVar1 = FUN_1000_4354(param_1);
    iVar1 = local_6 + iVar1;
  }
  else {
    iVar2 = FUN_1000_4354(param_1);
    iVar1 = iVar1 - iVar2;
  }
  return iVar1;
}

