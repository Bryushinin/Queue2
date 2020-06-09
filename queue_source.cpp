#include "queue_header.h"
double Trand(double a, double b)
{
    return(a+(b-a)*((double)rand()/RAND_MAX));
}

void Print(queue* Head, queue* Tail)
{
    queue* T=Tail;cout<<endl/*<<T->num*/<<" ";
    while(T!=Head)
    {
        T=T->next;
        if(T->num != 665) cout<<"( No "<<T->num<<" Tprih "<<T->tprih<<" Prishla "<<T->prishla<<" Obr "<<T->tobr<<" ) ";
    }
    cout<<"Printed"<<endl;
}

void Add(queue** Tail, int* nom, double* time, int* count, double* mm)
{
    ++(*nom);
    ++(*count);
    queue* A=(queue*)malloc(sizeof(queue));
    A->next=(*Tail)->next;
    A->num=*nom;
    A->waiting=0;
    A->prev=(*Tail);
    A->prob=Trand(0,1);
    A->tobr=Trand(mm[2],mm[3]);
    A->tprih=Trand(mm[0],mm[1]);
    A->prishla = *time + A->tprih;
    *time=A->prishla;
    ((*Tail)->next)->prev=A;
    (*Tail)->next=A;
    //cout<<endl<<"Add "<<(*Tail)->next->num<<" "<<(*Tail)->next->next->num<<endl;
}

int Length(queue** Head, queue** Tail)
{
    if((*Head)==((*Tail)->next))
        return(0);
    //queue* Temp=(queue*)malloc(sizeof(queue));
    int i=0;
    queue* Temp=(*Tail)->next;
    while(Temp!=(*Head))
    {
            ++i;
        Temp=Temp->next;
    }
    //cout<<"Length: "<<i<<endl;
    return(i);
}

int Length(queue** Head, queue** Tail, double time)
{
    if((*Head)==((*Tail)->next))
        return(0);
    //queue* Temp=(queue*)malloc(sizeof(queue));
    int i=0;
    queue* Temp=(*Tail)->next;
    while(Temp!=(*Head))
    {
        if(Temp->prishla <= time)
            ++i;
        Temp=Temp->next;
    }
    //cout<<"Length: "<<i<<endl;
    return(i);
}




double Pop(queue** Head, queue** Tail,/*int* nom,*/ int* k, int* l, double* time, int* number, int* count/*, const double* mm*/)
{
    queue* Temp=(*Head)->prev;//cout<<endl<<"POP H->pr->num: "<<(*Head)->prev->num<<endl;

    while((Temp->prishla)> *time  && (Temp!=*Tail))
        Temp=Temp->prev;

    if( !Length(Head,Tail,*time) || (Temp==*Tail))
    {
        cout<<"Trouble"<<endl;
        return(0);
    }

    double a=Temp->tobr;//cout<<a<<" H->p->tobr: "<<(*Head)->prev->tobr<<" num: "<<(*Head)->prev->num;
    (Temp->prev)->next=(Temp->next);
    (Temp->next)->prev=Temp->prev;
    *time+=a;
    --(*count);
    //cout<<"   POPPING :   "<<Temp->num<<"   ITS PROB :  "<<Temp->prob;
    if(Temp->prob <0.8)
    {
        //++(*nom);
        ++(*count);
        queue* A=(queue*)malloc(sizeof(queue));
        A->next=((*Tail)->next);
        A->prev=(*Tail);

        ((*Tail)->next)->prev=A;
        (*Tail)->next=A;

        A->num=Temp->num;
        A->waiting=Temp->waiting + *time - a - Temp->prishla;

        A->tprih=Temp->tprih;
        A->prob=Trand(0,1);
        A->tobr=a;
        //A->tprih=Temp->tprih;
        A->prishla=*time;
        ++(*l);
        //Print(*Head,*Tail);
            free(Temp);
            *number=0;
            return (0);
    }
    a=Temp->waiting;
    ++(*k);
    *number=Temp->num;
    //cout<<"   POPPING :   "<<*number;
    free(Temp);
    //cout<<Length(Head,Tail)<<"|"<<a<<endl;
    //Print(*Head,*Tail);
    return(a);
}

