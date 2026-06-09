// TIM2.EXE: FUN_3e34_0d3e @ file 0x04427E Ghidra 0x3F07E
// Subsystem: sound | Size: 395 bytes


void __cdecl16far FUN_3e34_0d3e(undefined4 param_1,char *param_2,uint param_3,int param_4)

{
  byte *pbVar1;
  char cVar2;
  undefined2 *puVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  byte *pbVar9;
  int iVar10;
  undefined2 *puVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  uint local_4;
  
  local_4 = 0;
  uVar4 = (param_3 >> 3) * param_4;
  uVar14 = (undefined2)((ulong)param_1 >> 0x10);
  iVar10 = (int)param_1;
  puVar11 = (undefined2 *)(iVar10 + uVar4 * 4);
  for (uVar6 = uVar4 >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
    puVar3 = puVar11;
    puVar11 = puVar11 + 1;
    *puVar3 = 0xffff;
  }
  if ((uVar4 & 1) != 0) {
    *(undefined1 *)puVar11 = 0xff;
  }
  uVar15 = (undefined2)((ulong)param_2 >> 0x10);
  cVar2 = *param_2;
  pbVar9 = (byte *)((char *)param_2 + 1);
  uVar6 = local_4;
  do {
    while( true ) {
      while( true ) {
        local_4 = uVar6;
        pbVar13 = pbVar9;
        pbVar9 = pbVar13 + 1;
        bVar5 = *pbVar13;
        uVar7 = bVar5 & 0x3f;
        if ((bVar5 & 0x80) != 0) break;
        if ((bVar5 & 0x40) == 0) {
          iVar10 = iVar10 + (param_3 >> 3);
          uVar6 = local_4 - uVar7;
          bVar5 = *pbVar9;
          if (((bVar5 & 0xc0) == 0) && (bVar5 != 0)) {
            pbVar9 = pbVar13 + 2;
            uVar6 = uVar6 + (uint)bVar5 * -0x40;
          }
        }
        else {
          if ((bVar5 & 0x3f) == 0) {
            return;
          }
          uVar6 = local_4 + uVar7;
        }
      }
      bVar8 = *(byte *)((local_4 & 7) + 0xd36);
      pbVar12 = (byte *)(iVar10 + (local_4 >> 3));
      if ((bVar5 & 0x40) != 0) break;
      bVar5 = *pbVar9 + cVar2 * '\x11';
      while( true ) {
        if ((bVar5 & 1) != 0) {
          *pbVar12 = *pbVar12 | bVar8;
        }
        pbVar12 = pbVar12 + uVar4;
        if ((bVar5 & 2) != 0) {
          *pbVar12 = *pbVar12 | bVar8;
        }
        pbVar12 = pbVar12 + uVar4;
        if ((bVar5 & 4) != 0) {
          *pbVar12 = *pbVar12 | bVar8;
        }
        if ((bVar5 & 8) != 0) {
          pbVar1 = pbVar12 + uVar4;
          *pbVar1 = *pbVar1 | bVar8;
        }
        pbVar12 = pbVar12 + uVar4 + uVar4;
        *pbVar12 = *pbVar12 ^ bVar8;
        local_4 = local_4 + 1;
        uVar7 = uVar7 - 1;
        pbVar9 = pbVar13 + 2;
        uVar6 = local_4;
        if (uVar7 == 0) break;
        bVar8 = bVar8 >> 1;
        if (bVar8 == 0) {
          bVar8 = 0x80;
          pbVar12 = pbVar12 + 1;
        }
        pbVar12 = pbVar12 + uVar4 * -4;
      }
    }
    while( true ) {
      pbVar1 = pbVar9;
      pbVar9 = pbVar9 + 1;
      bVar5 = *pbVar1 + cVar2 * '\x11';
      if ((bVar5 & 0x10) != 0) {
        *pbVar12 = *pbVar12 | bVar8;
      }
      pbVar12 = pbVar12 + uVar4;
      if ((bVar5 & 0x20) != 0) {
        *pbVar12 = *pbVar12 | bVar8;
      }
      pbVar12 = pbVar12 + uVar4;
      if ((bVar5 & 0x40) != 0) {
        *pbVar12 = *pbVar12 | bVar8;
      }
      if ((bVar5 & 0x80) != 0) {
        pbVar1 = pbVar12 + uVar4;
        *pbVar1 = *pbVar1 | bVar8;
      }
      pbVar13 = pbVar12 + uVar4 + uVar4;
      *pbVar13 = *pbVar13 ^ bVar8;
      uVar6 = local_4 + 1;
      if (uVar7 == 1) break;
      bVar8 = bVar8 >> 1;
      if (bVar8 == 0) {
        bVar8 = 0x80;
        pbVar13 = pbVar13 + 1;
      }
      pbVar13 = pbVar13 + uVar4 * -4;
      if ((bVar5 & 1) != 0) {
        *pbVar13 = *pbVar13 | bVar8;
      }
      pbVar13 = pbVar13 + uVar4;
      if ((bVar5 & 2) != 0) {
        *pbVar13 = *pbVar13 | bVar8;
      }
      pbVar13 = pbVar13 + uVar4;
      if ((bVar5 & 4) != 0) {
        *pbVar13 = *pbVar13 | bVar8;
      }
      if ((bVar5 & 8) != 0) {
        pbVar1 = pbVar13 + uVar4;
        *pbVar1 = *pbVar1 | bVar8;
      }
      pbVar12 = pbVar13 + uVar4 + uVar4;
      *pbVar12 = *pbVar12 ^ bVar8;
      local_4 = local_4 + 2;
      uVar7 = uVar7 - 2;
      uVar6 = local_4;
      if (uVar7 == 0) break;
      bVar8 = bVar8 >> 1;
      if (bVar8 == 0) {
        bVar8 = 0x80;
        pbVar12 = pbVar12 + 1;
      }
      pbVar12 = pbVar12 + uVar4 * -4;
    }
  } while( true );
}

