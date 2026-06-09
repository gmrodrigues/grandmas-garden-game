// TIM2.EXE: FUN_31f7_3011 @ file 0x03A181 Ghidra 0x34F81
// Subsystem: misc | Size: 385 bytes


void __cdecl16far FUN_31f7_3011(undefined4 param_1)

{
  int iVar1;
  int in_DX;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined2 uVar5;
  int local_4;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((((*(int *)(iVar2 + 0x16) != 0) &&
       (iVar1 = FUN_28eb_3783(iVar2,uVar5), iVar1 != 0 || in_DX != 0)) &&
      ((*(int *)(iVar1 + 8) == 0xe || (*(int *)(iVar1 + 8) == 0x56)))) &&
     (*(int *)(iVar1 + 0x12) == *(int *)(iVar1 + 0x14))) {
    *(undefined2 *)(iVar2 + 0x16) = 0;
  }
  if (*(int *)(iVar2 + 0x16) == 0) goto LAB_31f7_3153;
  uVar4 = (uint)(*(int *)(iVar2 + 0x6e) != 0 || *(int *)(iVar2 + 0x70) != 0);
  if (*(int *)(iVar2 + 0x72) != 0 || *(int *)(iVar2 + 0x74) != 0) {
    uVar4 = uVar4 | 2;
  }
  if (*(int *)(iVar2 + 0x10) < 4) {
    *(undefined2 *)(iVar2 + 0x10) = ((undefined2 *)&DAT_5b41_19ba)[uVar4];
  }
  if (*(int *)(iVar2 + 0x16) < 1) {
    if (*(int *)(iVar2 + 0x10) == ((undefined2 *)&DAT_5b41_19ba)[uVar4]) {
      *(int *)(iVar2 + 0x10) = ((undefined2 *)&DAT_5b41_19bc)[uVar4] + -1;
    }
    else {
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -1;
    }
  }
  else {
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
    if (*(int *)(iVar2 + 0x10) == ((undefined2 *)&DAT_5b41_19bc)[uVar4]) {
      *(undefined2 *)(iVar2 + 0x10) = ((undefined2 *)&DAT_5b41_19ba)[uVar4];
    }
  }
  if ((DAT_5b41_051f & 1) == 0) {
    if (*(int *)(iVar2 + 0x10) == ((undefined2 *)&DAT_5b41_19ba)[uVar4] + 2) {
      iVar1 = ((undefined2 *)&DAT_5b41_19ba)[uVar4];
    }
    else {
      if (*(int *)(iVar2 + 0x10) <= ((undefined2 *)&DAT_5b41_19ba)[uVar4] + 2) goto LAB_31f7_3145;
      iVar1 = ((undefined2 *)&DAT_5b41_19ba)[uVar4] + 1;
    }
    *(int *)(iVar2 + 0x10) = iVar1;
  }
LAB_31f7_3145:
  FUN_28eb_3328(iVar2,uVar5);
LAB_31f7_3153:
  for (local_4 = 4; local_4 < 6; local_4 = local_4 + 1) {
    iVar3 = iVar2 + local_4 * 4;
    iVar1 = *(int *)(iVar3 + 0x60);
    iVar3 = *(int *)(iVar3 + 0x5e);
    if (iVar3 != 0 || iVar1 != 0) {
      *(undefined2 *)(iVar3 + 0x16) = *(undefined2 *)(iVar2 + 0x16);
    }
  }
  return;
}

