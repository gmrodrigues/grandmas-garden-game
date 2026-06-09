// TIM2.EXE: FUN_31f7_9580 @ file 0x0406F0 Ghidra 0x3B4F0
// Subsystem: gfx | Size: 401 bytes


void __cdecl16far FUN_31f7_9580(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = (int)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if (*(int *)(iVar3 + 0x10) < DAT_5b41_1a9a) {
    iVar4 = 0;
  }
  else if (*(int *)(iVar3 + 0x10) < DAT_5b41_1a9c) {
    iVar4 = 1;
  }
  else {
    iVar4 = 2;
  }
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 0x40;
  if (((((undefined2 *)&DAT_5b41_1a8e)[iVar4] + 1 < *(int *)(iVar3 + 0x10)) &&
      (*(int *)(iVar3 + 0x10) != ((undefined2 *)&DAT_5b41_1a9a)[iVar4])) ||
     ((*(int *)(iVar3 + 0x16) != 0 &&
      ((*(int *)(iVar3 + 0x10) == ((undefined2 *)&DAT_5b41_1a8e)[iVar4] + 1 &&
       (*(int *)(iVar3 + 0xae) = *(int *)(iVar3 + 0xae) + 1,
       iVar4 * 0x14 + 0x14 <= *(int *)(iVar3 + 0xae))))))) {
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
  }
  if ((((undefined2 *)&DAT_5b41_1a8e)[iVar4] + 4 <= *(int *)(iVar3 + 0x10)) &&
     (*(int *)(iVar3 + 0x10) <= ((undefined2 *)&DAT_5b41_1a8e)[iVar4] + 6)) {
    FUN_28eb_51b3(iVar3,iVar5,0x3000,8,0x26,
                  *(undefined2 *)
                   ((*(int *)(iVar3 + 0x10) - ((undefined2 *)&DAT_5b41_1a8e)[iVar4]) * 2 + 0x3c86),0
                 );
    FUN_31f7_b9f5(iVar3,iVar5,0,8,0x26,
                  *(undefined2 *)
                   ((*(int *)(iVar3 + 0x10) - ((undefined2 *)&DAT_5b41_1a8e)[iVar4]) * 2 + 0x3c86),0
                 );
    iVar4 = iVar3;
    iVar6 = iVar5;
    while( true ) {
      iVar1 = *(int *)(iVar4 + 0x8e);
      iVar4 = *(int *)(iVar4 + 0x8c);
      if (iVar4 == 0 && iVar1 == 0) break;
      iVar6 = iVar1;
      if ((*(byte *)(iVar4 + 0xb) & 0x10) != 0) {
        iVar2 = FUN_31f7_9711(iVar4,iVar1);
        *(int *)(iVar4 + 0x3c) = -iVar2;
        if ((*(int *)(iVar4 + 8) == 0x36) && (*(int *)(iVar4 + 0x10) < DAT_5b41_09a3)) {
          *(int *)(iVar4 + 0x10) = DAT_5b41_09a3;
        }
      }
    }
    *(int *)(iVar3 + 0xae) = *(int *)(iVar3 + 0xae) + 1;
  }
  if (*(int *)(iVar3 + 0x10) != *(int *)(iVar3 + 0x12)) {
    FUN_28eb_3328(iVar3,iVar5);
  }
  return;
}

