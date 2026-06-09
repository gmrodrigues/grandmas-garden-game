// TIM2.EXE: FUN_2424_2fbd @ file 0x02C3FD Ghidra 0x271FD
// Subsystem: misc | Size: 555 bytes


void __cdecl16far FUN_2424_2fbd(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  undefined2 uVar13;
  
  uVar1 = DAT_5b41_0505 & 3;
  uVar13 = (undefined2)((ulong)param_1 >> 0x10);
  piVar12 = (int *)param_1;
  if (piVar12[2] < 1) {
    iVar9 = piVar12[2] + *param_1;
  }
  else {
    iVar9 = *param_1;
  }
  uVar10 = piVar12[2] >> 0xf;
  iVar2 = ((piVar12[2] ^ uVar10) - uVar10) + iVar9;
  iVar3 = iVar2 + -1;
  if (piVar12[3] < 1) {
    iVar8 = piVar12[1] + piVar12[3];
  }
  else {
    iVar8 = piVar12[1];
  }
  uVar10 = piVar12[3] >> 0xf;
  iVar4 = ((piVar12[3] ^ uVar10) - uVar10) + iVar8;
  iVar5 = iVar4 + -1;
  DAT_554c_42c3 = 1;
  DAT_554c_42c4 = iVar9;
  if (iVar9 < DAT_5b41_051b) {
    DAT_554c_42c4 = DAT_5b41_051b;
  }
  DAT_554c_42c6 = iVar3;
  if (DAT_5b41_051d < iVar3) {
    DAT_554c_42c6 = DAT_5b41_051d;
  }
  DAT_554c_42c8 = iVar8;
  if (iVar8 < DAT_5b41_0517) {
    DAT_554c_42c8 = DAT_5b41_0517;
  }
  DAT_554c_42ca = iVar5;
  if (DAT_5b41_0519 < iVar5) {
    DAT_554c_42ca = DAT_5b41_0519;
  }
  if ((DAT_554c_42c4 <= DAT_554c_42c6) && (DAT_554c_42c8 <= DAT_554c_42ca)) {
    iVar6 = FUN_3e34_0ad5(DAT_5b41_0523,param_2 + 3);
    uVar11 = uVar10;
    for (iVar7 = iVar8 - (4 - uVar1); iVar7 < iVar5; iVar7 = iVar7 + *(int *)(iVar6 + 8)) {
      FUN_3e34_0ec9(iVar6,uVar10,iVar9,iVar7,0,*(undefined2 *)(iVar6 + 6),*(undefined2 *)(iVar6 + 8)
                   );
    }
    iVar6 = FUN_3e34_0ad5(DAT_5b41_0523,param_2);
    uVar10 = uVar11;
    for (iVar7 = iVar9 - uVar1; iVar7 < iVar3; iVar7 = iVar7 + *(int *)(iVar6 + 6)) {
      FUN_3e34_0ec9(iVar6,uVar11,iVar7,iVar8,0,*(undefined2 *)(iVar6 + 6),*(undefined2 *)(iVar6 + 8)
                   );
    }
    iVar6 = FUN_3e34_0ad5(DAT_5b41_0523,param_2 + 3);
    DAT_554c_42c6 = DAT_554c_42c6 + 1;
    uVar11 = uVar10;
    for (iVar8 = iVar8 - uVar1; iVar8 < iVar5; iVar8 = iVar8 + *(int *)(iVar6 + 8)) {
      FUN_3e34_0ec9(iVar6,uVar10,iVar2 + -2,iVar8,0,*(undefined2 *)(iVar6 + 6),
                    *(undefined2 *)(iVar6 + 8));
    }
    DAT_554c_42c6 = DAT_554c_42c6 + -1;
    iVar2 = FUN_3e34_0ad5(DAT_5b41_0523,param_2);
    for (iVar9 = iVar9 - (4 - uVar1); iVar9 < iVar3; iVar9 = iVar9 + *(int *)(iVar2 + 6)) {
      FUN_3e34_0ec9(iVar2,uVar11,iVar9,iVar4 + -2,0,*(undefined2 *)(iVar2 + 6),
                    *(undefined2 *)(iVar2 + 8));
    }
  }
  FUN_2424_02ca();
  return;
}

