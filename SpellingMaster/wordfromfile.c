#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *inp,*out;
    inp=fopen("CorrectWord.txt","r");
    out=fopen("WrongWord.txt","r");
    srand(time(NULL));
    int count1,count2;
    char wrong[3][20];
    char right[20];
    char ch;
    count1=261;count2=201;
    int x1,count=0;
    x1=rand()%count1;
    int y1=rand()%count2;
    int y2=rand()%count2;
    int y3=rand()%count2;

    while(!feof(inp)){
            ch=fgetc(inp);
        if(ch=='\n'){
                count++;

        }
        if(count==x1){
            break;
        }
    }

    fscanf(inp,"%s",right);
    printf("%s\n",right);
    count=0;

    while(!feof(out)){
            ch=fgetc(out);
        if(ch=='\n'){
                count++;

        }
        if(count==y1){
            break;
        }
    }
    fscanf(out,"%s",wrong);
    rewind(out);
    printf("%s\n",wrong);

    count=0;

    while(!feof(out)){
            ch=fgetc(out);
        if(ch=='\n'){
                count++;

        }
        if(count==y2){
            break;
        }
    }
    fscanf(out,"%s",wrong+1);
    rewind(out);
    printf("%s\n",wrong+1);

    count=0;

    while(!feof(out)){
            ch=fgetc(out);
        if(ch=='\n'){
                count++;

        }
        if(count==y3){
            break;
        }
    }
    fscanf(out,"%s",wrong+2);

    printf("%s",wrong+2);

    fclose(inp);
    fclose(out);

}
