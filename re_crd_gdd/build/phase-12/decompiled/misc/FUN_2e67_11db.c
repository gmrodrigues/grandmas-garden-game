// TIM2.EXE: FUN_2e67_11db @ file 0x034A4B Ghidra 0x2F84B
// Subsystem: misc | Size: 156 bytes


void __cdecl16far FUN_2e67_11db(undefined2 *param_1,undefined2 *param_2,undefined2 param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 in_DX;
  
  uVar1 = FUN_2fc8_1438(param_3);
  uVar2 = FUN_2fc8_1410(param_3);
  uVar3 = FUN_2fc8_152f(*param_1,uVar1);
  FUN_2fc8_152f(*param_2,uVar2,in_DX,uVar3);
  uVar2 = FUN_2fc8_152f(*param_1,uVar2);
  FUN_2fc8_152f(*param_2,uVar1,in_DX,uVar2);
  uVar1 = FUN_1000_19bf();
  *param_1 = uVar1;
  uVar1 = FUN_1000_19bf();
  *param_2 = uVar1;
  return;
}

