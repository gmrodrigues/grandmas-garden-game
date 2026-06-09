// TIM2.EXE: FUN_1a3f_01e5 @ file 0x01F7D5 Ghidra 0x1A5D5
// Subsystem: utility | Size: 335 bytes


void __cdecl16far FUN_1a3f_01e5(void)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  int in_DX;
  undefined2 unaff_SS;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  char local_86 [128];
  char *local_6;
  undefined2 uVar10;
  
  iVar3 = FUN_1000_418e(0xaf,0xf7);
  if (iVar3 != 0) {
    iVar4 = FUN_1000_418e(0xbc,0xfa);
    if (iVar4 == 0) {
      FUN_1000_3d77(iVar3);
    }
    else {
      while ((*(byte *)(iVar3 + 2) & 0x20) == 0) {
        _local_6 = (char *)CONCAT22(unaff_SS,local_86);
        do {
          if ((*(byte *)(iVar3 + 2) & 0x20) != 0) break;
          cVar2 = FUN_1000_4820(iVar3);
          pcVar1 = _local_6;
          uVar10 = (undefined2)((ulong)_local_6 >> 0x10);
          _local_6 = (char *)CONCAT22(uVar10,local_6 + 1);
          *pcVar1 = cVar2;
        } while (cVar2 != '\n');
        if ((*(byte *)(iVar3 + 2) & 0x20) != 0) {
          uVar10 = (undefined2)((ulong)_local_6 >> 0x10);
          _local_6 = (char *)CONCAT22(uVar10,local_6 + -1);
        }
        ((char *)_local_6)[1] = '\0';
        uVar9 = 8;
        uVar8 = 0x554c;
        uVar7 = 0xfd;
        uVar5 = FUN_4340_0caf(local_86);
        iVar6 = FUN_4340_0b08(uVar5,in_DX,uVar7,uVar8,uVar9);
        if (iVar6 == 0) {
LAB_1a3f_02c4:
          FUN_4340_0a29(local_86);
          uVar8 = 0;
          uVar7 = 0;
          uVar5 = FUN_4340_0d3f(local_86);
          FUN_4340_0a29(uVar5,in_DX,uVar7,uVar8);
          FUN_1000_41b1(iVar4,0x10f,local_86);
        }
        else {
          uVar9 = 8;
          uVar8 = 0x554c;
          uVar7 = 0x106;
          uVar5 = FUN_4340_0caf(local_86);
          iVar6 = FUN_4340_0b08(uVar5,in_DX,uVar7,uVar8,uVar9);
          if (iVar6 == 0) goto LAB_1a3f_02c4;
          in_DX = (int)local_6 - (int)local_86;
          FUN_1000_4718(local_86,in_DX,1,iVar4);
        }
      }
      FUN_1000_3d77(iVar3);
      FUN_1000_3d77(iVar4);
      FUN_49fc_0489(0xaf,0x554c);
      FUN_49fc_04c1(0xbc,0x554c,0xaf,0x554c);
    }
  }
  return;
}

