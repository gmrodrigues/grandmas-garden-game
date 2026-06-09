// TIM2.EXE: FUN_1000_05f4 @ file 0x0157F4 Ghidra 0x105F4
// Subsystem: utility | Size: 47 bytes


void __cdecl16far FUN_1000_05f4(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  long lVar3;
  byte abStack_1a [14];
  uint local_c;
  int local_a;
  long lStack_8;
  byte *local_4;
  
  if (param_1 == (byte *)0x0) {
    lStack_8 = 0;
  }
  else {
    local_c = 0;
    local_a = 0;
    local_4 = (byte *)0x1ae;
    for (pbVar1 = param_1; *pbVar1 != 0; pbVar1 = pbVar1 + 1) {
      if ((0x60 < *pbVar1) && (*pbVar1 < 0x7b)) {
        *pbVar1 = *pbVar1 ^ 0x20;
      }
      local_a = local_a + (uint)*pbVar1 * (uint)*local_4;
      local_4 = local_4 + 1;
      local_c = local_c ^ *pbVar1;
      if ((*pbVar1 == 0x5c) || (*pbVar1 == 0x3a)) {
        local_c = 0;
        local_a = 0;
        param_1 = pbVar1 + 1;
      }
    }
    FUN_1000_54f0(abStack_1a,param_1,0xd);
    lStack_8 = 0;
    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
      lVar3 = FUN_1000_199b();
      lStack_8 = lVar3 + (ulong)abStack_1a[*(byte *)(iVar2 + 0x1aa)];
    }
    lStack_8 = lStack_8 + (int)(local_a * local_c);
  }
  DAT_5b41_0463 = (undefined2)((ulong)lStack_8 >> 0x10);
  DAT_5b41_0461 = (undefined2)lStack_8;
  return;
}

