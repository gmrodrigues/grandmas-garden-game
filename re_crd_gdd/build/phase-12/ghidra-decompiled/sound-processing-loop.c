// Sound processing loop at file 0x42200
// Function: FUN_31f7_b045


undefined2 __cdecl16far FUN_31f7_b045(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0xa2) == 0) {
    FUN_2424_0f94(iVar2,uVar3,3);
    *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 0x2000;
    if (*(int *)(*(int *)(iVar2 + 0x9a) + 0x10) < 8) {
      piVar1 = (int *)(*(int *)(iVar2 + 0x9a) + 0x10);
      *piVar1 = *piVar1 + 8;
    }
  }
  return 1;
}

