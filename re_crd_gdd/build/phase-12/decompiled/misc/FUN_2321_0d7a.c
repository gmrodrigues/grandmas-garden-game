// TIM2.EXE: FUN_2321_0d7a @ file 0x02918A Ghidra 0x23F8A
// Subsystem: misc | Size: 57 bytes


void __cdecl16far FUN_2321_0d7a(undefined2 *param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  
  while ((undefined2 *)param_1 != (undefined2 *)0x0 || param_1._2_2_ != 0) {
    uVar1 = ((undefined2 *)param_1)[1];
    puVar2 = (undefined2 *)*param_1;
    FUN_2321_0c23((undefined2 *)param_1,param_1._2_2_);
    param_1 = (undefined2 *)CONCAT22(uVar1,puVar2);
  }
  return;
}

