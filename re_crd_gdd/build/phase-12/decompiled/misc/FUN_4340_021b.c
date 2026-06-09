// TIM2.EXE: FUN_4340_021b @ file 0x04881B Ghidra 0x4361B
// Subsystem: misc | Size: 655 bytes


undefined2 __cdecl16far FUN_4340_021b(undefined2 param_1)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  int *piVar4;
  undefined2 uVar5;
  uint uVar6;
  byte *pbVar7;
  undefined2 *puVar8;
  int in_DX;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined2 unaff_SS;
  bool bVar13;
  byte local_11e [256];
  uint local_1e;
  int local_1c;
  undefined4 local_1a;
  byte *local_16;
  undefined2 uVar14;
  undefined4 local_e;
  undefined4 local_6;
  
  piVar4 = (int *)FUN_4340_07f3(param_1);
  local_6 = (int *)CONCAT22(in_DX,piVar4);
  if ((piVar4 != (int *)0x0 || in_DX != 0) && (piVar4[5] != 0)) {
    if ((*local_6 != 0 || piVar4[1] != 0) && (piVar4[2] != 0 || piVar4[3] != 0)) {
      return 1;
    }
    uVar5 = FUN_3f2b_0718(piVar4[5],0x3fae);
    local_1c = FUN_1000_0b20(uVar5);
    if (local_1c != 0) {
      FUN_1000_0e6d(local_1c,0,0,2);
      uVar6 = FUN_1000_0f2a(local_1c);
      iVar9 = (int)uVar6 >> 0xf;
      pbVar7 = (byte *)FUN_22de_01ec(uVar6,iVar9,2,0);
      if (pbVar7 == (byte *)0x0 && iVar9 == 0) {
        FUN_1000_0c9d(local_1c);
      }
      else {
        FUN_1000_0e6d(local_1c,0,0,0);
        local_1a = (byte *)CONCAT22(iVar9,pbVar7);
        uVar11 = uVar6;
        while (uVar11 != 0) {
          local_1e = uVar11;
          if (0x100 < (int)uVar11) {
            local_1e = 0x100;
          }
          FUN_1000_0d10(local_11e,local_1e,1,local_1c);
          uVar11 = uVar11 - local_1e;
          _local_16 = (byte *)CONCAT22(unaff_SS,local_11e);
          while (uVar1 = local_1e - 1, bVar13 = local_1e != 0, local_1e = uVar1, bVar13) {
            *local_1a = *_local_16;
            uVar14 = (undefined2)((ulong)_local_16 >> 0x10);
            _local_16 = (byte *)CONCAT22(uVar14,local_16 + 1);
            local_1a = (byte *)CONCAT22(local_1a._2_2_,(byte *)local_1a + 1);
          }
        }
        FUN_1000_0c9d(local_1c);
        local_1a = (byte *)CONCAT22(iVar9,pbVar7);
        _local_16 = (byte *)CONCAT22(iVar9,pbVar7);
LAB_4340_03c0:
        while (pbVar2 = local_16, local_16 < pbVar7 + uVar6) {
          local_1e = (uint)*_local_16;
          uVar14 = (undefined2)((ulong)_local_16 >> 0x10);
          _local_16 = (byte *)CONCAT22(uVar14,local_16 + 1);
          if (local_1e != 0x5c) {
            if (local_1e != 0xd) goto LAB_4340_03ae;
            *local_1a = 0;
            goto LAB_4340_03bd;
          }
          local_1e = (uint)*_local_16;
          _local_16 = (byte *)CONCAT22(uVar14,pbVar2 + 2);
          if (local_1e != 0xd) {
            if ((local_1e == 0x72) || (local_1e == 0x6e)) {
              local_1e = 10;
            }
            goto LAB_4340_03b4;
          }
        }
        while ((byte *)local_1a < local_16) {
          *local_1a = 0;
          uVar6 = uVar6 - 1;
          local_1a = (byte *)CONCAT22(local_1a._2_2_,(byte *)local_1a + 1);
        }
        iVar12 = 0;
        _local_16 = (byte *)CONCAT22(iVar9,pbVar7);
        while (local_16 < pbVar7 + uVar6) {
          iVar12 = iVar12 + (uint)(*_local_16 == 0);
          uVar14 = (undefined2)((ulong)_local_16 >> 0x10);
          _local_16 = (byte *)CONCAT22(uVar14,local_16 + 1);
        }
        iVar10 = iVar9;
        puVar8 = (undefined2 *)FUN_22de_01ec((iVar12 + 1) * 4,0,2,0);
        if (puVar8 != (undefined2 *)0x0 || iVar10 != 0) {
          local_e = (undefined2 *)CONCAT22(iVar10,puVar8);
          _local_16 = (byte *)CONCAT22(iVar9,pbVar7);
          do {
            pbVar3 = _local_16;
            uVar5 = (undefined2)((ulong)local_e >> 0x10);
            uVar14 = (undefined2)((ulong)_local_16 >> 0x10);
            local_16 = (byte *)pbVar3;
            ((undefined2 *)local_e)[1] = uVar14;
            *local_e = local_16;
            local_e = (undefined2 *)CONCAT22(uVar5,(undefined2 *)local_e + 2);
            _local_16 = pbVar3;
            do {
              pbVar3 = _local_16;
              if (pbVar7 + uVar6 <= local_16) {
                piVar4[1] = iVar9;
                *local_6 = (int)pbVar7;
                piVar4[3] = iVar10;
                piVar4[2] = (int)puVar8;
                piVar4[6] = iVar12;
                return 1;
              }
              uVar14 = (undefined2)((ulong)_local_16 >> 0x10);
              _local_16 = (byte *)CONCAT22(uVar14,local_16 + 1);
            } while (*pbVar3 != 0);
          } while( true );
        }
        FUN_22de_0351(pbVar7,iVar9);
      }
    }
  }
  return 0;
LAB_4340_03ae:
  if (local_1e != 10) {
LAB_4340_03b4:
    *local_1a = (byte)local_1e;
LAB_4340_03bd:
    local_1a = (byte *)CONCAT22(local_1a._2_2_,(byte *)local_1a + 1);
  }
  goto LAB_4340_03c0;
}

