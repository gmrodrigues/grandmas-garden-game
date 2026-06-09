// TIM2.EXE: FUN_1a9e_6ec1 @ file 0x026AA1 Ghidra 0x218A1
// Subsystem: misc | Size: 780 bytes


/* WARNING: Removing unreachable block (ram,0x00021bf0) */

int __cdecl16far FUN_1a9e_6ec1(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  int in_DX;
  int iVar5;
  bool bVar6;
  long lVar7;
  int local_e;
  int local_c;
  uint local_6;
  int local_4;
  
  lVar7 = CONCAT22(local_c,local_e);
  for (iVar5 = 2;
      (((undefined2 *)&DAT_5b41_25d6)[iVar5 * 2] != 0 ||
       ((undefined2 *)&DAT_5b41_25d8)[iVar5 * 2] != 0 && (iVar5 < 0x14)); iVar5 = iVar5 + 1) {
  }
  if (iVar5 < 0x14) {
    iVar2 = FUN_1a9e_6ea7(param_1);
    if (iVar2 == 0) {
      local_4 = 1;
      param_1 = FUN_1a9e_69e9(param_1);
    }
    else {
      local_4 = 0;
    }
    iVar2 = FUN_1a9e_6a85(param_1,DAT_554c_55a8,0);
    if ((in_DX == -1) && (iVar2 == -1)) {
      iVar5 = 0;
    }
    else {
      FUN_1000_0d10((int)(undefined2 *)&DAT_554c_42f4 + iVar5,1,1,param_1);
      if ((*(char *)((int)(undefined2 *)&DAT_554c_42f4 + iVar5) == -3) ||
         (*(char *)((int)(undefined2 *)&DAT_554c_42f4 + iVar5) == -1)) {
        ((undefined1 *)&DAT_5b41_25c2)[iVar5] =
             -*(char *)((int)(undefined2 *)&DAT_554c_42f4 + iVar5);
        FUN_1000_0d10((int)(undefined2 *)&DAT_554c_42f4 + iVar5,1,1,param_1);
        FUN_1000_0d10((int)(undefined2 *)&DAT_554c_4308 + iVar5,1,1,param_1);
        FUN_1000_0d10((undefined1 *)&DAT_5b41_26c6 + iVar5,1,1,param_1);
        FUN_1000_0d10((int)(undefined2 *)&DAT_554c_431c + iVar5,1,1,param_1);
        FUN_1000_0d10((int)(undefined2 *)&DAT_554c_4330 + iVar5,1,1,param_1);
        FUN_1000_0d10(&local_6,1,2,param_1);
        uVar3 = FUN_1a9e_6e3d(param_1);
        iVar2 = FUN_28eb_2779(0xffff,param_1,0x55af,uVar3,in_DX);
        bVar6 = iVar2 < 0;
        if (!bVar6) {
          uVar4 = FUN_28eb_2ba9(0x1000,iVar2);
          bVar6 = uVar4 != local_6;
        }
        if (!bVar6) {
          lVar7 = FUN_2fc8_00fc(0x1000,local_6,0,0,0);
          bVar6 = lVar7 == 0;
        }
        local_c = (int)((ulong)lVar7 >> 0x10);
        local_e = (int)lVar7;
        if (!bVar6) {
          uVar4 = FUN_28eb_2aad(iVar2,lVar7,local_6);
          bVar6 = uVar4 != local_6;
        }
        if (!bVar6) {
          ((undefined2 *)&DAT_5b41_2678)[iVar5 * 2] = local_c;
          ((undefined2 *)&DAT_5b41_2676)[iVar5 * 2] = local_e;
          iVar1 = local_e + (uint)*(byte *)((int)(undefined2 *)&DAT_554c_4330 + iVar5) * 2;
          *(int *)((undefined *)&DAT_5b41_2628 + iVar5 * 4) = local_c;
          ((undefined2 *)&DAT_5b41_2626)[iVar5 * 2] = iVar1;
          local_e = iVar1 + (uint)*(byte *)((int)(undefined2 *)&DAT_554c_4330 + iVar5);
          ((undefined2 *)&DAT_5b41_25d8)[iVar5 * 2] = local_c;
          ((undefined2 *)&DAT_5b41_25d6)[iVar5 * 2] = local_e;
        }
        FUN_28eb_29db(iVar2);
        if (bVar6) {
          if (local_e != 0 || local_c != 0) {
            func_0x0002fdf5(0x1000,local_e,local_c);
          }
          iVar5 = 0;
        }
      }
      else {
        if (*(char *)((int)(undefined2 *)&DAT_554c_42f4 + iVar5) == -2) {
          ((undefined1 *)&DAT_5b41_25c2)[iVar5] = 2;
          FUN_1000_0d10((int)(undefined2 *)&DAT_554c_42f4 + iVar5,1,1,param_1);
          local_6 = (uint)*(byte *)((int)(undefined2 *)&DAT_554c_42f4 + iVar5);
        }
        else {
          ((undefined1 *)&DAT_5b41_25c2)[iVar5] = 0;
          local_6 = (int)(*(byte *)((int)(undefined2 *)&DAT_554c_42f4 + iVar5) + 7) >> 3;
        }
        FUN_1000_0d10((int)(undefined2 *)&DAT_554c_4308 + iVar5,1,1,param_1);
        FUN_1000_0d10((int)(undefined2 *)&DAT_554c_431c + iVar5,1,1,param_1);
        FUN_1000_0d10((int)(undefined2 *)&DAT_554c_4330 + iVar5,1,1,param_1);
        local_6 = local_6 * (uint)*(byte *)((int)(undefined2 *)&DAT_554c_4308 + iVar5) *
                            (uint)*(byte *)((int)(undefined2 *)&DAT_554c_4330 + iVar5);
        iVar2 = FUN_1000_127a(local_6);
        if (iVar2 == 0) {
          iVar5 = 0;
        }
        else {
          FUN_1000_0d10(iVar2,local_6,1,param_1);
          ((undefined2 *)&DAT_5b41_25d8)[iVar5 * 2] = 0x554c;
          ((undefined2 *)&DAT_5b41_25d6)[iVar5 * 2] = iVar2;
          ((undefined2 *)&DAT_5b41_2678)[iVar5 * 2] = 0;
          ((undefined2 *)&DAT_5b41_2676)[iVar5 * 2] = 0;
          *(undefined2 *)((undefined *)&DAT_5b41_2628 + iVar5 * 4) = 0;
          ((undefined2 *)&DAT_5b41_2626)[iVar5 * 2] = 0;
        }
      }
    }
    if (local_4 != 0) {
      FUN_1a9e_6e73(param_1);
    }
  }
  else {
    iVar5 = 0;
  }
  return iVar5;
}

