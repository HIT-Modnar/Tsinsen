// Source : http://www.tsinsen.com/A1066
// Author : Modnar
// Date   : 2019-04-08

#include <cstdio>

// Note:
//   Because of the Tsinsen doesn't provide service now, I can not submit my code
//   to the online judge. Therefore, I can only get the source code from other
//   place. 
//
// Code source:
//   https://github.com/imageslr/tsinsen/blob/master/1066/1066.c

int c[3001];

int get(int i){
    while(i!=c[i])i=c[i];
    return i;
}

void add(int a, int b){
    int af=get(a);
    int bf=get(b);

    if(af!=bf)c[bf]=af;
}

int main(){
    int n,m,i,a,b,count=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        c[i]=i;
    }
    for(i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        add(a,b);
    }
    for(i=0;i<n;i++){
        if(i==c[i])count++;
    }
    printf("%d",count);

    return 0;
}
