// TIM2.EXE: FUN_2424_2a1e @ file 0x02BE5E Ghidra 0x26C5E
// Subsystem: misc | Size: 71 bytes


void __cdecl16far FUN_2424_2a1e(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  if ((((DAT_5b41_051f & 2) != 0) || ((*(byte *)(iVar3 + 0xf) & 0x10) == 0)) &&
     (iVar1 = *(int *)(*(int *)(iVar3 + 8) * 2 + 0x302),
     *(int *)(iVar1 + 0x18) != 0 || *(int *)(iVar1 + 0x1a) != 0)) {
    puVar2 = (undefined2 *)(*(int *)(*(int *)(iVar3 + 8) * 2 + 0x302) + 0x18);
    (*(code *)*puVar2)(0x2424,iVar3,param_1._2_2_,param_2);
  }
  return;
}

