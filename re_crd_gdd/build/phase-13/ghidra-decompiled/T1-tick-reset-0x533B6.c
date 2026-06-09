// TIM2.EXE — State machine site: T1-tick-reset-0x533B6
// File offset: 0x0533B6 → Ghidra 0x4E1B6
// Function: FUN_4bdc_23f3 @ entry 0x4E1B3
// Body: 0x4E1B3 - 0x4E1C8
// Size: 22 bytes
// Note: 

// === SYMBOLIC CONTEXT (2 instructions before / after target) ===
    4bdc:23d6: NOP
    4bdc:23d7: PUSH CS
    4bdc:23d8: CALL 0x4000:c91c
    4bdc:23db: POP SI
    4bdc:23dc: POP DI
    4bdc:23dd: POP DS
    4bdc:23de: POP BP
    4bdc:23df: RETF
    4bdc:23e0: PUSH BP
    4bdc:23e1: MOV BP,SP
    4bdc:23e3: PUSH DS
    4bdc:23e4: PUSH DI
    4bdc:23e5: PUSH SI
    4bdc:23e6: LES AX,[BP + 0x6]
    4bdc:23e9: NOP
    4bdc:23ea: PUSH CS

// === DECOMPILED C ===

void __cdecl16far FUN_4bdc_23f3(void)

{
  FUN_4bdc_096d();
  return;
}


