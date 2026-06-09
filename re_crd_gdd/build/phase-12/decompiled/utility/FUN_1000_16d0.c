// TIM2.EXE: FUN_1000_16d0 @ file 0x0168D0 Ghidra 0x116D0
// Subsystem: utility | Size: 33 bytes


undefined2 __cdecl16far FUN_1000_16d0(undefined2 param_1,undefined2 *param_2)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 in_CX;
  bool bVar3;
  
  bVar3 = false;
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if (bVar3) {
    uVar2 = FUN_1000_1b89(uVar2);
  }
  else {
    *param_2 = in_CX;
    uVar2 = 0;
  }
  return uVar2;
}

