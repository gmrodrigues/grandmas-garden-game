// TIM2.EXE: FUN_31f7_3daa @ file 0x03AF1A Ghidra 0x35D1A
// Subsystem: misc | Size: 138 bytes


undefined2 __cdecl16far
FUN_31f7_3daa(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4,
             uint param_5)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_3 >> 0x10);
  iVar2 = (int)param_3;
  if (param_5 == 1) {
    piVar1 = (int *)(*(int *)(iVar2 + 0x76) + 0x18);
    *piVar1 = *piVar1 + 1;
    return 0;
  }
  if ((param_5 & 6) == 2) {
LAB_31f7_3e03:
    uVar3 = 1;
  }
  else {
    if ((param_5 & 6) == 4) {
      if (*(int *)(iVar2 + 0x10) == DAT_5b41_19d4) {
        *(undefined2 *)(iVar2 + 0x10) = DAT_5b41_19d2;
      }
      else if ((*(int *)(iVar2 + 0x16) != 0) || (DAT_5b41_19cc <= *(int *)(iVar2 + 0x10)))
      goto LAB_31f7_3e03;
    }
    if (((param_5 & 0x8006) == 4) && (*(int *)(iVar2 + 0x16) == 0)) {
      if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
        *(undefined2 *)(iVar2 + 0x16) = 0xffff;
      }
      else {
        *(undefined2 *)(iVar2 + 0x16) = 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}

