// TIM2.EXE — State machine site: D1-dispatch-call-0x3AE71
// File offset: 0x03AE71 → Ghidra 0x35C71
// Function: FUN_31f7_3bd2 @ entry 0x35B42
// Body: 0x35B42 - 0x35CC7
// Size: 390 bytes
// Note: 

// === SYMBOLIC CONTEXT (2 instructions before / after target) ===
    31f7:3ce1: LES BX,[BP + 0x6]
    31f7:3ce4: CMP word ptr ES:[BX + 0x10],0x0
    31f7:3ce9: JZ 0x3000:5c7e
    31f7:3ceb: MOV AX,word ptr ES:[BX + 0x10]
    31f7:3cef: CMP AX,word ptr [0x791c]
    31f7:3cf3: JGE 0x3000:5ca3
    31f7:3cf5: INC word ptr ES:[BX + 0x10]
    31f7:3cf9: MOV AX,word ptr ES:[BX + 0x10]
    31f7:3cfd: CMP AX,word ptr [0x791c]
    31f7:3d01: JNZ 0x3000:5ca3
    31f7:3d03: LES BX,[BP + 0x6]
    31f7:3d06: MOV word ptr ES:[BX + 0x10],0x0
    31f7:3d0c: JMP 0x3000:5ca3
    31f7:3d0e: DEC word ptr [0x3aec]
    31f7:3d12: CMP word ptr [0x3aec],0x0
    31f7:3d17: JGE 0x3000:5ca3

// === DECOMPILED C ===

void __cdecl16far FUN_31f7_3bd2(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int in_DX;
  
  iVar1 = FUN_28eb_3783((int)param_1,param_1._2_2_);
  if ((iVar1 != 0 || in_DX != 0) && ((*(byte *)(iVar1 + 0xd) & 8) == 0)) {
    if ((*(int *)((int)param_1 + 0x10) < DAT_5b41_19ce) ||
       (DAT_5b41_19d2 <= *(int *)((int)param_1 + 0x10))) {
      *(undefined2 *)(iVar1 + 0x16) = 0;
    }
    else {
      *(int *)(iVar1 + 0x16) = *(int *)((int)param_1 + 0x16) * 2;
    }
  }
  if (*(int *)((int)param_1 + 0xae) == 0) {
    if (*(int *)((int)param_1 + 0x16) != 0) {
      if (*(int *)((int)param_1 + 0x10) < DAT_5b41_19cc) {
        *(int *)((int)param_1 + 0x10) = DAT_5b41_19cc + -1;
      }
      *(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + 1;
      if (*(int *)((int)param_1 + 0x10) == DAT_5b41_19d2) {
        *(undefined2 *)((int)param_1 + 0x10) = DAT_5b41_19d0;
      }
      goto LAB_31f7_3d33;
    }
    if ((DAT_5b41_051f & 1) == 0) goto LAB_31f7_3d33;
    if (*(int *)((int)param_1 + 0x10) == 0) {
      DAT_554c_3aec = DAT_554c_3aec + -1;
      if (DAT_554c_3aec < 0) {
        *(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + 1;
        uVar2 = FUN_460e_1a42();
        DAT_554c_3aec = uVar2 % 200 + 0x28;
      }
      goto LAB_31f7_3d33;
    }
    if ((DAT_5b41_19cc <= *(int *)((int)param_1 + 0x10)) ||
       (*(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + 1,
       *(int *)((int)param_1 + 0x10) != DAT_5b41_19cc)) goto LAB_31f7_3d33;
  }
  else {
    *(int *)((int)param_1 + 0xae) = *(int *)((int)param_1 + 0xae) + -1;
    if (*(int *)((int)param_1 + 0xae) != 0) {
      *(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + 1;
      if (*(int *)((int)param_1 + 0x10) == DAT_5b41_19d4) {
        *(int *)((int)param_1 + 0x10) = DAT_5b41_19d2;
      }
      else if (*(int *)((int)param_1 + 0x10) == DAT_5b41_19d6) {
        *(int *)((int)param_1 + 0x10) = DAT_5b41_19d4;
      }
      goto LAB_31f7_3d33;
    }
    if (*(int *)((int)param_1 + 0x10) < DAT_5b41_19d4) {
      if ((*(byte *)((int)param_1 + 0xc) & 0x10) == 0) {
        *(undefined2 *)((int)param_1 + 0x16) = 0xffff;
      }
      else {
        *(undefined2 *)((int)param_1 + 0x16) = 1;
      }
      *(undefined2 *)((int)param_1 + 0x10) = DAT_5b41_19d0;
      goto LAB_31f7_3d33;
    }
  }
  *(undefined2 *)((int)param_1 + 0x10) = 0;
LAB_31f7_3d33:
  if (*(int *)((int)param_1 + 0x10) != *(int *)((int)param_1 + 0x12)) {
    FUN_31f7_3aab((int)param_1,param_1._2_2_);
    FUN_28eb_3328((int)param_1,param_1._2_2_);
  }
  return;
}


