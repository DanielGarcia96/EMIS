#!/usr/bin/python

import student 
#Create the array of student objects
student_objects = []

#Create student objects
studentobj_1 = student.Student("Hayley", 90)
studentobj_2 = student.Student("Mark", 87)
studentobj_3 = student.Student("Eli", 60)
studentobj_4 = student.Student("Jane", 70)


#Add student objects
student_objects.append(studentobj_1)
student_objects.append(studentobj_2)
student_objects.append(studentobj_3)
student_objects.append(studentobj_4)

#Print size of roster
print "Current number of students registered is: ", studentobj_4.student_cnt
print ""

#Display all other information
for i in student_objects:
    print "Student name is: ", i.get_name()
    print "Student grade average is: ", i.get_average()
    print "Student grades are: ", i.get_grades()
    print ""

#Add some more grades to each of them
studentobj_1.add_grades(90, 80, 85, 93)
studentobj_2.add_grades(100, 78, 91, 65)
studentobj_3.add_grades(60, 50, 70, 45)
studentobj_4.add_grades(80, 67, 72, 90)

#Display information again
for i in student_objects:
    print "Student name is: ", i.get_name()
    print "Student grade average is: ", i.get_average()
    print "Student grades are: ", i.get_grades()
    print ""

studentobj_1.add_grades([100, 90, 94, 93])
studentobj_2.add_grades([80, 70, 84, 97])
studentobj_3.add_grades([40, 50, 75, 63])
studentobj_4.add_grades([70, 84, 65, 83])

#Display information again
for i in student_objects:
    print "Student name is: ", i.get_name()
    print "Student grade average is: ", i.get_average()
    print "Student grades are: ", i.get_grades()
    print ""

studentobj_1.add_grades(100)
studentobj_2.add_grades(80)
studentobj_3.add_grades(50)
studentobj_4.add_grades(75)

#Display information again
for i in student_objects:
    print "Student name is: ", i.get_name()
    print "Student grade average is: ", i.get_average()
    print "Student grades are: ", i.get_grades()
    print ""
