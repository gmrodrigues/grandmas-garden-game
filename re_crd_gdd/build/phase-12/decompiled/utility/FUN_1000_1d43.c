// TIM2.EXE: FUN_1000_1d43 @ file 0x016F43 Ghidra 0x11D43
// Subsystem: utility | Size: 97 bytes


void __cdecl16far FUN_1000_1d43(void)

{
  uint *puVar1;
  uint uVar2;
  undefined2 unaff_SS;
  undefined1 local_6 [2];
  undefined2 local_4;
  
  FUN_1000_27ad();
  FUN_1000_5c6b(local_6,0x59aa,0x554c,0,0,0x1e13,0x1000,1,0,0,0);
  local_4 = DAT_554c_59ac;
  puVar1 = (uint *)0x10;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + 1;
  *(int *)0x12 = *(int *)0x12 + (uint)(0xfffe < uVar2);
  FUN_1000_6d2e(0x1f17,0x1000,local_6);
  return;
}

