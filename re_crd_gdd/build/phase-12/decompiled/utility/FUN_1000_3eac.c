// TIM2.EXE: FUN_1000_3eac @ file 0x0190AC Ghidra 0x13EAC
// Subsystem: utility | Size: 116 bytes


undefined1 * __cdecl16far FUN_1000_3eac(undefined1 *param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  undefined1 *local_4;
  
  uVar4 = 0;
  local_4 = param_1;
  while ((uVar4 != 10 && (param_2 + -1 != 0 && 0 < param_2))) {
    piVar1 = param_3;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    if (SBORROW2(iVar2,1) == *piVar1 < 0) {
      pbVar3 = (byte *)param_3[5];
      param_3[5] = param_3[5] + 1;
      uVar4 = (uint)*pbVar3;
    }
    else {
      uVar4 = FUN_1000_4807(param_3);
    }
    if (uVar4 == 0xffff) break;
    *local_4 = (char)uVar4;
    local_4 = local_4 + 1;
    param_2 = param_2 + -1;
  }
  if ((uVar4 == 0xffff) && (local_4 == param_1)) {
    param_1 = (undefined1 *)0x0;
  }
  else {
    *local_4 = 0;
    if ((*(byte *)(param_3 + 1) & 0x10) != 0) {
      param_1 = (undefined1 *)0x0;
    }
  }
  return param_1;
}

