// TIM2.EXE: FUN_2e67_1277 @ file 0x034AE7 Ghidra 0x2F8E7
// Subsystem: misc | Size: 289 bytes


int __cdecl16far FUN_2e67_1277(uint param_1,int param_2,uint param_3,int param_4)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  
  if ((param_2 < 1) && (param_2 < 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bVar4 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar4 - param_2;
  }
  if ((param_4 < 1) && (param_4 < 0)) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if (bVar4) {
    bVar5 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar5 - param_4;
  }
  if (param_1 == 0 && param_2 == 0) {
    iVar3 = 0x400;
  }
  else if (param_3 == 0 && param_4 == 0) {
    iVar3 = 0;
  }
  else if ((param_2 == param_4) && (param_1 == param_3)) {
    iVar3 = 0x200;
  }
  else if ((param_4 < param_2) || ((param_4 <= param_2 && (param_3 <= param_1)))) {
    uVar2 = FUN_1000_199e(param_1,param_2);
    uVar2 = FUN_1000_18f0(0x1000,uVar2,param_4,param_1);
    iVar3 = FUN_2fc8_1520(uVar2);
  }
  else {
    uVar2 = FUN_1000_199e(param_3,param_4);
    uVar2 = FUN_1000_18f0(0x1000,uVar2,param_2,param_3);
    iVar3 = FUN_2fc8_1520(uVar2);
    iVar3 = 0x400 - iVar3;
  }
  if (bVar1) {
    iVar3 = 0x800 - iVar3;
  }
  if (bVar4) {
    iVar3 = 0x1000 - iVar3;
  }
  return (iVar3 + -0x400) * 0x10;
}

