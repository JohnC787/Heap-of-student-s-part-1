FUNCTION loadStudents(studentVector)

open students.csv

WHILE file has another line
    read line from file

    create new Student object on heap using line

    append pointer to vector

END WHILE

close file

END FUNCTION

FUNCTION printStudents(studentVector)

FOR each student pointer in vector

    call student->printDetails()

END FOR

END FUNCTION

FUNCTION showStudentNames(studentVector)

FOR each student pointer in vector

    call student->printSummary()

END FOR

END FUNCTION

FUNCTION findStudent(studentVector)

ask user for last name

FOR each student in vector

    IF lastName contains search text
        print student details

END FOR

END FUNCTION

FUNCTION delStudents(studentVector)

FOR each student pointer in vector

    delete student

END FOR

clear vector

END FUNCTION

FUNCTION menu()

print menu options

read user input

return input

END FUNCTION
