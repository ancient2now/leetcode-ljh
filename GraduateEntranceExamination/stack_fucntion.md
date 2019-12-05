###
利用一个栈实现以下递归函数的非递归实现 

$$
P{_n}(X)=
\begin{cases}
1 & n=0\\
2X & n=1\\
2XP_{n-1}(X)-2(n-1)p_{n-2}(X)  & n>1
\end{cases}
$$
###
实现
```
double p(int n, double x){
    if(n==0)
        return 1;
    struct stack{
        int no;
        int val;
    }st[MaxSize];
    int to = -1;
    double fv1 = 1;
    double fv2 = 2*x;
    for(int i = n; i >=2; i--){
        top++;
        st[top].no = i;
    }
    while(top > 0){
        st[top].val = 2*x*fv2-2*(st[top].no-1)*fv1;
        fv1 = fv2;
        fv2 = st[top].val;
        top--;
    }
    return fv2;
}
```


