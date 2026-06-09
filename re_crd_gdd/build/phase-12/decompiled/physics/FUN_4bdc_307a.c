// TIM2.EXE: FUN_4bdc_307a @ file 0x05403A Ghidra 0x4EE3A
// Subsystem: physics | Size: 235 bytes


int __cdecl16far FUN_4bdc_307a(int param_1,int param_2,int param_3,undefined1 param_4)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  
  if (param_1 != 0 || param_2 != 0) {
    for (iVar4 = 0; iVar4 < 7; iVar4 = iVar4 + 1) {
      uVar1 = ((undefined2 *)&DAT_5b41_2862)[iVar4 * 2];
      iVar2 = ((undefined2 *)&DAT_5b41_2860)[iVar4 * 2];
      if (*(char *)(iVar2 + 0x158) == -1) {
        *(int *)(iVar2 + 0x168) = param_2;
        *(int *)(iVar2 + 0x166) = param_1;
        uVar3 = FUN_4bdc_2846(param_1,param_2);
        *(int *)(iVar2 + 0x16c) = param_1;
        *(undefined2 *)(iVar2 + 0x16a) = uVar3;
        if (DAT_554c_573e == 0) {
          *(undefined1 *)(iVar2 + 0x15d) = param_4;
          *(undefined1 *)(iVar2 + 0x15c) = 1;
          *(undefined1 *)(iVar2 + 0x15e) = (undefined1)param_3;
        }
        else {
          *(undefined1 *)(iVar2 + 0x15d) = *(undefined1 *)(DAT_554c_573e + param_3 * 2);
          *(undefined1 *)(iVar2 + 0x15c) = *(undefined1 *)(DAT_554c_573e + param_3 * 2 + 1);
          *(undefined1 *)(iVar2 + 0x15e) = 0x7f;
        }
        FUN_4bdc_22fd(iVar2,uVar1,0);
        return iVar2;
      }
    }
  }
  return 0;
}

