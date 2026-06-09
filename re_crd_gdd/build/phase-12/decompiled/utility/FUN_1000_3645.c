// TIM2.EXE: FUN_1000_3645 @ file 0x018845 Ghidra 0x13645
// Subsystem: utility | Size: 302 bytes


undefined2 __cdecl16far FUN_1000_3645(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  if (DAT_554c_5b58 == '\0') {
    DAT_5b41_2914 = 0x1000;
    DAT_5b41_2912 = 0x3645;
    DAT_554c_5b58 = '\x01';
  }
  iVar2 = FUN_1000_3620(param_1);
  if (iVar2 == -1) {
    uRam0005554e = 0x13;
    return 0xffff;
  }
  uVar1 = *(undefined2 *)(iVar2 * 4 + 0x5b59);
  *(int *)(iVar2 * 4 + 0x5b5b) = param_3;
  *(int *)(iVar2 * 4 + 0x5b59) = param_2;
  if (param_1 == 2) {
    if (DAT_554c_5b57 == '\0') {
      iVar2 = param_3;
      DAT_5b41_2a1c = FUN_1000_18c5(0x23);
      DAT_554c_5b57 = '\x01';
      DAT_5b41_2a1e = iVar2;
    }
    uVar4 = DAT_5b41_2a1c;
    iVar2 = DAT_5b41_2a1e;
    if (param_2 != 0 || param_3 != 0) {
      uVar4 = 0x35a6;
      iVar2 = 0x1000;
    }
    uVar3 = 0x23;
  }
  else if (param_1 == 8) {
    FUN_1000_18d8(0,0x34c4,0x1000);
    iVar2 = 0x1000;
    uVar4 = 0x3535;
    uVar3 = 4;
  }
  else {
    if (param_1 == 0xb) {
      if (DAT_554c_5b56 != '\0') {
        return uVar1;
      }
      DAT_5b41_2a18 = FUN_1000_18c5(5);
      DAT_5b41_2a1a = param_3;
      FUN_1000_18d8(5,0x33d2,0x1000);
      DAT_554c_5b56 = 1;
      return uVar1;
    }
    if (param_1 != 4) {
      return uVar1;
    }
    iVar2 = 0x1000;
    uVar4 = 0x3453;
    uVar3 = 6;
  }
  FUN_1000_18d8(uVar3,uVar4,iVar2);
  return uVar1;
}

