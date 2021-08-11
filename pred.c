#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int expr();
void err(const char* s)
{
	perror(s);
	exit(0);
}
int factor()
{
	int val,i;
	char ch[0];
	scanf("%s",ch);
	switch(ch[0])
	{
		case '(':
		val=expr();
		scanf("%s",ch);
		if(ch[0]!=')')
		err("missing closing parantesis in factor,");
		break;
		default:
		for(i=0;i<strlen(ch);i++)
		{
			if((ch[i]>'0')&&ch[i]<='9')
				continue;
			else
				err("illegal char sequence factor.");
		}
		val=atoi(ch);
	}
	return val;
}
int term()
{
	int val;
	char ch[10];
	val=factor();
	while(1)
	{
		scanf("%s",ch);
		if(ch[0]=='*')
		{
			val=val*factor();
		}
		else
		break;
	}
	
	ungetc(ch[0],stdin);
	return val;
}
int expr()
{
	int val;
	char ch[10];
	val=term();
	while(1)
	{
		scanf("%s",ch);
		if(ch[0]=='+')
		{
			val=val+term();
		}
		else if(ch[0]=='-')
			val=val-term();
		else if(ch[0]=='/')
			val=val/term();
		else 
		break;
	}
	
	ungetc(ch[0],stdin);
	return val;
}
int main()
{
	printf("enter the exp:");
	printf("\n result:%d\n",expr());
}

