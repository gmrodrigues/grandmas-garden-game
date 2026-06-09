// TIM2.EXE: FUN_1000_74bd @ file 0x01C6BD Ghidra 0x174BD
// Subsystem: utility | Size: 110 bytes


void __cdecl16far FUN_1000_74bd(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int iVar4;
  int *piVar5;
  undefined2 *puVar6;
  undefined2 unaff_SS;
  undefined4 local_6;
  
  piVar5 = (int *)*(undefined4 *)0x16;
  iVar1 = ((int *)piVar5)[1];
  puVar2 = (undefined2 *)*piVar5;
  local_6 = (undefined2 *)CONCAT22(iVar1,puVar2);
  uVar3 = *local_6;
  puVar6 = (undefined2 *)*(undefined4 *)0x16;
  ((undefined2 *)puVar6)[1] = puVar2[1];
  *puVar6 = uVar3;
  iVar4 = puVar2[0x11];
  *(undefined2 *)(iVar4 + 0xc) =
       *(undefined2 *)((int)*(undefined4 *)(iVar4 + 6) + *(int *)(iVar4 + 0xc));
  FUN_1000_73f2(puVar2,iVar1);
  (*(code *)puVar2[0xc])(0x1000,puVar2,iVar1);
  return;
}

