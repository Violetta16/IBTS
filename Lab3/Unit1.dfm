object Form1: TForm1
  Left = 392
  Top = 162
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  TextHeight = 15
  object Label1: TLabel
    Left = 192
    Top = 200
    Width = 24
    Height = 15
    Caption = #1048#1084#1103
  end
  object Label2: TLabel
    Left = 192
    Top = 255
    Width = 55
    Height = 15
    Caption = #1054#1087#1080#1089#1072#1085#1080#1077
  end
  object Label3: TLabel
    Left = 192
    Top = 311
    Width = 40
    Height = 15
    Caption = #1056#1072#1079#1084#1077#1088
  end
  object Label4: TLabel
    Left = 192
    Top = 221
    Width = 3
    Height = 15
  end
  object Label5: TLabel
    Left = 192
    Top = 276
    Width = 3
    Height = 15
  end
  object Label6: TLabel
    Left = 192
    Top = 332
    Width = 3
    Height = 15
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 16
    Top = 8
    Width = 593
    Height = 177
    Header.AutoSizeIndex = 0
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    ParentShowHint = False
    ShowHint = False
    TabOrder = 0
    OnAddToSelection = VirtualStringTree1AddToSelection
    OnGetText = VirtualStringTree1GetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = #1048#1076#1077#1085#1090#1080#1092#1080#1082#1072#1090#1086#1088
        Width = 107
      end
      item
        Position = 1
        Text = #1048#1084#1103' '#1092#1072#1081#1083#1072
        Width = 101
      end>
  end
  object Button1: TButton
    Left = 16
    Top = 200
    Width = 129
    Height = 49
    Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1041#1044
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 16
    Top = 255
    Width = 129
    Height = 49
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1101#1082#1088#1072#1085
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 16
    Top = 311
    Width = 129
    Height = 50
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 16
    Top = 367
    Width = 129
    Height = 50
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1074#1089#1077' '#1089#1090#1088#1086#1082#1080
    TabOrder = 4
    OnClick = Button4Click
  end
end
