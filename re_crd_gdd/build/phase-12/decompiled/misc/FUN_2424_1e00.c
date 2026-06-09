// TIM2.EXE: FUN_2424_1e00 @ file 0x02B240 Ghidra 0x26040
// Subsystem: misc | Size: 542 bytes


void __cdecl16far FUN_2424_1e00(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  undefined2 uVar10;
  int *local_a;
  int *local_8;
  int *local_6;
  
  if (((DAT_5b41_04ae != (int *)0x0) || (iVar3 = FUN_2424_087c(0x32), iVar3 != 0)) && (0 < param_2))
  {
    uVar10 = (undefined2)((ulong)param_1 >> 0x10);
    piVar8 = (int *)param_1;
    if (piVar8[2] < 0) {
      iVar3 = piVar8[2];
      *param_1 = *param_1 + iVar3;
      piVar8[2] = -iVar3;
    }
    if (piVar8[3] < 0) {
      iVar3 = piVar8[3];
      piVar8[1] = piVar8[1] + iVar3;
      piVar8[3] = -iVar3;
    }
    piVar2 = DAT_5b41_04ae;
    piVar1 = DAT_5b41_04ae + 6;
    DAT_5b41_04ae = (int *)*DAT_5b41_04ae;
    *piVar1 = param_2;
    piVar2[1] = *param_1;
    piVar2[2] = piVar8[1];
    piVar2[3] = piVar8[2] + *param_1 + -1;
    piVar2[4] = piVar8[1] + piVar8[3] + -1;
    if (DAT_554c_42c3 != '\0') {
      if (piVar2[1] < DAT_554c_42c4) {
        piVar2[1] = DAT_554c_42c4;
      }
      if (DAT_554c_42c6 < piVar2[3]) {
        piVar2[3] = DAT_554c_42c6;
      }
      if (piVar2[2] < DAT_554c_42c8) {
        piVar2[2] = DAT_554c_42c8;
      }
      if (DAT_554c_42ca < piVar2[4]) {
        piVar2[4] = DAT_554c_42ca;
      }
    }
    piVar2[1] = piVar2[1] & 0xfff8;
    piVar2[3] = piVar2[3] | 7;
    if ((piVar2[1] <= piVar2[3]) && (piVar2[2] <= piVar2[4])) {
      DAT_5b41_04b4 = 1;
      piVar2[5] = ((piVar2[3] - piVar2[1]) / 8) * (piVar2[4] - piVar2[2]);
      local_6 = (int *)0x0;
      local_8 = (int *)0x0;
      do {
        local_a = (int *)0x0;
        piVar8 = DAT_5b41_04ac;
        do {
          if (piVar8 == local_6) {
            *piVar2 = (int)DAT_5b41_04ac;
            DAT_5b41_04ac = piVar2;
            return;
          }
          local_6 = local_8;
          piVar1 = (int *)*piVar8;
          piVar9 = piVar8;
          if (piVar8[6] == piVar2[6]) {
            iVar3 = piVar8[1];
            if (piVar2[1] <= iVar3) {
              iVar3 = piVar2[1];
            }
            iVar4 = piVar8[3];
            if (iVar4 <= piVar2[3]) {
              iVar4 = piVar2[3];
            }
            iVar5 = piVar8[2];
            if (piVar2[2] <= iVar5) {
              iVar5 = piVar2[2];
            }
            iVar6 = piVar8[4];
            if (iVar6 <= piVar2[4]) {
              iVar6 = piVar2[4];
            }
            uVar7 = ((iVar4 - iVar3) / 8) * (iVar6 - iVar5);
            if (uVar7 <= piVar8[5] + piVar2[5] + 0x14U) {
              piVar2[1] = iVar3;
              piVar2[2] = iVar5;
              piVar2[3] = iVar4;
              piVar2[4] = iVar6;
              piVar2[5] = uVar7;
              piVar9 = piVar1;
              if (local_a != (int *)0x0) {
                *local_a = (int)piVar1;
                piVar9 = DAT_5b41_04ac;
              }
              DAT_5b41_04ac = piVar9;
              *piVar8 = (int)DAT_5b41_04ae;
              local_6 = local_a;
              piVar9 = local_a;
              DAT_5b41_04ae = piVar8;
              local_8 = piVar1;
            }
          }
          piVar8 = piVar1;
          local_a = piVar9;
        } while ((piVar1 != (int *)0x0) || (local_6 == (int *)0x0));
      } while( true );
    }
    *piVar2 = (int)DAT_5b41_04ae;
    DAT_5b41_04ae = piVar2;
  }
  return;
}

