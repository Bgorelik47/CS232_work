char password[8] = "secret";
int main() {
    char input[8];
    int p;
    printf("please enter your password\n");
    scanf("%s", input);
    
    for(p = 0; p<=7; p++)
    {
        if(input[p] >= 65 && input[p] <= 90)
        {
            input[p] = input[p] + 32;
        } 
    }
    
    if(strcmp(input,password)==0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}