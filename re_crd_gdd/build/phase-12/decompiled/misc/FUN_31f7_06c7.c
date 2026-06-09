// TIM2.EXE: FUN_31f7_06c7 @ file 0x037837 Ghidra 0x32637
// Subsystem: misc | Size: 276 bytes


int __cdecl16far
FUN_31f7_06c7(int param_1,uint param_2,undefined4 param_3,uint param_4,undefined2 param_5,
             undefined2 param_6,undefined2 param_7)

{
  char cVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  uint in_DX;
  int iVar7;
  undefined2 uVar8;
  int iVar9;
  long lVar10;
  undefined2 local_8;
  int local_6;
  int local_4;
  
  iVar9 = (int)((ulong)param_3 >> 0x10);
  iVar7 = (int)param_3;
  if ((*(byte *)(iVar7 + 0xd) & 2) == 0) {
    local_4 = 0;
    local_6 = 0;
    while ((lVar10 = CONCAT22(in_DX,local_6), local_4 < 2 && (local_6 == 0))) {
      iVar2 = *(int *)(iVar7 + local_4 * 2 + 0x76);
      if (iVar2 != 0) {
        iVar5 = FUN_28eb_396b(iVar7,iVar9,iVar2);
        lVar10 = (ulong)in_DX << 0x10;
        if ((in_DX != param_2) || (iVar5 != param_1)) {
          if ((*(int *)(iVar2 + 6) == iVar9) && (*(int *)(iVar2 + 4) == iVar7)) {
            local_8 = 0;
            cVar1 = *(char *)(iVar2 + 0x14);
            uVar4 = *(undefined1 *)(iVar2 + 0x15);
          }
          else {
            local_8 = 1;
            cVar1 = *(char *)(iVar2 + 0x15);
            uVar4 = *(undefined1 *)(iVar2 + 0x14);
          }
          if (*(int *)(iVar7 + 0x16) < 1) {
            if (cVar1 != '\0') goto LAB_31f7_0779;
LAB_31f7_0774:
            uVar8 = 1;
          }
          else {
            if (cVar1 != '\0') goto LAB_31f7_0774;
LAB_31f7_0779:
            uVar8 = 0;
          }
          uVar6 = FUN_28eb_37bb(iVar2,local_8,uVar8);
          puVar3 = (undefined2 *)(*(int *)(*(int *)(iVar5 + 8) * 2 + 0x302) + 0x14);
          lVar10 = (*(code *)*puVar3)(0x28eb,iVar7,iVar9,iVar5,in_DX,uVar4,uVar6 | param_4,param_5,
                                      param_6,param_7);
        }
      }
      in_DX = (uint)((ulong)lVar10 >> 0x10);
      local_4 = local_4 + 1;
      local_6 = (int)lVar10;
    }
  }
  else {
    local_6 = 1;
  }
  return local_6;
}

