#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int INFINITE = 100000;

struct plat{
		int x, x2, y;
};

plat all[1005];
int zleft[1005];
int zright[1005];

int zmax;

int mycompare(const void* a, const void *b){
		const plat* aa = (const plat*) a;
		const plat* bb = (const plat*) b;
		return bb->y - aa->y;
}

void compute(bool bleft, int *l, int* r, int size, int pos, plat *all){

		int i, x, y = (all[pos]).y;
		int *tgt = NULL;

		if( bleft ){
				x = (all[pos]).x;
				tgt = l;
		}
		else {
				x = (all[pos]).x2;
				tgt = r;
		}

		for( i = pos + 1; i<=size; ++i ){
				plat& cur = all[i];
				if( cur.x <= x && cur.x2 >= x)
						break;
		}

		if( i > size ){
				if( y > zmax ){
						tgt[pos] = INFINITE;
				} else {
						tgt[pos] = y;
				}
				return;
		} else {
				if( y - (all[i]).y > zmax ){
						tgt[pos] = INFINITE;
						return ;
				}
		}

		int nlefttime = y - (all[i]).y + x - (all[i]).x;
		int nrighttime = y - (all[i]).y + (all[i]).x2 - x;

        nlefttime += l[i];
        nrighttime += r[i];
		if( nlefttime > nrighttime )
				tgt[pos] = nrighttime;
		else
				tgt[pos] = nlefttime;
}

int main(int argc, char* argv[]){

		int n,x,y,t;
		int x1,x2,h;
		cin >> t;
		while(t){

				cin >> n >> x >> y >> zmax;
				
				memset(all, 0, sizeof(all));
				memset(zleft, 0, sizeof(zleft));
				memset(zright, 0, sizeof(zright));

				(all[0]).x = x;
				(all[0]).x2 = x;
				(all[0]).y = y;
				
				for(int i=1; i<=n; ++i){
						cin >> x1 >> x2 >> h;
						(all[i]).x = x1;
						(all[i]).x2 = x2;
						(all[i]).y = h;
				}

				qsort(all, n+1, sizeof(plat), mycompare);

				for(int i=n; i>0; --i ){
						compute(true, zleft, zright, n, i, all);
						compute(false, zleft, zright, n, i, all);
				}
				compute(true, zleft, zright, n, 0, all);

				cout << zleft[0] << endl;
				--t;
		}
		return 0;
}
