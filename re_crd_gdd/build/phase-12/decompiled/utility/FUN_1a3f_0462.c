// TIM2.EXE: FUN_1a3f_0462 @ file 0x01FA52 Ghidra 0x1A852
// Subsystem: utility | Size: 410 bytes


int __cdecl16far FUN_1a3f_0462(void)

{
  byte *pbVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int in_DX;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 unaff_SS;
  undefined2 uVar8;
  int iVar9;
  byte local_70 [80];
  undefined1 local_20 [14];
  int local_12;
  int local_10;
  byte *local_e;
  undefined2 uVar10;
  undefined4 local_6;
  
  local_12 = 0;
  FUN_49fc_0403();
  piVar3 = (int *)FUN_49fc_0070(0,0,0x148,0x554c,0x18);
  if ((piVar3 != (int *)0x0 || in_DX != 0) && (local_10 = FUN_1000_0b20(0x14e,0x15b), local_10 != 0)
     ) {
    local_6 = (int *)CONCAT22(in_DX,piVar3);
    while( true ) {
      uVar7 = (undefined2)((ulong)local_6 >> 0x10);
      if (*local_6 == 0 && ((int *)local_6)[1] == 0) break;
      FUN_4340_0a29(local_20);
      iVar4 = FUN_1000_0b20(local_20,0x15e);
      if (iVar4 != 0) {
LAB_1a3f_04ec:
        _local_e = (byte *)0x554c00c9;
LAB_1a3f_04f4:
        uVar5 = FUN_1000_0fdc(iVar4);
        if (uVar5 == 0xffff) {
          FUN_1000_0c9d(iVar4);
          iVar4 = 0;
          goto LAB_1a3f_0529;
        }
        if (*_local_e == uVar5) goto code_r0x0001a90d;
        goto LAB_1a3f_04ec;
      }
LAB_1a3f_05d7:
      local_6 = (int *)CONCAT22(uVar7,(int *)local_6 + 2);
    }
    FUN_1000_0c9d(local_10);
  }
  return local_12;
code_r0x0001a90d:
  uVar10 = (undefined2)((ulong)_local_e >> 0x10);
  _local_e = (byte *)CONCAT22(uVar10,local_e + 1);
  if (*_local_e == 0) {
LAB_1a3f_0529:
    if (iVar4 != 0) {
      FUN_1000_0e6d(iVar4,7,0,1);
      _local_e = (byte *)CONCAT22(unaff_SS,local_70);
      do {
        bVar2 = FUN_1000_0fdc(iVar4);
        pbVar1 = _local_e;
        uVar10 = (undefined2)((ulong)_local_e >> 0x10);
        _local_e = (byte *)CONCAT22(uVar10,local_e + 1);
        *pbVar1 = bVar2;
      } while (bVar2 != 10);
      while ((local_70 < local_e &&
             (uVar6 = (undefined2)((ulong)_local_e >> 0x10), local_e[-1] < 0x21))) {
        _local_e = (byte *)CONCAT22(uVar6,local_e + -1);
      }
      *_local_e = 0;
      uVar8 = 1;
      iVar9 = local_10;
      uVar6 = FUN_4340_0a09(local_70);
      FUN_1000_10d5(local_70,uVar6,uVar8,iVar9);
      FUN_1000_1135(10,local_10);
      uVar8 = 1;
      iVar9 = local_10;
      uVar6 = FUN_4340_0a09(local_20);
      FUN_1000_10d5(local_20,uVar6,uVar8,iVar9);
      FUN_1000_1135(10,local_10);
      FUN_1000_0c9d(iVar4);
      local_12 = local_12 + 1;
    }
    goto LAB_1a3f_05d7;
  }
  goto LAB_1a3f_04f4;
}

