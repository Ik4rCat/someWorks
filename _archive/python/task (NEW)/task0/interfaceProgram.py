import random

# <============mainClassPart============>

class WindowElement:
    def __init__(self, sizeX=500, sizeY=500, x=0, y=0):
        self.sizeX = sizeX
        self.sizeY = sizeY
        self.x = x
        self.y = y

    # <======positionPart======>
    def getPosX(self):
        self.x

    def getPosY(self):
        self.y
    
    def setPosX(self, newX):
        self.x += newX

    def setPosY(self, newY):
        self.y += newY

    # <======sizePart======>
    def getSizeX(self):
        self.sizeX
    
    def getSizeY(self):
        self.sizeY
    
    def setSizeX(self, x):
        if(x>0):
            self.sizeX += x
    
    def setSizeY(self, y):
        if(y>0):
            self.sizeX += y
    
# <============ChildrenClassesPart============>

class Button(WindowElement):
    def __init__(self, x=0, y=0, sizeX=50, sizeY=20, pressed=False, cornersRoundingMain=0, cornerRTopLeft=0, cornerRTopRight=0, cornerRBottomLeft=0, cornerRBottomRight=0, text="text"):
        super().__init__(sizeX, sizeY, x, y)
        self.pressed= pressed
        self.cornerRoundingMain= cornersRoundingMain 
        self.cornerRTopLeft = cornerRTopLeft
        self.cornerRBottomLeft = cornerRBottomLeft
        self.cornerRTopRight = cornerRTopRight
        self.cornerRBottomRight = cornerRBottomRight
        self.text = text

class TextBox(WindowElement):
    def __init__(self, x=0, y=0,  sizeX=100, sizeY=50, text="text", font=["comic sans"], color=["white"]):
        super().__init__(sizeX, sizeY, x, y)
        self.text = text
        self.font = font
        self.color = color

class InputBox(WindowElement):
    def __init__(self, sizeX=100, sizeY=50, x=0, y=0, inputText="", sampleText="your text here", font=["comic sans"], color=["white"]):
        super().__init__(sizeX, sizeY, x, y)
        self.inputText = inputText
        self.sampleText = sampleText
        self.font = font
        self.color = color

