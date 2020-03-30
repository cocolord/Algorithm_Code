#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int q[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);
    while (m--)
    {
        /* code */
        int x;
        scanf("%d",&x);
        int l = 0,r = n-1;
        while (l<r)
        {
            // mid 的选择对于选择左右的端点来说很重要
            int mid = l + r >> 1;
            //这里的判断条件很重要，如何划分左右两端的区间？
            if(q[mid] < x)
                l = mid + 1;
            else
                r = mid;
        }
        if(q[l]!=x)
            cout<<"-1 -1"<<endl;
        else
        {
            cout<< l <<' ';
            int l = 0,r = n - 1;
            while(l<r){
                int mid = l + r + 1 >> 1;
                //这里的判断条件很重要，如何划分左右两端的区间？
                if(q[mid]<=x)
                    l = mid ;
                else 
                    r =  mid  - 1;
            }
            cout<<l<<endl;
        }
        

    }
    
    return 0;
}

// 作者：yxc
// 链接：https://www.acwing.com/activity/content/code/content/39787/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
