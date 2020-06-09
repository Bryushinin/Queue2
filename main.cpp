#include "queue_header.h"


int main()
{
    double* mm=(double *)calloc(5,sizeof(double));
    cout<<" Enter loading and counting time"<<endl<<" Example: "<<endl;
    cout<<" Loading: from 0"<<endl<<" to 6";
    cout<<endl<<" Counting: from 0"<<endl<<" to 1 "<<endl;
    cout<<" Now you"<<endl<<" Loading: from ";
    cin>>mm[0];
    cout<<" to ";
    cin>>mm[1];
    cout<<" Counting: from ";
    cin>>mm[2];
    cout<<" to ";
    cin>>mm[3];

    double time1=0,time2=0,stoim=0,Max=0,Sum=0;
    int nom=0,k=0,l=0,kk=0,number=0,NomMax=0, count=0, pot=0, request;

    cout<<"Enter the number of requests: ";cin>>request;
    queue* Head=(queue*)malloc(sizeof(queue));
    Head->next=NULL;
    //Head->prev=NULL;
    Head->num=665;Head->prob=0.9;Head->tobr=0.0;Head->tprih=0.0;

    queue* Tail=(queue*)malloc(sizeof(queue));
    Tail->next=Head;
    Tail->prev=NULL;
    Tail->num=666;Tail->prob=0.9;Tail->tobr=0.0;Tail->tprih=0.0;
    Head->prev=Tail;

    //Print(Head,Tail);

    while(k<request)
    {
        //cout<<"Before while length H->p->n  "<<" "<<Head->prev->num<<" T->n->n "<<Tail->next->num<<endl;
        while(Length(&Head,&Tail,time2) /*&& (time2<time1)*/)
        {
            //cout<<"Before POP H->p->n  "<<" "<<Head->prev->num<<" T->n->n "<<Tail->next->num<<endl;
            double a;
            //cout<<endl<<"Before Pop: ";cout<<" k: "<<k<<endl; Print(Head,Tail);
            a=Pop(&Head,&Tail,/*&nom,*/ &k, &l,&time2,&number,&count);
            Sum+=a;
            if(a> Max)
                {
                    Max=a;
                    NomMax=number;
                }
            //cout<<endl<<"After Pop: ";cout<<" k: "<<k<<endl;
            //Print(Head,Tail);
            if(!(k%100) && (kk!=k))
                {cout<<"Length: "<<count/*Length(&Head,&Tail)*/<<" Released: "<<k <<" Done: "<<k+l <<" time: "<<time2<<endl;kk=k;}
        }
        if(!(Length(&Head, &Tail,time2))  && (Head->prev->prishla >time2))
            {
                stoim+=(Head->prev->prishla - time2);
                time2=Head->prev->prishla;

            }
        //cout<<"hpp: "<<Head->prev->prishla<<endl;
        //cout<<"time2: "<<time2<<endl;
        //cout<<endl<<"Before Add: ";cout<<" k: "<<k<<endl; Print(Head,Tail);
        while(time1<time2 && (pot<request))
            {Add(&Tail,&nom,&time1,&count,mm);++pot;}
        //cout<<endl<<"After Add: ";cout<<" k: "<<k<<endl; Print(Head,Tail);
        //cout<<"time1: "<<time1<<endl;
        //Print(Head,Tail);

        //time1+= Tail->next->tprih;
    }

    /*cout<<"time1: "<<time1<<endl;
    cout<<"time2: "<<time2<<endl;
    Print(Head, Tail);*/
    cout<<" Downtime: "<<stoim<<endl<<" Max waiting time: "<<Max<<" request number: "<< NomMax<<endl<<" Average waiting time: "<< Sum/k;
    free(mm);
    free(Head);
    free(Tail);
    return 0;
}
