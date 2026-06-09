// TIM2.EXE: FUN_460e_157d @ file 0x04C85D Ghidra 0x4765D
// Subsystem: misc | Size: 110 bytes


undefined2 __cdecl16far FUN_460e_157d(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  int in_DX;
  int iVar5;
  undefined4 local_6;
  
  if ((((param_1 == 0) && (param_2 == 0)) || (param_3 == 0)) ||
     (puVar2 = (undefined2 *)FUN_460e_0d51(param_1,param_2), puVar4 = puVar2, iVar5 = in_DX,
     puVar2 == (undefined2 *)0x0 && in_DX == 0)) {
    uVar3 = 0;
  }
  else {
    while (local_6 = (undefined2 *)CONCAT22(iVar5,puVar4), puVar4 != (undefined2 *)0x0 || iVar5 != 0
          ) {
      puVar4[8] = param_3;
      piVar1 = puVar4 + 1;
      iVar5 = *piVar1;
      puVar4 = (undefined2 *)*local_6;
    }
    FUN_460e_0b44(puVar2,in_DX);
    uVar3 = 1;
  }
  return uVar3;
}

