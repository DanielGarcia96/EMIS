#!/usr/bin/python

#import all the necessary modules
import autopy
import time

#open firefox
autopy.key.type_string("firefox -new-tab www.reddit.com", 300)
autopy.key.tap(long(autopy.key.K_RETURN))
time.sleep(7);

#login to profile
autopy.mouse.smooth_move(1150, 235)
autopy.mouse.click(autopy.mouse.LEFT_BUTTON)
autopy.key.type_string("Dead8olt\t", 200)
autopy.key.type_string("artemis7", 200)
autopy.key.tap(long(autopy.key.K_RETURN))
