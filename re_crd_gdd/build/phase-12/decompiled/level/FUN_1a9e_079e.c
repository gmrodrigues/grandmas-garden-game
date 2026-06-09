// TIM2.EXE: FUN_1a9e_079e @ file 0x02037E Ghidra 0x1B17E
// Subsystem: level | Size: 200 bytes


void __cdecl16near FUN_1a9e_079e(void)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  undefined2 local_4;
  
  FUN_1000_0624(DAT_5b41_004d,DAT_5b41_004f,0,0x3aa1,0);
  DAT_5b41_1d1c = 9;
  DAT_5b41_1d1a = 0x1ff;
  for (local_4 = 0xff; -1 < local_4; local_4 = local_4 + -1) {
    uVar3 = DAT_5b41_004f;
    puVar1 = (undefined2 *)FUN_1000_1a88();
    *puVar1 = 0;
    uVar3 = DAT_5b41_004f;
    FUN_1000_1a88();
    puVar2 = (undefined1 *)FUN_1000_1a88();
    *puVar2 = (undefined1)local_4;
  }
  DAT_5b41_1d18 = 0x101;
  DAT_5b41_1d16 = 0;
  DAT_5b41_1d07 = 1;
  DAT_5b41_1d06 = 0;
  DAT_5b41_1d0a = 0;
  DAT_5b41_1d08 = 0;
  uVar3 = DAT_5b41_004f;
  DAT_5b41_1d0c = FUN_1000_1a88();
  DAT_5b41_1d0e = uVar3;
  return;
}

