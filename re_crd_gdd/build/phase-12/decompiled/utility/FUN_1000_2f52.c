// TIM2.EXE: FUN_1000_2f52 @ file 0x018152 Ghidra 0x12F52
// Subsystem: utility | Size: 122 bytes


undefined2 __cdecl16far FUN_1000_2f52(undefined2 param_1,int param_2,uint param_3,uint param_4)

{
  undefined2 uVar1;
  uint uVar2;
  
  DAT_1000_2bb1 = 0x554c;
  DAT_1000_2bb3 = param_4;
  DAT_1000_2bb5 = param_3;
  if (param_2 == 0) {
    uVar1 = FUN_1000_2df5(param_3,param_4);
  }
  else {
    if (param_3 == 0 && param_4 == 0) {
      FUN_1000_2ceb(param_3,param_2);
    }
    else {
      uVar2 = param_4 + (0xffec < param_3);
      if ((!CARRY2(param_4,(uint)(0xffec < param_3))) && ((uVar2 & 0xfff0) == 0)) {
        uVar2 = CONCAT11((byte)(param_3 + 0x13 >> 0xc) | (char)uVar2 * '\x10',
                         (char)(param_3 + 0x13 >> 4));
        if (*(uint *)0x0 < uVar2) {
          uVar1 = FUN_1000_2e72();
          return uVar1;
        }
        if (*(uint *)0x0 == uVar2) {
          DAT_1000_2bb1 = 0x554c;
          return 4;
        }
        uVar1 = FUN_1000_2eee();
        return uVar1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

