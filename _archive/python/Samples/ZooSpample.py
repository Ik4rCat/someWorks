global_var = 15

def first():
    loval_var = 10
    global global_var
    global_var = 2
    def second():
        local_var = 11
        print(local_var)

    second()

first()



class Animals():
    _voice_message = " голос"
    def __init__(self,name):
        self._name = name
    def voice(self):
        voice = self._name + self._voice_message
        print(voice)

class Dog(Animals):
    _voice_message = " Гав-Гав"
    def parent_voice(self):
        voice = self._name + super()._voice_message
        print(voice)

dog = Dog("Charli")

dog.voice()
dog.parent_voice()


