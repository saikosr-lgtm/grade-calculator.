// Grade Calculator
// Reads 5 scores for each student, prints the average and the grade,
// and at the end prints the number of students and the class average.
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int SCORE_COUNT = 5;
const int MIN_SCORE = 0;
const int MAX_SCORE = 100;
const double GRADE_A_MIN = 90.0;
const double GRADE_B_MIN = 75.0;
const double GRADE_C_MIN = 60.0;

int main()
{
    string studentName;
    int studentCount = 0;
    double sumOfAverages = 0.0;

    cout << fixed << setprecision(1);

    cout << "Student name (or end to finish): ";
    getline(cin, studentName);

    // Outer loop: one student per iteration, stops on "end"
    while (studentName != "end")
    {
        int totalScore = 0;

        // Read exactly 5 scores
        for (int i = 1; i <= SCORE_COUNT; i++)
        {
            int score = 0;
            bool isValid = false;

            // Inner loop: ask again until the score is valid
            while (!isValid)
            {
                cout << "Score " << i << ": ";
                cin >> score;

                if (cin.fail())
                {
                    // Bonus: letters were typed instead of a number
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid score. Enter a value from 0 to 100." << endl;
                }
                else if (score < MIN_SCORE || score > MAX_SCORE)
                {
                    cin.ignore(1000, '\n');
                    cout << "Invalid score. Enter a value from 0 to 100." << endl;
                }
                else
                {
                    cin.ignore(1000, '\n');
                    isValid = true;
                }
            }

            totalScore += score;
        }

        double average = (double)totalScore / SCORE_COUNT;

        // Choose the grade using the scale from the client
        char grade;
        if (average >= GRADE_A_MIN)
        {
            grade = 'A';
        }
        else if (average >= GRADE_B_MIN)
        {
            grade = 'B';
        }
        else if (average >= GRADE_C_MIN)
        {
            grade = 'C';
        }
        else
        {
            grade = 'F';
        }

        cout << studentName << ": average " << average << ", grade " << grade << endl;
        cout << endl;

        studentCount++;
        sumOfAverages += average;

        cout << "Student name (or end to finish): ";
        getline(cin, studentName);
    }

    if (studentCount == 0)
    {
        cout << "No students entered" << endl;
    }
    else
    {
        double classAverage = sumOfAverages / studentCount;
        cout << "Students entered: " << studentCount << endl;
        cout << "Class average: " << classAverage << endl;
    }

    return 0;
}
