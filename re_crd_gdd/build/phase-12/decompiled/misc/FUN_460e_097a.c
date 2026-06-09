// TIM2.EXE: FUN_460e_097a @ file 0x04BC5A Ghidra 0x46A5A
// Subsystem: misc | Size: 200 bytes


int * __cdecl16far FUN_460e_097a(undefined2 param_1)

{
  int *piVar1;
  int *piVar2;
  int in_DX;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  undefined4 local_e;
  undefined4 local_a;
  
  piVar1 = (int *)FUN_460e_0a42(param_1);
  local_e = (int *)CONCAT22(in_DX,piVar1);
  if ((piVar1 != (int *)0x0 || in_DX != 0) && (*local_e != 0 || piVar1[1] != 0)) {
    iVar5 = 0;
    piVar2 = piVar1;
    iVar6 = in_DX;
    while( true ) {
      iVar3 = piVar2[1];
      piVar2 = (int *)*piVar2;
      if (piVar2 == (int *)0x0 && iVar3 == 0) break;
      iVar5 = iVar5 + 1;
      iVar6 = iVar3;
    }
    piVar2 = (int *)FUN_22de_01ec(iVar5 * 4 + 4,0,0xb,0);
    if (piVar2 != (int *)0x0 || iVar3 != 0) {
      local_a = (int *)CONCAT22(iVar3,piVar2);
      while( true ) {
        iVar6 = piVar1[1];
        piVar1 = (int *)*piVar1;
        piVar4 = (int *)local_a;
        uVar7 = (undefined2)((ulong)local_a >> 0x10);
        if (piVar1 == (int *)0x0 && iVar6 == 0) break;
        piVar4[1] = iVar6;
        *local_a = (int)piVar1 + 7;
        local_a = (int *)CONCAT22(uVar7,piVar4 + 2);
        in_DX = iVar6;
      }
      piVar4[1] = 0;
      *local_a = 0;
      return piVar2;
    }
  }
  return (int *)0x0;
}

