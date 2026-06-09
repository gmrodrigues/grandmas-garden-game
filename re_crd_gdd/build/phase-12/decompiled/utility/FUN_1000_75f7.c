// TIM2.EXE: FUN_1000_75f7 @ file 0x01C7F7 Ghidra 0x175F7
// Subsystem: utility | Size: 131 bytes


int __cdecl16far
FUN_1000_75f7(int param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined2 param_5)

{
  int iVar1;
  undefined2 uVar2;
  
  if (((param_1 != 0 || param_2 != 0) &&
      (uVar2 = (undefined2)((ulong)param_3 >> 0x10),
      iVar1 = FUN_1000_752b((int)param_3 + *(int *)((int)param_3 + 10),uVar2,0,param_4,param_5,
                            &param_1), iVar1 == 0)) &&
     (uVar2 = (undefined2)((ulong)param_3 >> 0x10),
     iVar1 = FUN_1000_752b((int)param_3 + *(int *)((int)param_3 + 0xc),uVar2,1,param_4,param_5,
                           &param_1), iVar1 == 0)) {
    param_1 = 0;
  }
  return param_1;
}

