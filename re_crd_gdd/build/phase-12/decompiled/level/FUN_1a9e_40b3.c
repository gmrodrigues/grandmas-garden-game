// TIM2.EXE: FUN_1a9e_40b3 @ file 0x023C93 Ghidra 0x1EA93
// Subsystem: level | Size: 183 bytes


undefined2 __cdecl16far FUN_1a9e_40b3(uint *param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  undefined4 uVar6;
  
  bVar5 = false;
  if (param_2 < 1) {
    param_1[3] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    return 0;
  }
  *param_1 = 0;
  param_1[2] = 0;
  uVar3 = param_1[1];
  uVar4 = *param_1;
  puVar1 = param_1 + 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 - uVar4;
  param_1[3] = (param_1[3] - uVar3) - (uint)(uVar2 < uVar4);
  uVar6 = FUN_1000_18f0(0x1a9e,param_1[2],param_1[3],param_2);
  param_1[3] = (uint)((ulong)uVar6 >> 0x10);
  param_1[2] = (uint)uVar6;
  if (((int)param_1[3] < 1) && ((int)param_1[3] < 0)) {
    uVar2 = param_1[2];
    param_1[3] = -(uint)(uVar2 != 0) - param_1[3];
    param_1[2] = -uVar2;
    bVar5 = true;
  }
  if ((param_1[2] & 0x8000) == 0 && param_1[3] == 0) {
    *param_1 = 0x8000;
  }
  else {
    *param_1 = param_1[2];
  }
  if (bVar5) {
    uVar2 = param_1[2];
    param_1[3] = -(uint)(uVar2 != 0) - param_1[3];
    param_1[2] = -uVar2;
  }
  return 1;
}

