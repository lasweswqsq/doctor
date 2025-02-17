def find_grades(grades, students):
        
    result = []
    for student in students:
        if 'A' in grades:
            print(f"{student} has an A grade")
            result.append(grades[student])
        else:
            result.append(None)
            
    return result

# Usage:
# d = {'Ana':'B', 'Matt':'C', 'John':'B', 'Katy':'A'}
# print(find_grades(d, ['Matt', 'Katy'])) # returns ['C', 'A']
# for example
d = {'Ana':'B', 'Matt':'C', 'John':'B', 'Katy':'A'}
print(find_grades(d, ['Matt', 'Katy'])) # returns ['C', 'A']