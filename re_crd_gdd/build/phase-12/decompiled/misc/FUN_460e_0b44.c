// TIM2.EXE: FUN_460e_0b44 @ file 0x04BE24 Ghidra 0x46C24
// Subsystem: misc | Size: 525 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl16far FUN_460e_0b44(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined2 uVar8;
  undefined4 local_a;
  
  iVar6 = 0;
  if ((int *)param_1 != (int *)0x0 || param_1._2_2_ != 0) {
    if (*param_1 == 0 && ((int *)param_1)[1] == 0) {
      local_a = _DAT_5b41_1c0e;
      uVar7 = 1;
      while( true ) {
        if ((int *)local_a == (int *)0x0 && local_a._2_2_ == 0) break;
        if (((int *)param_1)[6] == ((int *)local_a)[6]) {
          return 0;
        }
        if (uVar7 <= (uint)((int *)local_a)[6]) {
          uVar7 = ((int *)local_a)[6] + 1;
        }
        local_a = (int *)CONCAT22(((int *)local_a)[1],(int *)*local_a);
      }
      if (((int *)param_1)[6] == 0) {
        ((int *)param_1)[6] = uVar7;
      }
      ((int *)param_1)[0x12] = ((int *)param_1)[0x12] | 4;
      DAT_5b41_1c1c = 1;
      piVar5 = DAT_5b41_1c0e;
      for (iVar6 = DAT_5b41_1c10;
          ((local_a = (int *)CONCAT22(iVar6,piVar5), piVar5 != (int *)0x0 || iVar6 != 0 &&
           ((uint)((int *)param_1)[8] <= (uint)piVar5[8])) &&
          ((piVar5[8] != ((int *)param_1)[8] || ((uint)((int *)param_1)[6] <= (uint)piVar5[6]))));
          iVar6 = *piVar1) {
        piVar1 = piVar5 + 1;
        piVar5 = (int *)*local_a;
      }
      if ((iVar6 == DAT_5b41_1c10) && (piVar5 == DAT_5b41_1c0e)) {
        ((int *)param_1)[3] = 0;
        ((int *)param_1)[2] = 0;
        piVar5 = DAT_5b41_1c0e;
        ((int *)param_1)[1] = DAT_5b41_1c10;
        *param_1 = (int)piVar5;
        if (piVar5 == (int *)0x0 && DAT_5b41_1c10 == 0) {
          _DAT_5b41_1c12 = param_1;
        }
        else {
          ((int *)_DAT_5b41_1c0e)[3] = param_1._2_2_;
          ((int *)_DAT_5b41_1c0e)[2] = (int)(int *)param_1;
        }
        _DAT_5b41_1c0e = param_1;
      }
      else if (piVar5 == (int *)0x0 && iVar6 == 0) {
        piVar5 = DAT_5b41_1c12;
        ((int *)param_1)[3] = DAT_5b41_1c14;
        ((int *)param_1)[2] = (int)piVar5;
        ((int *)param_1)[1] = 0;
        *param_1 = 0;
        ((int *)_DAT_5b41_1c12)[1] = param_1._2_2_;
        *_DAT_5b41_1c12 = (int)(int *)param_1;
        _DAT_5b41_1c12 = param_1;
      }
      else {
        iVar2 = piVar5[2];
        ((int *)param_1)[3] = piVar5[3];
        ((int *)param_1)[2] = iVar2;
        ((int *)param_1)[1] = iVar6;
        *param_1 = (int)piVar5;
        puVar3 = *(undefined2 **)((int *)param_1 + 2);
        ((undefined2 *)puVar3)[1] = param_1._2_2_;
        *puVar3 = (int *)param_1;
        uVar8 = (undefined2)((ulong)*(undefined4 *)param_1 >> 0x10);
        iVar6 = (int)*(undefined4 *)param_1;
        *(int *)(iVar6 + 6) = param_1._2_2_;
        *(undefined2 *)(iVar6 + 4) = (int *)param_1;
      }
      iVar6 = 1;
    }
    else {
      while( true ) {
        if ((int *)param_1 == (int *)0x0 && param_1._2_2_ == 0) break;
        iVar2 = ((int *)param_1)[1];
        piVar5 = (int *)*param_1;
        ((int *)param_1)[1] = 0;
        *param_1 = 0;
        iVar4 = FUN_460e_0b44((int *)param_1,param_1._2_2_);
        iVar6 = iVar4 + iVar6;
        param_1 = (int *)CONCAT22(iVar2,piVar5);
      }
    }
  }
  return iVar6;
}

