#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<double>
find_sum (std::vector<double> numbers, double desired);

void
part_one (std::vector<double> n);

void
part_two (std::vector<double> n);

int 
main(int argc, char const *argv[])
{
    std::vector<double> n;
    std::ifstream nums ("numbers.txt");
    if (nums)
    {
        double value;

        while (nums >> value)
        {
            n.push_back (value);
        }
    }
    nums.close ();

    std::sort (n.begin (), n.end());

    part_one (n);
    part_two (n);
    return 1;

}

void
part_one (std::vector<double> n)
{
    
    std::vector<double> numbers;
    double num1, num2;

    numbers = find_sum (n, 2020);
    num1 = numbers[0];
    num2 = numbers[1];
    std::cout << num1 << ", "
              << num2 << " multipled is "
              << num1 * num2 << "\n";
}

void
part_two (std::vector<double> n)
{
    std::vector<double> numbers;
    double num1, num2, num3;
    auto i = n.begin ();

    while (i != n.end())
    {
        num1 = n[0];
        i++;
        n.erase (n.begin ());

        double desired = 2020 - num1;
        numbers = find_sum (n, desired);
        if (numbers.size() == 2)
        {
            num2 = numbers[0];
            num3 = numbers[1];
            std::cout << num1 << ", "
                      << num2 << ", "
                      << num3 << " multipled is "
                      << num1 * num2 * num3 << "\n";
            break;
        }
    }
}

std::vector<double>
find_sum (std::vector<double> numbers, double desired)
{
    std::vector<double>::iterator num1, it;
    double num2;
    std::vector<double> sum;

    num1 = numbers.begin ();
    while (num1 != numbers.end ())
    {
        num2 = desired - *num1;
        it = find (numbers.begin (), numbers.end (), num2);
        if (it != numbers.end ())
        {
            sum.push_back (*num1);
            sum.push_back (num2);
            break;
        }
        num1++;
    }

    return sum;
}