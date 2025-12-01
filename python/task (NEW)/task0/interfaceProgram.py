import random

# <============mainClassPart============>

class WindowElement:
    def __init__(self, sizeX=500, sizeY=500):
        self.sizeX = sizeX
        self.sizeY = sizeY

    
# <============ChildrenClassesPart============>

class Button(WindowElement):
    def __init__(self, sizeX=50, sizeY=20, pressed=False, cornersRoundingMain=0, cornerRTopLeft=0, cornerRTopRight=0, cornerRBottomLeft=0, cornerRBottomRight=0, text="text"):
        super().__init__(sizeX, sizeY)
        self.pressed= pressed
        self.cornerRoundingMain= cornersRoundingMain 
        self.cornerRTopLeft = cornerRTopLeft
        self.cornerRBottomLeft = cornerRBottomLeft
        self.cornerRTopRight = cornerRTopRight
        self.cornerRBottomRight = cornerRBottomRight
        self.text = text

class TextBox(WindowElement):
    def __init__(self, sizeX=100, sizeY=50, text="text", font=["comic sans"], color=["white"]):
        super().__init__(sizeX, sizeY)
        self.text = text
        self.font = font
        self.color = color

class InputBox(WindowElement):
    def __init__(self, sizeX=100, sizeY=50, inputText="", sampleText="your text here", font=["comic sans"], color=["white"]):
        super().__init__(sizeX, sizeY)
        self.inputText = inputText
        self.sampleText = sampleText
        self.font = font
        self.color = color

