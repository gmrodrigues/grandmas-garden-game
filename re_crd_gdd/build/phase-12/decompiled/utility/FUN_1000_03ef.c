// TIM2.EXE: FUN_1000_03ef @ file 0x0155EF Ghidra 0x103EF
// Subsystem: utility | Size: 374 bytes


undefined2 __cdecl16far FUN_1000_03ef(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 in_DX;
  undefined2 uVar4;
  char local_14;
  char local_13;
  char local_12;
  char local_11;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  int local_8;
  undefined4 local_6;
  
  if (DAT_5b41_045c != '\0') {
    if (DAT_5b41_0467 != 0) {
      if (((undefined2 *)&DAT_5b41_03c8)[DAT_5b41_0467 * 0xe] != 0 ||
          ((undefined2 *)&DAT_5b41_03ca)[DAT_5b41_0467 * 0xe] != 0) {
        FUN_22de_0351(((undefined2 *)&DAT_5b41_03c8)[DAT_5b41_0467 * 0xe],
                      ((undefined2 *)&DAT_5b41_03ca)[DAT_5b41_0467 * 0xe]);
        ((undefined2 *)&DAT_5b41_03ca)[DAT_5b41_0467 * 0xe] = 0;
        ((undefined2 *)&DAT_5b41_03c8)[DAT_5b41_0467 * 0xe] = 0;
      }
      DAT_5b41_0467 = 0;
    }
    if ((param_1 != 0) && (iVar1 = FUN_1000_418e(param_1,0x1cb), iVar1 != 0)) {
      FUN_1000_4306(&local_14,4,1,iVar1);
      FUN_1000_4306(&local_8,2,1,iVar1);
      if (((local_8 == 1) &&
          (((cRam0005566a == local_14 && (cRam0005566b == local_13)) && (cRam0005566c == local_12)))
          ) && (cRam0005566d == local_11)) {
        iVar2 = DAT_5b41_0469 + 1;
        DAT_5b41_0467 = iVar2;
        FUN_1000_4306(iVar2 * 0x1c + 0x6300,0xd,1,iVar1);
        FUN_1000_4306(&local_8,2,1,iVar1);
        puVar3 = (undefined2 *)FUN_22de_01ec((local_8 + 1) * 8,0,9,1);
        local_6 = (undefined2 *)CONCAT22(in_DX,puVar3);
        ((undefined2 *)&DAT_5b41_03ca)[iVar2 * 0xe] = in_DX;
        ((undefined2 *)&DAT_5b41_03c8)[iVar2 * 0xe] = puVar3;
        *(int *)(iVar2 * 0x1c + 0x630e) = DAT_5b41_0467;
        while (local_8 != 0) {
          local_8 = local_8 + -1;
          FUN_1000_4306(&local_c,4,1,iVar1);
          FUN_1000_4306(&local_10,4,1,iVar1);
          uVar4 = (undefined2)((ulong)local_6 >> 0x10);
          puVar3 = (undefined2 *)local_6;
          puVar3[1] = local_a;
          *local_6 = local_c;
          puVar3[3] = local_e;
          puVar3[2] = local_10;
          local_6 = (undefined2 *)CONCAT22(uVar4,puVar3 + 4);
        }
        local_8 = local_8 + -1;
        FUN_1000_3d77(iVar1);
        return 1;
      }
      FUN_1000_3d77(iVar1);
    }
  }
  return 0;
}

