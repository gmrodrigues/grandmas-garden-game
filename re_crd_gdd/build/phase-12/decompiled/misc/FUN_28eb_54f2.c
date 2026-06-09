// TIM2.EXE: FUN_28eb_54f2 @ file 0x0335A2 Ghidra 0x2E3A2
// Subsystem: misc | Size: 174 bytes


void __cdecl16far FUN_28eb_54f2(undefined2 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 *puVar10;
  int iVar11;
  undefined2 *puVar12;
  int iVar13;
  undefined4 local_10;
  
  iVar13 = (int)((ulong)param_1 >> 0x10);
  puVar12 = (undefined2 *)param_1;
  if ((puVar12[4] == 0x11) || (puVar12[4] == 0x6c)) {
    puVar12[0x47] = 0;
    puVar12[0x46] = 0;
    iVar6 = puVar12[0x13] + 4;
    iVar7 = puVar12[0x13] + 0x20;
    iVar1 = puVar12[0x14];
    iVar2 = puVar12[0x25];
    iVar3 = puVar12[0x12];
    puVar10 = DAT_5b41_0557;
    iVar11 = DAT_5b41_0559;
    while (local_10 = (undefined2 *)CONCAT22(iVar11,puVar10),
          puVar10 != (undefined2 *)0x0 || iVar11 != 0) {
      if ((((iVar13 != iVar11) || (puVar12 != puVar10)) &&
          ((*(byte *)((int)puVar10 + 0xd) & 0x20) == 0)) &&
         (((*(byte *)((int)puVar10 + 0xf) & 0x40) == 0 && (puVar10[4] != 0xb)))) {
        if (puVar10[4] == 0x24) {
          iVar8 = puVar10[0x13] + 0x2a;
          iVar9 = puVar10[0x14] + 0x3d;
        }
        else if (puVar10[4] == 0x46) {
          iVar8 = puVar10[0x13] + 0x2f;
          iVar9 = puVar10[0x14] + 0x4a;
        }
        else {
          iVar8 = puVar10[0x13] + ((int)puVar10[0x24] >> 1);
          iVar9 = puVar10[0x14] + puVar10[0x25];
        }
        bVar5 = false;
        if (((puVar10[0x4d] != 0 || puVar10[0x4e] != 0) && (puVar10[0x4e] == iVar13)) &&
           (((undefined2 *)puVar10[0x4d] == puVar12 &&
            (((0 < (int)puVar10[0x1e] && (iVar6 < iVar8)) && (iVar8 < iVar7)))))) {
          bVar5 = true;
        }
        if (((!bVar5) && (iVar6 < iVar8)) &&
           ((iVar8 < iVar7 && ((iVar1 + 0x14 < iVar9 && (iVar9 + -4 < iVar2 + iVar1)))))) {
          bVar5 = true;
        }
        if (bVar5) {
          uVar4 = puVar12[0x46];
          puVar10[0x47] = puVar12[0x47];
          puVar10[0x46] = uVar4;
          puVar12[0x47] = iVar11;
          puVar12[0x46] = puVar10;
          puVar10[7] = puVar10[7] | 0x10;
          uVar4 = puVar12[0x1d];
          puVar10[0x1e] = puVar12[0x1e];
          puVar10[0x1d] = uVar4;
          puVar10[0x57] = iVar3 + 0x14;
        }
      }
      iVar11 = puVar10[1];
      puVar10 = (undefined2 *)*local_10;
    }
  }
  return;
}

