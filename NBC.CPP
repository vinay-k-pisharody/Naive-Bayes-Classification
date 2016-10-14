#include<conio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,p,max=0;
    cout<<"\nEnter number of training values : ";
    cin>>n;
    cout<<"\nEnter number of parameters : ";
    cin>>p;
    string name[p];
    int pcount[p];
    string pname[p][p];
    for(int i=0;i<p;i++)
    {
        int temp;
        cout<<"\nEnter parameter name : ";
        cin>>name[i];
        //cout<<name[i];
        cout<<"\nEnter number of values : ";
        cin>>temp;
        if(temp>max)
        {
            max=temp;
        }
        pcount[i]=temp;
        //cout<<pcount[i];
        for(int j=0;j<temp;j++)
        {
            cout<<"\nEnter value for "<<j+1<<" : ";
            cin>>pname[i][j];
        }
    }
    cout<<"\n";
    /*for(int i=0;i<p;i++)
    {
        cout<<name[i]<<"\t";
    }
    getch();*/
    /*for(int i=0;i<p;i++)
    {
        for(int j=0;j<pcount[i];j++)
        {
            cout<<pname[i][j]<<"\t";
        }
        cout<<"\n";
    }
    getch();*/
    //cout<<"\nArrays Template Initialised";
    int db[n][p];
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter value "<<i+1;
        for(int j=0;j<p;j++)
        {
            cout<<"\nEnter value for "<<name[j]<<" : ";
            cin>>db[i][j];
        }
    }
    cout<<"\nValues Entered\n";

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            cout<<db[i][j]<<"\t";
        }
        cout<<endl;
    }*/

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            int temp=db[i][j]-1;
            cout<<pname[j][temp]<<"\t\t";
        }
        cout<<"\n";
    }
    int cp;
    cout<<"\nSelect the parameter : ";
    for(int i=0;i<p;i++)
    {
        cout<<"\nEnter "<<i+1<<" for "<<name[i];
    }
    cin>>cp;
    cp--;
    cout<<"\nParameter for Classifying : "<<name[cp];
    cout<<"\nNumber of values in "<<name[cp]<<" : "<<pcount[cp];
    int d=pcount[cp];//no of divisions
    float spp[d];//selected parameter probability
    float ans[d];
    for(int i=0;i<d;i++)
    {
        spp[i]=0;
        ans[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        //cout<<"cp : "<<cp;
        int index=db[i][cp];
        //cout<<"\nIndex : "<<index;
        index--;
        spp[index]=spp[index]+1;
        //cout<<"spp[index] : "<<spp[index];
    }
    float scp[d];
    cout<<"\nProbability of selected parameter for classifying : ";
    for(int i=0;i<d;i++)
    {
        cout<<"\n"<<spp[i];
        scp[i]=(float)spp[i]/n;
        cout<<"\n"<<scp[i];
    }
    cout<<"\nProbability for the rest of db : \n";
    float probabilities[p-1][d][max];
    for(int i=0;i<p-1;i++)
    {
        for(int j=0;j<d;j++)
        {
            for(int k=0;k<max;k++)
            {
                probabilities[i][j][k]=0;
            }
        }
    }
    for(int i=0;i<p-1;i++)
    {
        for(int num=0;num<n;num++)
        {
            int temp=db[num][i];
            temp--;
            int temp1=db[num][cp];
            temp1--;
            probabilities[i][temp1][temp]+=1;
        }
    }

    //Used to display count
    /*cout<<"\nCounts ";
    for(int i=0;i<p-1;i++)
    {
        cout<<"\nFor "<<name[i];
        for(int j=0;j<d;j++)
        {
            //cout<<"\n\nFor "<<pname[cp][j];
            for(int k=0;k<pcount[i];k++)
            {
                cout<<"\nP("<<pname[i][k]<<"|"<<pname[cp][j]<<") : "<<probabilities[i][j][k];
            }
            cout<<"\n";
        }
        cout<<"\n";
    }*/

    for(int i=0;i<p-1;i++)
    {
        //cout<<"\nFor "<<name[i];
        for(int j=0;j<d;j++)
        {
            //cout<<"\n\nFor "<<pname[cp][j];
            for(int k=0;k<pcount[i];k++)
            {
                probabilities[i][j][k]=probabilities[i][j][k]/spp[j];
                //cout<<"\nP("<<pname[i][k]<<"|"<<pname[cp][j]<<") : "<<probabilities[i][j][k];
            }
            //cout<<"\n";
        }
        //cout<<"\n";
    }

    for(int i=0;i<p-1;i++)
    {
        cout<<"\nFor "<<name[i];
        for(int j=0;j<d;j++)
        {
            //cout<<"\n\nFor "<<pname[cp][j];
            for(int k=0;k<pcount[i];k++)
            {
                cout<<"\nP("<<pname[i][k]<<"|"<<pname[cp][j]<<") : "<<probabilities[i][j][k];
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    int tupple[p-1];
    cout<<"\nEnter the test tuple : ";
    for(int i=0;i<p-1;i++)
    {
        cout<<"\nEnter for "<<name[i];
        for(int j=0;j<pcount[i];j++)
        {
            cout<<"\n"<<j+1<<" for "<<pname[i][j];
        }
        cin>>tupple[i];
        tupple[i]--;
    }
    cout<<"\nSelected Tuple is : "<<endl;
    for(int i=0;i<p-1;i++)
    {
        cout<<pname[i][tupple[i]]<<"\t";
    }
    //cout<<"\nTuple selected properly";
    cout<<"\n";
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<p-1;j++)
        {
            //cout<<"\n"<<tupple[j];
            //cout<<"\n"<<ans[i]*probabilities[j][i][tupple[j]];
            ans[i]=(float)(ans[i]*probabilities[j][i][tupple[j]]);
        }
        ans[i]=(float)(ans[i]*scp[i]);
        cout<<"\nP(X|"<<pname[cp][i]<<") = "<<ans[i];
    }
    int min=0;
    int ansi;
    for(int i=0;i<d;i++)
    {
        if(ans[i]>min)
        {
            min=ans[i];
            ansi=i;
        }
    }
    cout<<"\n\nHence, the given tuple will be classified as "<<pname[cp][ansi]<<" for the class "<<name[cp]<<endl;
    return 0;
}
