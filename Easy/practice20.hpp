/******************************************************************************* 
 * @Author       : tuhuilin
 * @Date         : 2022-10-20 17:22:58
 * @Description  : 有效的括号
 * @Copyright (c) 2022 zyyt, All Rights Reserved. 
 *******************************************************************************/
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
		//最开始判断奇偶，奇直接返回
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }
		//果然使用了容器，并且使用的是键值对容器，使用键值对容器，可使左右括号形成强相关的一一对应的关系
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {				//遍历字符串,会复制一个s字符串再进行遍历操作,char& ch : s直接引用原字符串进行遍历操作,更快，但是可能会改值
            //先查有没有这个键值对，有的话这个就是右括号，没有这个就是左括号
			if (pairs.count(ch)) {		//通过给定 key 对unordered_map中存在的元素数量进行计数。注意：由于unordered_map不允许存储具有重复键的元素，因此count()函数本质上检查unordered_map中是否存在具有给定键的元素。
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();//最后判断栈是否为空，是的话说明右没配上对的左括号，就返回错误
    }
};

//自练习
//错误总结
//1.应当将右括号做为键值，这样根据键值查找值时找的是左括号，这样如果栈上有value，就可以进行配对了
//2.char对应的是'',而不是"".
class Solution {
public:
    bool isValid(string s) {
		//先判断奇偶。奇就直接返回false
		if(s.length()/2 != 0)
		{
			return false;
		}
		//用个map容器存储键值对，左括号为键，右括号为值，做成强关联，那之后如果输入的是左括号，该容器中就一定存在此键值对，否则输入的就是右括号
		unordered_map<char,char> pairs;	
		// {
		// 	"{","}"
		// 	// {"[","]"},
		// 	// {"(",")"},
		// };
		pairs.insert("(",")");
		pairs.insert("[","]");
		pairs.insert("{","}");

		//遍历输入的S字符，一个字符一个字符的遍历，查找刚开始进来的是不是左括号（找键值对存不存在），如果不存在，说明是右括号
		for(char ch:s)
		{
			stack<char> stacks;
			//如果是左括号
            if(pairs.count(ch))
			{
				stacks.push(ch);
			}
			//如果是右括号
			else
			{
				if(stacks.empty())
				{
					return false;
				}
				//我该如何根据值寻找keys?
				else
				{
					//根据右括号确定其左括号的符号，然后在栈中寻找是否有对应的左符号
					if()
					{
						stacks.pop();
					}
					else
					{
						return false;
					}
				}
			}
		}
		//右括号时，如果栈中找不到对应的左括号，则返回false，找到了，将对应的左括号移出去
		//如果是左括号，将这个左括号存入栈（栈是先入后出的）
		//最后全部遍历完，如果栈中无值返回true，有值返回false-
    }
};
