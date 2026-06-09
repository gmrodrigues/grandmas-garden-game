// TIM2.EXE: FUN_1a3f_0334 @ file 0x01F924 Ghidra 0x1A724
// Subsystem: utility | Size: 302 bytes


void __cdecl16far FUN_1a3f_0334(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  
  uVar8 = FUN_54fb_002a(0x1a3f);
  uVar6 = (undefined2)((ulong)uVar8 >> 0x10);
  FUN_28eb_1234();
  puVar7 = (undefined1 *)0x0;
  if (param_1 != 0) {
    FUN_4340_0a29((undefined1 *)&DAT_5b41_0002,0x554c,param_1,0x554c);
    uVar1 = FUN_4340_0d3f((undefined1 *)&DAT_5b41_0002,0x554c,0x2e,0,0);
    FUN_4340_0a29(uVar1,uVar6);
    FUN_4340_0abb((undefined1 *)&DAT_5b41_0002,0x554c,0x11f,0x554c);
    puVar7 = (undefined1 *)&DAT_5b41_0002;
  }
  uVar1 = 0x1000;
  iVar2 = FUN_1000_03ef(puVar7);
  if (iVar2 != 0) {
    do {
      iVar2 = FUN_3f2b_0aa7();
    } while (iVar2 != 0);
    FUN_460e_2442(0x124);
    FUN_406b_02f2(0,0,0);
    FUN_4340_0133(50000,0x131);
    for (iVar2 = 0; iVar2 < 0x32; iVar2 = iVar2 + 1) {
      uVar1 = FUN_4340_06ef(iVar2 + -0x3caf);
      uVar3 = FUN_4340_0d94(uVar1,uVar6);
      uVar5 = 0x51a7;
      *(undefined2 *)(iVar2 << 2) = uVar3;
      iVar4 = FUN_4340_0caf(uVar1,uVar6,0x2c);
      uVar1 = FUN_4340_0d94(iVar4 + 1,uVar5);
      uVar6 = 0x51a7;
      *(undefined2 *)(iVar2 * 4 + 2) = uVar1;
    }
    FUN_4340_0133(50000,0);
    FUN_406b_02f2(0x13c,0,0x51a7);
    uVar1 = 0x28eb;
    FUN_28eb_1234();
  }
  func_0x000552d0(uVar1,(undefined1 *)&DAT_5b41_0002);
  FUN_1a3f_01e5();
  if ((int)uVar8 != 0) {
    func_0x00054fdf(0x552b);
  }
  return;
}

