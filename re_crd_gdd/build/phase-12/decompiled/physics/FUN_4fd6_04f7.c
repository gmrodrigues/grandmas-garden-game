// TIM2.EXE: FUN_4fd6_04f7 @ file 0x055457 Ghidra 0x50257
// Subsystem: physics | Size: 102 bytes


/* WARNING: Removing unreachable block (ram,0x000113d3) */

undefined2 __cdecl16far FUN_4fd6_04f7(void)

{
  undefined2 in_AX;
  undefined2 *in_stack_00000000;
  
  if ((undefined2 *)in_stack_00000000 == (undefined2 *)0x2) {
    FUN_4fd6_05a7(*in_stack_00000000);
  }
  else {
    LOCK();
    UNLOCK();
    FUN_4fd6_05a7(*in_stack_00000000);
    LOCK();
    UNLOCK();
  }
  *(byte *)0x1a = *(byte *)0x1a & 0xf7;
  (*(code *)*(undefined2 *)0x86)(0x5000);
  return in_AX;
}

