// TIM2.EXE: FUN_1000_217f @ file 0x01737F Ghidra 0x1217F
// Subsystem: utility | Size: 75 bytes


undefined2 __cdecl16far FUN_1000_217f(undefined2 *param_1)

{
  undefined2 uVar1;
  undefined2 extraout_DX;
  undefined2 uVar2;
  undefined1 local_a [4];
  undefined1 local_6 [4];
  
  FUN_1000_185e(local_6);
  FUN_1000_1873(0x1000,local_a);
  uVar2 = extraout_DX;
  uVar1 = FUN_1000_551c(local_6,local_a);
  if (param_1 != (undefined2 *)0x0) {
    param_1[1] = uVar2;
    *param_1 = uVar1;
  }
  return uVar1;
}

