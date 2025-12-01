class Animal():
    _voice_message = " voice!"
    def __init__(self,name):
        self._name = name
    def voice(self):
        voice = self._name + self._voice_message
        print(voice)
