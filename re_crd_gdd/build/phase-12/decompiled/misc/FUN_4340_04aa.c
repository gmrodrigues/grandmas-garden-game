// TIM2.EXE: FUN_4340_04aa @ file 0x048AAA Ghidra 0x438AA
// Subsystem: misc | Size: 118 bytes


void __cdecl16far FUN_4340_04aa(undefined2 param_1)

{
  int *piVar1;
  int in_DX;
  undefined4 local_6;
  
  piVar1 = (int *)FUN_4340_07f3(param_1);
  local_6 = (int *)CONCAT22(in_DX,piVar1);
  if (piVar1 != (int *)0x0 || in_DX != 0) {
    if (*local_6 != 0 || piVar1[1] != 0) {
      FUN_22de_0351(*local_6,piVar1[1]);
    }
    if (piVar1[2] != 0 || piVar1[3] != 0) {
      FUN_22de_0351(piVar1[2],piVar1[3]);
    }
    piVar1[1] = 0;
    *local_6 = 0;
    piVar1[3] = 0;
    piVar1[2] = 0;
    piVar1[6] = 0;
  }
  return;
}

