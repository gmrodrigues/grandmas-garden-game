// TIM2.EXE: FUN_1a9e_74bc @ file 0x02709C Ghidra 0x21E9C
// Subsystem: physics | Size: 157 bytes


void __cdecl16far FUN_1a9e_74bc(byte *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  byte local_f;
  byte *local_e;
  byte *local_a;
  undefined4 local_6;
  
  local_f = 0x80;
  pbVar1 = (byte *)param_2 + param_3;
  local_6._2_2_ = (undefined2)((ulong)param_2 >> 0x10);
  local_6 = (byte *)CONCAT22(local_6._2_2_,pbVar1);
  local_a = (byte *)CONCAT22(local_6._2_2_,pbVar1 + param_3);
  local_e = (byte *)CONCAT22(local_6._2_2_,pbVar1 + param_3 + param_3);
  while (param_3 != 0) {
    bVar2 = (*param_2 & local_f) != 0;
    if ((*local_6 & local_f) != 0) {
      bVar2 = bVar2 | 2;
    }
    if ((*local_a & local_f) != 0) {
      bVar2 = bVar2 | 4;
    }
    if ((*local_e & local_f) != 0) {
      bVar2 = bVar2 | 8;
    }
    *param_1 = bVar2;
    param_1 = (byte *)CONCAT22(param_1._2_2_,(byte *)param_1 + 1);
    local_f = local_f >> 1;
    if (local_f == 0) {
      param_3 = param_3 + -1;
      local_f = 0x80;
      param_2 = (byte *)CONCAT22(param_2._2_2_,(byte *)param_2 + 1);
      local_6 = (byte *)CONCAT22(local_6._2_2_,(byte *)local_6 + 1);
      local_a = (byte *)CONCAT22(local_a._2_2_,(byte *)local_a + 1);
      local_e = (byte *)CONCAT22(local_e._2_2_,(byte *)local_e + 1);
    }
  }
  return;
}

