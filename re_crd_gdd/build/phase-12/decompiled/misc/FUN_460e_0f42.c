// TIM2.EXE: FUN_460e_0f42 @ file 0x04C222 Ghidra 0x47022
// Subsystem: misc | Size: 86 bytes


undefined2 * __cdecl16far FUN_460e_0f42(int param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 local_6;
  
  if (param_1 == 0) {
    return DAT_5b41_1c0e;
  }
  puVar2 = DAT_5b41_1c0e;
  iVar3 = DAT_5b41_1c10;
  if (param_1 != -1) {
    for (; (local_6 = (undefined2 *)CONCAT22(iVar3,puVar2),
           puVar2 != (undefined2 *)0x0 || iVar3 != 0 && (puVar2[6] != param_1)); iVar3 = *piVar1) {
      piVar1 = puVar2 + 1;
      puVar2 = (undefined2 *)*local_6;
    }
    return puVar2;
  }
  return DAT_5b41_1c12;
}

