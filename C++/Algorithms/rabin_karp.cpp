//Rabin Karp algorithm is a pattern searching algorithm which
//works in linear time and finds the position at which the 
//required pattern is found in given text.
#include<iostream>
#include<string>

using namespace std;

class rabin_karp
{
	private:
		int x = 23;
		long long p = 100000007;
		string pattern, text;
	public:
		rabin_karp(string pattern, string text): pattern(pattern), text(text) {}
		int is_substring();
		bool compare_strings(int);
};


bool rabin_karp::compare_strings(int i)
{
	for(int k = 0;  k < pattern.length(); k++)
	{	
		if(text[i] != pattern[k])
			return false;
		i++;
	}
	return true;
}

int rabin_karp::is_substring()
{
	long long temp = 1;
	if(pattern.length() > text.length())
		return -1;
	long long hash_pattern = 0, hash_text = 0;
	for(size_t i = 0; i < pattern.length(); i++)
	{
		hash_pattern = (hash_pattern*x + pattern[i])%p;
		hash_text = (hash_text*x + text[i])%p;
		temp *= x;
	}
	temp %= p;
	if(hash_pattern == hash_text)
		if(compare_strings(0))
			return 0;
	for(size_t i = pattern.length(); i < text.length();i++)
	{
		hash_text = (p + hash_text*x + text[i] - (temp*text[i - pattern.length()])%p)%p;
		// cout <<  hash_text<<' ';
		if(hash_text == hash_pattern)
		{
			// cout<<"JKFJK";
			if(compare_strings(i - pattern.length() + 1))
			{
				return i - pattern.length() + 1;
			}
		}
	}	
	return -1;
}
int main()
{
	string pattern, text;
	cin >> text;
	cin >> pattern;
	rabin_karp r(pattern, text);
	cout << r.is_substring();
	return 0;
}