// TIM2.EXE: FUN_460e_21ca @ file 0x04D4AA Ghidra 0x482AA
// Subsystem: misc | Size: 226 bytes


bool __cdecl16far FUN_460e_21ca(char *param_1,undefined2 param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  undefined2 unaff_SS;
  char local_1c [14];
  undefined4 local_e;
  undefined2 local_a;
  undefined2 local_8;
  int local_6;
  int local_4;
  
  bVar4 = false;
  if (DAT_5b41_1cea != '\0') {
    local_e = (char *)CONCAT22(param_2,param_1);
    pcVar3 = local_1c;
    do {
      pcVar2 = local_e;
      local_e = (char *)CONCAT22(local_e._2_2_,(char *)local_e + 1);
      cVar1 = *pcVar2;
      *pcVar3 = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    local_4 = 0;
    local_6 = 0;
    local_8 = 0;
    local_a = 0;
    FUN_1000_06d2(local_1c,local_1c,&local_a,&local_6);
    if (param_3 != 0) {
      return local_6 != 0 || local_4 != 0;
    }
    DAT_5b41_1ceb = 0;
    if (local_6 != 0 || local_4 != 0) {
      FUN_460e_2140();
      FUN_1000_136f(local_1c,unaff_SS,local_a,local_8,local_6,local_4,DAT_554c_3fd0,DAT_554c_3fd2,
                    DAT_5b41_1ced,0);
      FUN_1000_1376();
      DAT_5b41_1ceb = 0xffff;
      bVar4 = true;
    }
  }
  DAT_5b41_1ce8 = 0;
  DAT_5b41_1ce6 = 0;
  return bVar4;
}

