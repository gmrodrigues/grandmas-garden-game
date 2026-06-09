// TIM2.EXE: FUN_31f7_a1d2 @ file 0x041342 Ghidra 0x3C142
// Subsystem: sound | Size: 55 bytes


undefined2 __cdecl16far FUN_31f7_a1d2(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined2 uVar3;
  int in_CX;
  undefined2 in_DX;
  int iVar4;
  int unaff_SI;
  int iVar5;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  int iStackY_a;
  undefined2 uStackY_8;
  int iVar6;
  
  if (3 < DAT_5b41_0939 + 0x7ffdU) {
    *(undefined2 *)((int)param_1 + 0x48) = *(undefined2 *)((int)param_1 + 0x54);
    *(undefined2 *)((int)param_1 + 0x4a) = *(undefined2 *)((int)param_1 + 0x56);
    uVar3 = FUN_31f7_a0ef((int)param_1,param_1._2_2_);
    return uVar3;
  }
  iVar6 = (DAT_5b41_0939 + 0x7ffdU) * 2;
  switch(DAT_5b41_0939) {
  case -0x7ffd:
    iVar4 = unaff_SI + (int)&stack0xfffe * 4;
    iVar5 = unaff_DI + (int)&stack0xfffe * 8 + iVar4 * 4;
    *(undefined1 **)
     ((char *)s_c__config_sys_554c_36d6 + 6 + (int)&stack0xfffe * 4 + iVar4 + iVar5 * 3) =
         &stack0xfffe +
         *(int *)((char *)s_c__config_sys_554c_36d6 + 6 + (int)&stack0xfffe * 4 + iVar4 + iVar5 * 3)
         + iVar5 + iVar4 * 2 + in_CX;
    uVar2 = *(int *)(&stack0x0002 + iVar5 + iVar4 * 2 + iVar6) + 0xc000U >> 4;
    if ((uVar2 & 0x800) != 0) {
      uVar2 = 0x1000 - uVar2;
    }
    return *(undefined2 *)(uVar2 * 2 + 0xe);
  case -0x7ffb:
    uVar3 = (undefined2)((ulong)param_2 >> 0x10);
    puVar1 = (uint *)((int)param_2 + 0xc);
    *puVar1 = *puVar1 | 0x200;
    if ((*(byte *)((int)param_2 + 0xd) & 2) == 0) {
      if (unaff_DI == 2) {
        *(int *)(iStackY_a + 0x18) = *(int *)(iStackY_a + 0x18) + 1;
      }
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    return uVar3;
  case -0x7ffa:
    *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + 1;
    uVar3 = FUN_28eb_3328();
    return uVar3;
  }
  in(in_DX);
  if (*(int *)(iVar6 + 8) == 0x21) {
    *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) ^ 0x10;
    FUN_31f7_3f13(iVar6);
    uStackY_8 = *(undefined2 *)((int)param_1 + 0x9c);
    iStackY_a = *(int *)((int)param_1 + 0x9a);
    uVar2 = *(int *)((int)param_1 + 0xa0) + 0x8000;
    iVar6 = (int)param_1;
    uVar3 = param_1._2_2_;
  }
  else {
    iStackY_a = (int)param_1;
    uStackY_8 = param_1._2_2_;
    uVar3 = *(undefined2 *)((int)param_1 + 0x9c);
    iVar6 = *(int *)((int)param_1 + 0x9a);
    uVar2 = *(uint *)((int)param_1 + 0xa0);
  }
  if (((*(int *)(iStackY_a + 8) == 4) || (*(int *)(iStackY_a + 8) == 0x4f)) ||
     (*(int *)(iStackY_a + 8) == 0x6d)) {
    if ((*(byte *)(iVar6 + 0xc) & 0x10) == 0) {
      if ((uVar2 & 0x8000) == 0) {
        return 1;
      }
      iVar6 = *(int *)(iStackY_a + 8);
    }
    else {
      if ((uVar2 & 0x8000) != 0) {
        return 1;
      }
      iVar6 = *(int *)(iStackY_a + 8);
    }
    if (iVar6 == 0x4f) {
      *(undefined2 *)(iStackY_a + 0x16) = 2;
    }
    else {
      *(undefined2 *)(iStackY_a + 0x16) = 1;
    }
  }
  return 1;
}

