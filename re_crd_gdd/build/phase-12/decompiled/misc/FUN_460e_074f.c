// TIM2.EXE: FUN_460e_074f @ file 0x04BA2F Ghidra 0x4682F
// Subsystem: misc | Size: 123 bytes


int __cdecl16far FUN_460e_074f(undefined2 param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  int in_DX;
  undefined4 local_a;
  undefined4 local_6;
  
  puVar3 = (undefined2 *)FUN_460e_0a42(param_1);
  local_6 = (undefined2 *)CONCAT22(in_DX,puVar3);
  if (puVar3 == (undefined2 *)0x0 && in_DX == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = 0;
    local_a = (undefined2 *)CONCAT22(puVar3[1],(undefined2 *)*local_6);
    while ((undefined2 *)local_a != (undefined2 *)0x0 || local_a._2_2_ != 0) {
      uVar1 = ((undefined2 *)local_a)[1];
      puVar2 = (undefined2 *)*local_a;
      FUN_460e_0562(param_1,((undefined2 *)local_a)[2],0,0);
      iVar4 = iVar4 + 1;
      local_a = (undefined2 *)CONCAT22(uVar1,puVar2);
    }
    puVar3[2] = 0;
  }
  return iVar4;
}

