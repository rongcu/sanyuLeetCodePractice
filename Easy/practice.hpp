//两数之和

//以下是暴力破解法
char nums[] = {1, 8, 5, 7, 9, 2, 4, 8, 5, 4} //会有重复吗？数组内的元素值
char target = 15;
for (char i = 0; i < sizeof(nums) - 1; i++) //我写的，暴力破解法
{
	int answer = target - nums[i];
	for (char b = i + 1; b < sizeof(nums); b++)
	{
		if (nums[b] == answer)
		{
			return i, b; //好像不能同时返回两个值，得用容器或者使用指针返回
		}
		// else   这段是错误的，不需要
		// {
		// 	b++;
		// }
	}
	i++;
}
cout << "没有符合要求的数/n";
return 0;

//标准答案 C++
class Solution
{
public:												  //它将函数写在了公有条件下
	vector<int> twoSum(vector<int> &nums, int target) //它使用int类型的vector容器来存放正数，进行判断，类似数组吧
	{
		int n = nums.size();
		for (int i = 0; i < n; ++i) //为何这儿的大小为n,而不是n-1?,当i=n-1时，j=n,第二个循环已经不会进去了，所以没必要-1
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					return {i, j};
				}
			}
		}
		return {};
	}
};

// C
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{ //将它写入一个函数里
	for (int i = 0; i < numsSize; ++i)
	{
		for (int j = i + 1; j < numsSize; ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				int *ret = malloc(sizeof(int) * 2); //它是申请了一个指针，然后通过返回指针来获得值
				ret[0] = i, ret[1] = j;				//指针直接做数组名，用来保存数据
				*returnSize = 2;					//感觉这个指针没什么用，函数内部没有使用，也没有做返回值
				return ret;
			}
		}
	}
	*returnSize = 0;
	return NULL;
}

//以下是更高级的哈希算法
// C++
class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); ++i)
		{
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end())
			{
				return {it->second, i};
			}
			hashtable[nums[i]] = i;
		}
		return {};
	}
};

// C
struct hashTable
{
	int key;
	int val;
	UT_hash_handle hh;
};

struct hashTable *hashtable;

struct hashTable *find(int ikey)
{
	struct hashTable *tmp;
	HASH_FIND_INT(hashtable, &ikey, tmp);
	return tmp;
}

void insert(int ikey, int ival)
{
	struct hashTable *it = find(ikey);
	if (it == NULL)
	{
		struct hashTable *tmp = malloc(sizeof(struct hashTable));
		tmp->key = ikey, tmp->val = ival;
		HASH_ADD_INT(hashtable, key, tmp);
	}
	else
	{
		it->val = ival;
	}
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	hashtable = NULL;
	for (int i = 0; i < numsSize; i++)
	{
		struct hashTable *it = find(target - nums[i]);
		if (it != NULL)
		{
			int *ret = malloc(sizeof(int) * 2);
			ret[0] = it->val, ret[1] = i;
			*returnSize = 2;
			return ret;
		}
		insert(nums[i], i);
	}
	*returnSize = 0;
	return NULL;
}
