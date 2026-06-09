// TIM2.EXE: FUN_1000_2006 @ file 0x017206 Ghidra 0x12006
// Subsystem: utility | Size: 48 bytes


void __cdecl16far FUN_1000_2006(int param_1)

{
  code *pcVar1;
  bool bVar2;
  undefined2 uVar3;
  
  bVar2 = false;
  if ((*(byte *)(param_1 * 2 + 0x5916) & 2) == 0) {
    pcVar1 = (code *)swi(0x21);
    uVar3 = (*pcVar1)();
    if (!bVar2) {
      return;
    }
  }
  else {
    uVar3 = 5;
  }
  FUN_1000_1b4b(uVar3);
  return;
}

