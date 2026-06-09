// TIM2.EXE: FUN_31f7_1a9b @ file 0x038C0B Ghidra 0x33A0B
// Subsystem: misc | Size: 491 bytes


void __cdecl16far FUN_31f7_1a9b(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_DX;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = (int)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  if (DAT_5b41_1990 <= *(int *)(iVar5 + 0x10)) {
    if (*(int *)(iVar5 + 0x10) != DAT_5b41_1992) {
      *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 1;
    }
    goto LAB_31f7_1b89;
  }
  if ((((*(int *)(iVar5 + 0x16) != 0) &&
       (iVar2 = FUN_28eb_3783(iVar5,iVar6), iVar2 != 0 || in_DX != 0)) &&
      ((*(int *)(iVar2 + 8) == 0xe || (*(int *)(iVar2 + 8) == 0x56)))) &&
     (*(int *)(iVar2 + 0x12) == *(int *)(iVar2 + 0x14))) {
    *(undefined2 *)(iVar5 + 0x16) = 0;
  }
  if (*(int *)(iVar5 + 0x16) == 0) goto LAB_31f7_1b89;
  if ((*(byte *)(iVar5 + 0xc) & 0x10) == 0) {
    if (-1 < *(int *)(iVar5 + 0x16)) goto LAB_31f7_1b33;
LAB_31f7_1b2a:
    *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + -1;
  }
  else {
    if (-1 < *(int *)(iVar5 + 0x16)) goto LAB_31f7_1b2a;
LAB_31f7_1b33:
    *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 1;
  }
  iVar2 = DAT_5b41_198e;
  if (*(int *)(iVar5 + 0x10) == DAT_5b41_1990) {
LAB_31f7_1b5a:
    *(int *)(iVar5 + 0x10) = iVar2;
    *(int *)(iVar5 + 0xae) = *(int *)(iVar5 + 0xae) + 1;
  }
  else if (*(int *)(iVar5 + 0x10) < 1) {
    iVar2 = DAT_5b41_1990 + -1;
    goto LAB_31f7_1b5a;
  }
  uVar4 = (int)*(uint *)(iVar5 + 0x16) >> 0xf;
  if (8 >> ((byte)((int)((*(uint *)(iVar5 + 0x16) ^ uVar4) - uVar4) >> 1) & 0x1f) <=
      *(int *)(iVar5 + 0xae)) {
    *(int *)(iVar5 + 0x10) = DAT_5b41_1990;
  }
LAB_31f7_1b89:
  if ((DAT_5b41_1990 <= *(int *)(iVar5 + 0x10)) && (*(int *)(iVar5 + 0x10) <= DAT_5b41_1990 + 2)) {
    FUN_28eb_51b3(iVar5,iVar6,0x3000,0,0x1f,
                  *(undefined2 *)((*(int *)(iVar5 + 0x10) - DAT_5b41_1990) * 2 + 0x3a50),0);
    FUN_31f7_b9f5(iVar5,iVar6,0,0,0x1f,
                  *(undefined2 *)((*(int *)(iVar5 + 0x10) - DAT_5b41_1990) * 2 + 0x3a50),0);
    iVar2 = iVar5;
    iVar7 = iVar6;
    while( true ) {
      iVar1 = *(int *)(iVar2 + 0x8e);
      iVar2 = *(int *)(iVar2 + 0x8c);
      if (iVar2 == 0 && iVar1 == 0) break;
      iVar7 = iVar1;
      if ((*(byte *)(iVar2 + 0xb) & 0x10) != 0) {
        iVar3 = FUN_31f7_1ccd(iVar2,iVar1);
        if ((*(byte *)(iVar5 + 0xc) & 0x10) == 0) {
          *(int *)(iVar2 + 0x3a) = -iVar3;
        }
        else {
          *(int *)(iVar2 + 0x3a) = iVar3;
        }
        *(int *)(iVar2 + 0x3c) = -iVar3;
        if ((*(int *)(iVar2 + 8) == 0x36) && (*(int *)(iVar2 + 0x10) < DAT_5b41_09a3)) {
          *(int *)(iVar2 + 0x10) = DAT_5b41_09a3;
        }
      }
    }
  }
  if (*(int *)(iVar5 + 0x10) != *(int *)(iVar5 + 0x12)) {
    FUN_28eb_3328(iVar5,iVar6);
  }
  return;
}

