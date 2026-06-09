// TIM2.EXE: FUN_406b_03cb @ file 0x045C7B Ghidra 0x40A7B
// Subsystem: sound | Size: 269 bytes


uint __cdecl16far FUN_406b_03cb(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (DAT_53bd_0038 != 0) {
    if (param_1 == 0xfffc) {
      if (DAT_53bd_0044 != 0) {
        return 0xfffe;
      }
      return DAT_53bd_0042;
    }
    if (param_1 == 0xfffd) {
      param_1 = 0;
    }
    if (param_1 == 0xffff) {
      param_1 = DAT_53bd_0042;
    }
    if ((param_1 < DAT_53bd_003a) || (param_1 == 0xfffe)) {
      if (param_1 != 0xfffe) {
        uVar1 = FUN_1a9e_5398(0x406b,*(undefined2 *)(*(int *)(param_1 * 2 + DAT_53bd_0038) + 6),
                              *(undefined2 *)(*(int *)(param_1 * 2 + DAT_53bd_0038) + 8));
        if ((int)((ulong)uVar1 >> 0x10) != 0) {
          return 0;
        }
        if (DAT_53bd_0040 < (uint)uVar1) {
          return 0;
        }
      }
      if (DAT_5b41_1b64 <= param_2) {
        DAT_5b41_1b64 = param_2;
        DAT_53bd_0042 = param_1;
      }
      if (param_2 != 0xffff) {
        if (DAT_53bd_0042 != param_1) {
          return 1;
        }
        return 2;
      }
      if (DAT_53bd_0044 == 0) {
        DAT_53bd_0004 = param_1;
        FUN_406b_111b(0);
      }
      DAT_5b41_1b64 = 0;
      return 2;
    }
  }
  return 0;
}

