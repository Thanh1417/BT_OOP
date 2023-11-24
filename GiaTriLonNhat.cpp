#include <bits/stdc++.h>
using namespace std;
class Cau_hoi{
	private:
    	int u, v;
	public:
    	Cau_hoi(int uu, int vv) : u(uu), v(vv){}
    	int get_u() const{
        	return u;
    	}
    	int get_v() const{
        	return v;
    	}
};

class Update{
	private:
    	int u, v, k;
	public:
    	Update(int uu, int vv, int kk) : u(uu), v(vv), k(kk){}
    	int get_u() const{
        	return u;
    	}
    	int get_v() const{
        	return v;
    	}
    	int getK() const{
       		return k;
    	}
};

class mang_kq{
	private:
    	vector<int> arr;
	public:
    	mang_kq(int n) : arr(n, 0){}
    	void sau_sua(const Update& update){
        	arr[update.get_u() - 1] += update.getK();
        	if (update.get_v() < arr.size()) {
            	arr[update.get_v()] -= update.getK();
        	}
   		}
    	void tinh(){
        	for (int i = 1; i < arr.size(); ++i){
            	arr[i] += arr[i - 1];
        	}
    	}
    	int get_max(int u, int v) const{
        	int maxVal = INT_MIN;
        	for (int i = u - 1; i < v; ++i){
            	maxVal = max(maxVal, arr[i]);
        	}
        	return maxVal;
    	}	
};

int main(){
    int n, m;
    cin >> n >> m;
    mang_kq mang_kq(n);
    for (int i = 0; i < m; ++i){
        int u, v, k;
        cin >> u >> v >> k;
        Update update(u, v, k);
        mang_kq.sau_sua(update);
    }
    mang_kq.tinh();
    int p;
    cin >> p;
    for (int i = 0; i < p; ++i){
        int u, v;
        cin >> u >> v;
        Cau_hoi Cau_hoi(u, v);
        cout << mang_kq.get_max(Cau_hoi.get_u(), Cau_hoi.get_v()) << endl;
    }
}