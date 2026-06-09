// TIM2.EXE: FUN_311b_0a90 @ file 0x036E40 Ghidra 0x31C40
// Subsystem: misc | Size: 250 bytes


/* WARNING: Instruction at (ram,0x0003c053) overlaps instruction at (ram,0x0003c051)
    */

uint __cdecl16far FUN_311b_0a90(uint param_1)

{
  int *piVar1;
  uint uVar2;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  
  if (param_1 == 0x4e2c) {
    DAT_554c_2fee = DAT_554c_2fee + 2;
    if (8 < DAT_554c_2fee) {
      DAT_554c_2fee = 9;
    }
  }
  else if (param_1 < 0x4e2d) {
    param_1 = param_1 + 0xb1da;
    if (param_1 < 6) {
      switch(param_1) {
      case 1:
        piVar1 = (int *)(param_1 * 2 + unaff_SI);
        *piVar1 = *piVar1 + param_1;
        break;
      case 3:
        param_1 = 1;
        break;
      case 5:
        (&stack0xfffe)[unaff_DI] = (&stack0xfffe)[unaff_DI] + (char)(param_1 * 2 >> 8);
      case 4:
        param_1 = 0;
      case 2:
      }
      return param_1;
    }
  }
  else if (param_1 == 0x4e2f) {
    DAT_554c_2ff0 = DAT_554c_2ff0 + -300;
    if (DAT_554c_2ff0 < 0x259) {
      DAT_554c_2ff0 = 600;
    }
  }
  else if (param_1 < 0x4e30) {
    if (param_1 == 0x4e2d) {
      DAT_554c_2ff2 = DAT_554c_2ff2 + -300;
      if (DAT_554c_2ff2 < 0x259) {
        DAT_554c_2ff2 = 600;
      }
    }
    else if ((param_1 == 0x4e2e) && (DAT_554c_2ff2 = DAT_554c_2ff2 + 300, 0x1517 < DAT_554c_2ff2)) {
      DAT_554c_2ff2 = 0x1518;
    }
  }
  else if (param_1 == 0x4e30) {
    DAT_554c_2ff0 = DAT_554c_2ff0 + 300;
    if (0x1517 < DAT_554c_2ff0) {
      DAT_554c_2ff0 = 0x1518;
    }
  }
  else if (param_1 == 0xfe64) {
    DAT_5b41_0d3e = 2;
    uRam000557bc = 7;
  }
  FUN_460e_101b(0x4e26,0,2);
  uVar2 = FUN_460e_101b(0x4e27,0,2);
  return uVar2;
}

