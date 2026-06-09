// TIM2.EXE: FUN_50fb_03d4 @ file 0x056584 Ghidra 0x51384
// Subsystem: misc | Size: 162 bytes


void __cdecl16far FUN_50fb_03d4(int *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined2 unaff_SS;
  undefined2 local_24;
  undefined1 local_6 [2];
  undefined1 local_4 [2];
  
  FUN_1000_27ad();
  if (*(uint *)(*param_1 + 4) < param_2) {
    FUN_50fb_00d9(local_4,(char *)s_String_reference_out_of_range_554c_5ed2,0x554c,0,0,0xa251,0x1000
                  ,1,0,0,0);
    FUN_1000_5bc7(local_6,local_4);
    FUN_50fb_02c8(local_4,2);
    puVar1 = (uint *)0x10;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + 1;
    *(int *)0x12 = *(int *)0x12 + (uint)(0xfffe < uVar2);
    FUN_1000_6d2e(0xa32,0x1000,local_6);
  }
  *(undefined2 *)0x14 = local_24;
  return;
}

