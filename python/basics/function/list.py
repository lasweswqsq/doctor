def get_grade(student, name_list, grade_list): 
    i = name_list.index(student)
    print(i)
    grade = grade_list[i] 
    return (student, grade)

names = ['Ana'
,
'John'
,
'Matt'
,
'Katy']
grades = ['A+'
, 'B'
 ,
 'A'
,
 'A' ]

students = ['Ana', 'John', 'Matt', 'Katy']

for student in students:
    print(get_grade(student, names, grades))