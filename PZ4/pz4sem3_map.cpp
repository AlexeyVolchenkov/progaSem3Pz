#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	string a, b;
	map <string, int> mp;
	cout << "Введите строку: ";
	getline(cin, a);
	for (int i = 0; i < a.size() + 1; i++)
	{
		b += a[i];
		if (isspace(a[i]) || a[i] == '\0')
		{
			b.pop_back();
			mp[b]++;
			b = "";
		}
	}
	for (pair<string, int> e : mp)
	{
		cout << e.second << " - " << e.first << endl;
	}
}