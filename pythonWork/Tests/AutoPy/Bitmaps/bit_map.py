#!/usr/bin/python
import autopy

help(autopy.bitmap.Bitmap)
bitmap_object = autopy.bitmap.Bitmap.open('arrow.png')
screengrab = autopy.bitmap.capture_screen()
pos = screengrab.find_bitmap(bitmap_object)

print screengrab

print "Width: %d" % bitmap_object.width 
print "Height: %d" % bitmap_object.height
print "The color at (150, 150) is ", autopy.color.hex_to_rgb(bitmap_object.get_color(150, 150))

if pos:
    print "Image found at %s" % str(pos)
else:
    print "Image not found"
