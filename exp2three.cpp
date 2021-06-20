#include<bits/stdc++.h>
using namespace std;
stack<string> sta;
map<string,int> mp;
vector<string> ans;
stack<string> st;
//( ) == != <= >= + - * /
int main()
{
	int i,lstr;
	string word,str;
	//cin >> str;
	vector<string> vec;
	//lstr=str.length();

	getline(cin,str);
	istringstream record(str);
	while(record>>word)
	{
		vec.push_back(word);
	}
	/*while(cin >> word)
	{
		vec.push_back(word);
	}*/
	/*for(auto i:vec)
	{
		cout << i << " ";
	}*/
	
	mp.clear();
	mp["++"]=14;mp["--"]=14;
	mp["*"]=13;mp["/"]=13;mp["%"]=13;
	mp["+"]=12;mp["-"]=12;
	mp["<<"]=11;mp[">>"]=11;
	mp[">="]=10;mp["<="]=10;mp["<"]=10;mp[">"]=10;
	mp["=="]=9;mp["!="]=9;
	mp["^"]=7;
	mp["|"]=6;
	mp["&&"]=5;
	mp["||"]=4;
	mp["="]=2;mp["+="]=2;mp["-="]=2;mp["*="]=2;mp["/="]=2;mp["%="]=2;mp["&="]=2;mp["^="]=2;mp["|="]=2;mp["<<="]=2;mp[">>="]=2;
	mp["("]=-1;mp[")"]=-1;
	
	while(!sta.empty())sta.pop();

	for(i=0;i<vec.size();i++)
	{
		word=vec[i];
		if(mp[word]==0)
		{
			ans.push_back(word);
		}
		else
		{
			if(word!=")")
			{
				if(word!="(")
				{
					while(!sta.empty())
					{
						string Top=sta.top();sta.pop();
						if(mp[word]<=mp[Top])
						{
							ans.push_back(Top);
						}
						else
						{
							sta.push(Top);
							break;
						}
					}
					sta.push(word);
				}
				else sta.push(word);
			}
			else
			{
				while(!sta.empty())
				{
					string Top=sta.top();sta.pop();
					if(Top=="(")break;
					ans.push_back(Top);
				}
			}
		}
	}
	while(!sta.empty())
	{
		string Top=sta.top();sta.pop();
		ans.push_back(Top);
	}
	/*for(auto i:ans)
	{
		cout << i << " ";
	}*/
	int num=0;
	vector<string>::iterator it;
	for(it=ans.begin();it!=ans.end();it++)
	{
		string now=(*it);
		if(mp[now]==0)
		{
			st.push(now);
		}
		else
		{
			string Top=st.top();st.pop();
			string Top1=st.top();st.pop();
			if(now!="=")
			{
				num++;
				string var="temp"+to_string(num);
				cout << now << " " << var << " " << Top1 << " " << Top << endl;
				//cout << var << " = " << Top1 << " " << now << " " << Top << " " << endl;
				st.push(var);
			}
			else
			{
				cout << now << " " << Top1 << " " << Top << endl;
			}
		}
	}
	return 0;
}
