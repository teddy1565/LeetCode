#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Given a string s, find the length of the longest substring without repeating characters.
int lengthOfLongestSubstring(char *s){
    
    return 1;
}
int main(){
    int strleng=0;
    scanf("%d",&strleng);
    char *input;
    input = malloc(sizeof(char)*(strleng+1));
    fgets(input,strleng,stdin);
    printf("%d",lengthOfLongestSubstring(input));
    return 0;
}
