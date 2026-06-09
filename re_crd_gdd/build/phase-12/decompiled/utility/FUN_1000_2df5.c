// TIM2.EXE: FUN_1000_2df5 @ file 0x017FF5 Ghidra 0x12DF5
// Subsystem: utility | Size: 125 bytes


uint __cdecl16far FUN_1000_2df5(uint param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  DAT_1000_2bb1 = 0x554c;
  if (param_1 != 0 || param_2 != 0) {
    uVar2 = param_2 + (0xffec < param_1);
    if ((CARRY2(param_2,(uint)(0xffec < param_1))) || ((uVar2 & 0xfff0) != 0)) {
      param_1 = 0;
    }
    else {
      uVar2 = CONCAT11((byte)(param_1 + 0x13 >> 0xc) | (char)uVar2 * '\x10',
                       (char)(param_1 + 0x13 >> 4));
      if (DAT_1000_2bab == 0) {
        param_1 = FUN_1000_2d14();
      }
      else {
        iVar3 = DAT_1000_2baf;
        if (DAT_1000_2baf != 0) {
          do {
            if (uVar2 <= *(uint *)0x0) {
              if (*(uint *)0x0 <= uVar2) {
                FUN_1000_2c8b();
                *(undefined2 *)0x2 = *(undefined2 *)0x8;
                return 4;
              }
              uVar2 = FUN_1000_2dd2();
              return uVar2;
            }
            piVar1 = (int *)0x6;
            iVar3 = *piVar1;
          } while (*piVar1 != DAT_1000_2baf);
        }
        param_1 = FUN_1000_2d78();
      }
    }
  }
  return param_1;
}

