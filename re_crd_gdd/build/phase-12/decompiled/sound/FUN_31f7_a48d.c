// TIM2.EXE: FUN_31f7_a48d @ file 0x0415FD Ghidra 0x3C3FD
// Subsystem: sound | Size: 59 bytes


void __cdecl16far FUN_31f7_a48d(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar2 + 0x10);
  if (param_2 == 2) {
    *(undefined2 *)(iVar2 + 0x10) = 0x5a;
  }
  FUN_2424_2e7d(iVar2,uVar3,param_2);
  *(undefined2 *)(iVar2 + 0x10) = uVar1;
  return;
}

