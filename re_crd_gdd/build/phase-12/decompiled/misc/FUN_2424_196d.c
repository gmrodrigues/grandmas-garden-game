// TIM2.EXE: FUN_2424_196d @ file 0x02ADAD Ghidra 0x25BAD
// Subsystem: misc | Size: 71 bytes


void __cdecl16far FUN_2424_196d(void)

{
  undefined2 *puVar1;
  
  for (puVar1 = DAT_5b41_04b0; puVar1 != (undefined2 *)0x0; puVar1 = (undefined2 *)*puVar1) {
    FUN_406b_000c(puVar1[1],puVar1[2],(puVar1[3] - puVar1[1]) + 1,(puVar1[4] - puVar1[2]) + 1,0);
  }
  return;
}

