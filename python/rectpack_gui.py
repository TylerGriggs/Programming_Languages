"""
@author: Tyler Griggs
VCU CMSC 403 Assignment 7

The goal of this program is to take a collection of rectangles and display them
    on a canvas so that none of the rectangles overlap with each other.
    
This program uses algorithms for packing rectangles into rectangles contained
    in the library rectpack.    
    
    pypi.org/project/rectpack/

Sources:
    (rectpack Library) github.com/secnot/rectpack
    (Canvas Widget) anzeljg.github.io/rin2/book2/2405/docs/tkinter/canvas.html
    (TKinter Colors) science.smith.edu/dftwiki/index.php/Color_Charts_for_TKinter
"""

import sys
import tkinter
import rectpack as rp

class CustomCanvas:
    """
     Allows for the creation of custom sized GUI window containing a specific number,
         and specifically sized rectangles, defined by Rectangle Class objects
    """
    # Constructor
    def __init__(self, height, width):
        self.root = tkinter.Tk()
        self.canvas = tkinter.Canvas(self.root, 
           width=width,
           height=height,
           bg="gray25")
        
        self.canvas.pack()
    
    # Create the rectangles in canvas based on deminsions of Rectangle objects
    def draw(self, packedRects):
        """
        Provided a list of correctly packed Rectangle objects, an associated
            rectangle is created inside the CustomCanvas
            
        Parameter:
            packedRects         a rectpack packed list of Rectangle objects
        """
        # For each packed Rectangle objected passed to the CustomCanvas
        for r in packedRects:
            self.canvas.create_rectangle(r.x, r.y, r.x + r.width, r.y + r.height, fill="gold")
            
        self.root.mainloop()
        
class Rectangle:
    """
    Allows for the creation of Rectangle objects with a starting point (x,y) 
        and a size, given by height and width. Default values for the starting
        point are set as the tuple coordinate (0,0).
    """
    # Constructor
    def __init__(self, height, width, x = 0, y = 0):
        self.height = int(height)
        self.width = int(width)
        self.x = x
        self.y = y
    
    
def pack(allRect, canvasSize):
    """
    Provided a list of rectangle size-tuples, and the root size of the Canvas,
        this function uses the rectpack library to algorithically pack rectangles
        of different sizes into a 2D area
        
    Parameter:
            allRect             a list of Rectangle objects
            canvasSize          a tuple containing a canvas’ height and width
    """
    # Create new rectpack, Packer object
    packer = rp.newPacker() 
    
    # Add the rectangles to packing queue
    for r in allRect:
    	packer.add_rect(r.width,r.height)
    
    # Add bin for rectangles to be packed
    packer.add_bin(int(canvasSize[0]), int(canvasSize[1]))
    
    # Start packing
    packer.pack()
    
    packedRects = [] # Empty Array to be returned

    # Contruct rectangle objects from packed set
    for r in packer.rect_list(): 
        
        x = r[1]    # Starting x coordinate
        y = r[2]    # Starting y coordinate
        w = r[3]    # Rectangle Width
        h = r[4]    # Rectangle Height
        
        # Rectangle contructor call
        packedRects.append(Rectangle(h, w, x, y))

    # Return Packed Rectangles
    return packedRects


def main():
    """
    Main Function opens a passed filename as an argument from commandline, 
        where the passed text document contains on the first line the canvas
        size as a tuple Height, Width in that order. The remaining lines in 
        the text file contain sizes of rectangles to be packed into the canvas.
        
    Example Command:
        python Assignment7.py 25PercentFill.txt
        
    Example text file:
        300,300
        75,75
        25,25
        50,50
        100,100
        61,61
    """
    
    f = open(str(sys.argv[1]))          # Open test file
    size_tuple = f.readline()           # Extract first line
    canvasSize = size_tuple.split(',')  # Extract size from tuple
    
    lines = f.readlines()               # Extract lines from text file
    f.close()                           # Close text file
    rectArray = []                      # Initialize array storage
    
    # Each line in the test text file after Canvas-Size line
    for line in lines:
        size_tuple = line.split(',')    # Extract tuple from line
        height = size_tuple[0]          # Extract height from tuple
        width = size_tuple[1]           # Extract width from tuple
        
        # Array of Rectangle Objects
        rectArray.append(Rectangle(height, width, 0, 0))

    # Function call pack(), returns array of packed Rectangles
    packedRect = pack(rectArray,canvasSize)
    
    # Finally create the CustomCanvas with packed rectangles drawn in it
    CustomCanvas(canvasSize[0], canvasSize[1]).draw(packedRect)


main()