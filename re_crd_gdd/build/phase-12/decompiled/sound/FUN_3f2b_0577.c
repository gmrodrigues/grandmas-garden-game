// TIM2.EXE: FUN_3f2b_0577 @ file 0x044A27 Ghidra 0x3F827
// Subsystem: sound | Size: 293 bytes


int __cdecl16far FUN_3f2b_0577(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_DX;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  int local_e;
  undefined4 local_a;
  undefined4 local_6;
  
  if (DAT_5b41_1b42 != (int *)0x0 || DAT_5b41_1b44 != 0) {
    local_e = 0;
    puVar2 = (undefined1 *)FUN_4340_0caf(param_1,param_2,0x5c);
    local_a = (undefined1 *)CONCAT22(in_DX,puVar2);
    if (puVar2 == (undefined1 *)0x0 && in_DX == 0) {
      iVar6 = FUN_4340_0caf(param_1,param_2,0x3a);
      if (iVar6 != 0 || in_DX != 0) {
        local_a = (undefined1 *)CONCAT22(in_DX,(undefined1 *)(iVar6 + 1));
        uVar1 = *local_a;
        *local_a = 0;
        local_e = FUN_460e_071e(0x5fc3,param_1,param_2);
        *local_a = uVar1;
        param_1 = (undefined1 *)(iVar6 + 1);
        param_2 = in_DX;
      }
    }
    else {
      *local_a = 0;
      local_e = FUN_460e_071e(0x5fc3,param_1,param_2);
      *local_a = 0x5c;
      param_1 = puVar2 + 1;
      param_2 = in_DX;
    }
    uVar3 = FUN_460e_071e(0x5fc4,param_1,param_2);
    if (uVar3 != 0) {
      local_6 = (int *)CONCAT22(DAT_5b41_1b44,DAT_5b41_1b42);
      iVar6 = 0;
      while( true ) {
        iVar5 = DAT_5b41_1b46;
        if ((int *)local_6 == (int *)0x0 && local_6._2_2_ == 0) break;
        while( true ) {
          piVar4 = (int *)local_6;
          uVar7 = (undefined2)((ulong)local_6 >> 0x10);
          if (iVar5 == 0) break;
          iVar6 = iVar6 + 1;
          if ((*local_6 == local_e) && ((piVar4[1] & 0x7fffU) == uVar3)) {
            return iVar6;
          }
          local_6 = (int *)CONCAT22(uVar7,piVar4 + 9);
          iVar5 = iVar5 + -1;
        }
        local_6 = (int *)CONCAT22(piVar4[1],(int *)*local_6);
      }
    }
  }
  return 0;
}

