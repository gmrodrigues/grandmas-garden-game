// TIM2.EXE: FUN_1000_9d12 @ file 0x01EF12 Ghidra 0x19D12
// Subsystem: utility | Size: 40 bytes


void FUN_1000_9d12(int param_1,int param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  
  uVar1 = CONCAT11(DAT_554c_5e50,0x20);
  for (; param_2 <= param_1; param_2 = param_2 + 1) {
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return;
}

