#!/usr/bin/python
import os

os.rename("test.txt", "exam.txt")
os.remove("delete_this.txt")
os.mkdir("created_directory")
os.chdir("created_directory")
path = os.getcwd()
print path
os.chdir("..")
os.rmdir("removed_directory")
