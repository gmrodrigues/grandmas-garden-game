// TIM2.EXE: FUN_1000_8ac3 @ file 0x01DCC3 Ghidra 0x18AC3
// Subsystem: utility | Size: 172 bytes


int __cdecl16far
FUN_1000_8ac3(int param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined2 param_5,
             int param_6)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (param_1 == 0 && param_2 == 0) {
    FUN_1000_6d2e(0x8f3e,0x1000,0x8aea,0x554c,0,0,0,0,0,0,0,0);
  }
  if ((param_2 == 0x554c) && (param_1 == 0)) {
    FUN_1000_6d2e(0x8f3e,0x1000,0x8aea,0x554c,0,0,0,0,0,0,0,0);
  }
  uVar3 = (undefined2)((ulong)param_3 >> 0x10);
  iVar2 = (int)param_3 - *(int *)((int)param_3 + -2);
  uVar1 = *(undefined2 *)(iVar2 + -8);
  *(undefined2 *)(param_6 + 6) = *(undefined2 *)(iVar2 + -6);
  *(undefined2 *)(param_6 + 4) = uVar1;
  return param_6;
}

