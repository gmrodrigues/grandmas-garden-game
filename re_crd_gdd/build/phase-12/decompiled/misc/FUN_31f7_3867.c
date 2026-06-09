// TIM2.EXE: FUN_31f7_3867 @ file 0x03A9D7 Ghidra 0x357D7
// Subsystem: misc | Size: 116 bytes


void __cdecl16far FUN_31f7_3867(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  
  uVar9 = (undefined2)((ulong)param_1 >> 0x10);
  iVar7 = (int)param_1;
  iVar2 = *(int *)(iVar7 + 0x24);
  uVar10 = (undefined2)((ulong)param_2 >> 0x10);
  iVar8 = (int)param_2;
  iVar5 = *(int *)(iVar8 + 0x22) + (int)*(char *)(iVar8 + 0x82);
  iVar3 = *(int *)(iVar8 + 0x24);
  cVar1 = *(char *)(iVar8 + 0x83);
  if ((*(byte *)(iVar7 + 0xc) & 0x10) == 0) {
    iVar5 = iVar5 - (*(int *)(iVar7 + 0x22) + *(int *)(iVar7 + 0x54));
  }
  else {
    iVar5 = *(int *)(iVar7 + 0x22) - iVar5;
  }
  *param_3 = iVar5;
  uVar4 = (iVar2 + 0xb) - (iVar3 + cVar1);
  uVar6 = (int)uVar4 >> 0xf;
  *param_4 = (uVar4 ^ uVar6) - uVar6;
  return;
}

