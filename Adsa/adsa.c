//---------------------------------------------------------Advanced Data Structures-----------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>

struct Job
{
   char id;
   int deadline;
   int profit;
};

int compare(const void*a,const void*b)
{
   struct Job*jobA=(struct Job*)a;
   struct Job*jobB=(struct Job*)b;
   return jobB->profit-jobA->profit;
}

void jobSequencing(struct Job jobs[],int n)
{
   qsort(jobs, n, sizeof(struct Job), compare);

   int maxDeadline = 0;
  for(int i=0;i<n;i++)
  {
   if(jobs[i].deadline>maxDeadline)
   {
      maxDeadline=jobs[i].deadline;
   }
  }

  //free slot
  int slot[maxDeadline+1];
  for(int i=0;i<=maxDeadline;i++)
  {
   slot[i]=-1;
  }

  int totalProfit =0;
  int jobCount =0;

  for(int i=0;i<n;i++)
  {
   for(int j= jobs[i].deadline;j>0;j--)
   {
      if(slot[j]==-1)
      {
         slot[j]=i;
         totalProfit += jobs[i].profit;
         jobCount++;
         break;
      }
   }
  }

  //print
  for(int i =0 ;i<=maxDeadline;i++)
  {
   if(slot[i]!=-1)
   {
      printf("%c",jobs[slot[i]].id);
   }
  }
   printf("total profit %d",totalProfit);

}
int main()
{
   int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];
    printf("Enter job id, deadline, and profit for each job:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        getchar();
        scanf("%c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}


//--------------------------------------------------------------------------------------------------------------------------------------


#include<stdio.h>
#include<stdlib.h>

struct Job
{
   char id;
   int deadline;
   int profit;
};

int compare(const void*a,const void*b)
{
   struct Job*jobA=(struct Job*)a;
   struct Job*jobB=(struct Job*)b;
   return jobB->profit-jobA->profit;
}

void jobSequence(struct Job jobs[],int n)
{
   qsort(jobs,n,sizeof(struct Job),compare);

   int maxDeadline = 0;
   for(int i=0;i<n;i++)
   {
      if(jobs[i].deadline>maxDeadline)
      {
         maxDeadline=jobs[i].deadline;
      }
   }

   //free slot
   int slot [maxDeadline+1];
   for(int i=0;i<=maxDeadline;i++)
   {
      slot[i]=-1;
   }

   int totalProfit = 0;
   int jobCount =0 ;

   for(int i=0;i<n;i++)
   {
      for(int j=jobs[i].deadline;j>=0;j--)
      {
           if(slot[j]==-1)
           {
            slot[j]=i;
            totalProfit += jobs[i].deadline;
            jobCount++;
            break;
           }
      }
   }
   printf("seleted jobs");
   for(int i=0;i<=maxDeadline;i++)
   {
      printf("%c",jobs[slot[i]].id);
   }
   printf("Total profit %d",totalProfit);

}
int main()
{
   int n;
   printf("Enter the number of jobs\n");
   scanf("%d",&n);

   struct Job jobs[n];
   printf("Enter job id deadline and profit");
   for(int i=0;i<n;i++)
   {
      printf("jobs %d ",i+1);
      getchar();
      scanf("%c %d %d",&jobs[i].id,&jobs[i].deadline,&jobs[i].profit);
   }
   jobSequence(jobs,n);
   return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------

#include<stdio.h>
#include<stdbool.h>
#define MAX 20

int board[MAX][MAX];
int N;
void printBoard()
{
   for(int i=0;i<N;i++)
   {
      for(int j=0;j<N;j++)
      {
         if(board[i][j]==1)
         {
            printf("Q");
         }
         else
         {
            printf(".");
         }
      }
      printf("\n");
   }
}

bool isSafe(int row,int col)
{

   //check col
   for(int i=0;i<col;i++)
   {
     if(board[row][i]);
     return false;
   }
   // check right dia
   for(int i=row,j=col;i>=0&&j>=0;i--,j--)
   {
      if(board[i][j])
      {
         return false;
      }
   }
     // check left dia
   for(int i=row,j=col;i<N&&j>=0;i++,j--)
   {
      if(board[i][j])
      {
         return false;
      }
   }
   return true;
}

bool solveNQueens(int col)
{
  if(col>=N)
  {
   return true;
  }
   for(int i=0;i<N;i++)
   {
      if(isSafe(i,col))
      {

      }

   }
}

//--------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------travelling salesman

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

int n;
int cost[MAX][MAX];
int visited[MAX];
int bestcost = INT_MAX;
int bestpath[MAX];
int currentpath[MAX];

void tsp(int currentcity, int count, int costSofar)
{
   if (cost == n && cost[currentcity][0] > 0)
   {
      int totalcost = costSofar + cost[currentcity][0];
      if (totalcost < bestcost)
      {
         bestcost = totalcost;
         for (int i = 0; i < n; i++)
         {
            bestpath[i] = currentpath[i];
         }
         bestpath[n] = 0;
      }
      return;
   }

   for (int nextcity = 0; nextcity < n; nextcity++)
   {
      if (!visited[nextcity] && cost[currentcity][nextcity] > 0)
      {
         visited[nextcity] = 1;
         currentpath[count] = nextcity;

         tsp(nextcity, count + 1, costSofar + cost[currentcity][nextcity]);

         // backtrack
         visited[nextcity] = 0;
      }
   }
}

int main()
{
   printf("Enter the number of cities");
   scanf("%d",&n);

   printf("Enter the cost matrix");
   for(int i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         scanf("%d",&cost[i][j]);
      }
   }

  for(int i=0;i<n;i++)
  {
   visited[i]=0;
  }

}

--------------------------------------------------------------------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 10

int n;
int cost[MAX][MAX];
int visited[MAX];
int bestcost = INT_MAX;
int bestpath[MAX];
int currentpath[MAX];

void tsp(int currentcity ,int count,int costsofar)
{
   if(cost == n && cost[currentcity][0] > 0)
   {
      int totalcost = costsofar+cost[currentcity][0];
      if(totalcost < bestcost)
      {
         bestcost = totalcost;
         for(int i=0;i<n;i++)
         {
            bestpath[i]=currentpath[i];
         }
         bestpath[n]=0;
      }
      return;
   }
   //visit nextcities

   for(int nextcity=0;nextcity < n;nextcity++)
   {
      if(!visited[nextcity] && cost[currentcity][nextcity]>0)
      {
         visited[nextcity]=1;
         currentpath[count]=nextcity;

         tsp(nextcity,count+1,costsofar+cost[currentcity][nextcity]);

        visited[nextcity]=0;
      }
   }

}

//--------------------------------------------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>

#define MAX 20

struct Job
{
   char id;
   int deadline;
   int profit;
};

int compare(const void*a,const void*b)
{
   struct Job*jobA=(struct Job*)a;
   struct Job*jobB=(struct Job*)b;
   return jobB->profit-jobA->profit;
}

void jobsequence(struct Job jobs[],int n)
{
   qsort(jobs,n,sizeof(struct Job),compare);

   int maxDeadline = 0;
   for(int i=0;i<n;i++)
   {
      if(jobs[i].deadline > maxDeadline)
      {
         maxDeadline =jobs[i].deadline;
      }
   }

   int slot[maxDeadline+1];
   for(int i=0;i<=maxDeadline;i++)
   {
      slot[i]=-1;
   }

   int totalprofit = 0;
   int jobcount =0;

   for(int i=0;i<n;i++)
   {
      for(int j=jobs[i].deadline;j>=0;j--)
      {
         if(slot[j]==-1)
         {
            slot[j]=i;
            totalprofit += jobs[i].profit;
            jobcount++;
            break;
         }
      }
   }

   //print
   printf("selected profits");
   for(int i=0;i<=maxDeadline;i++)
   {
      if(slot[i]!=1)
      {
         printf("%c",jobs[slot[i]].id);
      }

   }
   printf("Total profit %d",totalprofit);
}
int main()
{
   printf("Enter the cost id");
}



//--------------------------------------------------------------------------------------------------------------------------------------
// NQUEENS
#include<stdio.h>
#include<stdbool.h>

#define MAX 20
int board[MAX][MAX];
int N;
void printBoard()
{
   for(int i=0;i<N;i++)
   {
      for(int j=0;j<N;j++)
      {
         if(board[i][j]==1)
         {
            printf("Q");
         }
         else
         {
            printf(".");
         }
      }
      printf("\n");
   }
}

bool isSafe(int row,int col)
{
   for(int i=0;i<col;i++)
   {
      if(board[row][i])
       return false;
   }
   for(int i=row,j=col;i>=0 && j>=0;i--,j--)
   {
      if(board[i][j])
       return false;
   }
    for(int i=row,j=col;i<N && j>=0;i++,j--)
   {
      if(board[i][j])
       return false;
   }
   return true;
}
bool solveNQueen(int col)
{
   if(col>=N)
   return true;

   for(int i=0;i<N;i++)
   {
      if(isSafe(i,col))
      {
         board[i][col]=1;

         if(solveNQueen(col+1))
          return true;
          board[i][col]=0;
      }
   }
   return false;
}
int main()
{
   printf("Enter the no of Queens");
   scanf("%d",&N);

   for(int i=0;i<N;i++)
   {
      for(int j=0;j<N;j++)
      {
         board[i][j]=0;
      }

   }
   if(solveNQueen(0))
   {
      printf("Solution\n ");
      printBoard();
   }
   else
   {
      printf("solution not found");
   }
   return 0;
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------
// 0/1KNAPSACK BY BACKTRACKING


#include<stdio.h>

int maxProfit =0;
int n;
int W;
void ksp(int i,int currentprofit,int currentweight,int values[],int weights[])
{
   if(i==n)
   {
      if(currentprofit > maxProfit)
      {
         maxProfit = currentprofit;
      }
      return;
   }
   if(currentweight+weights[i]<=W)
   {

    ksp(i+1,currentprofit+values[i],currentweight+weights[i],values,weights);
   }
  ksp(i+1,currentprofit,currentweight,values,weights);

}
int main()
{
   printf("Enter the no of items");
   scanf("%d",&n);
   printf("Enter the capacity of ks");
   scanf("%d",&W);

int values[n];
int weights[n];
   for(int i=0;i<n;i++)
   {
      printf("item %d -value",i+1);
      scanf("%d",&values[i]);
       printf("item %d -Weight",i+1);
      scanf("%d",&weights[i]);
   }
   ksp(0,0,0,values,weights);
     printf("%d",maxProfit);
   return 0;
}

#include<stdio.h>

int maxprofit =0;
int n;
int W;

void ksp(int i,int currentprofit,int currentweight,int values[],int weights[])
{
   if(i==n)
   {
      if(currentprofit > maxprofit)
      {
         maxprofit = currentprofit;
      }
      return;
   }
   if(currentweight+weights[i] <= W)
   {
      ksp(i+1,currentprofit+values[i],currentweight+weights[i],values,weights);

   }
   ksp(i+1,currentprofit,currentweight,values,weights);
}
int main()
{
   printf("Enter the no of items");
   scanf("%d",&n);

   printf("ENter the capacity of knapsack");
   scanf("%d",&W);


  int values[n];
  int weights[n];
   printf("Enter the item values ");
   for(int i =0;i<n;i++)
   {
      printf("Item %d -value",i+1);
      scanf("%d",&values[i]);
      printf("Item %d -weight ",i+1);
      scanf("%d",&weights[i]);
   }
   ksp(0,0,0,values,weights);
   printf("%d",maxprofit);
   return 0;
}


//
//

//---------------------------------------------------------PRACTISE--------------------------------------------------------------------------
#include<stdio.h>
#include<stdbool.h>

#define MAX 20
int N;
int board[MAX][MAX];

void printBoard()
{
   for(int i=0;i<N;i++)
   {
      for(int j=0;j<N;j++)
      {
         if(board[i][j]==1)
         {
            printf("Q");
         }
         else{
            printf(".");
         }
      }
      printf("\n");
   }
}

bool isSafe(int row,int col)
{
   for(int i = 0;i<col;i++)
   {
      if(board[row][i])
      return false;
   }
 for(int i =row,j=col;i>=0 && j>=0 ;i--,j--)
   {
      if(board[i][j])
      return false;
   }
   for(int i =row,j=col;i<N&& j>=0 ;i++,j--)
   {
      if(board[i][j])
      return false;
   }
   
return true;

}

bool solveNQueen(int col)
{
 if(col>=N)
 return true;

 for(int i=0;i<N;i++)
 {
   if(isSafe(i,col))
   {
      board[i][col]=1;

      if(solveNQueen(col+1))
      return true;
      board[i][col]=0;
   }
 }
 return false;
}
int main()
{
   printf("Enter the no of Queens");
   scanf("%d",&N);

   for(int i=0;i<N;i++)
   {
      for(int j=0;j<N;j++)
      {
         board[i][j]=0;
      }
   }

   if(solveNQueen(0))
   {
      printf("solution\n");
      printBoard();
   }
   else
   {
      printf("solution not found");
   }
}






#include<stdio.h>

int maxprofit =0;
int n;
int W;


void ksp(int i,int currentprofit ,int currentweight, int values[],int weights[])
{
   if(i==n)
   {

   if(currentprofit > maxprofit)
   {
      maxprofit= currentprofit;
   }
   return;
   }
   if(currentweight+weights[i] <= W)
   {
      ksp(i+1,currentprofit+values[i],currentweight+weights[i],values,weights);
   }
   ksp(i+1,currentprofit,currentweight,values,weights);
}
int main()
{
   printf("Enter the no of items\n");
   scanf("%d",&n);

   printf("Enter the capacity of Ksp\n");
   scanf("%d",&W);

  int values[n];
  int weights[n];

  for(int i=0 ;i<n;i++)
  {
     printf("Item %d -value",i+1);
     scanf("%d",&values[i]);
      printf("Item %d -weights",i+1);
     scanf("%d",&weights[i]);
  }

  ksp(0,0,0,values,weights);
  printf("maxprofit %d",maxprofit);
}





#include<stdio.h>
#include<stdlib.h>


struct Job
{
  char id;
  int profit;
  int deadline;
};

int compare(const void*a,const void*b)
{
  struct Job*jobA=(struct Job*)a;
  struct Job*jobB=(struct Job*)b;
  return jobB->profit - jobA->profit;
}
void jobseq(int n,struct Job jobs[])
{
  qsort(jobs,n,sizeof(struct Job),compare);

  int maxdeadline =0 ;
  for(int i=0;i<n;i++)
  {
    if(jobs[i].deadline> maxdeadline)
    {
      maxdeadline = jobs[i].deadline;
    }
  }

  int slot[maxdeadline+1];
  for(int i=0;i<=maxdeadline;i++)
  {
    slot[i]=-1;
  }

  int totalprofit =0 ;
  int jobcount =0;

  for(int i=0;i<n;i++)
  {
    for(int j=jobs[i].deadline;j>0;j--)
    {
       if(slot[j]==-1)
       {
        slot[j] = i;
        totalprofit+=jobs[i].profit;
        jobcount++;
        break;
       }
    }
  }

  printf("selected jobs\n");
  for(int i=0;i<=maxdeadline;i++)
  {
    if(slot[i]!=-1)
    {
      printf("%c",jobs[slot[i]].id);
    }
  }
  printf("Total profit",totalprofit);
} 

int main()
{
  int n;
  printf("Enter the number of jobs\n");
  scanf("%d",&n);

  struct Job jobs[n];
  printf("Enter the job id,job deadline,profit");
  for(int i=0;i<n;i++)
  {
    printf(" Job %d",i+1);
    getchar();
    scanf("%c %d %d ",&jobs[i].id ,&jobs[i].profit,&jobs[i].profit);
  }
  jobseq(n,jobs);
 return 0;
}





#include<stdio.h>
#include<stdlib.h>>
#include<limits.h>
#define MAX 10

int n;
int cost[MAX][MAX];
int visited[MAX];
int bestcost =INT_MAX;
int bestpath[MAX];
int currentpath[MAX];


void tsp(int currentcity,int count,int costsofar)
{
 if(count == 0 && cost[currentcity][0]>0)
 {
    int totalcost = costsofar+cost[currentcity][0];
    if(totalcost > bestcost)
    {
      bestcost = totalcost;
      for(int i=0;i<n;i++)
      {
        bestpath[i]=currentpath[i];
      }
      bestpath[n]=0;
    }
    return;
 }

for(int nc =0;nc<n;nc++)
{

  if(!visited[nc] && cost[currentcity][nc]>0 )
  {
    visited[nc] =1;

    currentpath[count]= nc;

    tsp(nc , count+1,costsofar+cost[currentcity][nc]);

    visited[nc]=0;
  }

}

}
//
