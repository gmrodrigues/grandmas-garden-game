// TIM2.EXE: FUN_311b_0d2b @ file 0x0370DB Ghidra 0x31EDB
// Subsystem: misc | Size: 164 bytes


bool __cdecl16far FUN_311b_0d2b(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 in_DX;
  
  if (DAT_5b41_0949 == DAT_5b41_094b) {
    uVar1 = FUN_4340_06ef(0x86b);
    FUN_1000_53c0(0x6c90,0x3027,uVar1,in_DX);
  }
  else {
    if (param_1 == 0) {
      uVar1 = 0x68a5;
      uVar2 = 0x68b0;
    }
    else {
      uVar1 = 0x68b0;
      uVar2 = 0x68a5;
    }
    uVar3 = FUN_4340_06ef(0x86a);
    FUN_1000_53c0(0x6c90,0x3017,uVar1,0x554c,uVar2,0x554c,uVar3,in_DX);
  }
  iVar4 = FUN_54a4_0043(0,(undefined2 *)&DAT_5b41_1a62,0x798f,(undefined2 *)&DAT_5b41_1a3e,0);
  return iVar4 == 0;
}

