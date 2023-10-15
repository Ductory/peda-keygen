VERSION 5.00
Begin VB.Form frmMain 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Pedagoguery Software KeyGen"
   ClientHeight    =   3015
   ClientLeft      =   45
   ClientTop       =   390
   ClientWidth     =   4710
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3015
   ScaleWidth      =   4710
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  '所有者中心
   Begin VB.CommandButton cmdCopy 
      Caption         =   "Copy"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   1440
      TabIndex        =   11
      Top             =   2400
      Width           =   855
   End
   Begin VB.CommandButton cmdCopies 
      Caption         =   "Copies"
      Height          =   375
      Left            =   120
      TabIndex        =   10
      Top             =   1920
      Width           =   855
   End
   Begin VB.CommandButton cmdGen 
      Caption         =   "Generate"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   120
      TabIndex        =   9
      Top             =   2400
      Width           =   1215
   End
   Begin VB.ComboBox cobProd 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   360
      ItemData        =   "frmMain.frx":0000
      Left            =   1080
      List            =   "frmMain.frx":0010
      TabIndex        =   5
      Text            =   "--------"
      Top             =   1440
      Width           =   1335
   End
   Begin VB.TextBox txtCode 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   720
      Locked          =   -1  'True
      TabIndex        =   4
      Top             =   960
      Width           =   3855
   End
   Begin VB.TextBox txtName 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   720
      TabIndex        =   2
      Text            =   "User"
      Top             =   480
      Width           =   3855
   End
   Begin VB.Label lblAuthor 
      Alignment       =   1  'Right Justify
      Caption         =   "Made by Dangfer"
      Height          =   255
      Left            =   3240
      TabIndex        =   12
      Top             =   2640
      Width           =   1455
   End
   Begin VB.Label lblMore 
      Alignment       =   2  'Center
      Caption         =   "more info"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00EE0000&
      Height          =   255
      Left            =   2400
      TabIndex        =   8
      Top             =   2280
      Width           =   2295
   End
   Begin VB.Label lblInfo 
      Caption         =   "(None)"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   10.5
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   840
      Left            =   2520
      TabIndex        =   7
      Top             =   1440
      Width           =   2160
   End
   Begin VB.Label lblProduct 
      Caption         =   "Product"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   120
      TabIndex        =   6
      Top             =   1440
      Width           =   855
   End
   Begin VB.Label lblCode 
      Caption         =   "Code"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   120
      TabIndex        =   3
      Top             =   960
      Width           =   495
   End
   Begin VB.Label lblName 
      Caption         =   "Name"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   120
      TabIndex        =   1
      Top             =   480
      Width           =   495
   End
   Begin VB.Label lblPageUrl 
      Alignment       =   2  'Center
      Caption         =   "http://www.peda.com/"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   12
         Charset         =   134
         Weight          =   400
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00EE0000&
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   4455
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim copies As Long

Private Sub cmdCopies_Click()
    Dim s As String
    s = InputBox("Please input the maximum number of copies:" & vbCrLf & _
                 "0 and 1: for use on one computer" & vbCrLf & _
                 "2 to 254: for use on up to N computers within the licensed site" & vbCrLf & _
                 "255: for use on all computers within the licensed site" & vbCrLf & _
                 "otherwise: generate the number randomly", "Input Copies", copies)
    If Not IsNumeric(s) Then Exit Sub
    copies = s
End Sub

Private Sub cmdCopy_Click()
    Clipboard.SetText txtCode.Text
End Sub

Private Sub cmdGen_Click()
    If cobProd.ListIndex = -1 Then Exit Sub
    Dim code(16) As Byte
    gen_code StrPtr(StrConv(txtName.Text, vbFromUnicode)), VarPtr(code(0)), cobProd.ListIndex, copies
    txtCode.Text = StrConv(code, vbUnicode)
End Sub

Private Sub cobProd_Click()
    Select Case cobProd.ListIndex
    Case PROD_POLY
        lblInfo.Caption = "explore polyhedra"
        lblMore.Tag = "http://www.peda.com/poly/"
    Case PROD_POLYPRO
        lblInfo.Caption = "Poly + export DXF, STL, and 3DMF models"
        lblMore.Tag = "http://www.peda.com/polypro/"
    Case PROD_GRAFEQ
        lblInfo.Caption = "graph equations and inequalities"
        lblMore.Tag = "http://www.peda.com/grafeq/"
    Case PROD_TESS
        lblInfo.Caption = "explore tessellations and other symmetric illustrations"
        lblMore.Tag = "http://www.peda.com/tess/"
    End Select
End Sub

Private Sub Form_Load()
    Randomize
End Sub

Private Sub lblMore_Click()
    Shell "explorer " & lblMore.Tag
End Sub

Private Sub lblPageUrl_Click()
    Shell "explorer " & lblPageUrl.Caption
End Sub
