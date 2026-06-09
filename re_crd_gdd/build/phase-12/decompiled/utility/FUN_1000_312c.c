// TIM2.EXE: FUN_1000_312c @ file 0x01832C Ghidra 0x1312C
// Subsystem: utility | Size: 43 bytes


undefined2 __cdecl16far FUN_1000_312c(undefined2 param_1,int param_2)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined1 in_CF;
  undefined4 uVar3;
  
  pcVar1 = (code *)swi(0x21);
  uVar3 = (*pcVar1)();
  uVar2 = (undefined2)uVar3;
  if ((bool)in_CF) {
    uVar2 = FUN_1000_1b4b(uVar2);
  }
  else if (param_2 == 0) {
    uVar2 = (int)((ulong)uVar3 >> 0x10);
  }
  return uVar2;
}

