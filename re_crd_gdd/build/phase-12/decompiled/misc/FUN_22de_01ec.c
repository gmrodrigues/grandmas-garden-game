// TIM2.EXE: FUN_22de_01ec @ file 0x0281CC Ghidra 0x22FCC
// Subsystem: misc | Size: 357 bytes


int __cdecl16far FUN_22de_01ec(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint in_DX;
  bool bVar2;
  int local_6;
  uint local_4;
  
  bVar2 = (param_3 & 2) != 0;
  DAT_5b41_02f0 = &param_1;
  local_4 = 0;
  local_6 = 0;
  do {
    if (local_6 != 0 || local_4 != 0) {
      return local_6;
    }
    if ((DAT_1a9e_4bb4 != -0x34) && ((param_3 & 1) != 0)) {
      FUN_3f2b_1159(4);
      if ((param_2 == -1) && (param_1 == -1)) {
        iVar1 = FUN_3f2b_0e3a(0);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = FUN_1000_199e();
        return iVar1;
      }
      local_6 = FUN_3f2b_0fa3(param_1,param_2,param_3,param_4);
      local_4 = in_DX;
    }
    if ((local_6 == 0 && local_4 == 0) && ((param_3 & 8) != 0)) {
      local_6 = FUN_3f2b_0d4d(param_1,param_2,param_3,param_4);
      local_4 = in_DX;
    }
    if ((local_6 == 0 && local_4 == 0) && ((param_3 & 4) != 0)) {
      in_DX = param_4 & 1;
      if (in_DX == 0) {
        local_6 = FUN_1000_127a(param_1);
      }
      else {
        local_6 = FUN_1000_12bf(param_1,1);
      }
      local_4 = 0x554c;
    }
    if (local_6 == 0 && local_4 == 0) {
      in_DX = param_4 & 1;
      local_6 = FUN_1a9e_539c(param_1,param_2,0,in_DX);
      local_4 = in_DX;
    }
    if (((local_6 == 0 && local_4 == 0) && (bVar2)) && (iVar1 = FUN_3f2b_0aa7(), iVar1 == 0)) {
      bVar2 = false;
    }
  } while ((local_6 != 0 || local_4 != 0) || (bVar2));
  return 0;
}

