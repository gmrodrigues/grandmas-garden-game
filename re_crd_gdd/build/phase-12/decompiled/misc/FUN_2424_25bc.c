// TIM2.EXE: FUN_2424_25bc @ file 0x02B9FC Ghidra 0x267FC
// Subsystem: misc | Size: 434 bytes


void __cdecl16far FUN_2424_25bc(undefined1 param_1,byte param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_22;
  int local_20;
  int local_6;
  int local_4;
  
  DAT_554c_42ce = param_1;
  FUN_1000_199e();
  FUN_1000_199e();
  FUN_1000_199e();
  FUN_1000_199e();
  uVar1 = 1 << (param_2 & 0x1f);
  iVar4 = (int)uVar1 >> 0xf;
  local_4 = FUN_1000_19bf();
  local_6 = FUN_1000_19bf();
  local_20 = 0;
  for (local_22 = 0; (local_20 < iVar4 || ((local_20 <= iVar4 && (local_22 <= uVar1))));
      local_22 = local_22 + 1) {
    iVar2 = FUN_1000_19bf();
    iVar3 = FUN_1000_19bf();
    if ((local_4 != iVar2) || (local_6 != iVar3)) {
      FUN_2424_27e0(local_4,local_6,iVar2,iVar3);
      local_6 = iVar3;
      local_4 = iVar2;
    }
    FUN_1000_180a();
    FUN_1000_180a();
    local_20 = local_20 + (uint)(0xfffe < local_22);
  }
  return;
}

