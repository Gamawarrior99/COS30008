
#include <iostream>

using namespace std;


/*int main()
{
	cout<<"Hello World!"<<endl;
	return 0;
}*/

int main(int argc, char* argv[])
{
	
	for (int i = 1; i < argc; i++)
	{
		cout << argv[i]<< endl;
	}
	cout << endl;
	return 0;
}
