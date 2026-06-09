// TIM2.EXE: FUN_1a9e_0b56 @ file 0x020736 Ghidra 0x1B536
// Subsystem: level | Size: 242 bytes


void __cdecl16near FUN_1a9e_0b56(void)

{
  uint *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined2 uVar14;
  undefined2 unaff_SS;
  undefined2 uVar15;
  bool bVar16;
  
  uVar10 = 0;
  DAT_554c_402a = DAT_5b41_0044 + (uint)*(byte *)(DAT_5b41_0042 + 0x1a);
  uVar8 = 0xffff;
  if (*(int *)(DAT_5b41_0042 + 0x10) - *(int *)(DAT_5b41_0042 + 0xc) ==
      (uint)(*(uint *)(DAT_5b41_0042 + 0xe) < *(uint *)(DAT_5b41_0042 + 10))) {
    uVar8 = *(uint *)(DAT_5b41_0042 + 0xe) - *(uint *)(DAT_5b41_0042 + 10);
  }
  uVar14 = (undefined2)((ulong)DAT_5b41_0049 >> 0x10);
  pbVar13 = (byte *)DAT_5b41_0049;
  uVar15 = (undefined2)((ulong)DAT_5b41_02eb >> 0x10);
  pbVar11 = (byte *)DAT_5b41_02eb;
  uVar9 = DAT_5b41_02e7;
  if ((DAT_5b41_02e9 & 0x40) == 0) {
    do {
      while( true ) {
        if (uVar10 == uVar8) goto LAB_1a9e_0bda;
        pbVar12 = pbVar11 + 1;
        bVar5 = *pbVar11;
        if (-1 < (char)bVar5) break;
        uVar6 = (uint)(bVar5 & 0x7f);
        pbVar11 = pbVar11 + 2;
        bVar5 = *pbVar12;
        uVar10 = uVar10 + 2;
        bVar16 = uVar9 < uVar6;
        uVar9 = uVar9 - uVar6;
        if (bVar16) goto LAB_1a9e_0bf6;
      }
      uVar6 = (uint)(bVar5 & 0x7f);
      uVar10 = uVar10 + uVar6 + 1;
      pbVar11 = pbVar12 + uVar6;
      bVar16 = uVar6 <= uVar9;
      uVar9 = uVar9 - uVar6;
      pbVar12 = pbVar11;
    } while (bVar16);
LAB_1a9e_0c33:
    uVar9 = uVar9 + uVar6;
    *(byte **)(undefined4 *)&DAT_5b41_0049 = pbVar13;
    pbVar11 = (byte *)*(undefined2 *)&DAT_554c_402a;
    for (uVar8 = uVar6; uVar8 != 0; uVar8 = uVar8 - 1) {
      pbVar3 = pbVar11;
      pbVar11 = pbVar11 + 1;
      pbVar2 = pbVar12;
      pbVar12 = pbVar12 + 1;
      *pbVar3 = *pbVar2;
    }
  }
  else {
    while (uVar10 != uVar8) {
      pbVar12 = pbVar11 + 1;
      bVar5 = *pbVar11;
      if ((char)bVar5 < '\0') {
        uVar6 = (uint)(bVar5 & 0x7f);
        pbVar11 = pbVar11 + 2;
        bVar5 = *pbVar12;
        uVar10 = uVar10 + 2;
        bVar16 = uVar9 < uVar6;
        uVar9 = uVar9 - uVar6;
        if (bVar16) goto LAB_1a9e_0bf6;
        if (((uint)pbVar13 & 1) != 0) {
          pbVar2 = pbVar13;
          pbVar13 = pbVar13 + 1;
          *pbVar2 = bVar5;
          uVar6 = uVar6 - 1;
        }
        for (uVar7 = uVar6 >> 1; uVar7 != 0; uVar7 = uVar7 - 1) {
          pbVar2 = pbVar13;
          pbVar13 = pbVar13 + 2;
          *(uint *)pbVar2 = CONCAT11(bVar5,bVar5);
        }
        for (uVar6 = (uint)((uVar6 & 1) != 0); uVar6 != 0; uVar6 = uVar6 - 1) {
          pbVar2 = pbVar13;
          pbVar13 = pbVar13 + 1;
          *pbVar2 = bVar5;
        }
      }
      else {
        uVar6 = (uint)(bVar5 & 0x7f);
        uVar10 = uVar10 + uVar6 + 1;
        bVar16 = uVar9 < uVar6;
        uVar9 = uVar9 - uVar6;
        if (bVar16) goto LAB_1a9e_0c33;
        if (((uint)pbVar13 & 1) != 0) {
          pbVar2 = pbVar13;
          pbVar13 = pbVar13 + 1;
          *pbVar2 = *pbVar12;
          uVar6 = uVar6 - 1;
          pbVar12 = pbVar11 + 2;
        }
        pbVar11 = pbVar12;
        for (uVar7 = uVar6 >> 1; uVar7 != 0; uVar7 = uVar7 - 1) {
          pbVar3 = pbVar13;
          pbVar13 = pbVar13 + 2;
          pbVar2 = pbVar11;
          pbVar11 = pbVar11 + 2;
          *(undefined2 *)pbVar3 = *(undefined2 *)pbVar2;
        }
        for (uVar6 = (uint)((uVar6 & 1) != 0); uVar6 != 0; uVar6 = uVar6 - 1) {
          pbVar3 = pbVar13;
          pbVar13 = pbVar13 + 1;
          pbVar2 = pbVar11;
          pbVar11 = pbVar11 + 1;
          *pbVar3 = *pbVar2;
        }
      }
    }
LAB_1a9e_0bda:
    uVar6 = 0;
  }
LAB_1a9e_0c0a:
  iVar4 = *(int *)&DAT_5b41_0042;
  *(char *)(iVar4 + 0x1a) = *(char *)(iVar4 + 0x1a) + (char)uVar6;
  *(uint *)&DAT_5b41_02e7 = uVar9;
  puVar1 = (uint *)(iVar4 + 10);
  uVar8 = *puVar1;
  *puVar1 = *puVar1 + uVar10;
  *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + (uint)CARRY2(uVar8,uVar10);
  return;
LAB_1a9e_0bf6:
  uVar9 = uVar9 + uVar6;
  *(byte **)(undefined4 *)&DAT_5b41_0049 = pbVar13;
  pbVar11 = (byte *)*(undefined2 *)&DAT_554c_402a;
  for (uVar8 = uVar6; uVar8 != 0; uVar8 = uVar8 - 1) {
    pbVar2 = pbVar11;
    pbVar11 = pbVar11 + 1;
    *pbVar2 = bVar5;
  }
  goto LAB_1a9e_0c0a;
}

