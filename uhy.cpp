
/*<!-- Created By Atul Chaudhary -->*/
#include <bits/stdc++.h>

using namespace std;


void solve() {
	string s;
	cin >> s;
	int conson = 0, vowel = 0;
	int ccc[26];
	for(int i = 0; i < 26; i++)
		ccc[i] = 0;
	for(int i = 0; i < (int)s.size(); i++) {
		if(s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O'
			or s[i] == 'U') {
			vowel++;
		}else conson++;
		ccc[s[i]-'A']++;
	}
	int verma = 0, atul = 0;
	verma += conson;
	int chau = ccc[0]+ccc[4]+ccc[8]+ccc[14]+ccc[20];
	int akanksha = max({ccc[0],ccc[4],ccc[8],ccc[14],ccc[20]});
	chau -= akanksha;
	verma += 2*chau;

	atul += vowel;
	chau = 0;
	akanksha = INT_MIN;
	for(int i = 1; i < 26; i++) {
		if(i == 4 or i == 8 or i == 14 or i == 20)
			continue;
		else chau += ccc[i];
		akanksha = max(akanksha, ccc[i]);
	}
	chau -= akanksha;
	atul += 2*chau;
	int ans = min(verma, atul);
	if(!vowel or !conson) {
		ans = min(ans, (int)s.size());
	}
	cout << ans << '\n';
}

int main(void)
{

	// file_i_o();

	clock_t start, end;
    start = clock();

    
    int bsdk;
	cin >> bsdk;
	for(int i = 1; i <= bsdk; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	

	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"Coded By Atul Chaudhary"<<endl;
	return 0;
}