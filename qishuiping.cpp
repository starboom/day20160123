/*有这样一道智力题：
“某商店规定：三个空汽水瓶可以换一瓶汽水。
小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”
答案是5瓶，
方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，
喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，
这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，
喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。
如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int save;
	int count = 0;
	cin >> n;
	// save = n % 3;//2
	// if(save == 2)
	// {
	// 	count++;
	// } 
	// cout << save << endl;
	int flag = 0;
	//n 代表我喝的空饼子数
	//count 代表我能用空瓶子换到的汽水树
	//save 最大我能剩下不能换汽水喝的瓶子。
	//
    // while(1)
    // {
    //     if(n/3 >= 1)
    //         {
    //         	count = count + n/3;//3 4
    //         	save = n % 3;
    //         	if(save == 2)
    //         	{
    //         		count++;
    //         	}  
    // 			// cout << "count : " << count << endl;
    //         	if(flag == 0)
    //         	{
    //         		n = n/3;//3 1
    //         	}
    //         	if(3 - (n + save) == 1)
    //         	{
    //         		flag = 1;
    //         		// cout << "n :" << n << endl;
    //         		count = count + 1;
    //         		break;
    //         	}
            	
    //     	}
    //     else
    //     {
    //         break;
    //     }
    // }
	while(1)
	{
		if(n == 2)
		{
			count++;
			break;
		}
		if(n == 1 || n == 0)
		{
			break;
		}
		if(n >= 3)
		{
			count = count + (n / 3);
			n = (n % 3) + (n / 3);	
		}

	}
	cout << count << endl;

	return 0;
}
