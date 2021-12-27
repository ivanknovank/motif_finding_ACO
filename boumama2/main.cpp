#include <bits/stdc++.h>

using namespace std;

int T=1000;
int n,d,l;
const double P=0.03;
const int beta=1,alpha=1;
const double Tmax=1;
int Count;
double Tmin;
long long NA[5],NC[5],NG[5],NT[5],N[5];
double TT[10000][5];
long long pA[10000][5],pC[10000][5],pG[10000][5],pT[10000][5];
double TA[10000][5],TC[10000][5],TG[10000][5];
string s,str[100];
int num=0;
int ress=0;

int minn=INT_MAX;
string ss;
struct st
{
    double score;
    string strr;
};
st ssave[10000];
bool cmp(st h,st k)
{
    return (h.score>k.score);
}
void profile()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<str[i].size(); j++)
        {
            if(str[i][j-1]=='A')
            {
                N[1]++;
                if(str[i][j]=='A')
                    NA[1]++;
                if(str[i][j]=='C')
                    NA[2]++;
                if(str[i][j]=='G')
                    NA[3]++;
                if(str[i][j]=='T')
                    NA[4]++;
            }
            if(str[i][j-1]=='C')
            {
                N[2]++;
                if(str[i][j]=='A')
                    NC[1]++;
                if(str[i][j]=='C')
                    NC[2]++;
                if(str[i][j]=='G')
                    NC[3]++;
                if(str[i][j]=='T')
                    NC[4]++;
            }
            if(str[i][j-1]=='G')
            {
                N[3]++;
                if(str[i][j]=='A')
                    NG[1]++;
                if(str[i][j]=='C')
                    NG[2]++;
                if(str[i][j]=='G')
                    NG[3]++;
                if(str[i][j]=='T')
                    NG[4]++;
            }
            if(str[i][j-1]=='T')
            {
                N[4]++;
                if(str[i][j]=='A')
                    NT[1]++;
                if(str[i][j]=='C')
                    NT[2]++;
                if(str[i][j]=='G')
                    NT[3]++;
                if(str[i][j]=='T')
                    NT[4]++;
            }
        }
    for(int i=0; i<=d; i++)
    {
        for(int j=1; j<=4; j++)
        {
            if(i!=0)
            {
                pA[i][j]=pow(NA[j],beta)+1;
                pC[i][j]=pow(NC[j],beta)+1;
                pG[i][j]=pow(NG[j],beta)+1;
                pT[i][j]=pow(NT[j],beta)+1;
                TA[i][j]=(Tmax+Tmin)/2;
                TC[i][j]=(Tmax+Tmin)/2;
                TG[i][j]=(Tmax+Tmin)/2;
                TT[i][j]=(Tmax+Tmin)/2;
            }
            else
            {
                pA[i][j]=1;
                pC[i][j]=1;
                pG[i][j]=1;
                pT[i][j]=1;
                TA[i][j]=(1+1/4)/2;
                TC[i][j]=(1+1/4)/2;
                TG[i][j]=(1+1/4)/2;
                TT[i][j]=(1+1/4)/2;
            }
        }
    }
}
int check(string a,string b)
{
    int num=0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]!=b[i])
            num++;
    }
    return num;
}
void min_dif_string(string a,string b,int length)
{
    for(int i=0; i<=a.size()-length; i++)
    {
        if(minn>check(a.substr(i,length),b))
        {
            ss=a.substr(i,length);
            minn=check(a.substr(i,length),b);
        }
    }
}
void consensus_score()
{
    while(T--)
    {
        minn=INT_MAX;
        //1=A,2=C,3=G,4=T
        string save[100];
        string s;
        int ssum=N[1]+N[2]+N[3]+N[4];
        int a=rand()%ssum+1;
        if(a>=1&&a<=N[1])
            s.push_back('A');
        if(a>N[1]&&a<=N[1]+N[2])
            s.push_back('C');
        if(a>N[1]+N[2]&&a<=N[1]+N[2]+N[3])
            s.push_back('G');
        if(a>N[1]+N[2]+N[3]&&a<=ssum)
            s.push_back('T');
        for(int i=1; i<d; i++)
        {
            if(s[s.size()-1]=='A')
            {
                int sum=pA[i][1]+pA[i][2]+pA[i][3]+pA[i][4];
                a=rand()%sum+1;
                if(a>=1&&a<=pA[i][1])
                    s.push_back('A');
                if(a>pA[i][1]&&a<=pA[i][1]+pA[i][2])
                    s.push_back('C');
                if(a>pA[i][1]+pA[i][2]&&a<=pA[i][1]+pA[i][2]+pA[i][3])
                    s.push_back('G');
                if(a>pA[i][1]+pA[i][2]+pA[i][3]&&a<=sum)
                    s.push_back('T');
            }
            else
            {
                if(s[s.size()-1]=='C')
                {
                    int sum=pC[i][1]+pC[i][2]+pC[i][3]+pC[i][4];
                    a=rand()%sum+1;
                    if(a>=1&&a<=pC[i][1])
                        s.push_back('A');
                    if(a>pC[i][1]&&a<=pC[i][1]+pC[i][2])
                        s.push_back('C');
                    if(a>pC[i][1]+pC[i][2]&&a<=pC[i][1]+pC[i][2]+pC[i][3])
                        s.push_back('G');
                    if(a>pC[i][1]+pC[i][2]+pC[i][3]&&a<=sum)
                        s.push_back('T');
                }
                else
                {
                    if(s[s.size()-1]=='G')
                    {
                        int sum=pG[i][1]+pG[i][2]+pG[i][3]+pG[i][4];
                        a=rand()%sum+1;
                        if(a>=1&&a<=pG[i][1])
                            s.push_back('A');
                        if(a>pG[i][1]&&a<=pG[i][1]+pG[i][2])
                            s.push_back('C');
                        if(a>pG[i][1]+pG[i][2]&&a<=pG[i][1]+pG[i][2]+pG[i][3])
                            s.push_back('G');
                        if(a>pG[i][1]+pG[i][2]+pG[i][3]&&a<=sum)
                            s.push_back('T');
                    }
                    else
                    {

                        if(s[s.size()-1]=='T')
                        {
                            int sum=pT[i][1]+pT[i][2]+pT[i][3]+pT[i][4];
                            a=rand()%sum+1;
                            if(a>=1&&a<=pT[i][1])
                                s.push_back('A');
                            if(a>pT[i][1]&&a<=pT[i][1]+pT[i][2])
                                s.push_back('C');
                            if(a>pT[i][1]+pT[i][2]&&a<=pT[i][1]+pT[i][2]+pT[i][3])
                                s.push_back('G');
                            if(a>pT[i][1]+pT[i][2]+pT[i][3]&&a<=sum)
                                s.push_back('T');
                        }
                    }
                }
            }
        }
        double maxx=INT_MIN;
        int re=0;
        for(int j=1; j<=n; j++)
        {
            min_dif_string(str[j],s,d);
            if(minn<=l)
            {
                re++;
                save[re]=ss;
            }
            if(j==n&&re<n)
            {
                for(int i=0; i<d; i++)
                {
                    int sa;
                    if(s[i]=='A')
                        sa=1;
                    if(s[i]=='C')
                        sa=2;
                    if(s[i]=='T')
                        sa=3;
                    if(s[i]=='G')
                        sa=4;
                    if(s[i-1]=='T')
                    {
                        TT[i][sa]=(1-P)*TT[i][sa]+P*Tmin;
                        pT[i][j]=pow(TT[i][sa],alpha)*pow(NT[j],beta);
                    }
                    if(s[i-1]=='A')
                    {
                        TA[i][sa]=(1-P)*TA[i][sa]+P*Tmin;
                        pA[i][j]=pow(TA[i][sa],alpha)*pow(NA[sa],beta);
                    }
                    if(s[i-1]=='C')
                    {
                        TC[i][sa]=(1-P)*TC[i][sa]+P*Tmin;
                        pC[i][j]=pow(TC[i][sa],alpha)*pow(NC[j],beta);
                    }
                    if(s[i-1]=='G')
                    {
                        TG[i][sa]=(1-P)*TG[i][sa]+P*Tmin;
                        pG[i][j]=pow(TG[i][sa],alpha)*pow(NG[j],beta);
                    }

                }
            }
            if(re==n)
            {
                num++;
                double AA[1000],CC[1000],GG[1000],TTT[1000];

                for(int j=0; j<d; j++)
                {
                    for(int i=1; i<=d; i++)
                    {
                        AA[j]=0;
                        CC[j]=0;
                        GG[j]=0;
                        TTT[j]=0;
                    }
                    double maxxx=-0.5;
                    for(int i=1; i<=n; i++)
                    {
                        if(save[i][j]=='A')
                            AA[j]++;
                        if(save[i][j]=='T')
                            CC[j]++;
                        if(save[i][j]=='G')
                            GG[j]++;
                        if(save[i][j]=='T')
                            TTT[j]++;
                    }

                    maxxx=max(maxx,max(AA[j],max(CC[j],max(GG[j],TTT[j]))));
                    if(AA[j]==maxxx)
                    {
                        ssave[num].score+=(double)AA[j];
                        ssave[num].strr.push_back('A');
                    }
                    else
                    {
                        if(CC[j]==maxxx)
                        {
                            ssave[num].score+=(double)CC[j];
                            ssave[num].strr.push_back('C');
                        }
                        else
                        {
                            if(GG[j]==maxxx)
                            {
                                ssave[num].score+=(double)GG[j];
                                ssave[num].strr.push_back('G');
                            }
                            else
                            {
                                if(TTT[j]==maxxx)
                                {
                                    ssave[num].score+=(double)TTT[j];
                                    ssave[num].strr.push_back('T');
                                }
                            }
                        }
                    }
                }
                //cout <<num<<" "<<ssave[num].score<<endl;
                for(int i=0; i<d; i++)
                {
                    int sa;
                    if(s[i]=='A')
                        sa=1;
                    if(s[i]=='C')
                        sa=2;
                    if(s[i]=='T')
                        sa=3;
                    if(s[i]=='G')
                        sa=4;
                    if(s[i-1]=='A')
                    {
                        TA[i][sa]=(1-P)*TA[i][sa]+P*Tmax;
                        pA[i][j]=pow(TA[i][sa],alpha)*pow(NA[sa],beta);
                    }
                    if(s[i-1]=='C')
                    {
                        TC[i][sa]=(1-P)*TC[i][sa]+P*Tmax;
                        pC[i][j]=pow(TC[i][sa],alpha)*pow(NC[j],beta);
                    }
                    if(s[i-1]=='G')
                    {
                        TG[i][sa]=(1-P)*TG[i][sa]+P*Tmax;
                        pG[i][j]=pow(TG[i][sa],alpha)*pow(NG[j],beta);
                    }
                    if(s[i-1]=='T')
                    {
                        TT[i][sa]=(1-P)*TT[i][sa]+P*Tmax;
                        pT[i][j]=pow(TT[i][sa],alpha)*pow(NT[j],beta);
                    }
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("inp3.inp","r",stdin);
    //freopen("out.inp","w",stdout);
    srand(time(0));
    cin >>n>>d>>l;

    Tmin=1/(16*d-16);
    for(int i=1; i<=n; i++)
    {
        cin >>str[i];
    }
    profile();
    consensus_score();
    sort(ssave+1,ssave+num+1,cmp);
    Count = ssave[1].score-2;
    for(int i=1; i<=num; i++)
    {
        if(ssave[i].score==Count)
            break;
        cout <<ssave[i].score<<" "<<ssave[i].strr<<endl;
    }
}
