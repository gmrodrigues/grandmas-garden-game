// TIM2.EXE: FUN_4340_1ccb @ file 0x04A2CB Ghidra 0x450CB
// Subsystem: misc | Size: 475 bytes


undefined2 __cdecl16far FUN_4340_1ccb(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  uint uVar2;
  
  if ((param_1 != 0) && (param_2 != 0 || param_3 != 0)) {
    for (uVar2 = 0; uVar2 < 0x19; uVar2 = uVar2 + 1) {
      if (*(int *)(uVar2 * 0x1e + 0x100) == param_1) {
        return 0;
      }
    }
    uVar2 = 0;
    while ((uVar2 < 0x19 && (*(int *)(uVar2 * 0x1e + 0x100) != 0))) {
      uVar2 = uVar2 + 1;
    }
    if (uVar2 < 0x19) {
      *(int *)(uVar2 * 0x1e + 0x100) = param_1;
      FUN_1000_1842(0x4340,param_2,param_3,uVar2 * 0x1e + 0x102,0x53c6);
      uVar1 = DAT_53c6_03f0;
      if (*(int *)(uVar2 * 0x1e + 0x102) == 0 && *(int *)(uVar2 * 0x1e + 0x104) == 0) {
        *(undefined2 *)(uVar2 * 0x1e + 0x104) = DAT_53c6_03f2;
        *(undefined2 *)(uVar2 * 0x1e + 0x102) = uVar1;
      }
      uVar1 = DAT_53c6_03f4;
      if (*(int *)(uVar2 * 0x1e + 0x106) == 0 && *(int *)(uVar2 * 0x1e + 0x108) == 0) {
        *(undefined2 *)(uVar2 * 0x1e + 0x108) = DAT_53c6_03f6;
        *(undefined2 *)(uVar2 * 0x1e + 0x106) = uVar1;
      }
      uVar1 = DAT_53c6_03f8;
      if (*(int *)(uVar2 * 0x1e + 0x10a) == 0 && *(int *)(uVar2 * 0x1e + 0x10c) == 0) {
        *(undefined2 *)(uVar2 * 0x1e + 0x10c) = DAT_53c6_03fa;
        *(undefined2 *)(uVar2 * 0x1e + 0x10a) = uVar1;
      }
      uVar1 = DAT_53c6_03fc;
      if (*(int *)(uVar2 * 0x1e + 0x10e) == 0 && *(int *)(uVar2 * 0x1e + 0x110) == 0) {
        *(undefined2 *)(uVar2 * 0x1e + 0x110) = DAT_53c6_03fe;
        *(undefined2 *)(uVar2 * 0x1e + 0x10e) = uVar1;
      }
      uVar1 = DAT_53c6_0400;
      if (*(int *)(uVar2 * 0x1e + 0x112) == 0 && *(int *)(uVar2 * 0x1e + 0x114) == 0) {
        *(undefined2 *)(uVar2 * 0x1e + 0x114) = DAT_53c6_0402;
        *(undefined2 *)(uVar2 * 0x1e + 0x112) = uVar1;
      }
      uVar1 = DAT_53c6_0404;
      if (*(int *)(uVar2 * 0x1e + 0x116) == 0 && *(int *)(uVar2 * 0x1e + 0x118) == 0) {
        *(undefined2 *)(uVar2 * 0x1e + 0x118) = DAT_53c6_0406;
        *(undefined2 *)(uVar2 * 0x1e + 0x116) = uVar1;
      }
      return 1;
    }
  }
  return 0;
}

