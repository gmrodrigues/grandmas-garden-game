// TIM2.EXE: FUN_460e_1092 @ file 0x04C372 Ghidra 0x47172
// Subsystem: misc | Size: 642 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_460e_1092(uint param_1,code *param_2,int param_3)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined2 uVar7;
  uint local_a;
  int local_8;
  undefined4 local_6;
  
  uVar7 = 0x460e;
  if (DAT_5b41_1b90 == 0xf) {
    if ((DAT_5b41_1b94 & 4) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0xffff;
    }
    FUN_460e_174c(0,uVar2,param_1,1);
  }
  if (DAT_5b41_1b90 == 1) {
    if (DAT_5b41_1ae2 == (undefined2 *)0x0 && DAT_5b41_1ae4 == 0) {
      FUN_460e_194a(param_1);
    }
  }
  puVar5 = DAT_5b41_1c0e;
  iVar6 = DAT_5b41_1c10;
  if (DAT_5b41_1c1c != 0) {
    while (local_6 = (undefined2 *)CONCAT22(iVar6,puVar5), puVar5 != (undefined2 *)0x0 || iVar6 != 0
          ) {
      puVar5[0x12] = puVar5[0x12] & 0xfffb;
      piVar1 = puVar5 + 1;
      iVar6 = *piVar1;
      puVar5 = (undefined2 *)*local_6;
    }
    DAT_5b41_1c1c = 0;
  }
  puVar5 = DAT_5b41_1ae2;
  iVar6 = DAT_5b41_1ae4;
  if ((DAT_5b41_1ae2 != (undefined2 *)0x0 || DAT_5b41_1ae4 != 0) &&
     (DAT_5b41_1ae2[0x10] != 0 || DAT_5b41_1ae2[0x11] != 0)) {
    if ((DAT_5b41_1b84 < (int)DAT_5b41_1ae2[10]) ||
       ((((int)(DAT_5b41_1ae2[10] + DAT_5b41_1ae2[0xc]) <= DAT_5b41_1b84 ||
         (DAT_5b41_1b86 < (int)DAT_5b41_1ae2[0xb])) ||
        ((int)(DAT_5b41_1ae2[0xb] + DAT_5b41_1ae2[0xd]) <= DAT_5b41_1b86)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    DAT_5b41_1c1a = 0;
    _DAT_5b41_1c16 = _DAT_5b41_1ae2;
    uVar4 = (*(code *)DAT_5b41_1ae2[0x10])(0x460e,DAT_5b41_1ae2,DAT_5b41_1ae4,uVar2);
    if ((((uVar4 & 2) != 0) && (DAT_5b41_1c1a == 0)) && (param_2 != (code *)0x0 || param_3 != 0)) {
      (*param_2)(0x460e,puVar5[6]);
    }
    if ((uVar4 & 1) != 0) {
      return;
    }
  }
  local_a = 0;
  local_8 = 0;
  puVar5 = DAT_5b41_1c0e;
  iVar6 = DAT_5b41_1c10;
  do {
    if (((puVar5 == (undefined2 *)0x0 && iVar6 == 0) || ((uint)puVar5[8] < param_1)) ||
       ((*(byte *)(puVar5 + 0x12) & 4) != 0)) {
      return;
    }
    if ((((DAT_5b41_1b84 < (int)puVar5[10]) || ((int)(puVar5[10] + puVar5[0xc]) <= DAT_5b41_1b84))
        || (DAT_5b41_1b86 < (int)puVar5[0xb])) ||
       ((int)(puVar5[0xb] + puVar5[0xd]) <= DAT_5b41_1b86)) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
    }
    _DAT_5b41_1c16 = (undefined2 *)CONCAT22(iVar6,puVar5);
    DAT_5b41_1c1a = 0;
    if (((puVar5[9] != 0) && (iVar3 != 0)) &&
       (((*(byte *)(puVar5 + 0x12) & 8) == 0 &&
        ((puVar5[8] != local_8 || (local_a < (uint)puVar5[6])))))) {
      uVar7 = 0x406b;
      FUN_406b_03cb(puVar5[9],puVar5[8]);
      local_8 = puVar5[8];
      local_a = puVar5[6];
    }
    if ((((iVar6 != DAT_5b41_1ae4) || (puVar5 != DAT_5b41_1ae2)) &&
        ((*(byte *)(puVar5 + 0x12) & 8) == 0)) &&
       (((iVar3 != 0 && ((DAT_5b41_1b88 & 6) != 0)) || ((*(byte *)(puVar5 + 0x12) & 1) != 0)))) {
      if (puVar5[0x10] == 0 && puVar5[0x11] == 0) {
        uVar4 = 2;
      }
      else {
        uVar4 = (*(code *)puVar5[0x10])(uVar7,puVar5,iVar6,iVar3);
      }
      if ((((uVar4 & 2) != 0) && (DAT_5b41_1c1a == 0)) && (param_2 != (code *)0x0 || param_3 != 0))
      {
        (*param_2)(uVar7,puVar5[6]);
      }
      if ((uVar4 & 1) != 0) {
        return;
      }
    }
    puVar5 = DAT_5b41_1c0e;
    iVar6 = DAT_5b41_1c10;
    if (DAT_5b41_1c16 != (undefined2 *)0x0 || DAT_5b41_1c18 != 0) {
      puVar5 = (undefined2 *)*_DAT_5b41_1c16;
      iVar6 = DAT_5b41_1c16[1];
    }
  } while( true );
}

