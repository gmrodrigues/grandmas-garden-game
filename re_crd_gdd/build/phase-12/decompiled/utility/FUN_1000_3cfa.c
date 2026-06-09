// TIM2.EXE: FUN_1000_3cfa @ file 0x018EFA Ghidra 0x13CFA
// Subsystem: utility | Size: 125 bytes


/* WARNING: Removing unreachable block (ram,0x00013d5f) */

undefined2 __cdecl16far FUN_1000_3cfa(uint param_1)

{
  code *pcVar1;
  bool bVar2;
  ulong uVar3;
  undefined4 uVar4;
  ulong uVar5;
  undefined2 uVar6;
  
  if (param_1 < DAT_554c_5914) {
    bVar2 = false;
    if ((*(byte *)(param_1 * 2 + 0x5917) & 2) != 0) {
      return 1;
    }
    pcVar1 = (code *)swi(0x21);
    uVar3 = (*pcVar1)();
    uVar6 = (undefined2)uVar3;
    if (!bVar2) {
      if ((uVar3 & 0x800000) != 0) {
        return 0;
      }
      bVar2 = false;
      pcVar1 = (code *)swi(0x21);
      uVar4 = (*pcVar1)();
      uVar6 = (undefined2)uVar4;
      if (!bVar2) {
        bVar2 = false;
        pcVar1 = (code *)swi(0x21);
        uVar3 = (*pcVar1)((int)((ulong)uVar4 >> 0x10));
        uVar6 = (undefined2)uVar3;
        if (!bVar2) {
          pcVar1 = (code *)swi(0x21);
          uVar5 = (*pcVar1)();
          uVar6 = (undefined2)uVar5;
          if (!bVar2) {
            if (uVar5 < uVar3) {
              return 0;
            }
            return 1;
          }
        }
      }
    }
  }
  else {
    uVar6 = 6;
  }
  uVar6 = FUN_1000_1b4b(uVar6);
  return uVar6;
}

