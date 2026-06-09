// TIM2.EXE: FUN_2424_23db @ file 0x02B81B Ghidra 0x2661B
// Subsystem: misc | Size: 142 bytes


void __cdecl16far FUN_2424_23db(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  
  uVar7 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  if (((*(byte *)(iVar5 + 0xd) & 0x20) == 0) && ((*(byte *)(iVar5 + 0xf) & 0x40) == 0)) {
    *(uint *)(iVar5 + 0xe) = *(uint *)(iVar5 + 0xe) | 0x20;
    iVar2 = *(int *)(iVar5 + 8);
    for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
      bVar1 = *(byte *)(*(int *)(iVar2 * 2 + 0x302) + iVar4 + 0x20);
      if (bVar1 != 0xff) {
        uVar3 = *(undefined2 *)((uint)bVar1 * 4 + 0x64bb);
        iVar6 = iVar5 + iVar4 * 4;
        *(undefined2 *)(iVar6 + 0x86) = *(undefined2 *)((uint)bVar1 * 4 + 0x64bd);
        *(undefined2 *)(iVar6 + 0x84) = uVar3;
        *(undefined2 *)((uint)bVar1 * 4 + 0x64bd) = uVar7;
        *(int *)((uint)bVar1 * 4 + 0x64bb) = iVar5;
        if (iVar4 == 0) {
          *(byte *)(iVar5 + 0x95) = bVar1;
        }
      }
    }
  }
  return;
}

