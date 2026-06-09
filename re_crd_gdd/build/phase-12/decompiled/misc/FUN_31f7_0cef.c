// TIM2.EXE: FUN_31f7_0cef @ file 0x037E5F Ghidra 0x32C5F
// Subsystem: misc | Size: 217 bytes


undefined2 __cdecl16far FUN_31f7_0cef(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  uVar1 = *(uint *)(*(int *)(iVar5 + 0x9a) + 0x16);
  uVar4 = (int)uVar1 >> 0xf;
  if (((*(int *)(iVar5 + 0xa2) == 0) && ((*(byte *)(iVar5 + 0xd) & 0x10) == 0)) ||
     ((-0x801 < *(int *)(iVar5 + 0xa0) && (*(int *)(iVar5 + 0xa0) < 0x801)))) {
    iVar2 = (uVar1 ^ uVar4) - uVar4;
    iVar3 = iVar2 * 0x800;
    if ((int)uVar1 < 1) {
      if (-1 < (int)uVar1) {
        return 1;
      }
      *(int *)(iVar5 + 0x3a) = *(int *)(iVar5 + 0x3a) + iVar2 * -0x800;
      if (iVar3 <= *(int *)(iVar5 + 0x3a)) {
        return 1;
      }
      goto LAB_31f7_0db7;
    }
    *(int *)(iVar5 + 0x3a) = *(int *)(iVar5 + 0x3a) + iVar3;
    if (*(int *)(iVar5 + 0x3a) <= iVar3) {
      return 1;
    }
  }
  else {
    if (*(int *)(iVar5 + 0xa2) != 2) {
      return 1;
    }
    if ((*(byte *)(iVar5 + 0xd) & 0x10) != 0) {
      return 1;
    }
    iVar2 = (uVar1 ^ uVar4) - uVar4;
    iVar3 = iVar2 * 0x800;
    if (-1 < (int)uVar1) {
      if ((int)uVar1 < 1) {
        return 1;
      }
      *(int *)(iVar5 + 0x3a) = *(int *)(iVar5 + 0x3a) + iVar2 * -0x800;
      if (iVar3 <= *(int *)(iVar5 + 0x3a)) {
        return 1;
      }
LAB_31f7_0db7:
      *(int *)(iVar5 + 0x3a) = -iVar3;
      return 1;
    }
    *(int *)(iVar5 + 0x3a) = *(int *)(iVar5 + 0x3a) + iVar3;
    if (*(int *)(iVar5 + 0x3a) <= iVar3) {
      return 1;
    }
  }
  *(int *)(iVar5 + 0x3a) = iVar3;
  return 1;
}

