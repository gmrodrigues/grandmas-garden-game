// TIM2.EXE: FUN_1000_4a0a @ file 0x019C0A Ghidra 0x14A0A
// Subsystem: utility | Size: 40 bytes


void __cdecl16far FUN_1000_4a0a(undefined2 *param_1,uint param_2,undefined1 param_3)

{
  undefined2 *puVar1;
  uint uVar2;
  
  if (((uint)param_1 & 1) != 0) {
    if (param_2 == 0) {
      return;
    }
    puVar1 = param_1;
    param_1 = (undefined2 *)((int)param_1 + 1);
    *(undefined1 *)puVar1 = param_3;
    param_2 = param_2 - 1;
  }
  for (uVar2 = param_2 >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
    puVar1 = param_1;
    param_1 = param_1 + 1;
    *puVar1 = CONCAT11(param_3,param_3);
  }
  if ((param_2 & 1) != 0) {
    *(undefined1 *)param_1 = param_3;
  }
  return;
}

