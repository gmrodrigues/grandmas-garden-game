// TIM2.EXE: FUN_3e34_0ec9 @ file 0x044409 Ghidra 0x3F209
// Subsystem: sound | Size: 152 bytes


void __cdecl16far
FUN_3e34_0ec9(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5,undefined2 param_6,undefined2 param_7)

{
  uint uVar1;
  uint uVar2;
  uint local_c [5];
  
  FUN_1000_1842(0x3e34,param_1,param_2,local_c);
  uVar1 = DAT_554c_3d5a;
  uVar2 = local_c[0] & 0xff;
  if (local_c[0] - uVar2 == DAT_554c_3d5a) {
    FUN_3f2b_0e3a(*(undefined2 *)(uVar2 * 2));
    local_c[0] = uVar1;
    FUN_4a54_0a88(local_c,param_3,param_4,param_5,param_6,param_7);
    local_c[0] = local_c[0] + uVar2;
    FUN_3f2b_118f();
  }
  else {
    FUN_4a54_0a88(local_c,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}

