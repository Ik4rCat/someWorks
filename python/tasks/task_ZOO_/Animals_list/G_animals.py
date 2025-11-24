from About_Animals import Animal

class Dog(Animal):
    canDo = ("walk","run","jump","crouch")
    _voice_message = " Гав-Гав"
    def parent_voice(self):
        voice = self._name + super()._voice_message
        print(f": {voice}")

class Cat(Animal):
    canDo = ("walk","run","jump","crouch")
    _voice_message = " Мяу-мяу"
    def parent_voice(self):
        voice = self._name + super()._voice_message
        print(f": {voice}")