// TIM2.EXE: FUN_28eb_2a59 @ file 0x030B09 Ghidra 0x2B909
// Subsystem: misc | Size: 34 bytes


void __cdecl16far FUN_28eb_2a59(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 local_a;
  
  local_a = (int *)CONCAT22(0x554c,param_2);
  if (*local_a == 0 && param_2[1] == 0) {
    iVar2 = *local_a;
    iVar3 = (int)((ulong)param_1 >> 0x10);
    piVar1 = (int *)param_1;
    piVar1[1] = param_2[1];
    *param_1 = iVar2;
    piVar1[3] = 0x554c;
    piVar1[2] = (int)param_2;
    param_2[1] = iVar3;
    *local_a = (int)piVar1;
    if (*param_1 != 0 || piVar1[1] != 0) {
      uVar4 = (undefined2)((ulong)*(undefined4 *)param_1 >> 0x10);
      iVar2 = (int)*(undefined4 *)param_1;
      *(int *)(iVar2 + 6) = iVar3;
      *(undefined2 *)(iVar2 + 4) = piVar1;
    }
    piVar1[5] = piVar1[5] & 0xc7ff;
    if (param_2 == (int *)&DAT_5b41_055f) {
      piVar1[5] = piVar1[5] | 0x800;
    }
    else if (param_2 == (int *)&DAT_5b41_0557) {
      piVar1[5] = piVar1[5] | 0x1000;
    }
    else if (param_2 == (int *)&DAT_5b41_054f) {
      piVar1[5] = piVar1[5] | 0x2000;
    }
    return;
  }
  FUN_28eb_2a7b();
  return;
}

