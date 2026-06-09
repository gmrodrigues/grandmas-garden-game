// TIM2.EXE: FUN_4a54_0c1d @ file 0x05035D Ghidra 0x4B15D
// Subsystem: misc | Size: 287 bytes


void __cdecl16near
FUN_4a54_0c1d(int param_1,undefined2 param_2,uint param_3,int param_4,undefined2 param_5)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  bool bVar4;
  uint uVar5;
  undefined1 local_10c [256];
  int local_c;
  int local_a;
  undefined1 *local_8;
  int local_6;
  undefined2 local_4;
  
  uVar3 = 0x4a54;
  uVar2 = 0x4000;
  while (uVar2 != 0) {
    uVar3 = 0x1000;
    local_8 = (undefined1 *)FUN_1000_127a(uVar2);
    if (local_8 != (undefined1 *)0x0) break;
    if ((int)uVar2 < 0x801) {
      uVar2 = uVar2 - 0x100;
    }
    else {
      uVar2 = (int)uVar2 >> 1;
    }
  }
  if (uVar2 == 0) {
    local_8 = local_10c;
    uVar2 = 0x100;
  }
  if (param_4 == 0) {
    local_a = 0;
  }
  else {
    local_a = FUN_1000_18f0(uVar3,0,1,uVar2);
  }
  local_c = local_a;
  local_4 = param_2;
  local_6 = param_1;
  while (param_3 != 0 || param_4 != 0) {
    uVar1 = uVar2;
    if ((param_4 <= (int)uVar2 >> 0xf) && ((param_4 < (int)uVar2 >> 0xf || (param_3 < uVar2)))) {
      uVar1 = param_3;
    }
    uVar1 = FUN_1000_0d10(local_8,1,uVar1,param_5);
    if (uVar1 == 0) break;
    uVar5 = uVar1;
    FUN_4a54_148b(local_6,local_4,local_8,0x554c,uVar1);
    local_6 = local_6 + uVar1;
    bVar4 = param_3 < uVar1;
    param_3 = param_3 - uVar1;
    param_4 = (param_4 - ((int)uVar1 >> 0xf)) - (uint)bVar4;
    if ((local_a != 0) && (local_c = local_c + -1, local_c == 0)) {
      FUN_1000_1a00(uVar5,0x1000);
      local_c = local_a;
      local_4 = param_2;
      local_6 = param_1;
    }
  }
  if ((local_8 != (undefined1 *)0x0) && (local_10c != local_8)) {
    FUN_1000_130c(local_8);
  }
  return;
}

