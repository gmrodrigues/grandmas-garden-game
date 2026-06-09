// TIM2.EXE: FUN_3f2b_11ba @ file 0x04566A Ghidra 0x4046A
// Subsystem: sound | Size: 39 bytes


uint __cdecl16near FUN_3f2b_11ba(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 unaff_ES;
  
  uVar2 = param_1 + *(uint *)0x2;
  if ((!CARRY2(param_1,*(uint *)0x2)) && (uVar2 < *(uint *)0x0)) {
    LOCK();
    uVar1 = *(uint *)0x2;
    *(uint *)0x2 = uVar2;
    UNLOCK();
    return uVar1;
  }
  return 0xffff;
}

