// TIM2.EXE: FUN_1000_1c50 @ file 0x016E50 Ghidra 0x11C50
// Subsystem: utility | Size: 45 bytes


void __cdecl16far FUN_1000_1c50(int param_1)

{
  uint *puVar1;
  code *pcVar2;
  undefined2 uVar3;
  bool bVar4;
  
  puVar1 = (uint *)(param_1 * 2 + 0x5916);
  bVar4 = false;
  *puVar1 = *puVar1 & 0xfdff;
  pcVar2 = (code *)swi(0x21);
  uVar3 = (*pcVar2)();
  if (bVar4) {
    FUN_1000_1b4b(uVar3);
  }
  return;
}

