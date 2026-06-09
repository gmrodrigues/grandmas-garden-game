// TIM2.EXE: FUN_1000_73f2 @ file 0x01C5F2 Ghidra 0x173F2
// Subsystem: utility | Size: 203 bytes


void __cdecl16near FUN_1000_73f2(undefined4 param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if (*(char *)(iVar3 + 0x34) != '\0') {
    if ((*(byte *)(iVar3 + 0x16) & 2) != 0) {
      uVar2 = *(undefined2 *)0x12;
      uVar1 = *(undefined2 *)0x10;
      uVar6 = (undefined2)((ulong)*(undefined4 *)(iVar3 + 4) >> 0x10);
      iVar4 = (int)*(undefined4 *)(iVar3 + 4);
      FUN_1000_73a3(iVar3 + 0x36,uVar5,*(undefined2 *)(iVar4 + 0x1e),*(undefined2 *)(iVar4 + 0x20),
                    *(undefined2 *)(iVar4 + 0x22));
      *(undefined2 *)0x12 = uVar2;
      *(undefined2 *)0x10 = uVar1;
    }
    *(undefined1 *)(iVar3 + 0x34) = 0;
  }
  if (*(char *)(iVar3 + 0x35) != '\0') {
    if (((*(byte *)(*(int *)(iVar3 + 0x2e) + 2) & 2) != 0) &&
       ((*(byte *)(*(int *)(iVar3 + 0x2e) + 8) & 2) != 0)) {
      FUN_1000_73a3(*(undefined2 *)(iVar3 + 0x32));
    }
    *(undefined1 *)(iVar3 + 0x35) = 0;
  }
  return;
}

