#include <iostream>

using namespace std;

class nodo{
public:
    int izq,der,valor;
    nodo *left;
    nodo *right;
    nodo *p;
    nodo(int l,int r){
        izq=l;
        der=r;
        left=0;
        right=0;
        p=0;
    }
    void setvalue(){
        if(left==0){
            valor=right->valor;
        }else if(right==0){
            valor=right->valor;
        }else{
            if(left->valor<right->valor){
                valor=left->valor;
            }else{
                valor=right->valor;
            }
        }
    }
};
class segment{
public:
    nodo *head;
    int n;
    segment(int a){
        head=0;
        n=a;
    }
    void crear(nodo* &p,int l,int r,int *A){
        if(head==0){
            cout<<"cabeza"<<endl;
            p= new nodo(l,r);
            head=p;
            int mid=(l+r)/2;
            crear(p->left,l,mid,A);
            crear(p->right,mid+1,r,A);
            return;
        }
        if(l==r){
            p=new nodo(l,r);
            p->valor=A[l];
            return;
        }
        int mid=(l+r)/2;
        p=new nodo(l,r);
        crear(p->left,l,mid,A);
        crear(p->right,mid+1,r,A);
        p->setvalue();
    }
    void imprimir(nodo *p){
        if(p==0){
            return;
        }
        imprimir(p->left);
        if(p->left==0 && p->right==0){
            cout<<p->valor<<" ";
        }
        imprimir(p->right);
    }
    nodo* busca(nodo* p,int l,int r,int i,int j){
        if(l>=i && r<=j){
            return p;
        }else if(j<l || i>r){
            return 0;
        }else{
            int mid=(l+r)/2;
            int valor1;
            nodo *a=busca(p->left,l,mid,i,j);
            nodo *b=busca(p->right,mid+1,r,i,j);
            if(a==0){
                valor1=b->valor;
            }else if(b==0){
                valor1=b->valor;
            }else{
                if(a->valor < b->valor){
                    valor1=a->valor;
                }else{
                    valor1=b->valor;
                }
            }
            nodo *tmp=new nodo(-1,-1);
            tmp->valor=valor1;
            return tmp;
        }
    }
    int busqueda(int i,int j){
        return busca(head,0,n-1,i,j)->valor;
    }
    };

int main(){
    int a[8]={3,5,1,7,9,8,5,3};
    segment arbol(8);
    arbol.crear(arbol.head,0,7,a);
    arbol.imprimir(arbol.head);
    cout<<endl;
    return 0;
}
