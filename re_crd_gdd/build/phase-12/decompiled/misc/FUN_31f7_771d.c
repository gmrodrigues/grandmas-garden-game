// TIM2.EXE: FUN_31f7_771d @ file 0x03E88D Ghidra 0x3968D
// Subsystem: misc | Size: 267 bytes


void __cdecl16far FUN_31f7_771d(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  bVar1 = DAT_5b41_1a52 <= *(int *)(iVar3 + 0x10);
  if (((DAT_5b41_051f & 1) != 0) ||
     (*(int *)(iVar3 + 0x10) != ((undefined2 *)&DAT_5b41_1a42)[bVar1])) {
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
  }
  if ((*(int *)(iVar3 + 0x10) == ((undefined2 *)&DAT_5b41_1a46)[bVar1]) ||
     (*(int *)(iVar3 + 0x10) == ((undefined2 *)&DAT_5b41_1a52)[bVar1])) {
    iVar2 = ((undefined2 *)&DAT_5b41_1a42)[bVar1];
  }
  else {
    iVar2 = DAT_5b41_1a52;
    if (*(int *)(iVar3 + 0x10) != ((undefined2 *)&DAT_5b41_1a4e)[bVar1]) goto LAB_31f7_7799;
  }
  *(int *)(iVar3 + 0x10) = iVar2;
LAB_31f7_7799:
  FUN_28eb_3328(iVar3,uVar4);
  if ((*(int *)(iVar3 + 0x10) == ((undefined2 *)&DAT_5b41_1a4a)[bVar1] + 1) ||
     (*(int *)(iVar3 + 0x10) == ((undefined2 *)&DAT_5b41_1a4e)[bVar1] + 1)) {
    if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
      FUN_28eb_51b3(iVar3,uVar4,0x2000,0,0x10,0xffef,0);
      uVar6 = 0x10;
      uVar5 = 0;
    }
    else {
      FUN_28eb_51b3(iVar3,uVar4,0x2000,0x40,0x50,0xffef,0);
      uVar6 = 0x50;
      uVar5 = 0x40;
    }
    FUN_31f7_b9f5(iVar3,uVar4,0,uVar5,uVar6,0xffef,0);
  }
  return;
}

