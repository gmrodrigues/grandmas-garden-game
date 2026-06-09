// TIM2.EXE: FUN_4551_01dc @ file 0x04A8EC Ghidra 0x456EC
// Subsystem: misc | Size: 300 bytes


undefined2 __cdecl16far
FUN_4551_01dc(undefined2 param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  int in_DX;
  bool bVar7;
  undefined4 local_a;
  undefined4 local_6;
  
  piVar1 = (int *)FUN_4551_06cf(param_1);
  local_6 = (int *)CONCAT22(in_DX,piVar1);
  if ((piVar1 != (int *)0x0 || in_DX != 0) && (param_2 < (uint)piVar1[6])) {
    if (*local_6 == 0 && piVar1[1] == 0) {
      iVar5 = piVar1[3];
      piVar2 = (int *)(piVar1[2] + param_2 * 0xc);
    }
    else {
      iVar5 = piVar1[3];
      piVar2 = (int *)(*(int *)((int)*(undefined4 *)local_6 + param_2 * 2) * 0xc + piVar1[2]);
    }
    local_a = (int *)CONCAT22(iVar5,piVar2);
    if ((param_5 & 2) == 0) {
      iVar3 = *local_a;
    }
    else {
      iVar3 = (piVar1[7] - *local_a) - piVar2[2];
    }
    if ((param_5 & 1) == 0) {
      iVar4 = piVar2[1];
    }
    else {
      iVar4 = (piVar1[8] - piVar2[1]) - piVar2[3];
    }
    DAT_5b41_1ad2 = 0;
    FUN_3f2b_069c(param_1);
    FUN_4551_049c(piVar2,iVar5,iVar3 + param_3,iVar4 + param_4,param_5);
    FUN_3f2b_06d5(param_1);
    if (DAT_5b41_1ad2 != 7) {
      DAT_5b41_1ba8 = 0;
      return 1;
    }
    bVar7 = DAT_5b41_1ba8 == 0;
    DAT_5b41_1ba8 = DAT_5b41_1ba8 + 1;
    if (bVar7) {
      do {
        iVar5 = FUN_3f2b_0aa7();
      } while (iVar5 != 0);
      uVar6 = FUN_4551_01dc(param_1,param_2,param_3,param_4,param_5);
      return uVar6;
    }
    DAT_5b41_1ba8 = 0;
  }
  return 0;
}

