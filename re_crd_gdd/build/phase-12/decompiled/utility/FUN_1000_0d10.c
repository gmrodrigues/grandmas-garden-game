// TIM2.EXE: FUN_1000_0d10 @ file 0x015F10 Ghidra 0x10D10
// Subsystem: utility | Size: 210 bytes


int __cdecl16far FUN_1000_0d10(undefined2 param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint local_6;
  
  if ((DAT_5b41_0469 != 0) && (piVar4 = (int *)FUN_1000_0abd(param_4), piVar4 != (int *)0x0)) {
    if (piVar4[8] == 0) {
      for (local_6 = param_2 * param_3;
          ((local_6 != 0 && (piVar4[4] - piVar4[6] == (uint)((uint)piVar4[3] < (uint)piVar4[5]))) &&
          ((uint)(piVar4[3] - piVar4[5]) < local_6)); local_6 = local_6 - param_2) {
        param_3 = param_3 + -1;
      }
      FUN_1000_09ba(*piVar4);
      FUN_1000_0a7c(piVar4[1] + piVar4[5],piVar4[2] + piVar4[6] + (uint)CARRY2(piVar4[1],piVar4[5]))
      ;
      iVar6 = FUN_1000_4306(param_1,param_2,param_3,*(undefined2 *)(*piVar4 * 0x1c + 0x6310));
      uVar7 = iVar6 * param_2;
      puVar1 = (uint *)(piVar4 + 5);
      uVar3 = *puVar1;
      *puVar1 = *puVar1 + uVar7;
      piVar4[6] = piVar4[6] + (uint)CARRY2(uVar3,uVar7);
      iVar5 = *piVar4;
      puVar1 = (uint *)(iVar5 * 0x1c + 0x6312);
      uVar3 = *puVar1;
      *puVar1 = *puVar1 + uVar7;
      piVar2 = (int *)(iVar5 * 0x1c + 0x6314);
      *piVar2 = *piVar2 + (uint)CARRY2(uVar3,uVar7);
      return iVar6;
    }
    param_4 = piVar4[8];
  }
  iVar5 = FUN_1000_4306(param_1,param_2,param_3,param_4);
  return iVar5;
}

