// TIM2.EXE: FUN_2321_0deb @ file 0x0291FB Ghidra 0x23FFB
// Subsystem: misc | Size: 268 bytes


undefined2 __cdecl16far FUN_2321_0deb(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  int iVar4;
  
  if ((int)param_1 != 0 || param_1._2_2_ != 0) {
    *(int *)((int)param_1 + 8) = param_2;
    *(undefined2 *)((int)param_1 + 10) = *(undefined2 *)(*(int *)(param_2 * 2 + 0x302) + 0x24);
    *(undefined2 *)((int)param_1 + 0xc) = *(undefined2 *)(*(int *)(param_2 * 2 + 0x302) + 0x26);
    *(undefined2 *)((int)param_1 + 0xe) = *(undefined2 *)(*(int *)(param_2 * 2 + 0x302) + 0x28);
    iVar4 = *(int *)(param_2 * 2 + 0x302);
    uVar1 = *(undefined2 *)(iVar4 + 0x2c);
    uVar2 = *(undefined2 *)(iVar4 + 0x2a);
    *(undefined2 *)((int)param_1 + 0x56) = uVar1;
    *(undefined2 *)((int)param_1 + 0x54) = uVar2;
    *(undefined2 *)((int)param_1 + 0x96) = *(undefined2 *)(*(int *)(param_2 * 2 + 0x302) + 0x22);
    *(undefined2 *)((int)param_1 + 0x3e) = *(undefined2 *)(*(int *)(param_2 * 2 + 0x302) + 0x38);
    *(undefined2 *)((int)param_1 + 0xa4) = 0xffff;
    *(undefined2 *)((int)param_1 + 0xa6) = 0xffff;
    uVar2 = *(undefined2 *)(*(int *)(param_2 * 2 + 0x302) + 0x2a);
    *(undefined2 *)((int)param_1 + 0x4a) = uVar1;
    *(undefined2 *)((int)param_1 + 0x48) = uVar2;
    iVar4 = *(int *)(param_2 * 2 + 0x302);
    if ((*(int *)(iVar4 + 0x1c) == 0 && *(int *)(iVar4 + 0x1e) == 0) ||
       (puVar3 = (undefined2 *)(*(int *)(param_2 * 2 + 0x302) + 0x1c),
       iVar4 = (*(code *)*puVar3)(0x2321,(int)param_1,param_1._2_2_), iVar4 != 0)) {
      puVar3 = (undefined2 *)(*(int *)(param_2 * 2 + 0x302) + 8);
      (*(code *)*puVar3)(0x2321,(int)param_1,param_1._2_2_);
      *(undefined2 *)((int)param_1 + 0xac) = *(undefined2 *)((int)param_1 + 0xc);
      FUN_28eb_3328((int)param_1,param_1._2_2_);
      return 1;
    }
  }
  return 0;
}

