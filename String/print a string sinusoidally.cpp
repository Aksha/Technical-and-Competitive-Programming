//Brute force question

void printStringSinusoidally(string s){
    
    int len = s.length();
    
    char wavedString[3][len];
    
    for(int i = 0; i < 3; i++)
    {
        for(int j=0; j<len; j++)
        {
            wavedString[i][j] = ' ';
        }
    }
    
    
    for(int i=2; i< len; i = i+4)
    {
       wavedString[0][i] = (s[i]==' ')?'~':s[i];
    }    
    for(int i=1; i<len; i = i+2)
    {
      wavedString[1][i] = (s[i] == ' ')?'~':s[i];  
    }
    for(int i=0; i<len; i=i+4)
    {
      wavedString[2][i] = (s[i] == ' ')?'~':s[i];    
    }
    
    string firstRow = "";
    string secondRow = "";
    string thirdRow = "";
    
    for(int i=0; i<len; i++)
    {
        firstRow += wavedString[0][i];
    }
    
    for(int i=0; i<len; i++)
    {
        secondRow += wavedString[1][i];
    }
    for(int i=0; i<sizeof(wavedString[2]); i++)
    {
        thirdRow += wavedString[2][i];
    }
    
    cout<<firstRow<<endl;
    cout<<secondRow<<endl;
    cout<<thirdRow<<endl;
    
}
