// TIM2.EXE: FUN_2e67_072c @ file 0x033F9C Ghidra 0x2ED9C
// Subsystem: misc | Size: 34 bytes


/* WARNING: Instruction at (ram,0x0002a24b) overlaps instruction at (ram,0x0002a249)
    */
/* WARNING: Removing unreachable block (ram,0x00024307) */
/* WARNING: Removing unreachable block (ram,0x00024310) */
/* WARNING: Removing unreachable block (ram,0x00024317) */
/* WARNING: Removing unreachable block (ram,0x0002431e) */
/* WARNING: Removing unreachable block (ram,0x00024327) */
/* WARNING: Removing unreachable block (ram,0x00024335) */
/* WARNING: Removing unreachable block (ram,0x00024343) */
/* WARNING: Removing unreachable block (ram,0x0002434f) */
/* WARNING: Removing unreachable block (ram,0x0002435b) */
/* WARNING: Removing unreachable block (ram,0x00024367) */
/* WARNING: Removing unreachable block (ram,0x00024371) */
/* WARNING: Removing unreachable block (ram,0x000243c3) */
/* WARNING: Removing unreachable block (ram,0x000243d2) */
/* WARNING: Removing unreachable block (ram,0x00024379) */
/* WARNING: Removing unreachable block (ram,0x0002437e) */
/* WARNING: Removing unreachable block (ram,0x0002438d) */
/* WARNING: Removing unreachable block (ram,0x000243af) */
/* WARNING: Removing unreachable block (ram,0x0002436e) */
/* WARNING: Removing unreachable block (ram,0x00024364) */
/* WARNING: Removing unreachable block (ram,0x00024358) */
/* WARNING: Removing unreachable block (ram,0x000243f0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl16far FUN_2e67_072c(undefined4 param_1)

{
  undefined2 *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  undefined2 *puVar7;
  uint uVar8;
  uint unaff_SI;
  int unaff_DI;
  uint uVar9;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  uint uStack_8;
  
  puVar7 = (undefined2 *)&stack0xfffe;
  bVar3 = false;
  uVar5 = (uint)param_1 / 1000;
  if (4 < uVar5) {
    return 0;
  }
  switch(uVar5) {
  case 0:
    uStack_8 = SUB42(s_String_reference_out_of_range_554c_5eb4._16_4_,2);
    uVar5 = uVar5 * 2;
    uVar8 = param_1._2_2_;
    uVar9 = uStack_8;
    break;
  case 1:
    uStack_8 = 0xffff;
    FUN_406b_03cb(0x28);
    FUN_406b_03cb(0xfffd,0);
    do {
    } while( true );
  case 2:
    DAT_554c_5599 = *(undefined2 *)0x2;
    DAT_554c_559b = uVar5;
    *(undefined2 *)0x0 = (char *)s_No_such_device_554c_5cfa + 8;
    *(undefined2 *)0x2 = 0x2000;
    return unaff_SI;
  case 3:
    return uVar5 + 1;
  case 4:
    puVar6 = &uStack_8;
    cVar2 = '\n';
    do {
      puVar7 = puVar7 + -1;
      puVar6 = puVar6 + -1;
      *puVar6 = *puVar7;
      cVar2 = cVar2 + -1;
    } while ('\0' < cVar2);
    return uVar5;
  }
  do {
    *(undefined2 *)(uVar5 + 0xac) = *(undefined2 *)(uVar5 + 0xc);
    if ((*(uint *)(uVar5 + 0x10) == unaff_SI) && (*(int *)(uVar5 + 0xc) == unaff_DI)) {
LAB_28eb_13e7:
      bVar3 = true;
    }
    else {
      iVar4 = FUN_28eb_0119((uint)param_1,param_1._2_2_);
      if ((iVar4 == 0) &&
         ((*(int *)((uint)param_1 + 0x58) == 0 ||
          (iVar4 = FUN_28eb_1c08(*(undefined2 *)((uint)param_1 + 0x58)), iVar4 != 0)))) {
        uVar8 = uVar8 | 0xc;
        goto LAB_28eb_13e7;
      }
    }
    if (bVar3) {
      *(uint *)((uint)param_1 + 0x10) = unaff_SI;
      *(int *)((uint)param_1 + 0xc) = unaff_DI;
      *(int *)((uint)param_1 + 0xac) = unaff_DI;
      puVar1 = (undefined2 *)(*(int *)(*(int *)((uint)param_1 + 8) * 2 + 0x302) + 0xc);
      (*(code *)*puVar1)(0x2000,(uint)param_1,param_1._2_2_,0);
      DAT_5b41_050f = 0;
      if ((*(byte *)((uint)param_1 + 0xf) & 4) != 0) {
        if ((uVar8 & 1) == 0) {
          uVar8 = uVar8 | 0x80;
        }
        else {
          uVar8 = uVar8 | 0x800;
        }
      }
      if (((iRam000557bc == 1) || (iRam000557bc == 6)) &&
         ((*(byte *)((uint)param_1 + 0xf) & 0x80) != 0)) {
        uVar8 = uVar8 | 0x200;
      }
      return uVar8;
    }
    puVar1 = (undefined2 *)(*(int *)(*(int *)((uint)param_1 + 8) * 2 + 0x302) + 0xc);
    (*(code *)*puVar1)(0x2000,(uint)param_1,param_1._2_2_,0xf);
    uVar5 = (uint)param_1;
    uVar9 = param_1._2_2_;
  } while( true );
}

