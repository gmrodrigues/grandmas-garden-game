// TIM2.EXE: FUN_3f2b_0220 @ file 0x0446D0 Ghidra 0x3F4D0
// Subsystem: sound | Size: 527 bytes


int __cdecl16far
FUN_3f2b_0220(undefined1 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
             int param_7)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int in_DX;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined2 uVar10;
  int local_12;
  undefined2 local_e;
  undefined4 local_a;
  undefined4 local_6;
  
  if ((((DAT_5b41_1b42 != 0 || DAT_5b41_1b44 != 0) ||
       (iVar2 = FUN_3f2b_0000(0x100,10,0x100,9,0), iVar2 != 0)) &&
      (param_1 != (undefined1 *)0x0 || param_2 != 0)) &&
     ((param_3 == 0 && param_4 == 0 || (param_5 == 0)))) {
    local_12 = 0;
    do {
      local_12 = local_12 + 1;
      puVar3 = (undefined2 *)FUN_3f2b_0b8e(local_12,1);
      local_6 = (undefined2 *)CONCAT22(in_DX,puVar3);
      if (puVar3 == (undefined2 *)0x0 && in_DX == 0) break;
    } while (puVar3[1] != 0);
    uVar8 = 0xffff;
    iVar2 = in_DX;
    for (uVar7 = 0; uVar9 = uVar8, uVar7 < DAT_5b41_1b4a; uVar7 = uVar7 + 1) {
      uVar10 = (undefined2)((ulong)DAT_5b41_1b3e >> 0x10);
      piVar6 = (int *)((int)DAT_5b41_1b3e + uVar7 * 4);
      iVar2 = piVar6[1];
      if ((iVar2 == param_7) && (uVar9 = uVar7, *piVar6 == param_6)) break;
      if ((uVar8 == 0xffff) &&
         ((uVar7 != 0 &&
          (piVar6 = (int *)((int)DAT_5b41_1b3e + uVar7 * 4), *piVar6 == 0 && piVar6[1] == 0)))) {
        uVar8 = uVar7;
      }
    }
    if (uVar9 != 0xffff) {
      local_e = 0;
      puVar4 = (undefined1 *)FUN_4340_0caf(param_1,param_2,0x5c);
      local_a = (undefined1 *)CONCAT22(iVar2,puVar4);
      if (puVar4 == (undefined1 *)0x0 && iVar2 == 0) {
        iVar5 = FUN_4340_0caf(param_1,param_2,0x3a);
        if (iVar5 != 0 || iVar2 != 0) {
          local_a = (undefined1 *)CONCAT22(iVar2,(undefined1 *)(iVar5 + 1));
          uVar1 = *local_a;
          *local_a = 0;
          local_e = FUN_460e_0290(0x5fc3,0,param_1,param_2);
          *local_a = uVar1;
          param_1 = (undefined1 *)(iVar5 + 1);
          param_2 = iVar2;
        }
      }
      else {
        *local_a = 0;
        local_e = FUN_460e_0290(0x5fc3,0,param_1,param_2);
        *local_a = 0x5c;
        param_1 = puVar4 + 1;
        param_2 = iVar2;
      }
      iVar2 = FUN_460e_0290(0x5fc4,0,param_1,param_2);
      if (iVar2 != 0) {
        uVar10 = (undefined2)((ulong)DAT_5b41_1b3e >> 0x10);
        piVar6 = (int *)((int)DAT_5b41_1b3e + uVar9 * 4);
        piVar6[1] = param_7;
        *piVar6 = param_6;
        puVar3[6] = 0;
        puVar3[5] = 1;
        *local_6 = local_e;
        puVar3[1] = iVar2;
        puVar3[2] = uVar9;
        iVar2 = DAT_5b41_1b4c + 1;
        DAT_5b41_1b4e = DAT_5b41_1b4e + (uint)(0xfffe < DAT_5b41_1b4c);
        DAT_5b41_1b4c = iVar2;
        puVar3[4] = DAT_5b41_1b4e;
        puVar3[3] = iVar2;
        if (param_3 != 0 || param_4 != 0) {
          puVar3[8] = param_4;
          puVar3[7] = param_3;
          return local_12;
        }
        puVar3[8] = 0;
        puVar3[7] = 0;
        puVar3[7] = param_5;
        return local_12;
      }
    }
  }
  return 0;
}

