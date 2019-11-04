//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-25.
//


bool canThreePartsEqualSum(vector<int>& A)
{
    if (A.empty() || A.size() < 3)
       return false;
    int sum = 0;
    for (auto i : A)
        sum += i;
    if (sum % 3 != 0)
        return false;

    sum /= 3;
    int count = 0;
    int tmp = 0;

    for (auto i : A)
    {
        tmp += i;
        if (tmp == sum)
        {
            tmp = 0;
            count++;
        }
    }

    if (count != 3 )
        return false;
    return true;


}

