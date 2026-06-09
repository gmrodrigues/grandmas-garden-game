// TIM2.EXE: FUN_3f2b_0718 @ file 0x044BC8 Ghidra 0x3F9C8
// Subsystem: sound | Size: 139 bytes


undefined1 * __cdecl16far FUN_3f2b_0718(undefined2 param_1)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  int in_DX;
  int iVar3;
  undefined4 local_6;
  
  puVar1 = (undefined2 *)FUN_3f2b_0b8e(param_1,0);
  local_6 = (undefined2 *)CONCAT22(in_DX,puVar1);
  if ((puVar1 != (undefined2 *)0x0 || in_DX != 0) && (puVar1[1] != 0)) {
    iVar3 = in_DX;
    uVar2 = FUN_460e_06a6(0x5fc3,*local_6);
    FUN_4340_0a29((undefined1 *)&DAT_5b41_1aec,0x554c,uVar2,iVar3);
    if (DAT_5b41_1aec != '\0') {
      FUN_4340_0abb((undefined1 *)&DAT_5b41_1aec,0x554c,0x3d50,0x554c);
    }
    uVar2 = FUN_460e_06a6(0x5fc4,puVar1[1] & 0x7fff);
    FUN_4340_0abb((undefined1 *)&DAT_5b41_1aec,0x554c,uVar2,iVar3);
    return (undefined1 *)&DAT_5b41_1aec;
  }
  return (undefined1 *)0x0;
}

