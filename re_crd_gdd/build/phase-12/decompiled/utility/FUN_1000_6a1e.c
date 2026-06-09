// TIM2.EXE: FUN_1000_6a1e @ file 0x01BC1E Ghidra 0x16A1E
// Subsystem: utility | Size: 764 bytes


void __cdecl16far
FUN_1000_6a1e(int *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8,
             undefined2 param_9,undefined2 param_10,undefined2 param_11,undefined2 param_12,
             undefined2 param_13,int param_14)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 unaff_SS;
  undefined2 local_46;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 *local_3e;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  undefined4 local_36;
  undefined4 local_32;
  uint local_2e;
  uint local_2c;
  int local_2a;
  int *local_28;
  int iStack_26;
  undefined4 local_24;
  undefined2 local_20;
  undefined2 local_14;
  
  FUN_1000_27ad();
  local_24 = param_1;
  if ((DAT_5b41_2a7c != (code *)0x0 || DAT_5b41_2a7e != 0) && (param_14 == 0)) {
    (*DAT_5b41_2a7c)(0x1000,((int *)param_1)[2] + (int)(int *)param_1,param_12,param_13);
  }
  *(undefined2 *)((int)*(undefined4 *)0x16 + 6) = 0x554c;
  *(undefined2 *)((int)*(undefined4 *)0x16 + 0x1a) = 0x8868;
  iVar6 = (int)((ulong)local_24 >> 0x10);
  local_28 = (int *)local_24;
  local_36 = (char *)CONCAT22(iVar6,(char *)((int)local_28 + local_28[2]));
  pcVar3 = (char *)*(undefined2 *)((int)*(undefined4 *)0x16 + 0x1a);
  while (*local_36 != '\0') {
    if (pcVar3 < (char *)(*(int *)((int)*(undefined4 *)0x16 + 0x1a) + 0x7f)) {
      *pcVar3 = *local_36;
      pcVar3 = pcVar3 + 1;
    }
    local_36 = (char *)CONCAT22(local_36._2_2_,(char *)local_36 + 1);
  }
  *pcVar3 = '\0';
  *(undefined2 *)((int)*(undefined4 *)0x16 + 0x18) = param_10;
  *(undefined2 *)((int)*(undefined4 *)0x16 + 0x16) = param_11;
  local_2a = *local_24;
  local_2c = local_28[1];
  if ((local_2c & 2) == 0) {
    local_2e = 0;
  }
  else {
    local_2e = local_28[4];
  }
  iVar4 = iVar6;
  if ((local_2c & 0x30) != 0) {
    iVar4 = local_28[4];
    local_28 = (int *)local_28[3];
  }
  iStack_26 = iVar4;
  puVar2 = (undefined2 *)FUN_1000_62c3(local_2a + 0x36);
  local_32 = (undefined2 *)CONCAT22(iVar4,puVar2);
  puVar1 = (undefined2 *)*(undefined4 *)0x16;
  uVar7 = *puVar1;
  puVar2[1] = ((undefined2 *)puVar1)[1];
  *local_32 = uVar7;
  puVar1 = (undefined2 *)*(undefined4 *)0x16;
  ((undefined2 *)puVar1)[1] = iVar4;
  *puVar1 = puVar2;
  puVar2[3] = local_24._2_2_;
  puVar2[2] = (int *)local_24;
  puVar2[6] = param_9;
  puVar2[7] = local_2a;
  puVar2[10] = local_2c;
  puVar2[0xb] = local_2e;
  puVar2[9] = iStack_26;
  puVar2[8] = local_28;
  puVar2[5] = param_5;
  puVar2[4] = param_4;
  puVar2[0x11] = 0;
  puVar2[0x13] = 0;
  puVar2[0x12] = 0;
  puVar2[0xd] = 0x1000;
  puVar2[0xc] = 0x6315;
  puVar2[0x15] = param_10;
  puVar2[0x16] = param_11;
  puVar2[0xf] = param_7;
  puVar2[0xe] = param_6;
  puVar2[0x10] = param_8;
  *(undefined1 *)((int)puVar2 + 0x35) = 0;
  *(undefined1 *)(puVar2 + 0x1a) = 1;
  FUN_1000_a355(puVar2 + 0x1b,iVar4,param_2,param_3,local_2a);
  if ((local_2e & 1) != 0) {
    local_38 = *(undefined2 *)0x12;
    local_3a = *(undefined2 *)0x10;
    local_14 = 6;
    FUN_1000_63e4((undefined2 *)local_32 + 0x1b,local_32._2_2_,param_2,param_3,param_6,param_7,
                  param_8);
    local_14 = 0;
    *(undefined2 *)0x12 = local_38;
    *(undefined2 *)0x10 = local_3a;
  }
  if ((param_14 == 0) && ((local_2e & 2) != 0)) {
    local_14 = 0x12;
    uVar7 = (undefined2)((ulong)local_24 >> 0x10);
    piVar5 = (int *)local_24;
    FUN_1000_6732(param_2,param_3,piVar5[0xf],piVar5[0x10],piVar5[0x11],1);
    local_14 = 0;
  }
  local_46 = *(undefined2 *)((int)*(undefined4 *)0x16 + 0x1a);
  local_44 = 0x554c;
  local_40 = param_13;
  local_42 = param_12;
  local_3c = local_32._2_2_;
  local_3e = (undefined2 *)local_32;
  FUN_1000_6ef8(0xface,0xeef,1,0,3,0,&local_46);
  *(undefined2 *)0x14 = local_20;
  return;
}

