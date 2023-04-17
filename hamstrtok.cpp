#include<stdio.h>
#include<string.h>

int main(){
	char s[100];
	char *s2=new char;
	scanf("%s",s2);
	gets(s);
	char *p=strtok(s," ");
	while(p!=NULL){
		if(strcmp(p,s2)!=0)printf("%s ",p);
		p=strtok(NULL," ");
	}
	return 0;
}
