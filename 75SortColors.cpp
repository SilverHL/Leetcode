#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
	void sortColors(vector<int>& nums)
	{
		int second = nums.size() - 1, zero = 0;
		for (int i = 0; i <= second; i++)
		{
			while (nums[i] == 2 && nums[i] > nums[second]) swap(nums[i], nums[second--]);
			while (nums[i] == 1 && nums[i] < nums[zero]) swap(nums[i], nums[zero++]);
		}
	}
};

int main75()
{
	int *a = new int[5];
	a[0] = 1;
	a[1] = 9;
	int *p = a;
	int c = *p++;
	//cout << c;
	//cout << a[0];
	//cout << *p;

	const char * s = "12\r\n123\r\n";
	char *end;
	for (int i = strtol(s, &end, 10);
		s != end;
		i = strtol(s, &end, 10))
	{
		cout << i << endl;
		s = end;
	}

	getchar();
	return 0;
}