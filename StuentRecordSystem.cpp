// Muhammad Yousaf_I228797_SE-F
#include <iostream>

using namespace std;

class Student
{
private:
	int stdID;
	string Name;
	string *courseCodes;
	int numCourses;
	int *courseGrades;
	float gpa;

public:
	Student()
	{
		stdID = 0;
		Name = "";
		numCourses = 0;
		courseCodes = NULL;
		courseGrades = NULL;
		gpa = 0.0;
	}
	~Student()
	{
		if (courseCodes != NULL)
		{
			delete[] courseCodes;
			courseCodes = NULL;
		}
		if (courseGrades != NULL)
		{
			delete[] courseGrades;
			courseGrades = NULL;
		}
	}
	int getStdID() //- a getter for the student's ID
	{
		return stdID;
	}
	string getName() //- a getter for the student's first name
	{
		return Name;
	}
	int getNumCourses() //- a getter for the number of courses taken by the student
	{
		return numCourses;
	}
	string getCourseCode(int i) //- a getter for the course code of the course taken at index i of the courseCodes array
	{
		if (i < numCourses) // validation
			return (*(courseCodes + i));
		else
			return "";
	}
	int getCourseGrade(int i) //- a getter for the grade obtained by the student in the course taken at index i of the courseGrades array
	{
		if (i < numCourses) // validation
			return (*(courseGrades + i));
		else
			return -1;
	}
	float getGPA() //- a getter for the student's GPA
	{
		return gpa;
	}
	void setStdID(int id) //- a setter for the student's ID
	{
		this->stdID = id;
	}
	void setName(string firstName) //- a setter for the student's first name
	{
		this->Name = firstName;
	}
	void setCourseGrade(string courseCode, int grade) //- a function to set the grade obtained by the student in the course with the given course code
	{
		if(grade>4 || grade<0)
		{
			cout<<"Error! grade can never be greater than 4 or smaller than 0"<<endl;
		}
		else
		{
			for (int i = 0; i < numCourses; i++)
		{
			if (*(courseCodes + i) == courseCode)
			{
				*(courseGrades + i) = grade;
				calcGPA();
				break;
			}
		}
		}
	}
	void addCourse(string courseCode, int grade) //- a function to add a course with the given course code and grade to the student's record
	{
		string *newcourseCodes = new string[numCourses + 1]; // new extended array to add new course code
		int *newcourseGrades = new int[numCourses + 1];		 // new extended array to add new course grade

		for (int i = 0; i < numCourses; i++) // To fill previous empty values in new arrays before adding the new ones
		{
			(*(newcourseCodes + i)) = (*(courseCodes + i));
			(*(newcourseGrades + i)) = (*(courseGrades + i));
		}

		*(newcourseCodes + (numCourses)) = courseCode; // adding new values
		*(newcourseGrades + (numCourses)) = grade;

		if (courseCodes != NULL)
		{
			delete[] courseCodes; // deleting previous arrays and releasing memory
			courseCodes = NULL;
		}
		if (courseGrades)
		{
			delete[] courseGrades;
			courseGrades = NULL;
		}
		courseCodes = newcourseCodes; // assigning the arrays to the new arrays with updated data
		courseGrades = newcourseGrades;

		//delete[] newcourseCodes; // deleting the new arrays and releasing the memory (as their data is now stored)
		//newcourseCodes = NULL;
		
		//delete[] newcourseGrades;
		//newcourseGrades = NULL;

		numCourses++;

		calcGPA();
	}
	void calcGPA() //- a function to calculate the student's GPA
	{
		float sum = 0;
		for (int i = 0; i < numCourses; i++)
		{
			sum += *(courseGrades + i);
		}
		if (numCourses > 0)
            gpa = sum / numCourses;
        else
            gpa = -1.0;
	}
};

Student getStudentAt(Student students[], int index) //- returns the Student object at the given array index
{
	return students[index];
}

float calcClassGPA(Student students[], int numStudents) //- calculates the average GPA of all students in the array
{
	float sum = -1.0;
	for (int i = 0; i < numStudents; i++)
	{
		students[i].calcGPA();
		sum += students[i].getGPA();
	}
	return (sum / numStudents);
}

float getMaxGPA(Student students[], int numStudents) //- calculates the maximum GPA from all the students in the array
{
	float max = -1.0;
	for (int i = 0; i < numStudents; i++)
	{
		students[i].calcGPA();
		if (students[i].getGPA() > max)
		{
			max = students[i].getGPA();
		}
	}
	return max;
}

float getMinGPA(Student students[], int numStudents) //- calculates the minimum GPA from all the students in the array
{
	float min = 4.0;
	for (int i = 0; i < numStudents; i++)
	{
		students[i].calcGPA();
		if (students[i].getGPA() < min)
		{
			min = students[i].getGPA();
		}
		else
			continue;
	}
	return min;
}
void printStudentRecord(Student student) //- prints the record of the given student, including the student's ID, name, course codes, grades, and GPA
{
	cout << "Student ID : " << student.getStdID() << endl;
	cout << "Student Name : " << student.getName() << endl;
	cout << "Courses taken by the student : " << student.getNumCourses() << endl;
	cout << " Course code "
		 << "  Grade " << endl;
	for (int i = 0; i < student.getNumCourses(); i++)
	{
		cout << " " << student.getCourseCode(i) << "   " << student.getCourseGrade(i) << endl;
	}
	cout << endl;
	cout << "GPA of the student: " << student.getGPA() << endl
		 << endl;
}
void printAllStudentRecords(Student students[], int numStudents) //- prints the records of all students in the array
{
	for (int i = 0; i < numStudents; i++)
	{
		printStudentRecord(students[i]);
	}
}
int main()
{
	
}
