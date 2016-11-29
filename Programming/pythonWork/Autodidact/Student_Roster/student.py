class Student:
    student_cnt = 0

    def __init__(self, name, *grades):
        self.name = name
        self.grades = grades
        self.grades = list(self.grades)
        Student.student_cnt += 1

    def get_name(self):
        return self.name
    
    def add_grade(self, grade):
        self.grades.append(grade)
    
    def add_grades(self, *grades):
        if not isinstance(grades[0], int):
            self.grades.extend(grades[0])
        else:
            for i in grades:
                self.add_grade(i)

    def get_grades(self):
        return self.grades

    def get_grade(self, index):
        if index < len(self.grades) and index >= 1:
            return self.grades[index]
        else:
            print "Error: Invalid Index"

    def get_average(self):
        grade_sum = 0
        for i in self.grades:
            grade_sum += i
        return grade_sum / len(self.grades)
