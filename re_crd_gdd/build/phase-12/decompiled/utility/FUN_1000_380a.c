// TIM2.EXE: FUN_1000_380a @ file 0x018A0A Ghidra 0x1380A
// Subsystem: utility | Size: 55 bytes


undefined2 __cdecl16far FUN_1000_380a(undefined2 param_1,byte param_2)

{
  uint uVar1;
  undefined2 uVar2;
  
  uVar1 = FUN_1000_3c7c(param_1,0);
  if (uVar1 == 0xffff) {
    uVar2 = 0xffff;
  }
  else if (((param_2 & 2) == 0) || ((uVar1 & 1) == 0)) {
    uVar2 = 0;
  }
  else {
    uRam0005554e = 5;
    uVar2 = 0xffff;
  }
  return uVar2;
}

