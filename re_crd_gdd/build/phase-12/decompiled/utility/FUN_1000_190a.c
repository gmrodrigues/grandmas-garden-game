// TIM2.EXE: FUN_1000_190a @ file 0x016B0A Ghidra 0x1190A
// Subsystem: utility | Size: 145 bytes


undefined4 __stdcall16far FUN_1000_190a(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint in_CX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  
  if ((param_4 == 0) && ((param_2 == 0 || (param_3 == 0)))) {
    uVar1 = (uint)(CONCAT22(param_2,param_1) / (ulong)param_3);
    if ((in_CX & 2) != 0) {
      uVar1 = (uint)(CONCAT22(param_2,param_1) % (ulong)param_3);
    }
    param_2 = 0;
  }
  else {
    if ((in_CX & 1) == 0) {
      if ((int)param_2 < 0) {
        bVar5 = param_1 != 0;
        param_1 = -param_1;
        param_2 = -(uint)bVar5 - param_2;
        in_CX = in_CX | 0xc;
      }
      if ((int)param_4 < 0) {
        bVar5 = param_3 != 0;
        param_3 = -param_3;
        param_4 = -(uint)bVar5 - param_4;
        in_CX = in_CX ^ 4;
      }
    }
    iVar2 = 0x20;
    uVar4 = 0;
    uVar3 = 0;
    do {
      bVar5 = (int)param_1 < 0;
      param_1 = param_1 * 2;
      bVar6 = (int)param_2 < 0;
      param_2 = param_2 << 1 | (uint)bVar5;
      bVar5 = (int)uVar3 < 0;
      uVar3 = uVar3 << 1 | (uint)bVar6;
      uVar4 = uVar4 << 1 | (uint)bVar5;
      if ((param_4 <= uVar4) && ((param_4 < uVar4 || (param_3 <= uVar3)))) {
        bVar5 = uVar3 < param_3;
        uVar3 = uVar3 - param_3;
        uVar4 = (uVar4 - param_4) - (uint)bVar5;
        param_1 = param_1 + 1;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    uVar1 = param_1;
    if ((in_CX & 2) != 0) {
      in_CX = in_CX >> 1;
      uVar1 = uVar3;
      param_2 = uVar4;
    }
    if ((in_CX & 4) != 0) {
      bVar5 = uVar1 != 0;
      uVar1 = -uVar1;
      param_2 = -(uint)bVar5 - param_2;
    }
  }
  return CONCAT22(param_2,uVar1);
}

