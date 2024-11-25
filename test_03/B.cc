#include <iostream>
#include <queue>
struct person
{
    int bad_or_good;
    int order;
};
int main()
{
    int ans;
    int k;
    int good = k;
    int bad = k;
    std::cin >> k;
    std::queue<person> persons;
    person p1;
    p1.bad_or_good = 1;
    p1.order = 1;
    persons.push(p1);
    for (int i = 2; i <= k; i++)
    {
        person p;
        p.bad_or_good = 1;
        p.order = i;
        persons.push(p);
    }
    for (int i = 2; i <= k; i++)
    {
        person p;
        p.bad_or_good = 0;
        p.order = i;
        persons.push(p);
    }
    for (int m = 2;; m++)
    {
        int flag = 1;
        while (bad != 0)
        {
            person p = persons.front();
            persons.pop();
            if (flag == m)
            {
                if (p.order == 1 && p.bad_or_good == 1)
                {
                    break;
                }
                switch (p.bad_or_good)
                {
                case 0:
                    bad--;
                    break;
                case 1:
                    good--;
                    break;
                }
                if(bad == 0)
                {
                    std::cout << m << std::endl;
                    return 0;
                }
            }
            else
            {
                persons.push(p);
            }
            flag++;
        }
    }
}