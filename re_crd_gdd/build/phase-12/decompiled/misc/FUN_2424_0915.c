// TIM2.EXE: FUN_2424_0915 @ file 0x029D55 Ghidra 0x24B55
// Subsystem: misc | Size: 173 bytes


void __cdecl16far FUN_2424_0915(undefined4 param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (((int)param_1 != 0 || param_1._2_2_ != 0) && (DAT_5b41_050f == 0)) {
    if (*(int *)((int)param_1 + 8) == 7) {
      puVar1 = (undefined2 *)*(undefined2 *)((int)param_1 + 0x78);
    }
    else {
      if (*(int *)((int)param_1 + 8) == 8) {
        return;
      }
      if (*(int *)((int)param_1 + 8) == 10) {
        return;
      }
      if (*(int *)((int)param_1 + 8) == 0x4c) {
        return;
      }
      if ((DAT_5b41_0937 != 0x2000) && (iVar2 = *(int *)((int)param_1 + 0x58), iVar2 != 0)) {
        FUN_2424_09c2(*(undefined2 *)(iVar2 + 2),*(undefined2 *)(iVar2 + 4),param_2);
      }
      puVar1 = (undefined2 *)*(int *)((int)param_1 + 0x76);
      if (puVar1 != (undefined2 *)0x0) {
        FUN_2424_0a23(*puVar1,puVar1[1],param_2);
      }
      puVar1 = (undefined2 *)*(undefined2 *)((int)param_1 + 0x78);
    }
    if (puVar1 != (undefined2 *)0x0) {
      FUN_2424_0a23(*puVar1,puVar1[1],param_2);
    }
  }
  return;
}

