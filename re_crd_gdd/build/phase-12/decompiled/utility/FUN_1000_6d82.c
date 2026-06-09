// TIM2.EXE: FUN_1000_6d82 @ file 0x01BF82 Ghidra 0x16D82
// Subsystem: utility | Size: 165 bytes


void __cdecl16far FUN_1000_6d82(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_SS;
  undefined2 in_stack_00000000;
  undefined2 in_stack_00000002;
  
  piVar3 = (int *)*(undefined4 *)0x16;
  iVar1 = ((int *)piVar3)[1];
  iVar2 = *piVar3;
  if (iVar2 == 0 && iVar1 == 0) {
    FUN_1000_287e();
  }
  if (*(char *)(iVar2 + 0x34) == '\0') {
    iVar4 = *(int *)(iVar2 + 0x32);
  }
  else {
    iVar4 = iVar2 + 0x36;
    unaff_SS = iVar1;
  }
  FUN_1000_6a1e(*(undefined2 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 6),iVar4,unaff_SS,
                *(undefined2 *)(iVar2 + 8),*(undefined2 *)(iVar2 + 10),*(undefined2 *)(iVar2 + 0x1c)
                ,*(undefined2 *)(iVar2 + 0x1e),*(undefined2 *)(iVar2 + 0x20),
                *(undefined2 *)(iVar2 + 0xc),param_1,param_2,in_stack_00000000,in_stack_00000002,1);
  return;
}

