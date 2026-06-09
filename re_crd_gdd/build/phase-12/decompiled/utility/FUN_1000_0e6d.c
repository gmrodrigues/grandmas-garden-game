// TIM2.EXE: FUN_1000_0e6d @ file 0x01606D Ghidra 0x10E6D
// Subsystem: utility | Size: 189 bytes


undefined2 __cdecl16far FUN_1000_0e6d(undefined2 param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined2 uVar2;
  bool bVar3;
  
  if ((DAT_5b41_0469 != 0) && (iVar1 = FUN_1000_0abd(param_1), iVar1 != 0)) {
    if (*(int *)(iVar1 + 0x10) == 0) {
      if (param_4 == 1) {
        bVar3 = CARRY2(*(uint *)(iVar1 + 10),param_2);
        param_2 = *(uint *)(iVar1 + 10) + param_2;
        param_3 = *(int *)(iVar1 + 0xc) + param_3 + (uint)bVar3;
      }
      else if (param_4 == 2) {
        if ((param_3 < *(uint *)(iVar1 + 8)) ||
           ((*(uint *)(iVar1 + 8) == param_3 && (param_2 < *(uint *)(iVar1 + 6))))) {
          bVar3 = *(uint *)(iVar1 + 6) < param_2;
          param_2 = *(uint *)(iVar1 + 6) - param_2;
          param_3 = (*(int *)(iVar1 + 8) - param_3) - (uint)bVar3;
        }
        else {
          param_3 = 0;
          param_2 = 0;
        }
      }
      if ((*(uint *)(iVar1 + 8) <= param_3) &&
         ((*(uint *)(iVar1 + 8) < param_3 || (*(uint *)(iVar1 + 6) < param_2)))) {
        param_3 = *(uint *)(iVar1 + 8);
        param_2 = *(uint *)(iVar1 + 6);
      }
      *(uint *)(iVar1 + 0xc) = param_3;
      *(uint *)(iVar1 + 10) = param_2;
      return 0;
    }
    param_1 = *(undefined2 *)(iVar1 + 0x10);
  }
  uVar2 = FUN_1000_43c4(param_1,param_2,param_3,param_4);
  return uVar2;
}

