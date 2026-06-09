// TIM2.EXE: FUN_1000_5924 @ file 0x01AB24 Ghidra 0x15924
// Subsystem: utility | Size: 61 bytes


undefined2 __cdecl16far FUN_1000_5924(int param_1)

{
  uint *puVar1;
  code *pcVar2;
  bool bVar3;
  undefined2 uVar4;
  
  bVar3 = false;
  if ((*(byte *)(param_1 * 2 + 0x5916) & 1) == 0) {
    pcVar2 = (code *)swi(0x21);
    uVar4 = (*pcVar2)();
    if (!bVar3) {
      puVar1 = (uint *)(param_1 * 2 + 0x5916);
      *puVar1 = *puVar1 | 0x1000;
      return uVar4;
    }
  }
  else {
    uVar4 = 5;
  }
  uVar4 = FUN_1000_1b4b(uVar4);
  return uVar4;
}

