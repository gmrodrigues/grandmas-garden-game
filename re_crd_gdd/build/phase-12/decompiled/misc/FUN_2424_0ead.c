// TIM2.EXE: FUN_2424_0ead @ file 0x02A2ED Ghidra 0x250ED
// Subsystem: misc | Size: 231 bytes


void __cdecl16far FUN_2424_0ead(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  undefined2 local_4;
  
  iVar1 = (int)param_1;
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  if (param_2 == 0) {
    local_4 = *(undefined2 *)(iVar1 + 0x24);
    local_6 = *(undefined2 *)(iVar1 + 0x22);
    local_8 = *(undefined2 *)(iVar1 + 0x56);
    local_a = *(undefined2 *)(iVar1 + 0x54);
    FUN_2424_1da0(&local_6,&local_a,1);
  }
  if ((param_2 & 1) != 0) {
    local_4 = *(undefined2 *)(iVar1 + 0x38);
    local_6 = *(undefined2 *)(iVar1 + 0x36);
    local_8 = *(undefined2 *)(iVar1 + 0x52);
    local_a = *(undefined2 *)(iVar1 + 0x50);
    FUN_2424_1da0(&local_6,&local_a,1);
  }
  if ((param_2 & 2) != 0) {
    local_4 = *(undefined2 *)(iVar1 + 0x34);
    local_6 = *(undefined2 *)(iVar1 + 0x32);
    local_8 = *(undefined2 *)(iVar1 + 0x4e);
    local_a = *(undefined2 *)(iVar1 + 0x4c);
    FUN_2424_1da0(&local_6,&local_a,2);
  }
  if ((param_2 & 4) != 0) {
    local_4 = *(undefined2 *)(iVar1 + 0x30);
    local_6 = *(undefined2 *)(iVar1 + 0x2e);
    local_8 = *(undefined2 *)(iVar1 + 0x4a);
    local_a = *(undefined2 *)(iVar1 + 0x48);
    FUN_2424_1da0(&local_6,&local_a,1);
  }
  return;
}

