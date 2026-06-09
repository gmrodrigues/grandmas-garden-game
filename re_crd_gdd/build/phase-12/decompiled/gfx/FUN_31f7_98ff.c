// TIM2.EXE: FUN_31f7_98ff @ file 0x040A6F Ghidra 0x3B86F
// Subsystem: gfx | Size: 92 bytes


undefined2 __cdecl16far FUN_31f7_98ff(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar3 + 0x9c);
  iVar2 = *(int *)(iVar3 + 0x9a);
  if (*(int *)(iVar2 + 0x10) == 0) {
    iVar3 = *(int *)(iVar3 + 0xa2);
    if ((*(byte *)(iVar2 + 0xc) & 0x10) != 0) {
      iVar3 = (*(int *)(DAT_554c_03b4 + 0x22) - iVar3) + -2;
      if (iVar3 < 0) {
        iVar3 = iVar3 + *(int *)(DAT_554c_03b4 + 0x22);
      }
    }
    if (iVar3 == 0) {
      *(undefined2 *)(iVar2 + 0x16) = 1;
    }
  }
  return 1;
}

