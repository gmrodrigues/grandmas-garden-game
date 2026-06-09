// TIM2.EXE: FUN_54f1_0043 @ file 0x05A153 Ghidra 0x54F53
// Subsystem: misc | Size: 125 bytes


/* WARNING: Control flow encountered bad instruction data */

void FUN_54f1_0043(void)

{
  byte *pbVar1;
  code *pcVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  undefined2 uVar8;
  int in_CX;
  char extraout_DL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  byte bVar9;
  char cVar10;
  byte in_AF;
  
  pcVar2 = (code *)swi(0x3f);
  iVar5 = (*pcVar2)();
  puVar6 = (undefined1 *)&DAT_6000_21c0 + iVar5;
  in_AF = 9 < ((byte)puVar6 & 0xf) | in_AF;
  bVar3 = (byte)puVar6 + in_AF * -6 & 0xf;
  pbVar7 = (byte *)(unaff_SI + 1);
  if (in_CX == 1 || puVar6 == (undefined1 *)0x0) {
    bVar4 = 9 < bVar3 | in_AF;
    pbVar7 = (byte *)(CONCAT11(((char)((uint)puVar6 >> 8) - in_AF) - bVar4,bVar3 + bVar4 * -6) &
                     0xff0f);
    bVar3 = (byte)(byte *)(unaff_SI + 1);
    bVar9 = CARRY1(bVar3,pbVar7[in_BX]) || CARRY1(bVar3 + pbVar7[in_BX],bVar4);
    pcVar2 = (code *)swi(0x3f);
    bVar3 = (*pcVar2)();
    cVar10 = CARRY1(bVar3,pbVar7[in_BX]) || CARRY1(bVar3 + pbVar7[in_BX],bVar9);
    pcVar2 = (code *)swi(0x3f);
    bVar3 = (*pcVar2)();
    pbVar7[unaff_BP] = (pbVar7[unaff_BP] - extraout_DL) - cVar10;
    in_AF = 9 < (bVar3 & 0xf) | bVar4;
  }
  pcVar2 = (code *)swi(0x3f);
  (*pcVar2)();
  pcVar2 = (code *)swi(0x3f);
  uVar8 = (*pcVar2)();
  bVar3 = (byte)uVar8;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar3;
  in_AF = 9 < (bVar3 & 0xf) | in_AF;
  bVar4 = bVar3 + in_AF * -6 & 0xf;
  bVar3 = 9 < bVar4 | in_AF;
  pbVar7[in_BX] = pbVar7[in_BX] + (bVar4 + bVar3 * -6 & 0xf);
  bVar4 = bRam000555d4;
  *(char *)(in_BX + unaff_DI) =
       *(char *)(in_BX + unaff_DI) + (((char)((uint)uVar8 >> 8) - in_AF) - bVar3);
  cRam000555c0 = cRam000555c0 + bVar4;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar4;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar4;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar4;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar4;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar4;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar4;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar4;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar4;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar4;
  bVar3 = bVar4 + (9 < (bVar4 & 0xf) | bVar3) * -6 & 0xf;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar3;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar3;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar3;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar3;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar3;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar3;
  pbVar7[in_BX] = pbVar7[in_BX] + bVar3;
  pcVar2 = (code *)swi(0x3f);
  iVar5 = (*pcVar2)();
  pbVar1 = pbVar7 + in_BX;
  bVar3 = *pbVar1;
  *pbVar1 = *pbVar1 + (byte)iVar5;
  *pbVar7 = *pbVar7 << 1 | CARRY1(bVar3,(byte)iVar5);
  *(int *)(pbVar7 + in_BX) = *(int *)(pbVar7 + in_BX) + iVar5;
  *(int *)(unaff_BP + iVar5) = *(int *)(unaff_BP + iVar5) + in_BX;
  cVar10 = (char)pbVar7;
  *(char *)(in_BX + iVar5) = *(char *)(in_BX + iVar5) + cVar10;
  *(char *)(in_BX + iVar5) = *(char *)(in_BX + iVar5) + cVar10;
  *(char *)(in_BX + iVar5) = *(char *)(in_BX + iVar5) + cVar10;
  *(char *)(in_BX + iVar5) = *(char *)(in_BX + iVar5) + cVar10;
  *(char *)(in_BX + iVar5) = *(char *)(in_BX + iVar5) + cVar10;
  *(char *)(in_BX + iVar5) = *(char *)(in_BX + iVar5) + cVar10;
  *(char *)(in_BX + iVar5) = *(char *)(in_BX + iVar5) + cVar10;
  *(char *)(in_BX + iVar5) = *(char *)(in_BX + iVar5) + cVar10;
  *(char *)(in_BX + iVar5) = *(char *)(in_BX + iVar5) + cVar10;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

