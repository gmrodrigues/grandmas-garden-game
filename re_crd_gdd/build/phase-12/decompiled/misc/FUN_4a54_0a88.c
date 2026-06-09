// TIM2.EXE: FUN_4a54_0a88 @ file 0x0501C8 Ghidra 0x4AFC8
// Subsystem: misc | Size: 100 bytes


void __cdecl16far
FUN_4a54_0a88(int *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5,undefined2 param_6)

{
  int iVar1;
  
  *param_1 = *param_1 + ((uint)param_1[1] >> 4);
  param_1[1] = param_1[1] & 0xf;
  iVar1 = param_1[2];
  if (iVar1 != -3) {
    if (iVar1 == -2) {
      FUN_1a9e_610c(param_1,param_2,param_3,param_4,param_5,param_6);
      return;
    }
    if (iVar1 != -1) {
      FUN_1a9e_416a(param_1,param_2,param_3,param_4,param_5,param_6);
    }
  }
  return;
}

