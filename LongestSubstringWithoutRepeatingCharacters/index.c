#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Given a string s, find the length of the longest substring without repeating characters.
int lengthOfLongestSubstring(char *s){
    char *p = &s[0];
    int counter=0;
    if(s[0]=='\0')return 0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i+1]=='\0'&&i!=0)return 1;
        if(s[i]!=s[i+1])break;
    }
    for(int i=0,offset=0;s[i]!='\0';i++){
        int subCounter=0;
        for(int j=0+offset;p[j]!='\0'&&j<i;j++){
            if(p[j]==s[i]){
                offset=j+1;
                break;
            }
            subCounter++;
        }
        if(subCounter>counter)counter = subCounter;
    }
    return counter+1;
}
int main(){
    char input[100];
    fgets(input,100,stdin);
    for(int i=0;i<100;i++){
        if(input[i]=='\n')input[i]='\0';
    }
    printf("%d",lengthOfLongestSubstring(input));
    return 0;
}
