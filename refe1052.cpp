#include <stdio.h>
#include <malloc.h>
 
typedef struct student {
    double    number;
    double    gread;
 
    struct student * next;
}*node, Node;                   //���
 
node creat( int n );         //����������
 
void output( node l );        //�������
 
void order( node l1, node l2 );   //������
 
 
int main()
{
    int    n, m;            //a ��b
    node    head1, head2;   //���������ͷ���
 
    scanf( "%d%d", &n, &m );  
 
    head1    = creat( n );   //��������a
    head2    = creat( m );   //��������b
 
    order( head1, head2 );   //����
  
    return(0);
}
/*-------------------------------------------------------------*/
 
node creat( int n )
{
    node h;         //ͷ���ָ��
    h    = (node) malloc( sizeof(Node) );   //����ͷ���
    h->next = NULL;                         //nextָ���򸳿�
    node    q = h;                         //����ָ��q��ָ��ͷ���
    node    p;                             
 
    for ( int i = 0; i < n; i++ )       //����n�����
    {
        p = (node) malloc( sizeof(Node) );   
        scanf( "%lf%lf", &(*p).number, &(*p).gread );  //����ѧ�ţ��ɼ�
 
        p->next = q->next;           //���ú�����ڵ�
        q->next = p;
        q    = p;
    }
 
    return(h);   //����ͷ���
}
/*-------------------------------------------------------------*/
 
void output( node l )      //�������ÿ��������Ϣ
{
    l = l->next;
    node q; //�����ͷŽ��
    while ( l != NULL )
    {
        printf( "%.0f %0.f\n", l->number, l->gread );
        q=l;
        l = l->next;
        free(q);  //�ͷŽ��
    }
}
 
/*-------------------------------------------------------------*/
void order( node l1, node l2 )   //����
{
    node q;           //����ָ��q
    q    = l1;           //qָ���a��ͷ���
    l2    = l2->next;        //��b��ͷ�������
 
    while ( q->next != NULL )    //��qָ���a�����һ�����
    {
        q = q->next;
    }
    q->next = l2;          //��a�����һ������nextָ���b�ģ��׽�㣩�������
 
    q = l1->next;     //�ٴΰ�qָ���a��ͷ���
 
    node min;       //����ָ����Сѧ�Ž���ָ��
 
  
    int    t;      //������Сѧ�ŵı���
    int    n, g;   //����ѧ�ţ��ɼ����м����
    node    p;     //����ָ��p�������м��������Сѧ��
 
    while ( q != NULL )  //��ʼ������ѡ�����������
    {
        p = q;         //p���ڲ��ҵĵ�һ�����q
 
        t    = p->number;     //��t���ڿ�ʼ���ҵĵ�һ������ѧ��
        min    = p;           //��Сѧ�Ž��ָ��ָ��p
        while ( p != NULL )   //�ӽ��p������
        {
            if ( p->number < t )
            {
                t    = p->number;    //��¼��Сѧ��
                min    = p;          //��¼��Сѧ�Ž��
            } 
 
            p = p->next;    //����p����һ�����
        }
 
        n        = q->number;        //n���ڵ�һ������ѧ��
        q->number    = min->number;  //��Сѧ�Ž���ѧ�����һ������ѧ�Ž���
        min->number    = n;
 
        g        = q->gread;        //ͬ��ѳɼ�Ҳ������
        q->gread    = min->gread;    /*��������˼·����ѡ������*/
        min->gread    = g;
 
        q = q->next;   //��һ���������q���ƣ�Ҳ����ѡ������ʼ�ŵڶ���ʱ�ĵ�һ����      
    }
 
    output( l1 );    //������ɺ��������
}
