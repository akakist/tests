#include <vector>
#include <string>
#include <map>
class num6_13
{
    std::vector<int64_t> v;
public:
    num6_13()
    {
        v.resize(6);
        for(int i=0;i<6;i++)
        {
            v[i]=0;
        }
    }
    int64_t sum()
    {
        int r=0;
        for(auto& z: v)
        {
            r+=z;
        }
        return r;
    }
    std::string hex()
    {
        std::string buf;
        for(auto i=v.rbegin();i!=v.rend();i++)
        {
            char b[10];
            snprintf(b,sizeof (b),"%llx",*i);
            buf+=b;
        }
        return buf;
    }
    void inc()
    {
        for(int i=0;i<6;i++)
        {
            if(v[i]==12)
            {
                v[i]=0;
                continue;
            }
            else
            {
                v[i]++;
                break;
            }
        }
    }
};

int main(int argc, char *argv[])
{

    std::map<int64_t, int64_t> sums;

    int64_t maxnum=13*13*13*13*13*13;
    num6_13 n;
    for(int64_t i=0;i<maxnum;i++)
    {
        int sum=n.sum();
        if(sums.count(sum))
            sums[sum]++;
        else
            sums[sum]=1;
        n.inc();
    }

    int64_t total=0;
    for(auto & z: sums)
    {
        total+=(int64_t)z.second*z.second;
    }
    printf("total %lld\n",total);


    int64_t a=9203637295151;
    int64_t b=707972099627;
    return 0;
}
