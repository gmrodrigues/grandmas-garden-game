// TIM2.EXE: FUN_1000_13c9 @ file 0x0165C9 Ghidra 0x113C9
// Subsystem: utility | Size: 40 bytes


/* WARNING: Instruction at (ram,0x000113df) overlaps instruction at (ram,0x000113dd)
    */
/* WARNING: Removing unreachable block (ram,0x000113df) */

void __cdecl16far FUN_1000_13c9(void)

{
  code *pcVar1;
  bool in_CF;
  bool in_SF;
  undefined2 *in_stack_00000002;
  undefined2 in_stack_0000000a;
  
  if (in_SF) {
    if (in_CF) {
      FUN_1000_3773();
      FUN_1000_13f1();
      return;
    }
    out(*in_stack_00000002,in_stack_0000000a);
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
  }
  FUN_1000_17d2();
  return;
}

