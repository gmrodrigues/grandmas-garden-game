// TIM2.EXE: FUN_28eb_3c0f @ file 0x031CBF Ghidra 0x2CABF
// Subsystem: misc | Size: 64 bytes


void FUN_28eb_3c0f(undefined2 param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar1 = FUN_2fc8_1410(param_3);
  FUN_2fc8_152f(param_4,uVar1);
  uVar1 = FUN_2fc8_1438(param_3);
  FUN_2fc8_152f(param_4,uVar1);
  uVar1 = FUN_1000_19bf();
  uVar2 = (undefined2)((ulong)param_2 >> 0x10);
  *(undefined2 *)((int)param_2 + 0x3a) = uVar1;
  uVar1 = FUN_1000_19bf();
  *(undefined2 *)((int)param_2 + 0x3c) = uVar1;
  return;
}

