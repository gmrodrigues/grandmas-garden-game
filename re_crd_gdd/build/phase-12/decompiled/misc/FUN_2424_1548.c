// TIM2.EXE: FUN_2424_1548 @ file 0x02A988 Ghidra 0x25788
// Subsystem: misc | Size: 264 bytes


void __cdecl16far FUN_2424_1548(void)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  bool bVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined4 local_a;
  undefined4 local_6;
  
  iVar6 = 0;
  do {
    if (1 < iVar6) {
      return;
    }
    if (iVar6 == 0) {
      puVar5 = (undefined2 *)&DAT_5b41_0557;
    }
    else {
      puVar5 = (undefined2 *)&DAT_5b41_054f;
    }
    local_6 = (undefined2 *)CONCAT22(0x554c,puVar5);
LAB_2424_162c:
    iVar3 = ((undefined2 *)local_6)[1];
    puVar5 = (undefined2 *)*local_6;
    local_6 = (undefined2 *)CONCAT22(iVar3,puVar5);
    if (puVar5 != (undefined2 *)0x0 || iVar3 != 0) {
      iVar1 = puVar5[4];
      if (iVar1 == 0x58) {
LAB_2424_15a1:
        bVar4 = true;
      }
      else {
        if (0x58 < iVar1) {
          if (((iVar1 != 0x61) && (iVar1 != 0x62)) && (iVar1 != 0x6c)) goto LAB_2424_15a6;
          goto LAB_2424_15a1;
        }
        if (iVar1 == 0x39) goto LAB_2424_15a1;
        if (iVar1 < 0x3a) {
          if ((iVar1 == 0xb) || (iVar1 == 0x11)) goto LAB_2424_15a1;
        }
        else if (iVar1 == 0x47) goto LAB_2424_15a1;
LAB_2424_15a6:
        bVar4 = false;
      }
      local_a = &DAT_5b41_0557;
      while (bVar4) {
        iVar1 = ((undefined2 *)local_a)[1];
        puVar2 = (undefined2 *)*local_a;
        local_a = (undefined2 *)CONCAT22(iVar1,puVar2);
        if (puVar2 == (undefined2 *)0x0 && iVar1 == 0) break;
        if ((((*(byte *)((int)puVar2 + 0xd) & 0x20) == 0) &&
            ((*(byte *)((int)puVar2 + 0xf) & 0x40) == 0)) &&
           (((int)puVar5[0x17] < (int)(puVar2[0x17] + puVar2[0x24]) &&
            ((((int)puVar2[0x17] < (int)(puVar5[0x17] + puVar5[0x24]) &&
              ((int)puVar5[0x18] < (int)(puVar2[0x18] + puVar2[0x25]))) &&
             ((int)puVar2[0x18] < (int)(puVar5[0x18] + puVar5[0x25]))))))) {
          FUN_2424_0f94(puVar2,iVar1,4);
        }
      }
      goto LAB_2424_162c;
    }
    iVar6 = iVar6 + 1;
  } while( true );
}

