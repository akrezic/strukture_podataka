struct elem {
  int ai, bi, ci, di;
	char pre_ime[40];
	int dan, mjesec, godina, godine;
	float tekuci, devizni;
	}x;
       
struct qu {
    elem klijent;
    qu *sljedeci;
    };
       	
struct que {
    qu *front,*rear;
    };
       
que q, salter, brzi, novi;
int n, placa=0;

typedef que& red;
 
elem FrontQ(red q) {
    if(q.front==q.rear) exit(0);
    return (q.front->sljedeci)->klijent;
	}
     
void EnQueueQ(elem x,red q) {
	qu *zadnji = q.front,*novi;
    while(zadnji->sljedeci) zadnji=zadnji->sljedeci;
    novi = new qu;
    novi->sljedeci=NULL;
    novi->klijent=x;
    zadnji->sljedeci=novi;
    q.rear=novi;
    }
     
void DeQueueQ(red q) {
    if(q.front==q.rear) return;
    qu *brisi = q.front;
    q.front=brisi->sljedeci;
    delete brisi;
    }
 
bool IsEmptyQ(red q) {
    if(q.front==q.rear) return true;
    else return false;
     }
     
void InitQ(red q) {
    qu* novi = new qu;
    novi->sljedeci=NULL;
    q.rear=novi;
    q.front=novi;
    } 
