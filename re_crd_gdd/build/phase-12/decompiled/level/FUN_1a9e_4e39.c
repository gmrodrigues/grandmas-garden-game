// TIM2.EXE: FUN_1a9e_4e39 @ file 0x024A19 Ghidra 0x1F819
// Subsystem: level | Size: 50 bytes


undefined1 __cdecl16far FUN_1a9e_4e39(int param_1)

{
  int iVar1;
  undefined1 local_3;
  
  iVar1 = FUN_1a9e_4e6b(param_1);
  if ((iVar1 == 0) && (param_1 != 0)) {
    local_3 = 0;
  }
  else {
    local_3 = *(undefined1 *)((int)(undefined2 *)&DAT_554c_4308 + param_1);
  }
  return local_3;
}

