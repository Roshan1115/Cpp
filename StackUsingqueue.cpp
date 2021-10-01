#include<stdio.h>

int q1[1000];
int q2[1000];
int front1 = -1, back1 = -1;
int front2 = -1, back2 = -1;

int isempty1(){
  return (front1 == -1 || front1 > back1);
}
int isempty2(){
  return (front2 == -1 || front2 > back2);
}

void enqueue1(int x){
  q1[++back1] = x;
  if(front1 == -1)  front1++;
}
void enqueue2(int x){
  q2[++back2] = x;
  if(front2 == -1)  front2++;
}

int dqueue1(){
  if(!isempty1()){
    return q1[front1++];
  }
  return -1111111111;
}
int dqueue2(){
  if(!isempty2()){
    return q2[front2++];
  }
  return -1111111111;
}


// stack using above two queues
int size = 0;

int isEmpty(){
  return size == 0;
}

void push(int x){
  enqueue2(x);
  while(!isempty1()){
    enqueue2(dqueue1());
  }
  while(!isempty2()){
    enqueue1(dqueue2());
  }
  size++;
}

int pop(){
  if(!isempty1()){
    size--;
    return dqueue1();
  }
  return -111111111;
}

int main(){
  int n;
  printf("Enter number of elements you want to push. ");
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    int x;
    printf("enter element to push ");
    scanf("%d", &x);
    push(x);
  }

  while(!isEmpty()){
    printf("%D\n", pop());
  }
  return 0;
}