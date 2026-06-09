// TIM2.EXE: FUN_1000_3964 @ file 0x018B64 Ghidra 0x13964
// Subsystem: utility | Size: 502 bytes


/* WARNING: Removing unreachable block (ram,0x00013ae2) */
/* WARNING: Removing unreachable block (ram,0x00013a1a) */
/* WARNING: Removing unreachable block (ram,0x00013b45) */

void __cdecl16far FUN_1000_3964(uint param_1,int param_2,byte *param_3,undefined1 *param_4)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined4 uVar8;
  long lVar9;
  long lVar10;
  
  FUN_1000_554f();
  iVar4 = param_1 - (DAT_554c_5e28 + 0xa600);
  iVar1 = (param_2 - (DAT_554c_5e2a + 0x12ce + (uint)(0x59ff < DAT_554c_5e28))) -
          (uint)(param_1 < DAT_554c_5e28 + 0xa600);
  param_4[2] = 0;
  uVar3 = FUN_1000_18fc(iVar4,iVar1,0x3c,0);
  param_4[3] = uVar3;
  uVar8 = FUN_1000_18ed(iVar4,iVar1,0x3c,0);
  uVar3 = FUN_1000_18fc(uVar8,0x3c,0);
  *param_4 = uVar3;
  uVar8 = FUN_1000_18ed(uVar8,0x3c,0);
  iVar4 = FUN_1000_18ed(uVar8,0x88f8,0);
  *(int *)param_3 = iVar4 * 4 + 0x7bc;
  lVar9 = FUN_1000_18fc(uVar8,0x88f8,0);
  if (0x224f < lVar9) {
    iVar4 = (uint)lVar9 + 0xddb0;
    iVar1 = (int)((ulong)lVar9 >> 0x10) - (uint)((uint)lVar9 < 0x2250);
    *(int *)param_3 = *(int *)param_3 + 1;
    iVar5 = FUN_1000_18ed(iVar4,iVar1,0x2238,0);
    *(int *)param_3 = *(int *)param_3 + iVar5;
    lVar9 = FUN_1000_18fc(iVar4,iVar1,0x2238,0);
  }
  if (DAT_554c_5e2c != 0) {
    uVar6 = FUN_1000_18fc(lVar9,0x18,0);
    uVar7 = FUN_1000_18ed(lVar9,0x18,0,uVar6);
    iVar4 = FUN_1000_570b(*(int *)param_3 + -0x7b2,0,uVar7,uVar6);
    if (iVar4 != 0) {
      lVar9 = lVar9 + 1;
    }
  }
  uVar3 = FUN_1000_18fc(lVar9,0x18,0);
  param_4[1] = uVar3;
  lVar10 = FUN_1000_18ed(lVar9,0x18,0);
  lVar9 = lVar10 + 1;
  if ((*param_3 & 3) == 0) {
    if (lVar9 < 0x3d) {
      if (lVar9 == 0x3c) {
        param_3[3] = 2;
        param_3[2] = 0x1d;
        return;
      }
    }
    else {
      lVar9 = CONCAT22((int)((ulong)lVar9 >> 0x10) - (uint)((int)lVar9 == 0),(int)lVar10);
    }
  }
  param_3[3] = 0;
  for (; (int)*(char *)((char)param_3[3] + 0x5b7e) < lVar9; lVar9 = lVar9 - (int)cVar2) {
    cVar2 = *(char *)((char)param_3[3] + 0x5b7e);
    param_3[3] = param_3[3] + 1;
  }
  param_3[3] = param_3[3] + 1;
  param_1._0_1_ = (byte)lVar9;
  param_3[2] = (byte)param_1;
  return;
}

