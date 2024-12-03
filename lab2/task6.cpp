#include <iostream>
#include <string>
using namespace std;
int main()
{
    string names[5] = {"Sarah", "Misbah", "Asif", "Noman", "Kashan"};
    double *nums[5];
    nums[0] = new double[5]{2.66, 2.08, 3, 3.09, 3.45};
    nums[1] = new double[5]{4, 2, 2.66, 2, 0};
    nums[2] = new double[5]{2, 0, 2.33, 0, 3.45};
    nums[3] = new double[5]{3.66, 3.33, 4, 0, 0};
    nums[4] = new double[5]{4, 2.66, 4, 2, 4};
    double gpa[5];
    for (int i = 0; i < 5; i++)
    {
        gpa[i] = 0;
        for (int j = 0; j < 5; j++)
        {
            gpa[i] += (nums[i][j] / 4.0) * 0.75;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Name: " << names[i] << "\tSGPA: " << gpa[i] << endl;
    }

    return 0;
}