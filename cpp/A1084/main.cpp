// Source : http://www.tsinsen.com/A1084
// Author : Modnar
// Date   : 2019-04-08

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#define LOCAL

// Note:
//   Because of the Tsinsen doesn't provide service now, I can not submit my code
//   to the online judge. Therefore, I can only get the source code from other
//   place. 
//
// Code source:
//   https://www.cnblogs.com/hoskey/p/4377054.html

const double Pi = acos(-1.0);
const int MAXN = 200000 + 10;
using namespace std;
typedef long long ll;
struct Num {
   double a , b;
    //构造函数
   Num(double x = 0,double y = 0) {a = x; b = y;}
    //复数的三种运算
   Num operator + (const Num &c) {return Num(a + c.a, b + c.b);}
   Num operator - (const Num &c) {return Num(a - c.a, b - c.b);}
   Num operator * (const Num &c) {return Num(a * c.a - b * c.b, a * c.b + b * c.a);}
}x1[MAXN] , x2[MAXN];

//注意loglen为log后的长度
void change(Num *t, int len, int loglen){
    //蝶形变换后的序列编号
    for (int i = 0; i < len; i++){
        int x = i, k = 0;
        for (int j = 0; j < loglen; j++, x >>= 1) k = (k << 1) | (x & 1);
        if (k < i) swap(t[k], t[i]);
    }
}
//基2-FFT
void FFT(Num *x, int len, int loglen){
    change(x, len, loglen);
    int t = 1;
    //t为长度
    for (int i = 0; i < loglen; i++, (t <<= 1)){
        int l = 0, r = l + t;
        while (l < len){
            //初始化
            Num a, b, wo(cos(Pi / t), sin(Pi / t)), wn(1, 0);
            for (int j = l; j < l + t; j++){
                a = x[j];
                b = x[j + t] * wn;
                //蝶形计算
                x[j] = a + b;
                x[j + t] = a - b;
                wn = wn * wo;
            }
            //注意是合并所以要走2t步
            l = r + t;
            r = l + t;
        }
    }
}
//离散傅里叶变换
void DFT(Num *x, int len, int loglen){
    int t = (1<<loglen);
    for (int i = 0; i < loglen; i++){
        t >>= 1;
        int l = 0, r = l + t;
        while (l < len){
            Num a, b, wn(1, 0), wo(cos(Pi / t), -sin(Pi / t));
            for (int j = l; j < l + t; j++){
                a = x[j] + x[j + t];
                b = (x[j] - x[j + t]) * wn;
                x[j] = a;
                x[j + t] = b;
                wn = wn * wo;
            }
            l = r + t;
            r = l + t;
        }    
    }
    change(x, len, loglen);
    for (int i= 0; i < len; i++) x[i].a /= len;
}
int solve(char *a, char *b){
    int len1, len2, len, loglen;
    int t, over;
    len1 = strlen(a) << 1;
    len2 = strlen(b) << 1;
    len = 1;
    loglen = 0;
    while (len < len1) len <<= 1, loglen++;
    while (len < len2) len <<= 1, loglen++;
    //处理len1
    for (int i = 0; i < len; i++){
        if (a[i]) x1[i].a = a[i] - '0', x1[i].b = 0;
        else x1[i].a = x1[i].b = 0;
    }
    for (int i = 0; i < len; i++){
        if (b[i]) x2[i].a = b[i] - '0', x2[i].b = 0;
        else x2[i].a = x2[i].b = 0;
    }
    FFT(x1, len, loglen);
    FFT(x2, len, loglen);
    for (int i = 0; i < len; i++) x1[i] = x1[i] * x2[i];

    DFT(x1, len, loglen);
    over = len = 0;
    //转换成十进制的整数
    for (int i = ((len1 + len2) / 2) - 2; i >= 0; i--){
        t = (int)((double)x1[i].a + (double)over + 0.5);
        a[len++] = t % 10;
        over = t / 10;
    }
    while (over){
        a[len++] = over % 10;
        over /= 10;
    }
    return len;
}
//输出
void print(char *str, int len){
     for(len--; len>=0 && !str[len];len--);
    if(len < 0) putchar('0');
    else for(;len>=0;len--) putchar(str[len]+'0');
    printf("\n");
}
char a[MAXN] , b[MAXN];

int main() {
    int n;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lf%lf", &x1[i].a, &x1[i].b);
    int t = 0;
    while ((1<<t) < n) t++;
    FFT(x1, n, t);
    for (int i = 0; i < n; i++) printf("%.2lf %.2lf\n", x1[i].a / n, x1[i].b / n);
   return 0;
}
