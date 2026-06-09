// TIM2.EXE: FUN_1a9e_1c03 @ file 0x0217E3 Ghidra 0x1C5E3
// Subsystem: level | Size: 102 bytes


void __cdecl16near FUN_1a9e_1c03(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 local_4;
  
  uVar1 = 0;
  uVar3 = (undefined2)((ulong)DAT_5b41_1d46 >> 0x10);
  uVar2 = *(uint *)((int)DAT_5b41_1d46 + (param_1 + 0x273) * 2);
  local_4 = 0;
  do {
    uVar1 = uVar1 >> 1;
    if ((uVar2 & 1) != 0) {
      uVar1 = uVar1 + 0x8000;
    }
    local_4 = local_4 + 1;
    uVar2 = *(uint *)((int)DAT_5b41_1d46 + uVar2 * 2);
  } while (uVar2 != 0x272);
  FUN_1a9e_1806(local_4,uVar1);
  DAT_5b41_1d3e = local_4;
  DAT_5b41_1d40 = uVar1;
  FUN_1a9e_1ae7(param_1);
  return;
}

