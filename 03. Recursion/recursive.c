#include <stdio.h>

int linsearch(int* a, int ele, int i){
	if(ele==*a){
		return(i);
	}
	a++;
	return linsearch(a, ele, ++i);
}

int main(){
	int a[5], ele;
	printf("Enter elements of array(5):\n");
        int i=0; 
        while(i<5){
                printf("%d: ",i);
                scanf("%d", &a[i]);
                ++i;
        }
	printf("Enter element to search: ");
	scanf("%d", &ele);
	int p;
	p= linsearch(a,ele,0);
	printf("Element found at position: %d\n",p+1);
	return 0;
}
