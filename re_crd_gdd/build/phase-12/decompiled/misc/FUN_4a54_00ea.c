// TIM2.EXE: FUN_4a54_00ea @ file 0x04F82A Ghidra 0x4A62A
// Subsystem: misc | Size: 364 bytes


void __cdecl16near FUN_4a54_00ea(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  
  if ((param_3 != 0) && (param_4 != 0)) {
    local_e = 0;
    local_c = 0;
    iVar2 = param_3 >> 1;
    iVar3 = param_3 + 1 >> 1;
    iVar4 = param_4 >> 1;
    iVar5 = param_4 + 1 >> 1;
    local_10 = iVar2;
    if (DAT_5b41_2844 != 0) {
      local_10 = 0;
      local_c = iVar3;
    }
    local_12 = iVar4;
    if (DAT_5b41_2842 != 0) {
      local_12 = 0;
      local_e = iVar5;
    }
    bVar1 = (*DAT_554c_5670)(4);
    if ((bVar1 & 8) == 0) {
      FUN_4a54_0346(param_1 + local_c,param_2 + local_e,iVar2,iVar4);
    }
    else {
      FUN_4a54_00ea(param_1 + local_c,param_2 + local_e,iVar2,iVar4);
    }
    if ((bVar1 & 4) == 0) {
      FUN_4a54_0346(param_1 + local_10,param_2 + local_e,iVar3,iVar4);
    }
    else {
      FUN_4a54_00ea(param_1 + local_10,param_2 + local_e,iVar3,iVar4);
    }
    if ((bVar1 & 2) == 0) {
      FUN_4a54_0346(param_1 + local_c,param_2 + local_12,iVar2,iVar5);
    }
    else {
      FUN_4a54_00ea(param_1 + local_c,param_2 + local_12,iVar2,iVar5);
    }
    if ((bVar1 & 1) != 0) {
      FUN_4a54_00ea(param_1 + local_10,param_2 + local_12,iVar3,iVar5);
      return;
    }
    FUN_4a54_0346(param_1 + local_10,param_2 + local_12,iVar3,iVar5);
  }
  return;
}

