// TIM2.EXE: FUN_4bdc_2d09 @ file 0x053CC9 Ghidra 0x4EAC9
// Subsystem: physics | Size: 172 bytes


uint * __cdecl16far FUN_4bdc_2d09(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined2 uVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 local_6;
  
  if ((uint *)param_1 != (uint *)0x0 || param_1._2_2_ != 0) {
    uVar6 = (uint)((ulong)param_2 >> 0x10);
    puVar5 = (uint *)param_2;
    if (*param_1 < *param_2) {
      local_6 = param_1;
      do {
        uVar4 = local_6._2_2_;
        puVar3 = (uint *)local_6;
        uVar1 = ((uint *)local_6)[3];
        puVar2 = (uint *)((uint *)local_6)[2];
        local_6 = (uint *)CONCAT22(uVar1,puVar2);
        if (puVar2 == (uint *)0x0 && uVar1 == 0) break;
      } while (*local_6 < *param_2);
      puVar5[3] = uVar1;
      puVar5[2] = (uint)puVar2;
      puVar3[3] = uVar6;
      puVar3[2] = (uint)puVar5;
    }
    else {
      puVar5[3] = param_1._2_2_;
      puVar5[2] = (uint)(uint *)param_1;
      param_1 = (uint *)((ulong)param_2 & 0xffff);
    }
  }
  return (uint *)param_1;
}

