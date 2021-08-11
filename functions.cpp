#include<bits/stdc++.h>
using namespace std;

class functions{
    public:
    //// 2021-07-30 ////
    int a;
    functions(int a){
        this->a = a;
    }
    functions(){
        a = 0;
    }
    int lcm(int a, int b){
        int higher = max(a,b);
        while(!(higher%a == 0 && higher%b == 0)) higher ++;
        return higher;
    }
    int lcm_mult(int a, int b){
        int higher = max(a,b), i = 1, lower = min(a,b);
        while((higher*i)%lower != 0) i++;
        return higher*i;
    }
    int hcf(int a, int b){
        int ans = 1, i = 1;
        while(i<=min(a,b)){
            if(a%i==0 && b%i==0) ans = i;
            i++;
        }
        return ans;
    }
    int sum_of_factors(int a){
        int ans = 0, i = 1;
        while(i<=a){
            if(a%i==0) ans += i;
            i++;
        }
        return ans;
    }
    int factorial(int a){
        if(a==1) return a;
        else return (a*factorial(a-1));
    }
    bool ispalindrome(string s, int l){
        string temp;
        for(auto i=l-1;i>=0;i--) temp.push_back(s[i]);
        if(strcmp(s.c_str(),temp.c_str())==0) return true;
        return false;
    }
    bool isleapyr(int a){
        return ((a%100 != 0 && a%4 ==0) || (a%100 == 0 && a%400 == 0));
    }
    bool isleapyr1(functions* f){
        int a = f->a;
        return ((a%100 != 0 && a%4 ==0) || (a%100 == 0 && a%400 == 0));
    }
    int nextleapyear(){
        this->a++;
        while(!isleapyr1(this)) this->a++;
        return this->a;
    }

    //// 2021-07-31 ////
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    

    public:
    void fibonacci(int n){
        int a = 0, b = 1, c;
        if(n==0) return;
        else if(n==1) cout<<a;
        else{
            cout<<a<<" "<<b<<" ";
            while(n>0){
                c = a+b; a = b; b = c;
                cout<<c<<" ";
                n--;
            }
        }
    }
    void print_arr(int a[], int n){
        for(int i = 0; i < n; i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
    int quick_sort(int a[], int low, int high){
        static int count = 0;
        if(low<high){
            int pivot = a[high-1];
            int i = low, j = low;
            while(j<high-1){
                if(pivot>a[j]) swap(a[i++], a[j]);
                j++; count++;
            }
            int c;
            swap(a[i], a[high-1]);
            c = quick_sort(a, low, i);
            c = quick_sort(a, i+1, high);
        }
        else{
            return count;
        }
        return count;
    }
};

bool binary_search(int a[], int low, int high, int n){
    if(low>high) return false;
    int mid = (low+high)/2;
    if(a[mid] == n) return true;
    else if(a[mid]>n) return binary_search(a, low, mid, n);
    else return binary_search(a, mid+1, high, n);

}

void string_palindrome()
{
    string s,v,m;
    string temp;
    int i,l,j=0;
    cout<<"Enter any string: ";
    cin>>s;
    l=s.size();

    for(auto i=l-1;i>=0;i--)
    {
        temp.push_back(s[i]);
        j++;
    }
    
    cout<<"\n"<<temp;
    if(strcmp(s.c_str(),temp.c_str())==0)
    {
        cout<<"\npalindrome";
    }
}

//// Convert any base to decimal
int value_in_deci(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
 
int toDeci(char *str, int base)
{
    int len = strlen(str);
    int power = 1; // Initialize power of base
    int num = 0;  // Initialize result
    int i;

    for (i = len - 1; i >= 0; i--)
    {
        if (value_in_deci(str[i]) >= base)
        {
           printf("Invalid Number");
           return -1;
        }
        num += value_in_deci(str[i]) * power;
        power = power * base;
    }
 
    return num;
}

//// Convert Decimal to base
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
 
// Utility function to reverse a string
void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}
 
char* fromDeci(char res[], int base, int inputNum)
{
    int index = 0;
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';
    strev(res);
    return res;
}

int main()
{
    int inputNum = 282, base = 16;
    char res[100];
    printf("Equivalent of %d in base %d is "
           " %s\n", inputNum, base, fromDeci(res, base, inputNum));
    return 0;
}

int main_todeci()
{
    char str[] = "11A";
    int base = 16;
    printf("Decimal equivalent of %s in base %d is "
           " %d\n", str, base, toDeci(str, base));
    return 0;
}


int main3(){
    int a = 5, b = 60, year = 4001;
    string s = "Hello olleH";

    functions fn, gn(5);
    fn.a = 2000;

    // cout<<"LCM of "<<a<<" and "<<b<<" = "<<fn.lcm(a,b)<<endl;
    cout<<"LCM of "<<a<<" and "<<b<<" = "<<fn.lcm_mult(a,b)<<endl;
    cout<<"HCF of "<<a<<" and "<<b<<" = "<<fn.hcf(a,b)<<endl;
    cout<<"Sum of factors of "<<a<<" = "<<fn.sum_of_factors(a)<<endl;
    cout<<"Factorial of "<<a<<" = "<<fn.factorial(a)<<endl;
    (fn.ispalindrome(s, s.size()))? cout<<s<<" is a palindrome"<<endl:cout<<s<<" is not a palindrome"<<endl;
    (fn.isleapyr(year))? cout<<year<<" is a leap year"<<endl:cout<<year<<" is not a leap year"<<endl;
    cout<<"Next leap year of "<<fn.a<<" : "<<fn.nextleapyear()<<endl;
    unsigned char p; p = -1;
    printf("%d", p);
    // printf(strlen("hello"));
    return 0;
}

int main_2(){
    functions s1;
    int a[20] = {9, 23, 78, 10, 5, 45, 105, 23, 29, 0, 9, 25, 49, 123, 85, 5, 15, 999, 31, 4}, n = 20;
    // s1.fibonacci(n);
    s1.print_arr(a, n);
    int c = s1.quick_sort(a, 0, n);
    s1.print_arr(a, n);
    cout<<"Number of steps: "<<c;
    return 0;
}

int main_binary_search(){
    int a[5] = {10,20,30,40,50};
    int n, len = 5;
    cout<<"Enter number: ";
    cin>>n;
    bool ans = binary_search(a, 0, len - 1, n);
    if(ans) cout<<"Found.";
    else cout<<"Not found.";
    return 0;
}
