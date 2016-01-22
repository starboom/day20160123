/*在地下室里放着n种颜色的手套，手套分左右手，
但是每种颜色的左右手手套个数不一定相同。
A先生现在要出门，所以他要去地下室选手套。
但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。
所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。
现在的问题是，他至少要拿多少只手套(左手加右手)，
才能保证一定能选出一双颜色相同的手套。
给定颜色种数n(1≤n≤13),
同时给定两个长度为n的数组left,right,
分别代表每种颜色左右手手套的数量。
数据保证左右的手套总数均不超过26，
且一定存在至少一种合法方案。
测试样例：
4,[0,7,1,6],[1,5,0,6]
返回：10(解释：可以左手手套取2只，右手手套取8只)*/

#include <iostream>
using namespace std;

class Glove
{
public:
	Glove()
	{
		right = new int[ColorNum];
		left  = new	int[ColorNum];
		// cout << ColorNum << "|" << endl;
	}
	void InitGlove()
	{
		int i;
		cin >> ColorNum;
		// cout << ",[" ;
		for(i = 0;i < ColorNum;i++)
		{
			cin >> left[i];
		}
		for(i = 0;i < ColorNum;i++)
		{
			cin >> right[i];
		}
		cout << ColorNum << ",[";
		for(i = 0;i < ColorNum;i++)
		{
			cout << left[i];
			if(i != ColorNum - 1)
				cout <<",";
			else
				cout <<"],[";
		}
		for(i = 0;i < ColorNum;i++)
		{
			cout << right[i];
			if(i != ColorNum - 1)
				cout <<",";
			else
				cout <<"]" << endl;
		}
	}
	int PickGlove(int pic);

	~Glove()
	{
		if(right != NULL)
		{
			cout << "bry" << endl;
			delete[] right;
		}
		if(left != NULL)
		{
			cout << "bay" << endl;
			delete[] left;		
		}
	}
private:
	int ColorNum;
	int *right;
	int *left;
};
int PickGloveNice(Glove& ggg)
{
	int m1;
	int m2;
	m1 = ggg.PickGlove(1);
	m2 = ggg.PickGlove(2);
	cout << m1 << "  " << m2 <<endl;
	return (m1 > m2)?m2 : m1;
	// return 1;
}
int Glove :: PickGlove(int pic)// 1 for left main 2 for right main
{
	int i;
	int j;
	int *Main;
	int *Second;
	int MainCount[4] = {0};//每种颜色的情况记录
	int SecondCount[4] = {0};//每种情况的总数
	int SecondTotal = 0;
	int MainTotal = 0;
	int PickNumber;
	int MainNum = 0; //左手套总数
	int SecondNum = 0;//右手手套总数
	if(pic == 1)
	{
		Main = left;
		Second = right;		
	}
	if(pic == 2)
	{
		Main = right;
		Second = left;	
	}

	for(i = 0;i < 4;i++)
	{
		MainNum = Main[i] + MainNum;
		SecondNum = Second[i] + SecondNum;
	}
	// for(i = 0;i < 4;i++)
	// {
	// 	if(Main[i] != 0 && Second[i] == 0)
	// 	{
	// 		MainTotal = 1;
	// 	}
	// }
	for(i = 0;i < 4;i++)
	{
		if(Main[i] == 0)
		{
			continue;
		}
		if(Main[i] != 0)
		{
			MainCount[i]++;
			cout << "MainCount|" << MainCount[i] << "----";
			if(Second[i] > 1)
			{
				SecondCount[i] = SecondNum - Second[i] + 1;
				cout << "SecondNum|" << SecondCount[i] << endl;

			}
			if(Second[i] == 1)
			{
				SecondCount[i] = SecondNum;
				cout << "SecondNum|" << SecondCount[i] << endl;
			}
			if(Second[i] == 0)
			{
				SecondCount[i] = 0;
				cout << "SecondNum|" << SecondCount[i] << endl;			
			}
		}
	}
	for(i = 0;i < 4;i++)
	{
		MainTotal = MainCount[i] + MainTotal;
	}
	if(MainTotal % 4 != 0)
	{
		MainTotal = 2;
	}
	else
	{
		MainTotal = MainTotal / 4;
	}
	cout << "MainTotal  |" << MainTotal << endl;

	for(i = 0;i < 4;i++)
	{
		for(j = 0;j < 4 - 1 - i;j++)
		{
			if(SecondCount[j] < SecondCount[j+1])
			{

				SecondCount[j]=SecondCount[j]+SecondCount[j+1];
    			SecondCount[j+1]=SecondCount[j]-SecondCount[j+1];
    			SecondCount[j]=SecondCount[j]-SecondCount[j+1];
			}
		}
	}
	SecondTotal = SecondCount[0];
	cout << "SecondTotal |" << SecondTotal << endl;
	PickNumber = SecondTotal + MainTotal;
	return  PickNumber;
}
int main(int argc, char const *argv[])
{
	Glove gg;;
	gg.InitGlove();
	cout << "The end |" << PickGloveNice(gg) << endl;
	return 0; 
}


