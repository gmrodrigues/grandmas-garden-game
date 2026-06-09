// TIM2.EXE: FUN_1000_7b1d @ file 0x01CD1D Ghidra 0x17B1D
// Subsystem: utility | Size: 132 bytes


int * __cdecl16near FUN_1000_7b1d(int param_1,undefined2 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined4 local_6;
  
  local_6 = (int *)CONCAT22(param_2,(int *)(param_1 + 4));
  while( true ) {
    uVar4 = (undefined2)((ulong)local_6 >> 0x10);
    piVar2 = (int *)local_6;
    if (*local_6 == 0 && piVar2[1] == 0) break;
    if (piVar2[2] == 0 && piVar2[3] == 0) goto LAB_1000_7b9b;
    uVar3 = (undefined2)((ulong)param_3 >> 0x10);
    iVar1 = (int)param_3;
    iVar1 = FUN_1000_6348(*(undefined2 *)(iVar1 + 4),*(undefined2 *)(iVar1 + 6),
                          *(undefined2 *)(iVar1 + 8),*(undefined2 *)(iVar1 + 10),piVar2[2],piVar2[3]
                          ,*(undefined2 *)(iVar1 + 0xc),0);
    if (iVar1 != 0) goto LAB_1000_7b9b;
    local_6 = (int *)CONCAT22(uVar4,piVar2 + 8);
  }
  uVar4 = 0;
  piVar2 = (int *)0x0;
LAB_1000_7b9b:
  return (int *)CONCAT22(uVar4,piVar2);
}

