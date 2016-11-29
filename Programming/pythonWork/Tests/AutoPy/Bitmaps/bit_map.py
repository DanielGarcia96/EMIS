#!/usr/bin/python
import autopy

screengrab = autopy.bitmap.capture_screen()
width, height = autopy.screen.get_size()
width = width / 2
height = height / 2
print hex(screengrab.get_color(width, height))

#print screengrab

#print "Width: %d" % bitmap_object.width 
#print "Height: %d" % bitmap_object.height
#print "The color at (150, 150) is ", autopy.color.hex_to_rgb(bitmap_object.get_color(150, 150))

#if pos:
#    print "Image found at %s" % str(pos)
#else:
#    print "Image not found"
