from About_Animals import Water_Animals
 

class fish(Water_Animals):
    _voice_message = " *sound of fish"
    def parent_voice(self):
        voice = self._name + super()._voice_message
        print(f": {voice}")

class turtule(Water_Animals):
    canDo = ("walk","run","jump","crouch")
    _voice_message = " *scary sounds of death"
    def parent_voice(self):
        voice = self._name + super()._voice_message
        print(f": {voice}")