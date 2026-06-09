// TIM2.EXE: FUN_1000_4c5b @ file 0x019E5B Ghidra 0x14C5B
// Subsystem: utility | Size: 81 bytes


int __cdecl16far FUN_1000_4c5b(undefined2 param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = false;
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)();
  if (bVar3) {
    iVar2 = FUN_1000_1b4b(iVar2);
  }
  else {
    *(uint *)(iVar2 * 2 + 0x5916) = param_2 & 0xb8ff | 0x8000;
  }
  return iVar2;
}

