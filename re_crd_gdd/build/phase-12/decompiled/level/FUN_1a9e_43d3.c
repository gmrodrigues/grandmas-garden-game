// TIM2.EXE: FUN_1a9e_43d3 @ file 0x023FB3 Ghidra 0x1EDB3
// Subsystem: level | Size: 106 bytes


void __cdecl16far FUN_1a9e_43d3(undefined2 param_1,int param_2,int param_3,undefined2 param_4)

{
  int iVar1;
  int iVar2;
  
  FUN_1000_180a();
  iVar1 = FUN_1000_19bf();
  FUN_1000_180a();
  iVar2 = FUN_1000_19bf();
  FUN_1a9e_416a(param_1,param_2 - (iVar1 >> 1),param_3 - (iVar2 >> 1),param_4,iVar1,iVar2);
  return;
}

