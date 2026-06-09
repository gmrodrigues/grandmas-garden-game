// TIM2.EXE: FUN_28eb_467f @ file 0x03272F Ghidra 0x2D52F
// Subsystem: misc | Size: 49 bytes


void __cdecl16far FUN_28eb_467f(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  if (DAT_5b41_096b != (undefined2 *)0x0) {
    puVar1 = (undefined2 *)*DAT_5b41_096b;
    puVar3 = DAT_5b41_096b;
    while (puVar2 = puVar1, puVar2 != (undefined2 *)0x0) {
      puVar3 = puVar2;
      puVar1 = (undefined2 *)*puVar2;
    }
    *puVar3 = DAT_5b41_096d;
    DAT_5b41_096d = DAT_5b41_096b;
    DAT_5b41_096b = (undefined2 *)0x0;
  }
  return;
}

