// TIM2.EXE: FUN_4551_00fd @ file 0x04A80D Ghidra 0x4560D
// Subsystem: misc | Size: 122 bytes


undefined2 __cdecl16far FUN_4551_00fd(undefined2 param_1)

{
  undefined2 uVar1;
  int in_DX;
  uint uVar2;
  int local_86 [64];
  int local_6;
  int local_4;
  
  local_6 = FUN_3f2b_07a3(param_1);
  if (local_6 == 0 && in_DX == 0) {
    uVar1 = 0;
  }
  else {
    local_4 = in_DX;
    FUN_4551_0b02(param_1,local_86);
    for (uVar2 = 0; uVar2 < 0x40; uVar2 = uVar2 + 1) {
      if (local_86[uVar2] != 0) {
        FUN_3e34_08ef(local_86[uVar2]);
      }
    }
    FUN_22de_0351(local_6,local_4);
    FUN_3f2b_08e1(param_1,0,0);
    uVar1 = 1;
  }
  return uVar1;
}

