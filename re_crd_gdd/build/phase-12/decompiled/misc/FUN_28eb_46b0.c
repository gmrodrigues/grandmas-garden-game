// TIM2.EXE: FUN_28eb_46b0 @ file 0x032760 Ghidra 0x2D560
// Subsystem: misc | Size: 217 bytes


undefined2 __cdecl16far FUN_28eb_46b0(undefined4 param_1,int param_2,int param_3)

{
  undefined2 *puVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 uVar8;
  
  puVar4 = DAT_5b41_096d;
  uVar8 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = *(int *)((int)param_1 + 0x42);
  uVar3 = *(uint *)((int)param_1 + 0x40);
  for (puVar5 = DAT_5b41_096b; puVar5 != (undefined2 *)0x0; puVar5 = (undefined2 *)*puVar5) {
    if ((puVar5[2] == param_3) && (puVar5[1] == param_2)) {
      if ((iVar2 <= (int)puVar5[4]) && ((puVar5[4] != iVar2 || (uVar3 <= (uint)puVar5[3])))) {
        return 0;
      }
    }
  }
  if (DAT_5b41_096b != (undefined2 *)0x0) {
    if ((iVar2 < (int)DAT_5b41_096b[4]) ||
       ((iVar2 <= (int)DAT_5b41_096b[4] && (uVar3 <= (uint)DAT_5b41_096b[3])))) {
      puVar5 = (undefined2 *)*DAT_5b41_096b;
      puVar7 = DAT_5b41_096b;
      while (puVar6 = puVar5, puVar6 != (undefined2 *)0x0) {
        if (((int)puVar6[4] <= iVar2) && ((puVar6[4] != iVar2 || ((uint)puVar6[3] <= uVar3))))
        break;
        puVar7 = puVar6;
        puVar5 = (undefined2 *)*puVar6;
      }
      puVar1 = DAT_5b41_096d;
      DAT_5b41_096d = (undefined2 *)*DAT_5b41_096d;
      *puVar1 = *puVar7;
      *puVar7 = puVar4;
      goto LAB_28eb_476a;
    }
  }
  puVar1 = DAT_5b41_096d;
  DAT_5b41_096d = (undefined2 *)*DAT_5b41_096d;
  *puVar1 = DAT_5b41_096b;
  DAT_5b41_096b = puVar4;
LAB_28eb_476a:
  puVar4[2] = param_3;
  puVar4[1] = param_2;
  puVar4[4] = iVar2;
  puVar4[3] = uVar3;
  return 1;
}

