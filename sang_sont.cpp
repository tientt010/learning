#include<stdio.h>

int main(){
    int sont[100001]={};
    sont[1]=1;
    for(int i=2;i<=1001;i++){
        if(sont[i]==0){
            for(int j=i*i;j<=1e5;j+=i)sont[j]=1;
        }
    }
    int cnt_sont[100002]={};
    for(int i=1;i<=100001;i++){
        cnt_sont[i]=(cnt_sont[i-1]+!sont[i]);
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",cnt_sont[r]-cnt_sont[l-1]);
        
    }

}