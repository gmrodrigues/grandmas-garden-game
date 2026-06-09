// TIM2.EXE: FUN_1000_0fdc @ file 0x0161DC Ghidra 0x10FDC
// Subsystem: utility | Size: 166 bytes


undefined2 __cdecl16far FUN_1000_0fdc(int param_1)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined2 uVar6;
  
  DAT_5b41_0458 = param_1;
  if ((DAT_5b41_0469 != 0) && (piVar5 = (int *)FUN_1000_0abd(param_1), piVar5 != (int *)0x0)) {
    if (piVar5[8] == 0) {
      if (((uint)piVar5[4] <= (uint)piVar5[6]) &&
         ((piVar5[6] != piVar5[4] || ((uint)piVar5[3] <= (uint)piVar5[5])))) {
        return 0xffff;
      }
      FUN_1000_09ba(*piVar5);
      FUN_1000_0a7c(piVar5[1] + piVar5[5],piVar5[2] + piVar5[6] + (uint)CARRY2(piVar5[1],piVar5[5]))
      ;
      DAT_5b41_045a = *(undefined2 *)(*piVar5 * 0x1c + 0x6310);
      uVar6 = FUN_1000_4820(DAT_5b41_045a);
      puVar1 = (uint *)(piVar5 + 5);
      uVar3 = *puVar1;
      *puVar1 = *puVar1 + 1;
      piVar5[6] = piVar5[6] + (uint)(0xfffe < uVar3);
      iVar4 = *piVar5;
      puVar1 = (uint *)(iVar4 * 0x1c + 0x6312);
      uVar3 = *puVar1;
      *puVar1 = *puVar1 + 1;
      piVar2 = (int *)(iVar4 * 0x1c + 0x6314);
      *piVar2 = *piVar2 + (uint)(0xfffe < uVar3);
      return uVar6;
    }
    param_1 = piVar5[8];
  }
  DAT_5b41_045a = param_1;
  uVar6 = FUN_1000_4820(param_1);
  return uVar6;
}

