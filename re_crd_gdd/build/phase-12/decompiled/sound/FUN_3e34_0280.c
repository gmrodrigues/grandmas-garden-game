// TIM2.EXE: FUN_3e34_0280 @ file 0x0437C0 Ghidra 0x3E5C0
// Subsystem: sound | Size: 332 bytes


undefined2 * __cdecl16far FUN_3e34_0280(undefined2 *param_1,byte param_2)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int in_DX;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined2 uVar9;
  int local_16;
  undefined2 *local_10;
  undefined2 *local_e;
  undefined4 local_a;
  undefined4 local_6;
  
  if (param_1 != (undefined2 *)0x0) {
    local_16 = FUN_4a54_09d2(param_1);
    if ((param_2 & 2) == 0) {
      uVar9 = 2;
    }
    else {
      uVar9 = 1;
    }
    puVar4 = (undefined2 *)FUN_22de_01ec(local_16 * 0xe + 4,0,uVar9,1);
    if (puVar4 != (undefined2 *)0x0 || in_DX != 0) {
      local_10 = (undefined2 *)*param_1;
      local_a = (undefined2 *)CONCAT22(in_DX,puVar4);
      local_e = puVar4 + local_16 * 2 + 2;
      while( true ) {
        if (local_16 == 0) break;
        ((undefined2 *)local_a)[1] = in_DX;
        *local_a = local_e;
        local_a = (undefined2 *)CONCAT22(local_a._2_2_,(undefined2 *)local_a + 2);
        puVar7 = local_10;
        puVar8 = local_e;
        for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
          puVar1 = puVar8;
          puVar8 = puVar8 + 1;
          puVar3 = puVar7;
          puVar7 = puVar7 + 1;
          *puVar1 = *puVar3;
        }
        local_10 = local_10 + 5;
        local_e = local_e + 5;
        local_16 = local_16 + -1;
      }
      ((undefined2 *)local_a)[1] = 0;
      *local_a = 0;
      FUN_1000_130c(*param_1);
      FUN_1000_130c(param_1);
      return puVar4;
    }
    puVar5 = (undefined4 *)FUN_22de_01ec(0x12,0,4,1);
    local_6 = (undefined4 *)CONCAT22(in_DX,puVar5);
    *(int *)((int)puVar5 + 2) = in_DX;
    *(undefined4 **)local_6 = puVar5 + 2;
    puVar4 = (undefined2 *)*param_1;
    puVar3 = (undefined2 *)*puVar5;
    puVar7 = (undefined2 *)puVar3;
    for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar2 = puVar7;
      puVar7 = puVar7 + 1;
      puVar1 = puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = *puVar1;
    }
    FUN_1000_130c(*param_1);
    FUN_1000_130c(param_1);
    FUN_3e34_0085(puVar5,in_DX);
  }
  return (undefined2 *)0x0;
}

