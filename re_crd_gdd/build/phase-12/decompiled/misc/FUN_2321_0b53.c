// TIM2.EXE: FUN_2321_0b53 @ file 0x028F63 Ghidra 0x23D63
// Subsystem: misc | Size: 127 bytes


undefined2 __cdecl16far FUN_2321_0b53(int param_1)

{
  undefined2 *puVar1;
  int in_DX;
  undefined4 local_a;
  
  if ((0 < param_1) &&
     (puVar1 = (undefined2 *)FUN_22de_01ec(param_1 * 0xba,0,9,1),
     puVar1 != (undefined2 *)0x0 || in_DX != 0)) {
    local_a = (undefined2 *)CONCAT22(in_DX,puVar1);
    while( true ) {
      param_1 = param_1 + -1;
      if (param_1 == 0) break;
      ((undefined2 *)local_a)[1] = local_a._2_2_;
      *local_a = (undefined2 *)local_a + 0x5d;
      local_a = (undefined2 *)CONCAT22(local_a._2_2_,(undefined2 *)local_a + 0x5d);
    }
    ((undefined2 *)local_a)[1] = DAT_5b41_04ff;
    *local_a = DAT_5b41_04fd;
    DAT_5b41_04fd = puVar1;
    DAT_5b41_04ff = in_DX;
    return 1;
  }
  return 0;
}

