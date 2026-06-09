// TIM2.EXE: FUN_4bdc_3f75 @ file 0x054F35 Ghidra 0x4FD35
// Subsystem: physics | Size: 50 bytes


undefined2 __cdecl16far FUN_4bdc_3f75(undefined2 param_1,undefined2 param_2,uint param_3)

{
  code *pcVar1;
  undefined2 uVar2;
  bool bVar3;
  
  if ((param_3 & 0xf) != 0) {
    param_3 = param_3 + 0x10;
  }
  bVar3 = (param_3 >> 3 & 1) != 0;
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if (!bVar3) {
    uVar2 = 0;
  }
  return uVar2;
}

