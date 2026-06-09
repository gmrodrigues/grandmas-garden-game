// TIM2.EXE: FUN_1000_49eb @ file 0x019BEB Ghidra 0x149EB
// Subsystem: utility | Size: 31 bytes


undefined2 * __cdecl16far FUN_1000_49eb(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined2 *puVar4;
  
  puVar4 = param_1;
  for (uVar3 = param_3 >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = puVar4;
    puVar4 = puVar4 + 1;
    puVar1 = param_2;
    param_2 = param_2 + 1;
    *puVar2 = *puVar1;
  }
  if ((param_3 & 1) != 0) {
    *(undefined1 *)puVar4 = *(undefined1 *)param_2;
  }
  return param_1;
}

