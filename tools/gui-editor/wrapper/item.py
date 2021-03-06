__author__ = 'JordSti'
import surface
import object_wrap
import style

class item(object_wrap.object_wrap):

    def __init__(self, obj=None):
        object_wrap.object_wrap.__init__(self, obj)

    def set_dimension(self, width, height):
        self.lib.Item_setDimension(self.obj, width, height)

    def set_point(self, x, y):
        self.lib.Item_setPoint(self.obj, x, y)

    def set_rectangle(self, x, y , width, height):
        self.lib.Item_setRectangle(self.obj, x, y, width, height)

    def get_x(self):
        return self.lib.Item_getX(self.obj)

    def get_y(self):
        return self.lib.Item_getY(self.obj)

    def get_width(self):
        return self.lib.Item_getWidth(self.obj)

    def get_height(self):
        return self.lib.Item_getHeight(self.obj)

    def set_minimum_size(self, width, height):
        self.lib.Item_setMinimumSize(self.obj, width, height)

    def set_maximum_size(self, width, height):
        self.lib.Item_setMaximumSize(self.obj, width, height)

    def set_fixed_size(self, width, height):
        self.lib.Item_setFixedSize(self.obj, width, height)

    def render(self):
        sdl_sur = self.lib.Item_render(self.obj)
        sur = surface.surface(sdl_sur)
        return sur

    def get_style(self):
        #todo style object wrapper, even mutable style
        return style.style(self.lib.Item_getStyle(self.obj))
