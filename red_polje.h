struct elem {
  int ai, bi, ci, di;
	char pre_ime[40];
	int dan, mjesec, godina, godine;
	float tekuci, devizni;
	}x;
       
struct que {
	elem klijent[10000];
    int front,rear;
    };
       
que q, salter, brzi, novi;
int n, placa=0;

typedef que& red;
 
int AddOne(int n) {
    return ((n+1)%10000); 
    }
    
elem FrontQ(red q) {
     if(AddOne(q.rear)==q.front) {
                                 system("pause");
                                 exit(0);
                                 }
     return q.klijent[q.front];
     }
     
void EnQueueQ(elem x, red q) {
     if(AddOne(AddOne(q.rear))==q.front) return;
                                         
     q.rear=AddOne(q.rear);
     q.klijent[q.rear]=x;
     }
     
void DeQueueQ(red q) {
     if(AddOne(q.rear)==q.front) return;
                       
     q.front=AddOne(q.front);
     }
     
void InitQ(red q) {
     q.front=0;
     q.rear=9999;
     }
     
bool IsEmptyQ(red q) {
     if(AddOne(q.rear)==q.front) return true;
     else return false;
     }
