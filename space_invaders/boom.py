from kivy.uix.image import Image
from kivy.core.audio import SoundLoader

class Boom(Image):
        sound = SoundLoader.load('boom.wav')
        def boom(self, **kwargs):
            self.__class__.sound.play()
            super(Boom, self).__init__(**kwargs)
