// TIM2.EXE: FUN_31f7_5ab5 @ file 0x03CC25 Ghidra 0x37A25
// Subsystem: misc | Size: 1026 bytes


void __cdecl16far FUN_31f7_5ab5(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  uint uVar8;
  undefined2 uVar9;
  int iVar10;
  int iVar11;
  int local_e;
  int local_a;
  uint local_8;
  uint local_6;
  
  iVar11 = (int)((ulong)param_1 >> 0x10);
  iVar10 = (int)param_1;
  iVar1 = *(int *)(iVar10 + 0x22);
  bVar4 = false;
  bVar3 = DAT_5b41_1a12 <= *(int *)(iVar10 + 0x10);
  iVar5 = *(int *)(iVar10 + 0x10);
  if ((iVar5 != DAT_5b41_19fe) && (iVar5 != DAT_5b41_1a00)) {
    if ((iVar5 < (int)((undefined2 *)&DAT_5b41_1a02)[bVar3]) ||
       ((int)((undefined2 *)&DAT_5b41_1a0a)[bVar3] <= iVar5)) {
      *(int *)(iVar10 + 0x10) = *(int *)(iVar10 + 0x10) + 1;
      iVar5 = FUN_4551_0308(DAT_5b41_0a02,*(undefined2 *)(iVar10 + 0x10));
      if (iVar5 != 0) {
        *(undefined2 *)(iVar10 + 0x10) = ((undefined2 *)&DAT_5b41_19fe)[bVar3];
        FUN_28eb_3328(iVar10,iVar11);
      }
    }
    else {
      bVar4 = true;
      *(int *)(iVar10 + 0x10) = *(int *)(iVar10 + 0x10) + 1;
      if ((*(byte *)(iVar10 + 0xc) & 0x10) == 0) {
        *(int *)(iVar10 + 0x22) =
             *(int *)(iVar10 + 0x22) +
             *(int *)((*(int *)(iVar10 + 0x10) - ((undefined2 *)&DAT_5b41_1a02)[bVar3]) * 2 + 0x3b56
                     );
      }
      else {
        *(int *)(iVar10 + 0x22) =
             *(int *)(iVar10 + 0x22) -
             *(int *)((*(int *)(iVar10 + 0x10) - ((undefined2 *)&DAT_5b41_1a02)[bVar3]) * 2 + 0x3b56
                     );
      }
      if (*(int *)(iVar10 + 0x10) == ((undefined2 *)&DAT_5b41_1a0a)[bVar3]) {
        *(undefined2 *)(iVar10 + 0x10) = ((undefined2 *)&DAT_5b41_19fe)[bVar3];
      }
    }
  }
  if ((*(int *)(iVar10 + 0x10) < (int)((undefined2 *)&DAT_5b41_1a02)[bVar3]) ||
     ((int)((undefined2 *)&DAT_5b41_1a0a)[bVar3] <= *(int *)(iVar10 + 0x10))) {
    if (bVar4) {
      local_a = 0xa0;
    }
    else {
      local_a = 0x40;
    }
    if ((*(byte *)(iVar10 + 10) & 1) != 0) {
      FUN_28eb_4f3d(iVar10,iVar11,0x1000,0xff00,0x100,0xfff8,8);
      local_8 = 400;
      local_6 = 400;
      local_e = 0;
      iVar5 = iVar10;
      iVar6 = iVar11;
      while( true ) {
        iVar2 = *(int *)(iVar5 + 0x8e);
        iVar5 = *(int *)(iVar5 + 0x8c);
        if (iVar5 == 0 && iVar2 == 0) break;
        if (((*(int *)(iVar5 + 8) == 0xc) &&
            (uVar8 = (int)*(uint *)(iVar5 + 0x90) >> 0xf,
            (int)((*(uint *)(iVar5 + 0x90) ^ uVar8) - uVar8) <= local_a)) &&
           (uVar8 = (int)*(uint *)(iVar5 + 0x90) >> 0xf,
           (int)((*(uint *)(iVar5 + 0x90) ^ uVar8) - uVar8) <
           (int)((local_6 ^ (int)local_6 >> 0xf) - ((int)local_6 >> 0xf)))) {
          local_6 = *(uint *)(iVar5 + 0x90);
        }
        iVar6 = iVar2;
        if (((*(int *)(iVar10 + 0x10) < DAT_5b41_1a12) || (DAT_5b41_1a00 <= *(int *)(iVar10 + 0x10))
            ) && ((*(int *)(iVar5 + 8) == 0x34 &&
                  (uVar8 = (int)*(uint *)(iVar5 + 0x90) >> 0xf,
                  (int)((*(uint *)(iVar5 + 0x90) ^ uVar8) - uVar8) <
                  (int)((local_8 ^ (int)local_8 >> 0xf) - ((int)local_8 >> 0xf)))))) {
          if ((*(int *)(iVar10 + 0x22) + 0x10 < *(int *)(iVar5 + 0x22)) ||
             (*(int *)(iVar5 + 0x22) + *(int *)(iVar5 + 0x48) + 2 < *(int *)(iVar10 + 0x22))) {
            local_8 = *(uint *)(iVar5 + 0x90);
          }
          else {
            if (*(int *)(iVar5 + 0x22) + 8 < *(int *)(iVar10 + 0x22)) {
              local_e = 2;
            }
            else {
              local_e = 1;
            }
            local_8 = 0;
          }
        }
      }
      if ((local_6 == 400) && (local_8 != 400)) {
        if (((*(int *)(iVar10 + 0x10) < DAT_5b41_1a12) || (DAT_5b41_1a00 <= *(int *)(iVar10 + 0x10))
            ) && (local_e != 0)) {
          *(int *)(iVar10 + 0x10) = DAT_5b41_1a12;
          iVar5 = *(int *)(iVar10 + 0xc);
          if (local_e == 1) {
            *(uint *)(iVar10 + 0xc) = *(uint *)(iVar10 + 0xc) & 0xffef;
          }
          else {
            *(uint *)(iVar10 + 0xc) = *(uint *)(iVar10 + 0xc) | 0x10;
          }
          if (*(int *)(iVar10 + 0xc) != iVar5) {
            FUN_31f7_59c1(iVar10,iVar11);
            iVar6 = FUN_28eb_0119(iVar10,iVar11);
            if (iVar6 != 0) {
              *(int *)(iVar10 + 0xc) = iVar5;
              FUN_31f7_59c1(iVar10,iVar11);
            }
          }
        }
        else {
          local_6 = -local_8;
        }
      }
      if (local_6 != 400) {
        uVar9 = *(undefined2 *)(iVar10 + 0x10);
        if (bVar4) {
          uVar7 = ((undefined2 *)&DAT_5b41_1a06)[bVar3];
        }
        else {
          uVar7 = ((undefined2 *)&DAT_5b41_1a02)[bVar3];
        }
        *(undefined2 *)(iVar10 + 0x10) = uVar7;
        iVar5 = *(int *)(iVar10 + 0xc);
        if ((int)local_6 < 0) {
          *(uint *)(iVar10 + 0xc) = *(uint *)(iVar10 + 0xc) & 0xffef;
        }
        else {
          *(uint *)(iVar10 + 0xc) = *(uint *)(iVar10 + 0xc) | 0x10;
        }
        if (*(int *)(iVar10 + 0xc) != iVar5) {
          FUN_31f7_59c1(iVar10,iVar11);
          iVar6 = FUN_28eb_0119(iVar10,iVar11);
          if (iVar6 != 0) {
            *(int *)(iVar10 + 0xc) = iVar5;
            FUN_31f7_59c1(iVar10,iVar11);
            *(undefined2 *)(iVar10 + 0x10) = uVar9;
            local_6 = 400;
          }
        }
      }
      if (((local_6 == 400) && ((DAT_5b41_051f & 1) != 0)) &&
         (DAT_554c_3b66 = DAT_554c_3b66 + -1, DAT_554c_3b66 < 1)) {
        *(undefined2 *)(iVar10 + 0x10) = ((undefined2 *)&DAT_5b41_1a0e)[bVar3];
        DAT_554c_3b66 = 0x78;
      }
    }
  }
  if (*(int *)(iVar10 + 0x10) != *(int *)(iVar10 + 0x12)) {
    iVar5 = *(int *)(iVar10 + 0x22);
    if (iVar5 != iVar1) {
      *(int *)(iVar10 + 0x1c) = iVar5 >> 0xf;
      *(int *)(iVar10 + 0x1a) = iVar5;
      uVar9 = *(undefined2 *)(iVar10 + 0x1c);
      uVar7 = FUN_1000_199e();
      *(undefined2 *)(iVar10 + 0x1c) = uVar9;
      *(undefined2 *)(iVar10 + 0x1a) = uVar7;
    }
    FUN_28eb_3328(iVar10,iVar11);
  }
  return;
}

