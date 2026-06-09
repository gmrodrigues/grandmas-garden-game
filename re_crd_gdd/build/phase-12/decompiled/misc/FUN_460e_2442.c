// TIM2.EXE: FUN_460e_2442 @ file 0x04D722 Ghidra 0x48522
// Subsystem: misc | Size: 277 bytes


undefined2 __cdecl16far FUN_460e_2442(int param_1)

{
  int iVar1;
  uint uVar2;
  int in_DX;
  int iVar3;
  undefined4 local_e;
  undefined4 local_a;
  
  if (DAT_5b41_1cf4 != (char *)0x0 || DAT_5b41_1cf6 != 0) {
    FUN_460e_2557();
  }
  if ((param_1 != 0) && (iVar1 = FUN_1000_0b20(param_1,0x3fe0), iVar1 != 0)) {
    FUN_1000_0e6d(iVar1,0,0,2);
    uVar2 = FUN_1000_0f2a(iVar1);
    FUN_1000_0e6d(iVar1,0,0,0);
    iVar3 = in_DX + (uint)(0xfffe < uVar2);
    DAT_5b41_1cf4 = (char *)FUN_22de_01ec(uVar2 + 1,iVar3,0xb,1);
    DAT_5b41_1cf6 = iVar3;
    if (DAT_5b41_1cf4 != (char *)0x0 || iVar3 != 0) {
      FUN_1000_0de2(DAT_5b41_1cf4,iVar3,uVar2,in_DX,1,0,iVar1);
      FUN_1000_0c9d(iVar1);
      local_e = (char *)CONCAT22(DAT_5b41_1cf6,DAT_5b41_1cf4);
      local_a = (char *)CONCAT22(DAT_5b41_1cf6,DAT_5b41_1cf4);
      do {
        if (*local_a == '\0') {
          *local_e = '\0';
          local_e = (char *)CONCAT22(local_e._2_2_,(char *)local_e + 1);
          *local_e = '\0';
          return 1;
        }
        if (*local_a == '\r') {
          *local_e = '\0';
LAB_460e_252d:
          local_e = (char *)CONCAT22(local_e._2_2_,(char *)local_e + 1);
        }
        else if (*local_a != '\n') {
          *local_e = *local_a;
          goto LAB_460e_252d;
        }
        local_a = (char *)CONCAT22(local_a._2_2_,(char *)local_a + 1);
      } while( true );
    }
    FUN_1000_0c9d(iVar1);
  }
  return 0;
}

