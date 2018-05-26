#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check(char* filePath)
{
    char data[1000];

	int brace_number = 0;
	int brack_number = 0;
	int i, line;

    FILE *fp=fopen(filePath,"r");
    if(!fp)
    {
        printf("can't open file\n");
        return false;
    }
    line = 1;
    while(!feof(fp))
    {
        fscanf(fp,"%s",&data);
	// 开始check
		for(i = 0; data[i] != '\0'; ++i){
			if( 0 > brace_number ){
				printf("%d行 多余的}\n", line);	
				return false;
			}
			if( 0 > brack_number ){
				printf("%d行 多余的)\n", line);
				return false;
			}
			if('{' == data[i]) ++brace_number;
			if('(' == data[i]) ++brack_number;
			if('}' == data[i]) --brace_number;
			if(')' == data[i]) --brack_number;
		}
        //printf("%s",data);
        //printf("\n");
        ++line;
    }
    if( 0 < brace_number){
        printf("花括号未闭合\n");
        return false;
    }
    if( 0 < brack_number){
        printf("圆括号未闭合\n");
        return true;
    }
    fclose(fp);
    return true;
}
bool in_array(char needle[]){
    
}
main()
{
    check("./1.php");
}
