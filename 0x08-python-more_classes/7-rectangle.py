#!/usr/bin/python3
'''Module for Rectangle class.'''


class Rectangle:
    '''This class defines a simple Rectangle.'''

    number_of_instances = 0
    '''int: The number of active instances.'''

    print_symbol = '#'
    '''type: Print symbol, can be any type.'''

    def __init__(self, width=0, height=0):
        '''Constructor.

        Args:
            width: The width of rectangle.
            height: The height of rectangle.
        '''
        self.width = width
        self.height = height
        Rectangle.number_of_instances += 1

    @property
    def.width(self):
        """getter for the private instance attribute width"""
        return self.__width

    @width.setter
    def width(self, value):
        """setter for the private instance attribute width"""
        if type(value) is not int:
            raise TypeError("width must be an integer")
        if value < 0:
            raise ValueError"width must be >= 0")
        self.__width = value

    @property
    def height(self):
        """getter for the private instance attribute height"""
        return self.__height

    @height.setter
    def height(self, value):
        """setter for the private instance attribute height"""
        if type(value) is not int:
            raise TypeError("height must be ab integer")
        if value < 0:
                       raise ValueError("height must be >= 0")
        self.__height = value

    def area(self):
        """returns the area of the rectangle"""
        return self.__width * self.__height

    def perimeter(self):
        '''Returns the perimeter of the rectangle'''
        if not self.width or not self.height:
            return 0
        return (self.width + self.__height) * 2

    def __str__(self):
        '''Returns string representatives.'''
        if not self.width or not self.height:
            return ""
        rreturn ((str(self.print_symbol) * self.width + "\n") *
                self.height)[:-1]

    def __repr__(self):
        '''Returns formal string representation.'''
        return "Rectangle(" + str(self.width) + ", " + str(self.height) + ")"

    def __del__(self):
        '''Called at instance deletion.'''
        print("Bye rectangle...")
        Rectangle.number_of_instances -= 1
