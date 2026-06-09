// TIM2.EXE: FUN_31f7_9871 @ file 0x0409E1 Ghidra 0x3B7E1
// Subsystem: gfx | Size: 142 bytes


void __cdecl16far FUN_31f7_9871(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (param_2 == 0xf) {
    if (*(int *)(iVar1 + 0x10) < DAT_5b41_09ab) {
      *(int *)(iVar1 + 0x10) = DAT_5b41_09ab;
      if ((*(byte *)(iVar1 + 0xc) & 0x20) == 0) {
        *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x10;
      }
      *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xffdf;
    }
    else {
      *(undefined2 *)(iVar1 + 0x10) = 0;
      if ((*(byte *)(iVar1 + 0xc) & 0x10) != 0) {
        *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x20;
      }
      *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xffef;
    }
  }
  *(undefined2 *)(iVar1 + 0xa8) = *(undefined2 *)(iVar1 + 0x10);
  FUN_31f7_97c2(iVar1,param_1._2_2_);
  FUN_28eb_3328(iVar1,param_1._2_2_);
  FUN_2424_0f94(iVar1,param_1._2_2_,3);
  FUN_28eb_2d82(iVar1,param_1._2_2_,2);
  return;
}

