#include<stdio.h>
#include<stdlib.h>
#define m 10
int opcount=0;
typedef struct node
{
    int val;
    struct node* link;
}NODE;

NODE* getnode()
{
    NODE* x=(NODE*)malloc(sizeof(NODE));
    return x;
}

NODE* ht[m];

int hashFunc(int key)
{
        return key % m;
}

void insert(int key)
{
    int index=hashFunc(key);
    NODE* cell=getnode();
    cell->val= key; cell->link=NULL;
    if(ht[index]==NULL){ ht[index]=cell;return;}
    NODE* temp=ht[index];
    while(temp->link!=NULL) temp=temp->link;
    temp->link=cell;
}

int search(int key)
{
    int ind=hashFunc(key);
    NODE* temp=ht[ind];
    opcount++;
    while(temp!=NULL){
        opcount++;
        if(temp->val==key)  return 1;
        temp=temp->link;
    }

    return 0;

}

void display()
{

    for(int i=0;i<m;i++)
    {
        NODE* temp=ht[i];
        printf(" %d: ",i);
        while(temp!=NULL){
            printf(" %d ->", temp->val);
            temp=temp->link;
        }
        printf("NULL\n");
    }
}

void main() {
    int n, key;

    for (int i = 0; i < m; i++) {
        ht[i] = NULL;
    }

    printf("Enter the number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    printf("\nHash Table after insertion:\n");
    display();

    // Search for a key
    printf("\nEnter key to search: ");
    scanf("%d", &key);
    if (search(key))
        printf("Key %d found!\n", key);
    else
        printf("Key %d not found!\n", key);

    printf("\nOpcount: %d", opcount);

    return;
}

