// TIM2.EXE: FUN_3e34_0085 @ file 0x0435C5 Ghidra 0x3E3C5
// Subsystem: sound | Size: 183 bytes


void __cdecl16far FUN_3e34_0085(undefined2 *param_1)

{
  int iVar1;
  undefined2 unaff_SS;
  uint local_14;
  undefined2 uStack_12;
  uint *local_a;
  
  if ((undefined2 *)param_1 != (undefined2 *)0x0 || param_1._2_2_ != 0) {
    FUN_1000_1842(0x3e34,*param_1,((undefined2 *)param_1)[1],&local_14);
    iVar1 = DAT_554c_3d5a;
    _local_a = (uint *)CONCAT22(unaff_SS,&local_14);
    if (*_local_a - (*_local_a & 0xff) == DAT_554c_3d5a) {
      FUN_3f2b_0e3a(*(undefined2 *)((*_local_a & 0xff) * 2));
      FUN_3f2b_0ffb(((uint *)_local_a)[1],iVar1);
      FUN_3f2b_118f();
    }
    else {
      FUN_22de_0351(uStack_12,*_local_a);
    }
    FUN_22de_0351((undefined2 *)param_1,param_1._2_2_);
  }
  return;
}

