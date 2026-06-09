// TIM2.EXE: FUN_1a9e_51b3 @ file 0x024D93 Ghidra 0x1FB93
// Subsystem: level | Size: 363 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_1a9e_51b3(char *param_1,uint param_2,undefined2 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  undefined2 unaff_SS;
  
  puVar4 = &stack0xfffe;
  uVar2 = (uint)(char *)param_1 | param_1._2_2_;
  if (uVar2 != 0) {
    if ((((char)DAT_554c_42c2 < '\x02') && (uVar2 = (uint)DAT_554c_42c3, uVar2 == 0)) &&
       (DAT_5b41_25c2 < 2)) {
      while (**(char **)(puVar4 + 6) != '\0') {
        if (*(uint *)(puVar4 + -2) < 9) {
          *(uint *)(puVar4 + -6) = (uint)**(byte **)(puVar4 + 6) - (uint)(byte)DAT_554c_431c;
          if (DAT_5b41_2676 == 0 && DAT_5b41_2678 == 0) {
            if (*(int *)(puVar4 + -8) == 0) {
              *(uint *)(puVar4 + -2) = (uint)(byte)DAT_554c_42f4;
              *(uint *)(puVar4 + -4) = (uint)(byte)DAT_554c_4308;
              *(uint *)(puVar4 + -8) = (*(int *)(puVar4 + -2) + 7U >> 3) * *(int *)(puVar4 + -4);
            }
            iVar3 = *(int *)(puVar4 + -6);
            iVar1 = *(int *)(puVar4 + -8);
            *(undefined2 *)(puVar4 + -10) = DAT_5b41_25d8;
            *(int *)(puVar4 + -0xc) = DAT_5b41_25d6 + iVar3 * iVar1;
          }
          else {
            *(uint *)(puVar4 + -2) = (uint)*(byte *)((int)_DAT_5b41_2626 + *(int *)(puVar4 + -6));
            *(uint *)(puVar4 + -4) = (uint)(byte)DAT_554c_4308;
            iVar3 = *(int *)(DAT_5b41_2676 + *(int *)(puVar4 + -6) * 2);
            *(undefined2 *)(puVar4 + -10) = DAT_5b41_25d8;
            *(int *)(puVar4 + -0xc) = DAT_5b41_25d6 + iVar3;
          }
          (*DAT_554c_4d7a)(0x1a9e,unaff_DI,unaff_SI);
          *(int *)(puVar4 + 10) = *(int *)(puVar4 + 10) + *(int *)(puVar4 + -2);
        }
        else {
          iVar3 = FUN_1a9e_4f06(**(undefined1 **)(puVar4 + 6),*(undefined2 *)(puVar4 + 10),
                                *(undefined2 *)(puVar4 + 0xc));
          *(int *)(puVar4 + 10) = *(int *)(puVar4 + 10) + iVar3;
        }
        *(int *)(puVar4 + 6) = *(int *)(puVar4 + 6) + 1;
      }
      return;
    }
    while (*param_1 != '\0') {
      iVar3 = FUN_1a9e_4f06(CONCAT11((char)(uVar2 >> 8),*param_1),param_2,param_3);
      uVar2 = param_2 + iVar3;
      param_2 = uVar2;
      if ((DAT_554c_42c2 & 2) != 0) {
        param_2 = uVar2 + 1;
      }
      param_1 = (char *)CONCAT22(param_1._2_2_,(char *)param_1 + 1);
    }
  }
  return;
}

