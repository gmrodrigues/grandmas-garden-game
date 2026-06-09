// TIM2.EXE: FUN_2424_03c5 @ file 0x029805 Ghidra 0x24605
// Subsystem: misc | Size: 327 bytes


void __cdecl16far FUN_2424_03c5(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  func_0x00054aef(0x2424,0,0,0);
  FUN_311b_0244();
  uVar1 = DAT_5b41_0567;
  if (5000 < DAT_554c_2f1c) {
    DAT_5b41_0567 = 0;
  }
  if (iRam000557bc != 7) {
    FUN_2424_10b2();
  }
  FUN_2424_0ff3();
  if (iRam000557bc != 7) {
    FUN_2424_20ab(0);
  }
  FUN_2424_184a(0);
  DAT_5b41_0505 = DAT_5b41_0505 + 1;
  if (((int)DAT_5b41_0567 == 0 && DAT_5b41_0567._2_2_ == 0) || (LAB_554c_02ee == -1)) {
    FUN_54f1_0043((char *)s_SIGNIN_RES_554c_3111 + 10);
  }
  else {
    FUN_2424_2165((int)DAT_5b41_0567,DAT_5b41_0567._2_2_,LAB_554c_02ee,1);
    uVar3 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10);
    iVar2 = (int)DAT_5b41_0567;
    if ((*(int *)(iVar2 + 8) == 0x16) || (*(int *)(iVar2 + 8) == 0x37)) {
      if (*(int *)(iVar2 + 0x62) != 0 || *(int *)(iVar2 + 100) != 0) {
        FUN_2424_2165(*(undefined2 *)(iVar2 + 0x62),*(undefined2 *)(iVar2 + 100),0,0);
      }
    }
  }
  if (DAT_554c_02f0 != -1) {
    DAT_554c_42ce = (undefined1)DAT_554c_02f0;
    FUN_2424_276e(DAT_5b41_0547 - DAT_5b41_0925,DAT_5b41_0549 - DAT_5b41_0927,
                  DAT_5b41_054b - DAT_5b41_0925,DAT_5b41_054d - DAT_5b41_0927,0);
    FUN_2424_1a04((undefined2 *)&DAT_5b41_0547,(undefined2 *)&DAT_5b41_054b,2);
  }
  if (5000 < DAT_554c_2f1c) {
    FUN_2424_196d();
    FUN_2424_184a(1);
  }
  FUN_2424_0304();
  FUN_460e_1314(0);
  FUN_2424_1650();
  DAT_5b41_0567 = uVar1;
  return;
}

