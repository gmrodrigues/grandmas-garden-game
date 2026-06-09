// TIM2.EXE decompiled function: FUN_4bdc_24de
// Source: file offset 0x05359F → Ghidra 0x4E39F
// Body: 0x4E29E - 0x4E3F5
// Size: 340 bytes


bool __cdecl16far FUN_4bdc_24de(int param_1,int param_2,undefined2 param_3,undefined2 param_4)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  int in_DX;
  
  bVar1 = false;
  if (param_2 != -2) {
    FUN_1000_132f(0x56c2,*(undefined2 *)(param_2 * 2 + 0x56da));
    DAT_554c_5744 = FUN_4bdc_27b2(param_4,0x56be,0);
    DAT_554c_5746 = in_DX;
    if (DAT_554c_5744 == 0 && in_DX == 0) {
      bVar1 = true;
    }
    else {
      DAT_554c_5756 = 1;
      FUN_4bdc_31b4(DAT_554c_5744,in_DX);
      iVar3 = FUN_1000_1356(param_3,1);
      if (iVar3 == 0) {
        DAT_554c_5756 = 0;
        FUN_1000_1384();
        FUN_2e67_10e9(DAT_554c_5744,DAT_554c_5746,1);
        DAT_554c_5746 = 0;
        DAT_554c_5744 = 0;
        bVar1 = true;
      }
    }
  }
  if (param_1 != -2) {
    FUN_1000_132f(0x56c2,*(undefined2 *)(param_1 * 2 + 0x56c8));
    DAT_554c_5740 = FUN_4bdc_27b2(param_4,0x56be,0);
    DAT_554c_5742 = in_DX;
    if (DAT_554c_5740 == 0 && in_DX == 0) {
      bVar1 = true;
    }
    else {
      bVar2 = FUN_4bdc_22d3(DAT_554c_5740,in_DX);
      DAT_554c_572e = (uint)bVar2;
      iVar3 = FUN_4bdc_2409(param_4,(undefined2 *)&DAT_554c_572e,0);
      if (iVar3 == 0) {
        FUN_2e67_10e9(DAT_554c_5740,DAT_554c_5742,1);
        DAT_554c_5742 = 0;
        DAT_554c_5740 = 0;
        bVar1 = true;
      }
    }
    if (param_1 == 8) {
      param_1 = 3;
    }
  }
  DAT_554c_575a = param_1;
  return !bVar1;
}


