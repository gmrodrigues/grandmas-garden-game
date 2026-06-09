// TIM2.EXE: FUN_28eb_0d77 @ file 0x02EE27 Ghidra 0x29C27
// Subsystem: misc | Size: 100 bytes


int __cdecl16far FUN_28eb_0d77(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (*(int *)((int)param_1 + 0x22) + *(int *)((int)param_1 + 0x54) / 2) - DAT_5b41_1b84 >> 0xf
  ;
  iVar1 = FUN_1000_180a();
  iVar2 = FUN_1000_180a(iVar2);
  return iVar1 + iVar2;
}

