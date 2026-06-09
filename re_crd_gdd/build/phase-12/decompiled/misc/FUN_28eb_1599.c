// TIM2.EXE: FUN_28eb_1599 @ file 0x02F649 Ghidra 0x2A449
// Subsystem: misc | Size: 363 bytes


void __cdecl16far FUN_28eb_1599(undefined4 param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  
  if ((int)param_1 != 0 || param_1._2_2_ != 0) {
    if ((int *)param_2 != (int *)0x0 || param_2._2_2_ != 0) {
      *param_2 = *(int *)((int)param_1 + 0x22) - DAT_5b41_0925;
      ((int *)param_2)[1] = *(int *)((int)param_1 + 0x24) - DAT_5b41_0927;
      ((int *)param_2)[2] = *(int *)((int)param_1 + 0x44);
      ((int *)param_2)[3] = *(int *)((int)param_1 + 0x46);
      iVar2 = *(int *)((int)param_1 + 8);
      if (iVar2 == 8) {
        if (*(int *)(*(int *)((int)param_1 + 0x58) + 10) != 0 ||
            *(int *)(*(int *)((int)param_1 + 0x58) + 0xc) != 0) {
          uVar3 = *(undefined2 *)(*(int *)((int)param_1 + 0x58) + 0xc);
          iVar2 = *(int *)(*(int *)((int)param_1 + 0x58) + 10);
          *param_2 = (*(int *)(iVar2 + 0x2e) + (uint)*(byte *)(iVar2 + 0x5a)) -
                     *(int *)(iVar2 + 0x5c);
          ((int *)param_2)[1] =
               (*(int *)(iVar2 + 0x30) + (uint)*(byte *)(iVar2 + 0x5b)) - *(int *)(iVar2 + 0x5c);
          ((int *)param_2)[2] = *(int *)(iVar2 + 0x5c) * 2 + 1;
          ((int *)param_2)[3] = *(int *)(iVar2 + 0x5c) * 2 + 1;
        }
      }
      else if ((((iVar2 == 10) || (iVar2 == 0x4c)) &&
               (iVar2 = *(int *)((int)param_1 + 0x76), iVar2 != 0)) &&
              (*(int *)(iVar2 + 8) != 0 || *(int *)(iVar2 + 10) != 0)) {
        uVar3 = *(undefined2 *)(iVar2 + 10);
        iVar4 = *(int *)(iVar2 + 8);
        bVar1 = *(byte *)(iVar2 + 0x15);
        *param_2 = *(int *)(iVar4 + 0x2e) + (int)*(char *)(iVar4 + (uint)bVar1 * 2 + 0x7a) + -8;
        ((int *)param_2)[1] =
             *(int *)(iVar4 + 0x30) + (int)*(char *)(iVar4 + (uint)bVar1 * 2 + 0x7b) + -7;
        ((int *)param_2)[2] = 0x10;
        ((int *)param_2)[3] = 0xe;
      }
    }
  }
  return;
}

