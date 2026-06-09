// TIM2.EXE: FUN_2424_050d @ file 0x02994D Ghidra 0x2474D
// Subsystem: misc | Size: 166 bytes


void __cdecl16far FUN_2424_050d(int param_1)

{
  undefined2 uVar1;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  undefined2 local_4;
  
  FUN_28eb_1234();
  FUN_2424_0304();
  if (param_1 == 0) {
    local_8 = 0;
    local_a = 0;
    local_6 = DAT_554c_49aa;
    local_4 = DAT_554c_49ac;
    FUN_2424_1e00(&local_a);
  }
  uVar1 = 0x54ac;
  FUN_54ac_002a(0x28eb);
  if (DAT_554c_02e6 != 0) {
    uVar1 = 0x54bb;
    func_0x00054bdf(0x54ac,0);
  }
  func_0x00054ab0(uVar1);
  if ((param_1 != 0) && (5000 < DAT_554c_2f1c)) {
    FUN_460e_101b(0,DAT_554c_2f1c,1);
  }
  FUN_2424_03c5();
  FUN_2424_028d();
  FUN_460e_18af(DAT_554c_2f1c,1);
  FUN_2e67_0a1f();
  FUN_2424_08e8();
  FUN_311b_06b8();
  FUN_406b_03cb(0xfffd,0xffff);
  FUN_2424_01b2();
  return;
}

