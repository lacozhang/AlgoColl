
//求出n个词的所有可能组合
//dat是n个词的指针数组，n是词的个数

void all_comb(char* dat[], int n){
		if(!dat)
				return;
		int i=1;
		int *opts = new int[n];
		for(i=1; i<n; ++i){
				comb(dat, n, i, 0, opts, 0);
		}
}


// 在大小为size的dat数组中，从pos - （n-1）的所有候选词中，选择k个词，并将其在dat数组中的下标
//放入数组opts中，从位置i开始存储。

void comb(char* dat[], int size, int k, int pos, int opts[], int i){

		if(!dat)
				return;d
		if( size - pos < k )
				return;
		if( pos >= size )
				return ;
		if( k == 0 ){
				//opts数组中，存储i个选择的词，输出所有选择的词
				for(int j=0; j<i; ++j){
						printf("%s\t", dat[opts[j]]);
				}
				printf("\n");
		}
//不选择当前词
		comb(dat, size, k, pos+1, opts, i);
//选择当前词
		opts[i] = pos;
		comb(dat, size, k-1, pos+1, opts, i+1);
}

