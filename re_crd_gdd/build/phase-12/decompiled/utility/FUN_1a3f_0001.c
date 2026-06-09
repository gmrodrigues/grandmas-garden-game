// TIM2.EXE: FUN_1a3f_0001 @ file 0x01F5F1 Ghidra 0x1A3F1
// Subsystem: utility | Size: 484 bytes


void __cdecl16far FUN_1a3f_0001(int param_1)

{
  bool bVar1;
  bool bVar2;
  byte *pbVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  undefined2 in_DX;
  undefined2 uVar8;
  undefined2 unaff_SS;
  undefined1 *puVar9;
  byte local_86 [128];
  byte *local_6;
  int iVar10;
  
  iVar5 = FUN_1000_418e(0xaf,0xd4);
  if (iVar5 == 0) {
LAB_1a3f_01d6:
    puVar9 = (undefined1 *)0xa2;
  }
  else {
    do {
      do {
        if ((*(byte *)(iVar5 + 2) & 0x20) != 0) {
          FUN_1000_3d77(iVar5);
          goto LAB_1a3f_01d6;
        }
        _local_6 = (byte *)CONCAT22(unaff_SS,local_86);
        do {
          if ((*(byte *)(iVar5 + 2) & 0x20) != 0) break;
          bVar4 = FUN_1000_4820(iVar5);
          pbVar3 = _local_6;
          iVar10 = (int)((ulong)_local_6 >> 0x10);
          _local_6 = (byte *)CONCAT22(iVar10,local_6 + 1);
          *pbVar3 = bVar4;
        } while (bVar4 != 10);
        while ((local_86 < local_6 &&
               (uVar8 = (undefined2)((ulong)_local_6 >> 0x10), local_6[-1] < 0x21))) {
          _local_6 = (byte *)CONCAT22(uVar8,local_6 + -1);
        }
        *_local_6 = 0;
        _local_6 = (byte *)CONCAT22(unaff_SS,local_86);
        while( true ) {
          pbVar3 = _local_6;
          bVar4 = *_local_6;
          iVar10 = (int)((ulong)_local_6 >> 0x10);
          uVar8 = iVar10;
          if ((bVar4 == 0) || (0x20 < *pbVar3)) break;
          _local_6 = (byte *)CONCAT22(iVar10,local_6 + 1);
        }
        pbVar7 = local_6;
        _local_6 = pbVar3;
        iVar6 = FUN_4340_0b08(pbVar7,uVar8,0xd7,0x554c,8);
        pbVar3 = _local_6;
      } while (iVar6 != 0);
      iVar10 = (int)((ulong)_local_6 >> 0x10);
      uVar8 = iVar10;
      local_6 = (byte *)pbVar3;
      pbVar7 = local_6;
      _local_6 = pbVar3;
      pbVar7 = (byte *)FUN_4340_0caf(pbVar7,uVar8,0x3d);
      _local_6 = (byte *)CONCAT22(in_DX,pbVar7);
      while( true ) {
        pbVar3 = _local_6;
        iVar10 = (int)((ulong)_local_6 >> 0x10);
        if (((local_6 == (byte *)0x0 && iVar10 == 0) || (*pbVar3 == 0)) ||
           ((0x20 < *pbVar3 && (*pbVar3 != 0x3d)))) break;
        _local_6 = (byte *)CONCAT22(iVar10,local_6 + 1);
      }
      bVar1 = local_6 == (byte *)0x0;
      bVar2 = iVar10 == 0;
      _local_6 = pbVar3;
    } while ((bVar1 && bVar2) || (*pbVar3 == 0));
    FUN_4340_0a29(local_86);
    FUN_1000_3d77(iVar5);
    if (param_1 == 0) {
      FUN_1a3f_0334(local_86);
      return;
    }
    FUN_4340_0a29((undefined1 *)&DAT_5b41_0002,0x554c,local_86);
    uVar8 = FUN_4340_0d3f((undefined1 *)&DAT_5b41_0002,0x554c,0x2e,0,0);
    FUN_4340_0a29(uVar8,in_DX);
    FUN_4340_0abb((undefined1 *)&DAT_5b41_0002,0x554c,0xe0,0x554c);
    uVar8 = FUN_1000_418e((undefined1 *)&DAT_5b41_0002,0xe5);
    iVar5 = FUN_1000_3d77(uVar8);
    if (iVar5 != 0) {
      FUN_4340_0a29((undefined1 *)&DAT_5b41_0002,0x554c,0xe8,0x554c);
      uVar8 = FUN_1000_418e((undefined1 *)&DAT_5b41_0002,0xf4);
      iVar5 = FUN_1000_3d77(uVar8);
      if (iVar5 != 0) {
        func_0x000552d0(0x1000,0xa2);
        DAT_5b41_0002 = 0;
        FUN_1a3f_01e5();
        return;
      }
      FUN_1a3f_01e5();
    }
    puVar9 = (undefined1 *)&DAT_5b41_0002;
  }
  func_0x000552d0(0x1000,puVar9);
  return;
}

