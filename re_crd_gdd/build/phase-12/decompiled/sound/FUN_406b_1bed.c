// TIM2.EXE: FUN_406b_1bed @ file 0x04749D Ghidra 0x4229D
// Subsystem: sound | Size: 158 bytes


undefined2 __cdecl16far FUN_406b_1bed(undefined2 param_1)

{
  uint uVar1;
  undefined2 unaff_SS;
  char local_302 [768];
  
  FUN_406b_1765(local_302);
  FUN_406b_1e45(param_1,0x6f,0x53bd,4);
  FUN_406b_1da9(param_1,DAT_53bd_0079 * 3,0);
  for (uVar1 = 0; uVar1 < (uint)(DAT_53bd_0079 * 3); uVar1 = uVar1 + 1) {
    local_302[uVar1] = local_302[uVar1] << 2;
  }
  FUN_406b_1e45(param_1,local_302);
  return 1;
}

