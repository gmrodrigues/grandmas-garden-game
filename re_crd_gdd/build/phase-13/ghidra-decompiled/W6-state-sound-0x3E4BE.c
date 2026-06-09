// TIM2.EXE — State machine site: W6-state-sound-0x3E4BE
// File offset: 0x03E4BE → Ghidra 0x392BE
// Function: FUN_31f7_7332 @ entry 0x392A2
// Body: 0x392A2 - 0x39335
// Size: 148 bytes
// Note: 

// === SYMBOLIC CONTEXT (2 instructions before / after target) ===
    31f7:7330: POP BP
    31f7:7331: RETF
    31f7:7332: PUSH BP
    31f7:7333: MOV BP,SP
    31f7:7335: PUSH SI
    31f7:7336: CMP word ptr [0x7984],0x0
    31f7:733b: JZ 0x3000:92b0
    31f7:733d: JMP 0x3000:9330
    31f7:7340: XOR SI,SI
    31f7:7342: JMP 0x3000:9309
    31f7:7344: MOV BX,SI
    31f7:7346: ADD BX,BX
    31f7:7348: PUSH word ptr [BX + 0x3bba]
    31f7:734c: PUSH word ptr [0x6972]
    31f7:7350: CALLF 0x4000:5880
    31f7:7355: ADD SP,0x4

// === DECOMPILED C ===

undefined2 __cdecl16far FUN_31f7_7332(void)

{
  undefined2 uVar1;
  int iVar2;
  
  if (DAT_5b41_1a34 == 0) {
    for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {
      uVar1 = FUN_4551_0370(DAT_5b41_0a22,((undefined2 *)&DAT_554c_3bba)[iVar2]);
      ((undefined2 *)&DAT_5b41_1a32)[iVar2] = uVar1;
      uVar1 = FUN_4551_0370(DAT_5b41_0a22,((undefined2 *)&DAT_554c_3bbe)[iVar2]);
      ((undefined2 *)&DAT_5b41_1a36)[iVar2] = uVar1;
      uVar1 = FUN_4551_0370(DAT_5b41_0a22,((undefined2 *)&DAT_554c_3bc2)[iVar2]);
      ((undefined2 *)&DAT_5b41_1a3a)[iVar2] = uVar1;
    }
    DAT_5b41_1a3e = FUN_4551_0370(DAT_5b41_0a22,0xe);
    DAT_5b41_1a40 = FUN_4551_0370(DAT_5b41_0a22,0xffff);
  }
  return 1;
}


