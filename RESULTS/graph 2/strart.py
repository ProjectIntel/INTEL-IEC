import wx

class MyForm(wx.Frame):

    #----------------------------------------------------------------------
    def __init__(self):
        wx.Frame.__init__(self, None, wx.ID_ANY, "BOT POSITION")

        # Add a panel so it looks the correct on all platforms
        panel = wx.Panel(self, wx.ID_ANY)
        self.answers = {}
        self.questions = ["BOT1 X", "BOT1 Y",
                          "BOT2 X","BOT2 Y"]
        self.nextQuestion = 0

        self.question = wx.StaticText(panel, label="Do You Want To Continue(Y/N)")
        self.answer = wx.TextCtrl(panel, value="")
        submitBtn = wx.Button(panel, label="Submit")
        submitBtn.Bind(wx.EVT_BUTTON, self.onSubmit)

        sizer = wx.BoxSizer(wx.VERTICAL)
        self.panelSizer = wx.BoxSizer(wx.VERTICAL)

        sizer.Add(self.question, 0, wx.ALL, 5)
        
        sizer.Add(self.answer, 0, wx.ALL|wx.EXPAND, 5)
        sizer.Add(submitBtn, 0, wx.ALL|wx.CENTER, 5)
        panel.SetSizer(sizer)

        self.panelSizer.Add(panel, 1, wx.EXPAND)
        self.SetSizer(self.panelSizer)

    #----------------------------------------------------------------------
    def onSubmit(self, event):
        """"""
        self.answers[self.question.GetLabel()] = self.answer.GetValue()
        self.question.SetLabel(self.questions[self.nextQuestion])
        self.answer.SetValue("")
        self.nextQuestion += 1
        print self.answers
        self.panelSizer.Fit(self)



# Run the program
if __name__ == "__main__":
    app = wx.App(False)
    frame = MyForm()
    frame.Show()
    app.MainLoop()
