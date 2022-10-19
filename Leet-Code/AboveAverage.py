cases = int(input())
for dataSets in range (1,cases+1):
    numStudents = int(input())
    grades = []
    grades.clear()    
    counter = 0
    print(grades)
    while counter < numStudents:
        grades.append(1)
        grades[counter] = int(input())
        counter+1 
    print(grades)
