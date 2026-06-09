// TIM2.EXE: FUN_31f7_7d4e @ file 0x03EEBE Ghidra 0x39CBE
// Subsystem: misc | Size: 192 bytes


void __cdecl16far FUN_31f7_7d4e(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  FUN_28eb_51b3((int)param_1,param_1._2_2_,0x1000,7,10,6,0xb);
  iVar3 = (int)param_1;
  iVar5 = param_1._2_2_;
  while( true ) {
    iVar1 = *(int *)(iVar3 + 0x8e);
    iVar3 = *(int *)(iVar3 + 0x8c);
    if (iVar3 == 0 && iVar1 == 0) break;
    iVar5 = iVar1;
    if ((*(int *)(iVar3 + 8) == 0x2a) &&
       (uVar2 = *(int *)((int)param_1 + 0x22) - *(int *)(iVar3 + 0x22), uVar4 = (int)uVar2 >> 0xf,
       (int)((uVar2 ^ uVar4) - uVar4) < 0xe)) {
      FUN_2424_0f94(iVar3,iVar1,3);
      *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 0x2000;
      *(undefined2 *)((int)param_1 + 0x16) = 1;
      *(undefined2 *)((int)param_1 + 0x10) = 0;
    }
  }
  if (*(int *)((int)param_1 + 0x16) != 0) {
    *(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + 1;
    iVar3 = FUN_4551_0308(*(undefined2 *)(*(int *)((int)param_1 + 8) * 2 + 0x68fe),
                          *(undefined2 *)((int)param_1 + 0x10));
    if (iVar3 == -1) {
      *(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + -1;
      *(undefined2 *)((int)param_1 + 0x16) = 0;
    }
  }
  return;
}

