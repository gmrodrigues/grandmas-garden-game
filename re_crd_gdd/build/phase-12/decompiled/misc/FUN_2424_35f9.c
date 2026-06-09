// TIM2.EXE: FUN_2424_35f9 @ file 0x02CA39 Ghidra 0x27839
// Subsystem: misc | Size: 127 bytes


undefined2 __cdecl16far FUN_2424_35f9(undefined2 *param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int iVar4;
  
  puVar2 = DAT_5b41_054f;
  iVar4 = DAT_5b41_0551;
  if ((undefined2 *)param_1 == (undefined2 *)0x0 && param_1._2_2_ == 0) {
    while (param_1 = (undefined2 *)CONCAT22(iVar4,puVar2), puVar2 != (undefined2 *)0x0 || iVar4 != 0
          ) {
      if ((*(byte *)((int)puVar2 + 0xf) & 0x20) != 0) {
        FUN_2424_35f9(puVar2,iVar4);
      }
      piVar1 = puVar2 + 1;
      iVar4 = *piVar1;
      puVar2 = (undefined2 *)*param_1;
    }
    uVar3 = FUN_2424_3680();
    return uVar3;
  }
  if ((*(byte *)((int)(undefined2 *)param_1 + 0xf) & 0x20) != 0) {
    iVar4 = FUN_2424_4087((undefined2 *)param_1,param_1._2_2_);
    if (iVar4 != 0) {
      uVar3 = FUN_2424_378a((undefined2 *)param_1,param_1._2_2_);
      return uVar3;
    }
    if (*(int *)((int)(undefined2 *)param_1 + 8) == 0x76) {
      uVar3 = FUN_2424_40d8((undefined2 *)param_1,param_1._2_2_);
      return uVar3;
    }
  }
  return 0;
}

