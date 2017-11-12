#include<iostream>
#include<vector>
using namespace std;

vector<int> lis(vector<int> v) {
	vector<vector<int>>   out;
	vector<int> p, line_to_add;
	p.push_back(v.front());
	out.push_back(p);
/*	p.clear();
	p.push_back(7);
	p.push_back(8);
	out.push_back(p);
	p.clear();
	p.push_back(10);
	out.push_back(p);*/
	for (auto a = v.begin()+1; a != v.end(); ++a) {
		int i;
		int z = 0;
		for (i = 0; i < out.size(); ++i) {
			if ( out[i].back() <= *a) {
				z = i;
			}
		}
		cout << "Puts: " << *a << endl;;
		cout << out[z].back()<< endl;
		if(z == 0 && out[0][0] > *a) {
			int d = out[0][0];
			out[0][0]=*a;
//			out[1][0]=*a;
//			out[1][1] = d;
			cout << "Z=0 then d = " << d <<endl;
		int t;
		cin >> t;
		} else {
		line_to_add = out[z];
		line_to_add.push_back(*a);
		if ((z+1) == out.size()) {
			out.push_back(line_to_add);
		} else {
			if(line_to_add.back() < out[z+1].back()) {
				out[z+1]=line_to_add;
			}
		}
		}
		//find where put a - compere last item of each vector if next 
	}
cout << "=====" <<endl;
	for( int i=0; i < out.size(); ++i) {
		for(auto w : out[i]) cout << w << " ";
		cout << endl;
	}
return v;
}



int main()
{
	vector<int> v={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}, g;
//	vector<int> v={10,22,9,33,21,50,41,60,80}, g;
	g = lis(v);


return 0;
}
