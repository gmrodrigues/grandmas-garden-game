// TIM2.EXE: FUN_1000_02a3 @ file 0x0154A3 Ghidra 0x102A3
// Subsystem: utility | Size: 332 bytes


char __cdecl16far FUN_1000_02a3(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  int in_DX;
  undefined2 uVar5;
  bool bVar6;
  undefined2 local_12;
  int local_10;
  undefined2 local_e;
  undefined2 local_c;
  int local_a;
  int local_8;
  undefined4 local_6;
  
  if (DAT_5b41_045c == '\0') {
    if (DAT_5b41_046b == 0 && DAT_5b41_046d == 0) {
      DAT_5b41_046b = FUN_1000_18c5(0x24);
      DAT_5b41_046d = in_DX;
      FUN_1000_18d8(0x24,0x11c2,0x1000);
    }
    iVar2 = FUN_1000_418e(0x1bb,0x1c8);
    if (iVar2 != 0) {
      FUN_1000_4306(0x1aa,4,1,iVar2);
      FUN_1000_4306(&local_a,2,1,iVar2);
      DAT_5b41_0469 = DAT_5b41_0469 + local_a;
      local_8 = DAT_5b41_0469 - local_a;
      while (local_8 = local_8 + 1, iVar1 = local_8, local_8 <= DAT_5b41_0469) {
        iVar3 = local_8 * 0x1c;
        FUN_1000_4306(iVar3 + 0x6300,0xd,1,iVar2);
        FUN_1000_4306(&local_a,2,1,iVar2);
        puVar4 = (undefined2 *)FUN_22de_01ec((local_a + 1) * 8,0,9,1);
        local_6 = (undefined2 *)CONCAT22(in_DX,puVar4);
        ((undefined2 *)&DAT_5b41_03ca)[iVar1 * 0xe] = in_DX;
        ((undefined2 *)&DAT_5b41_03c8)[iVar1 * 0xe] = puVar4;
        *(int *)(iVar3 + 0x630e) = local_8;
        while (iVar1 = local_a + -1, bVar6 = local_a != 0, local_a = iVar1, bVar6) {
          FUN_1000_4306(&local_e,4,1,iVar2);
          FUN_1000_4306(&local_12,4,1,iVar2);
          uVar5 = (undefined2)((ulong)local_6 >> 0x10);
          puVar4 = (undefined2 *)local_6;
          puVar4[1] = local_c;
          *local_6 = local_e;
          puVar4[3] = local_10;
          puVar4[2] = local_12;
          local_6 = (undefined2 *)CONCAT22(uVar5,puVar4 + 4);
          in_DX = local_10;
        }
      }
      FUN_1000_3d77(iVar2);
      DAT_5b41_045c = '\x01';
    }
  }
  return DAT_5b41_045c;
}

