import wx

class StaticTextFrame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, None, -1, 'Static Text Example', size=(400, 300))
        panel = wx.Panel(self, -1)
	#self.Bind(wx.EVT_SIZE,self.OnSize)
        text= wx.StaticText(panel, -1, "Speed of Bot1 along x axis: 23 cm/sec", (10, 10))
	font = wx.Font(18, wx.DECORATIVE, wx.ITALIC, wx.NORMAL)
	text.SetFont(font)
	text= wx.StaticText(panel, -1, "Speed of Bot1 along y axis: 19 cm/sec", (10, 30))
	font = wx.Font(18, wx.DECORATIVE, wx.ITALIC, wx.NORMAL)
	text.SetFont(font)
	text=wx.StaticText(panel,-1,"Speed of Bot1 Average: 29.8 cm/sec",(10,50))
	font = wx.Font(18, wx.DECORATIVE, wx.ITALIC, wx.NORMAL)
	text.SetFont(font)
 	text=wx.StaticText(panel,-1,"Speed of Bot2 along x axis: 19.14 cm/sec",(10,70))
	font = wx.Font(18, wx.DECORATIVE, wx.ITALIC, wx.NORMAL)
        text.SetFont(font)
	text=wx.StaticText(panel,-1,"Speed of Bot2 along y axis: 22.5 cm/sec",(10,90))
	font = wx.Font(18, wx.DECORATIVE, wx.ITALIC, wx.NORMAL)
        text.SetFont(font)
	text=wx.StaticText(panel,-1,"Speed of Bot2 Average: 29.54 cm/sec",(10,110))
	font = wx.Font(18, wx.DECORATIVE, wx.ITALIC, wx.NORMAL)
        text.SetFont(font)
       #center = wx.StaticText(panel, -1, "align center", (100, 50), (160, -1),# wx.ALIGN_CENTER)
        #center.SetForegroundColour('white')
        #center.SetBackgroundColour('black')


 

app = wx.PySimpleApp()
frame = StaticTextFrame()
frame.Show()
app.MainLoop()
