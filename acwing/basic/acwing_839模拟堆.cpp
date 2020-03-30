#include<iostream>

using namespace std;

const int N=100010;

int h[N];
int cnt;
int idx;

int hp[N],ph[N];
//交换堆中
//a b位置的两个元素
void heap_swap(int a,int b){
    //先找到堆中a b 索引在原数组中的位置
    swap(ph[hp[a]],ph[hp[b]]);
    //交换a b 索引在原数组中的位置
    swap(hp[a],hp[b]);
    //交换 a b 索引在堆中的位置
    swap(h[a],h[b]);
}

void down(int u){
    int t=u;
    if(2*u<=cnt&&h[t]>h[2*u]) t=2*u;
    if(2*u+1<=cnt&&h[t]>h[2*u+1]) t=2*u+1;
    if(u!=t){
        heap_swap(u,t);
        down(t);
    }
}
//插入的时候往上up
void up(int u){
    while(u/2&&h[u]<h[u/2]){
        heap_swap(u,u/2);
        u/=2;
    }
}

int main(){
    int n;
    cin>>n;
    string op;
    while(n--){
        cin>>op;
        //插入
        //插入放到最后
        if(op=="I"){
            int x;
            cin>>x;
            h[++cnt]=x;
            
            hp[cnt]=++idx;
            ph[idx]=cnt;
            //最后up 上去
            up(cnt);
        }else if(op=="PM"){//输出当前堆的最小值
            cout<<h[1]<<endl;//最小堆,输出栈顶就好
        }else if(op=="DM"){//删除当前堆的最小值
            heap_swap(1,cnt);//把最小值放到最后
            cnt--;//删除最后值
            down(1);//把堆首down下去
        }else if(op=="D"){//删除第k个插入的数
            int k;
            cin>>k;
            k=ph[k];//找到第k个插入的数对应堆中的位置
            heap_swap(k,cnt);// 把堆中第k个元素换到最后
            cnt--;//删除最后一个
            //k现在不知道应该up还是down
            //换到合适的位置
            down(k);
            up(k);
        }else {//修改第k个插入的数为x 
            int k,x;
            cin>>k>>x;
            k=ph[k];
            h[k]=x;
            down(k);
            up(k);
        }
    }
    return 0;
}