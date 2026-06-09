// TIM2.EXE: FUN_31f7_3e34 @ file 0x03AFA4 Ghidra 0x35DA4
// Subsystem: misc | Size: 64 bytes


void __cdecl16far FUN_31f7_3e34(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x10) == 0) {
    *(undefined2 *)(iVar1 + 0x98) =
         *(undefined2 *)*(undefined2 *)(*(int *)(*(int *)(iVar1 + 8) * 2 + 0x302) + 0x46);
  }
  else {
    *(undefined2 *)(iVar1 + 0x98) = 0;
  }
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

