// TIM2.EXE: FUN_4340_0520 @ file 0x048B20 Ghidra 0x43920
// Subsystem: misc | Size: 78 bytes


undefined2 __cdecl16far FUN_4340_0520(undefined2 param_1)

{
  int *piVar1;
  int in_DX;
  undefined4 local_6;
  
  piVar1 = (int *)FUN_3f2b_07a3(param_1);
  local_6 = (int *)CONCAT22(in_DX,piVar1);
  if (piVar1 != (int *)0x0 || in_DX != 0) {
    if ((piVar1[2] != 0 || piVar1[3] != 0) && (*local_6 != 0 || piVar1[1] != 0)) {
      FUN_4340_04aa(piVar1[4] * 1000);
      return 1;
    }
  }
  return 0;
}

