// TIM2.EXE: FUN_1a9e_6a85 @ file 0x026665 Ghidra 0x21465
// Subsystem: misc | Size: 941 bytes


undefined2 __cdecl16far FUN_1a9e_6a85(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  int in_DX;
  undefined2 *puVar10;
  undefined2 *puVar11;
  int local_8;
  uint local_6;
  
  if ((param_1 == 0) || (puVar5 = (undefined2 *)FUN_1a9e_6886(param_1), puVar5 == (undefined2 *)0x0)
     ) {
    return 0xffff;
  }
  local_6 = 0xffff;
  do {
    local_6 = local_6 + 1;
  } while (*(char *)(param_2 + local_6) != '\0');
  if ((local_6 == 0) || ((local_6 & 3) != 0)) {
    return 0xffff;
  }
  puVar11 = (undefined2 *)&DAT_5b41_26de;
  puVar10 = puVar5;
  for (iVar9 = 0x21; iVar9 != 0; iVar9 = iVar9 + -1) {
    puVar3 = puVar11;
    puVar11 = puVar11 + 1;
    puVar2 = puVar10;
    puVar10 = puVar10 + 1;
    *puVar3 = *puVar2;
  }
  *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
  iVar9 = FUN_1a9e_6904(param_2,puVar5 + 1,0x19);
  if (iVar9 == 0) {
    if (param_3 < 1) {
      param_3 = 1;
      local_8 = 0;
    }
    else {
      FUN_1a9e_68b6(puVar5);
      local_8 = param_3;
    }
  }
  else {
    if (((param_3 == 0) && (iVar9 = FUN_1000_0f2a(*puVar5), in_DX == *(int *)((int)puVar5 + 0x3d)))
       && (iVar9 == *(int *)((int)puVar5 + 0x3b))) {
      return *(undefined2 *)((int)puVar5 + 0x3b);
    }
    if (param_3 == -1) {
      FUN_1000_0e6d(*puVar5,*(undefined2 *)((int)puVar5 + 0x3b),*(undefined2 *)((int)puVar5 + 0x3d),
                    0);
      return *(undefined2 *)((int)puVar5 + 0x3b);
    }
    if (*(int *)((int)puVar5 + 0x39) == 0) {
      local_8 = param_3;
      if (param_3 == 0) {
        param_3 = 1;
      }
      else {
        FUN_1a9e_68b6(puVar5);
      }
    }
    else if (param_3 == 0) {
      param_3 = 1;
      local_8 = *(int *)((int)puVar5 + 0x39) + 1;
    }
    else {
      local_8 = param_3;
      if (*(int *)((int)puVar5 + 0x39) < param_3) {
        param_3 = param_3 - *(int *)((int)puVar5 + 0x39);
      }
      else {
        if (*(int *)((int)puVar5 + 0x39) <= param_3) {
          FUN_1000_0e6d(*puVar5,*(undefined2 *)((int)puVar5 + 0x3b),
                        *(undefined2 *)((int)puVar5 + 0x3d),0);
          return *(undefined2 *)((int)puVar5 + 0x3b);
        }
        FUN_1a9e_68b6(puVar5);
      }
    }
  }
  if ((*(uint *)((int)puVar5 + (*(int *)((int)puVar5 + 0x37) >> 2) * 4 + 0x1d) & 0x8000) == 0) {
    iVar9 = *(int *)((int)puVar5 + 0x41);
    uVar4 = *(uint *)((int)puVar5 + 0x3f);
    puVar1 = (uint *)((int)puVar5 + 0x3b);
    uVar8 = *puVar1;
    *puVar1 = *puVar1 + uVar4;
    *(int *)((int)puVar5 + 0x3d) = *(int *)((int)puVar5 + 0x3d) + iVar9 + (uint)CARRY2(uVar8,uVar4);
  }
  FUN_1000_0e6d(*puVar5,*(undefined2 *)((int)puVar5 + 0x3b),*(undefined2 *)((int)puVar5 + 0x3d),0);
  do {
    iVar9 = param_3 + -1;
    if (param_3 == 0) {
      *(int *)((int)puVar5 + 0x39) = local_8;
      return *(undefined2 *)((int)puVar5 + 0x3b);
    }
    do {
      while( true ) {
        while ((iVar6 = *(int *)((int)puVar5 + 0x37) >> 2,
               (*(uint *)((int)puVar5 + iVar6 * 4 + 0x1d) & 0x7fff) == *(uint *)((int)puVar5 + 0x3d)
               && (*(int *)((int)puVar5 + iVar6 * 4 + 0x1b) == *(int *)((int)puVar5 + 0x3b)))) {
          if (*(int *)((int)puVar5 + 0x37) == 0) {
            uVar7 = FUN_1a9e_6a52(puVar5);
            return uVar7;
          }
          *(int *)((int)puVar5 + 0x37) = *(int *)((int)puVar5 + 0x37) + -4;
        }
        if ((*(uint *)((int)puVar5 + (*(int *)((int)puVar5 + 0x37) >> 2) * 4 + 0x1d) & 0x8000) != 0)
        break;
        iVar6 = *(int *)((int)puVar5 + 0x41);
        uVar4 = *(uint *)((int)puVar5 + 0x3f);
        puVar1 = (uint *)((int)puVar5 + 0x3b);
        uVar8 = *puVar1;
        *puVar1 = *puVar1 + uVar4;
        *(int *)((int)puVar5 + 0x3d) =
             *(int *)((int)puVar5 + 0x3d) + iVar6 + (uint)CARRY2(uVar8,uVar4);
        FUN_1000_0e6d(*puVar5,*(undefined2 *)((int)puVar5 + 0x3b),
                      *(undefined2 *)((int)puVar5 + 0x3d),0);
      }
      iVar6 = FUN_1000_0d10((undefined1 *)((int)puVar5 + *(int *)((int)puVar5 + 0x37) + 2),1,4,
                            *puVar5);
      if (iVar6 != 4) {
        uVar7 = FUN_1a9e_6a52(puVar5);
        return uVar7;
      }
      *(int *)((int)puVar5 + 0x37) = *(int *)((int)puVar5 + 0x37) + 4;
      if (0x17 < *(int *)((int)puVar5 + 0x37)) {
        uVar7 = FUN_1a9e_6a52(puVar5);
        return uVar7;
      }
      *(undefined1 *)((int)puVar5 + *(int *)((int)puVar5 + 0x37) + 2) = 0;
      puVar1 = (uint *)((int)puVar5 + 0x3b);
      uVar8 = *puVar1;
      *puVar1 = *puVar1 + 8;
      *(int *)((int)puVar5 + 0x3d) = *(int *)((int)puVar5 + 0x3d) + (uint)(0xfff7 < uVar8);
      iVar6 = FUN_1000_0d10((undefined1 *)((int)puVar5 + 0x3f),4,1,*puVar5);
      if (iVar6 != 1) {
        uVar7 = FUN_1a9e_6a52(puVar5);
        return uVar7;
      }
      uVar8 = *(uint *)((int)puVar5 + 0x3b);
      uVar4 = *(uint *)((int)puVar5 + 0x3f);
      iVar6 = *(int *)((int)puVar5 + 0x37) >> 2;
      *(int *)((int)puVar5 + iVar6 * 4 + 0x1d) =
           *(int *)((int)puVar5 + 0x3d) + *(int *)((int)puVar5 + 0x41) +
           (uint)CARRY2(uVar8,*(uint *)((int)puVar5 + 0x3f));
      *(int *)((int)puVar5 + iVar6 * 4 + 0x1b) = uVar8 + uVar4;
      *(undefined2 *)((int)puVar5 + 0x3f) = *(undefined2 *)((int)puVar5 + 0x3f);
      *(uint *)((int)puVar5 + 0x41) = *(uint *)((int)puVar5 + 0x41) & 0x7fff;
      if (*(int *)((int)puVar5 + 0x41) < 0) {
LAB_1a9e_6ddd:
        uVar7 = FUN_1a9e_6a52(puVar5);
        return uVar7;
      }
      uVar8 = *(uint *)((int)puVar5 + 0x1d) & 0x7fff;
      if ((uVar8 <= *(uint *)((int)puVar5 + 0x41)) &&
         ((*(uint *)((int)puVar5 + 0x41) != uVar8 ||
          (*(uint *)((int)puVar5 + 0x1b) <= *(uint *)((int)puVar5 + 0x3f))))) goto LAB_1a9e_6ddd;
    } while ((*(uint *)((int)puVar5 + 0x37) != local_6) ||
            (iVar6 = FUN_1a9e_6904(puVar5 + 1,param_2,local_6), param_3 = iVar9, iVar6 == 0));
  } while( true );
}

