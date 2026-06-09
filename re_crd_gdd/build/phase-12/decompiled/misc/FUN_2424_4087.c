// TIM2.EXE: FUN_2424_4087 @ file 0x02D4C7 Ghidra 0x282C7
// Subsystem: misc | Size: 81 bytes


undefined2 __cdecl16far FUN_2424_4087(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 8);
  if (iVar1 != 0x52) {
    if (iVar1 < 0x53) {
      if (iVar1 != 0x30) {
        if (iVar1 < 0x31) {
          if ((iVar1 != 1) && (iVar1 != 0x2e)) {
            return 0;
          }
        }
        else if ((iVar1 != 0x38) && (iVar1 != 0x3c)) {
          return 0;
        }
      }
    }
    else if (iVar1 != 0x55) {
      if (iVar1 < 0x56) {
        if ((iVar1 != 0x53) && (iVar1 != 0x54)) {
          return 0;
        }
      }
      else if (iVar1 != 0x7d) {
        return 0;
      }
    }
  }
  return 1;
}

