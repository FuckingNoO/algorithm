#include<iostream>
using namespace std;
#define MAX_COL 3
/**
 * bubble_sort
 **/ 
void bubble_sort(int* a,int n){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp; 
			}
		}
	}
}


/**
 * select_sort
 */
void select_sort(int* a,int n){
	int min,temp;
	for(int i=0;i<n;i++){
		min=a[i];
		temp=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<min){
				min=a[j];
				temp=j;
			}	
		}
		a[temp]=a[i];
		a[i]=min;
	}
}

/**
 * insert_sort
 */
void insert_sort(int* a, int n){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j>0;j--){
			if(a[j]<a[j-1]){
	 			temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
		    } 
		}	
	}
}
/**
 *merge_sort
 */
void merge_sort(int* a,int start,int end){
	if(start<end){
		int mid=(start+end)/2;
		merge_sort(a,start,mid);
		merge_sort(a,mid+1,end);

		int len1=mid-start+1,len2=end-mid;
		int* l=new int[len1];
		int* r=new int[len2];
		l[len1]=10000;
		r[len2]=10000;
		for(int i=0;i<len1;i++){	
			l[i]=a[start+i];
		}
		for(int j=0;j<len2;j++){
			r[j]=a[mid+1+j];
		}
		for(int k=start,x=0,y=0;k<=end;k++){
			if(l[x]<r[y]){
				a[k]=l[x];
				x++;
			}else{
				a[k]=r[y];
				y++;
			}
		}
		delete []l;
		delete []r;
    }
}
/**
 *quick_sort
 */
void quick_sort(int* a,int low, int high){
	if(low >= high){
		return ;	
	}
	int front=low;
	int back=high;
	int pivot=a[front];
	int temp;
	while(front<back){
		while(front<back&&a[back]>pivot){
			back--;
		}
		a[front]=a[back];
		a[back]=pivot;

		while(front<back&&a[front]<pivot){
			front++;
		}
		a[back]=a[front];
		a[front]=pivot;
	}

	quick_sort(a,low,front-1);
	quick_sort(a,front+1,high);
}

/**
 * R_quick
 */

void R_quick_sort(int* a,int low,int high){
	if(low>=high){
		return ;
	}
	int front=low;
	int back=high;
	int pivot_key=low+random()%(high-low+1);
	int pivot=a[pivot_key];
	while(front<back){
		while(front<back&&a[back]>pivot){
			back--;
		}
		a[pivot_key]=a[back];
		a[back]=pivot;
		pivot_key=back;
		while(front<back&&a[front]<pivot){
			front++;
		}
		a[pivot_key]=a[front];
		a[front]=pivot;
		pivot_key=front;
	}
	R_quick_sort(a,low,front-1);
	R_quick_sort(a,front+1,high);
}

/**
 * Count_sort
 */
void Count_sort(int* a,int n){
	//在这里我们假设每个数不大于10
	int* t=new int[10];
	int a_key=0;
	for(int i=0;i<n;i++){
		t[a[i]]++;
	}
	for(int j=0;j<10;j++){
		for(int k=0;k<t[j];k++){

			a[a_key]=j;
			a_key++;
		}
	}
	delete []t;
}

/**
 * Bucket_sort
 */
/**
 * Radix_sort
 */
void Radix_sort(int* a,int n){
	 int maxBit = MaxBit(data,n);  	  
     int* tmpData = new int[n];     
     int* cnt = new int[10];    
     int  radix = 1;         
	 int  i,j,binNum;        
	 for(i = 1; i<= maxBit;++i){  
		for(j = 0;j < 10;++j)  
		cnt[j] = 0;   								  
		for(j = 0;j < n; ++j){  
		  binNum = (data[j]/radix)%10;   
		  cnt[binNum]++;  
	   	}  
													  
	 for(binNum=1;binNum< 10;++binNum)  
		cnt[binNum] = cnt[binNum-1] + cnt[binNum];   
	 for(j = n-1;j >= 0;--j){
		 binNum=(data[j]/radix)%10;
	 tmpData[cnt[binNum]-1] = data[j];      
			cnt[binNum]--;
	 }
	 for(j = 0;j < n;++j)
		 data[j] = tmpData[j];  
		 radix = radix*10;  
																					    }  
		 delete [] tmp;  
		 delete [] cnt;
}

int main(int argc,char* argv[]){
	int n,x;
	cout<<"请输入n的值: ";
	cin>>n;
	cout<<"请输入这些数字："<<endl;
	int* a = new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"=========================="<<endl;
	cout<<"1.bubble_sort           2.select_sort"<<endl;
	cout<<"3.insert_sort           4.merge_sort"<<endl;
    cout<<"5.quick_sort            6.R_quick_sort"<<endl;
	cout<<"7.count_sort             8.radix_sort"<<endl;
	cout<<"请选择排序方式: ";
	cin>>x;
	switch(x){
		case 1:bubble_sort(a,n);break;
		case 2:select_sort(a,n);break;
		case 3:insert_sort(a,n);break;
		case 4:merge_sort(a,0,n-1);break;
		case 5:quick_sort(a,0,n-1);break;	
	    case 6:R_quick_sort(a,0,n-1);break;
		case 7:Count_sort(a,n);break;
	    case 8:Radix_sort(a,n);break;			   
		default:cout<<"error~";return 1; 		  
	}
	for(int k=0;k<n;k++){
		cout<<a[k]<<" ";
	}
	cout<<endl;
	delete []a;
	return 0;
}

