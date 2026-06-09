// TIM2.EXE: FUN_28eb_3328 @ file 0x0313D8 Ghidra 0x2C1D8
// Subsystem: misc | Size: 159 bytes


void __cdecl16far FUN_28eb_3328(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  int local_c;
  int local_a;
  int local_4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  local_4 = *(int *)(iVar3 + 8);
  iVar1 = *(int *)(local_4 * 2 + 0x68fe);
  *(undefined2 *)(iVar3 + 0x2e) = *(undefined2 *)(iVar3 + 0x22);
  *(undefined2 *)(iVar3 + 0x30) = *(undefined2 *)(iVar3 + 0x24);
  uVar2 = *(uint *)(iVar3 + 0xc);
  FUN_28eb_33c7(iVar3,uVar4);
  if (iVar1 != 0) {
    FUN_4551_03eb(iVar1,*(undefined2 *)(iVar3 + 0x10),&local_c);
    if ((uVar2 & 0x10) != 0) {
      local_c = (*(int *)(iVar3 + 0x44) - local_c) - *(int *)(iVar3 + 0x48);
    }
    *(int *)(iVar3 + 0x2e) = *(int *)(iVar3 + 0x2e) + local_c;
    if ((uVar2 & 0x20) == 0) {
      *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) + local_a;
    }
    else {
      *(int *)(iVar3 + 0x30) =
           *(int *)(iVar3 + 0x30) + ((*(int *)(iVar3 + 0x46) - local_a) - *(int *)(iVar3 + 0x4a));
    }
  }
  return;
}

