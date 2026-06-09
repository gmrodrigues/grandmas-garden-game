// TIM2.EXE: FUN_31f7_0dc8 @ file 0x037F38 Ghidra 0x32D38
// Subsystem: misc | Size: 253 bytes


void __cdecl16far FUN_31f7_0dc8(undefined4 param_1)

{
  int iVar1;
  int in_DX;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((((*(int *)(iVar2 + 0x16) != 0) &&
       (iVar1 = FUN_28eb_3783(iVar2,uVar3), iVar1 != 0 || in_DX != 0)) &&
      ((*(int *)(iVar1 + 8) == 0xe || (*(int *)(iVar1 + 8) == 0x56)))) &&
     (*(int *)(iVar1 + 0x12) == *(int *)(iVar1 + 0x14))) {
    *(undefined2 *)(iVar2 + 0x16) = 0;
  }
  if (*(int *)(iVar2 + 0x16) != 0) {
    iVar1 = (*(int *)(iVar2 + 0x48) + -0x20) / 0x10;
    if (*(int *)(iVar2 + 0x16) < 1) {
      if ((*(int *)(iVar2 + 0x10) == ((undefined2 *)&DAT_5b41_196c)[iVar1]) ||
         (*(int *)(iVar2 + 0x10) == ((undefined2 *)&DAT_5b41_1960)[iVar1])) {
        if ((DAT_5b41_051f & 1) == 0) {
          *(int *)(iVar2 + 0x10) = ((undefined2 *)&DAT_5b41_1960)[iVar1] + 2;
        }
        else {
          *(int *)(iVar2 + 0x10) = ((undefined2 *)&DAT_5b41_1962)[iVar1] + -1;
        }
      }
      else {
        *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -1;
      }
    }
    else {
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
      if (*(int *)(iVar2 + 0x10) == ((undefined2 *)&DAT_5b41_1962)[iVar1]) {
        if ((DAT_5b41_051f & 1) == 0) {
          *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -2;
        }
        else {
          *(undefined2 *)(iVar2 + 0x10) = ((undefined2 *)&DAT_5b41_196c)[iVar1];
        }
      }
    }
  }
  return;
}

