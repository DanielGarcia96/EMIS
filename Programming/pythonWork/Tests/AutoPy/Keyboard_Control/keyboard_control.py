#!/usr/bin/python

import autopy

autopy.key.type_string('ls -al', 120)
autopy.key.tap(long(autopy.key.K_RETURN))
