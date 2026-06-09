// TIM2.EXE: FUN_1000_59e3 @ file 0x01ABE3 Ghidra 0x159E3
// Subsystem: utility | Size: 103 bytes


void __cdecl16far FUN_1000_59e3(int param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined2 unaff_SS;
  undefined1 local_6 [2];
  undefined2 local_4;
  
  FUN_1000_27ad();
  FUN_1000_5c6b(local_6,param_1,0x554c,0,0,0x5a4a,0x1000,1,0,0,0);
  local_4 = *(undefined2 *)(param_1 + 2);
  puVar1 = (uint *)0x10;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + 1;
  *(int *)0x12 = *(int *)0x12 + (uint)(0xfffe < uVar2);
  FUN_1000_6d2e(0x5a7b,0x1000,local_6);
  return;
}

