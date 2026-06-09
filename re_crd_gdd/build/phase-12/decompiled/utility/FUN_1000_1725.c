// TIM2.EXE: FUN_1000_1725 @ file 0x016925 Ghidra 0x11725
// Subsystem: utility | Size: 25 bytes


void __cdecl16far FUN_1000_1725(undefined2 param_1,uint *param_2)

{
  code *pcVar1;
  byte bVar2;
  
  pcVar1 = (code *)swi(0x21);
  bVar2 = (*pcVar1)();
  *param_2 = (uint)bVar2;
  return;
}

