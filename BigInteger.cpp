#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct BigInteger {
    static const int BASE = 10000;
    static const int WIDTH = 4;//s每一个单元保存4位数
    vector<int> s;
    BigInteger operator = (const string& str);
    BigInteger operator = (int);
    BigInteger operator = (long long);
    BigInteger(long long num = 0) { *this = num; }
    BigInteger operator + (int);
    BigInteger operator - (const int);
    BigInteger operator * (const int);
    BigInteger operator / (const int);
    BigInteger operator + (const BigInteger);
    BigInteger operator - (const BigInteger);
    BigInteger operator * (const BigInteger);
    BigInteger operator / (const BigInteger);

    BigInteger operator = (const string& str) {
        s.clear();
        int x, len = (str.length() - 1)/WIDTH + 1;
        for(int i = 0; i < len; i++) {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end-start).c_str(),"%d",&x);
            s.push_back(x);
        }
        return *this;
    }
    BigInteger operator = (long long num) {
        s.clear();
        do {
            s.push_back(num % BASE);
            num/=BASE;
        } while(num > 0);
        return *this;
    }
    BigInteger operator = (int num){
        s.clear();
        do{
            s.push_back(num % BASE);
            num /= BASE;
        }while(num > 0);
        return *this;
    }
    BigInteger operator + (BigInteger num){
        
    }
    BigInteger operator + (int num) {
        BigInteger Num = num;
        return *this + Num;
    }
};
ostream& operator << (ostream &out, const BigInteger& x){
    out << x.s.back();
    for(int i = x.s.size()-2; i >= 0; i--){
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for(int j = 0; j < strlen(buf); j++) out << buf[j];
    }
    return out;
}
istream& operator >> (istream &in, BigInteger& x){
    string s;
    if(!(in >> s)) return in;
    x = s;
    return in;
} 
int main(){

}