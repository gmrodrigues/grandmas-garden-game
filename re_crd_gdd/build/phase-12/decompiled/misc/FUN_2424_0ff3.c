// TIM2.EXE: FUN_2424_0ff3 @ file 0x02A433 Ghidra 0x25233
// Subsystem: misc | Size: 191 bytes


void __cdecl16far FUN_2424_0ff3(void)

{
  int *piVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  undefined2 *puVar8;
  undefined2 *local_c;
  
  FUN_2424_02ca();
  DAT_554c_42c3 = 1;
  DAT_554c_42ce = DAT_5b41_0757;
  DAT_554c_42cd = DAT_5b41_0757;
  DAT_554c_42d8 = DAT_554c_42d2;
  local_c = (undefined2 *)0x0;
  puVar2 = DAT_5b41_04ac;
  puVar8 = local_c;
  while (local_c = puVar8, puVar8 = puVar2, puVar8 != (undefined2 *)0x0) {
    puVar2 = (undefined2 *)*puVar8;
    piVar1 = puVar8 + 6;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      iVar3 = puVar8[1];
      iVar4 = puVar8[2];
      iVar6 = (puVar8[3] - iVar3) + 1;
      iVar7 = (puVar8[4] - iVar4) + 1;
      DAT_554c_42cc = 1;
      if ((((iVar3 <= DAT_554c_42c6) && (DAT_554c_42c4 < iVar3 + iVar6)) && (iVar4 <= DAT_554c_42ca)
          ) && (DAT_554c_42c8 < iVar4 + iVar7)) {
        FUN_1a9e_3854(iVar3,iVar4,iVar6,iVar7);
      }
      puVar5 = puVar2;
      if (local_c != (undefined2 *)0x0) {
        *local_c = puVar2;
        puVar5 = DAT_5b41_04ac;
      }
      DAT_5b41_04ac = puVar5;
      *puVar8 = DAT_5b41_04b0;
      DAT_5b41_04b0 = puVar8;
      puVar8 = local_c;
    }
  }
  return;
}

