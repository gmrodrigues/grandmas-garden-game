// TIM2.EXE: FUN_1a9e_054d @ file 0x02012D Ghidra 0x1AF2D
// Subsystem: level | Size: 411 bytes


undefined2 __cdecl16near FUN_1a9e_054d(int param_1,undefined2 param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int local_4;
  
  if (param_1 < 4) {
    iVar2 = param_1 * 0xe;
    local_4 = 0x80;
    uVar9 = FUN_1a9e_0446(param_2);
    uVar7 = (uint)((ulong)uVar9 >> 0x10);
    if ((int)uVar9 == 0) {
      uVar3 = *(uint *)(iVar2 + 0x16a);
    }
    else {
      local_4 = *(int *)(iVar2 + 0x166);
      uVar3 = *(uint *)(iVar2 + 0x168);
    }
    *DAT_5b41_0042 = 0;
    if (local_4 == 0x80) {
      for (iVar2 = 0; (iVar2 < 4 && (((undefined2 *)&DAT_5b41_02dd)[iVar2] != 0)); iVar2 = iVar2 + 1
          ) {
      }
      if (iVar2 < 4) {
        puVar4 = (undefined1 *)&DAT_5b41_00dd + iVar2 * 0x80;
        ((undefined2 *)&DAT_5b41_02dd)[iVar2] = puVar4;
        *DAT_5b41_0042 = (int)puVar4;
        for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
      }
    }
    if (*DAT_5b41_0042 == 0) {
      iVar2 = FUN_1000_12bf(1,local_4);
      *DAT_5b41_0042 = iVar2;
      if (iVar2 == 0) goto LAB_1a9e_06d3;
    }
    piVar1 = DAT_5b41_0042;
    iVar2 = iRam00055624;
    iVar8 = iRam00055622;
    if (uVar3 != 0) {
      if (iRam00055622 == 0 && iRam00055624 == 0) {
        uVar5 = FUN_1a9e_539c(0xffff,0xffff,0,0);
        piVar1 = DAT_5b41_0042;
        if ((uVar7 < 0x8000) && ((0 < (int)uVar7 || (uVar3 + 0x20 < uVar5)))) {
          iVar8 = (uVar7 - (uVar5 < uVar3)) + -1 + (uint)(0x1f < uVar5 - uVar3);
          DAT_5b41_004d = FUN_1a9e_539c((uVar5 - uVar3) - 0x20,iVar8,0,0);
          DAT_5b41_004f = iVar8;
          iVar2 = FUN_1a9e_539c(uVar3,0,0,0);
          piVar1 = DAT_5b41_0042;
          DAT_5b41_0042[2] = iVar8;
          piVar1[1] = iVar2;
          FUN_1a9e_5415(DAT_5b41_004d,DAT_5b41_004f);
        }
        else {
          DAT_5b41_0042[2] = 0;
          piVar1[1] = 0;
        }
        iVar2 = DAT_5b41_0042[2];
        iVar8 = DAT_5b41_0042[1];
      }
      else {
        DAT_5b41_0042[2] = iRam00055624;
        piVar1[1] = iVar8;
      }
      DAT_5b41_004d = iVar8;
      DAT_5b41_004f = iVar2;
      if (DAT_5b41_0042[1] == 0 && DAT_5b41_0042[2] == 0) goto LAB_1a9e_06d3;
    }
    *(undefined1 *)(DAT_5b41_0042 + 0x10) = (undefined1)param_1;
    uVar6 = 0;
  }
  else {
LAB_1a9e_06d3:
    uVar6 = 0xffff;
  }
  return uVar6;
}

