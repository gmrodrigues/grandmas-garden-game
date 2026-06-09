// TIM2.EXE: FUN_22de_0190 @ file 0x028170 Ghidra 0x22F70
// Subsystem: misc | Size: 92 bytes


uint __cdecl16far FUN_22de_0190(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int local_8;
  int local_6;
  int local_4;
  
  local_8 = 0;
  uVar2 = 0;
  iVar3 = 0;
  while( true ) {
    iVar1 = FUN_1000_9ada(&local_8);
    if (iVar1 != 2) break;
    iVar3 = local_8 + local_6;
    if ((local_4 == 0) && (uVar2 < local_6 - 4U)) {
      uVar2 = local_6 - 4;
    }
  }
  if (uVar2 < (uint)(-iVar3 - DAT_554c_02ea)) {
    uVar2 = -iVar3 - DAT_554c_02ea;
  }
  return uVar2;
}

