#include<iostream>
#include<vector>
using namespace std;

vector<int> lis(vector<int> v) {
	vector<vector<int>>   out;
	vector<int> p, line_to_add;
	p.push_back(v.front());
	out.push_back(p);
	for (auto a = v.begin()+1; a != v.end(); ++a) {
		int i;
		int z = 0;
		for (i = 0; i < out.size(); ++i) {
			if ( out[i].back() <= *a) {
				z = i;
			}
		}
		if(z == 0 && out[0][0] > *a) {
			int d = out[0][0];
			out[0][0]=*a;
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
	}
return out.back();
}



int main()
{
//	vector<int> v={15,1,16}, g;
	vector<int> v={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}, g;
//	vector<int> v={10,22,9,33,21,50,41,60,80}, g;
	g = lis(v);
	cout << "Longest increasing subsequent has: " << g.size() << " elements." << endl;
	for( auto w : g) {
		cout << w << endl;
	}
return 0;
}
