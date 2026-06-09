// TIM2.EXE: FUN_2424_2469 @ file 0x02B8A9 Ghidra 0x266A9
// Subsystem: misc | Size: 339 bytes


void __cdecl16far FUN_2424_2469(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  undefined4 local_10;
  int local_c;
  int iStack_a;
  char local_3;
  
  DAT_554c_42d8 = DAT_554c_42d2;
  DAT_554c_42c3 = 1;
  FUN_2424_02ca();
  local_3 = '\t';
  while( true ) {
    local_c = 0;
    iStack_a = 0;
    local_10 = 0;
    if (local_3 == '\0') break;
    bVar4 = local_3 - 1;
    iVar5 = *(int *)((uint)bVar4 * 4 + 0x64bb);
    iVar6 = *(int *)((uint)bVar4 * 4 + 0x64bd);
    while (iVar5 != 0 || iVar6 != 0) {
      *(uint *)(iVar5 + 0xe) = *(uint *)(iVar5 + 0xe) & 0xffdf;
      if ((*(byte *)(iVar5 + 0x18) & 0x80) == 0) {
        FUN_2424_2a1e(iVar5,iVar6,bVar4);
      }
      else {
        FUN_2424_2919(iVar5,iVar6,bVar4);
      }
      if ((*(byte *)(iVar5 + 0xf) & 0x20) != 0) {
        iVar2 = iVar5;
        iVar3 = iVar6;
        if (local_c != 0 || iStack_a != 0) {
          uVar7 = (undefined2)((ulong)local_10 >> 0x10);
          *(int *)((int)local_10 + 0x8e) = iVar6;
          *(int *)((int)local_10 + 0x8c) = iVar5;
          iVar2 = local_c;
          iVar3 = iStack_a;
        }
        iStack_a = iVar3;
        local_c = iVar2;
        local_10 = CONCAT22(iVar6,iVar5);
        *(undefined2 *)(iVar5 + 0x8e) = 0;
        *(undefined2 *)(iVar5 + 0x8c) = 0;
      }
      if (*(byte *)(iVar5 + 0x95) == bVar4) {
        piVar1 = (int *)(iVar5 + 0x86);
        iVar5 = *(int *)(iVar5 + 0x84);
        iVar6 = *piVar1;
      }
      else {
        piVar1 = (int *)(iVar5 + 0x8a);
        iVar5 = *(int *)(iVar5 + 0x88);
        iVar6 = *piVar1;
      }
    }
    while (local_c != 0 || iStack_a != 0) {
      FUN_2424_3684(local_c,iStack_a);
      piVar1 = (int *)(local_c + 0x8e);
      local_c = *(int *)(local_c + 0x8c);
      iStack_a = *piVar1;
    }
    local_3 = local_3 + -1;
  }
  FUN_2424_227b();
  return;
}

