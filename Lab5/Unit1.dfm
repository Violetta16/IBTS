object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 376
  ClientWidth = 778
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 15
    Height = 13
    Caption = 'C:\'
  end
  object Label2: TLabel
    Left = 16
    Top = 66
    Width = 3
    Height = 13
  end
  object Label3: TLabel
    Left = 24
    Top = 144
    Width = 3
    Height = 13
  end
  object Button1: TButton
    Left = 16
    Top = 35
    Width = 75
    Height = 25
    Caption = #1042#1099#1073#1086#1088' '#1087#1091#1090#1080
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 97
    Top = 35
    Width = 96
    Height = 25
    Caption = #1055#1086#1080#1089#1082' '#1089#1080#1075#1085#1072#1090#1091#1088
    TabOrder = 1
    OnClick = Button2Click
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 224
    Top = 8
    Width = 546
    Height = 360
    Header.AutoSizeIndex = 0
    TabOrder = 2
    OnGetText = VirtualStringTree1GetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = #1060#1072#1081#1083
        Width = 258
      end
      item
        Position = 1
        Text = #1050#1083#1072#1089#1090#1077#1088
        Width = 136
      end>
  end
  object Button3: TButton
    Left = 8
    Top = 280
    Width = 113
    Height = 41
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 327
    Width = 113
    Height = 41
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1074#1089#1077' '#1089#1090#1088#1086#1082#1080
    TabOrder = 4
    OnClick = Button4Click
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 176
    Width = 185
    Height = 105
    Caption = #1056#1077#1078#1080#1084' '#1087#1086#1080#1089#1082#1072
    ItemIndex = 0
    Items.Strings = (
      #1042#1089#1077' '#1082#1083#1072#1089#1090#1077#1088#1099
      #1055#1088#1086#1087#1091#1089#1082#1072#1090#1100' '#1087#1091#1089#1090#1099#1077)
    TabOrder = 5
  end
end
