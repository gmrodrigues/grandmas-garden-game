// TIM2.EXE — FUN_4551_0370_lookup
// Target address (Ghidra): 0x45880
// File offset: 0x4AA80
// Function: FUN_4551_0370 @ entry 0x45880
// Body: 0x45880 - 0x458FA (122 bytes)
// Note: exact match

// === CONTEXT INSTRUCTIONS ===
    4551:0370: PUSH BP
    4551:0371: MOV BP,SP
    4551:0373: SUB SP,0x8
    4551:0376: PUSH SI
    4551:0377: MOV SI,word ptr [BP + 0x8]
    4551:037a: PUSH word ptr [BP + 0x6]
    4551:037d: NOP
    4551:037e: PUSH CS
    4551:037f: CALL 0x4000:5bdf
    4551:0382: ADD SP,0x2
    4551:0385: MOV word ptr [BP + -0x2],DX
    4551:0388: MOV word ptr [BP + -0x4],AX
    4551:038b: CMP SI,-0x1
    4551:038e: JNZ 0x4000:58b2
    4551:0390: OR AX,word ptr [BP + -0x2]
    4551:0393: JZ 0x4000:58ae
    4551:0395: LES BX,[BP + -0x4]
    4551:0398: MOV AX,word ptr ES:[BX + 0xc]
    4551:039c: JMP 0x4000:58b0
    4551:039e: XOR AX,AX

// === DECOMPILED C ===

undefined2 __cdecl16far FUN_4551_0370(undefined2 param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  int in_DX;
  undefined2 *puVar3;
  undefined4 local_a;
  
  iVar1 = FUN_4551_06cf(param_1);
  if (param_2 == -1) {
    if (iVar1 == 0 && in_DX == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined2 *)(iVar1 + 0xc);
    }
  }
  else if ((iVar1 == 0 && in_DX == 0) || (*(int *)(iVar1 + 8) == 0 && *(int *)(iVar1 + 10) == 0)) {
    uVar2 = 0;
  }
  else {
    local_a = (undefined2 *)
              CONCAT22(*(undefined2 *)(iVar1 + 10),(undefined2 *)*(undefined2 *)(iVar1 + 8));
    while( true ) {
      uVar2 = (undefined2)((ulong)local_a >> 0x10);
      puVar3 = (undefined2 *)local_a;
      if ((puVar3[1] == 0) || (puVar3[1] == param_2)) break;
      local_a = (undefined2 *)CONCAT22(uVar2,puVar3 + 2);
    }
    uVar2 = *local_a;
  }
  return uVar2;
}


