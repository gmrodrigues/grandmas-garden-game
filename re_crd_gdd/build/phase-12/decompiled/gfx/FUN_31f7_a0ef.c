// TIM2.EXE: FUN_31f7_a0ef @ file 0x04125F Ghidra 0x3C05F
// Subsystem: gfx | Size: 227 bytes


void __cdecl16far FUN_31f7_a0ef(undefined4 param_1)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  if (*(int *)(iVar4 + 0x98) == 0) {
    uVar2 = FUN_1000_12bf(*(undefined2 *)(iVar4 + 0x96),6);
    *(undefined2 *)(iVar4 + 0x98) = uVar2;
  }
  if (*(int *)(iVar4 + 0x98) != 0) {
    puVar1 = (undefined2 *)*(undefined2 *)(iVar4 + 0x98);
    if (*(int *)(iVar4 + 0x4a) < *(int *)(iVar4 + 0x48)) {
      puVar1[3] = 0x20;
      *puVar1 = 0x20;
      puVar1[0x15] = 0;
      puVar1[6] = 0;
      iVar3 = *(int *)(iVar4 + 0x48) + -1;
      puVar1[0x12] = iVar3;
      puVar1[9] = iVar3;
      iVar3 = *(int *)(iVar4 + 0x48) + -0x21;
      puVar1[0xf] = iVar3;
      puVar1[0xc] = iVar3;
      puVar1[0x16] = 0x25;
      puVar1[0x13] = 0x25;
      puVar1[0x10] = 0x25;
      puVar1[1] = 0x25;
      puVar1[0xd] = 0;
      puVar1[10] = 0;
      puVar1[7] = 0;
      puVar1[4] = 0;
    }
    else {
      puVar1[0x15] = 0;
      puVar1[0x12] = 0;
      puVar1[0xf] = 0;
      *puVar1 = 0;
      puVar1[0xc] = 0x25;
      puVar1[9] = 0x25;
      puVar1[6] = 0x25;
      puVar1[3] = 0x25;
      puVar1[4] = 0x20;
      puVar1[1] = 0x20;
      puVar1[0x16] = 0;
      puVar1[7] = 0;
      iVar3 = *(int *)(iVar4 + 0x4a) + -1;
      puVar1[0x13] = iVar3;
      puVar1[10] = iVar3;
      iVar3 = *(int *)(iVar4 + 0x4a) + -0x21;
      puVar1[0x10] = iVar3;
      puVar1[0xd] = iVar3;
    }
    FUN_28eb_3670(iVar4,uVar5);
  }
  return;
}

