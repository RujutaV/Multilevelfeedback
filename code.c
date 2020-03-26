#include<stdio.h>

#define N 10
int count;
typedef struct
{
      int process_id, arrival_time, burst_time, priority;
      int q, ready;
}process_structure process[10]; //made process queue global

int assignQueue(int t1)
{
      if(t1 <= 3) //changed condtion
      {
            return 1;
      }
      else
      {
            return 2;
      }
}
void ready(int y)
{
  for(index = y; index < limit; index++)
  {
        if(process[index].arrival_time < time)
        {
              process[index].ready = 1;
        }
  }
}

void sort_by_qt(int y)
{ process temp;
  for(index = y; index < limit - 1; index++)
  {
        for(j = index + 1; j < limit; j++)
        {
              if(process[index].ready == 1 && process[j].ready == 1)
              {
                    if(process[index].q == 2 && process[j].q == 1)
                    {
                          temp = process[index];
                          process[index] = process[j];
                          process[j] = temp;
                    }
              }
        }
  }
}

sort_by_bt(int y)
{process temp;
  for(index = y; index < limit - 1; index++)
  {
        for(j = index + 1; j < limit; j++)
        {
              if(process[index].ready == 1 && process[j].ready == 1)
              {
                    if(process[index].q == 1 && process[j].q == 1)
                    {
                          if(process[index].burst_time > process[j].burst_time)
                          {
                                temp = process[index];
                                process[index] = process[j];
                                process[j] = temp;
                          }
                          else
                          {
                                break;
                          }
                    }
              }
        }
  }
}
int main()
{
      int  index, temp_process, time, j, y; //made limit global
      process_structure temp;
      printf("Enter Total Number of Processes:\t");
      scanf("%d", &limit);
      //process_structure process[limit];
      for(index = 0; index < limit; index++)
      {
            printf("\nProcess ID:\t");
            scanf("%d", &process[index].process_id);
            printf("Arrival Time:\t");
            scanf("%d", &process[index].arrival_time);
            printf("Burst Time:\t");
            scanf("%d", &process[index].burst_time);
            printf("Process Priority:\t");
            scanf("%d", &process[index].priority);
            //avoided the temp_process variable
            process[index].q = assignQueue(process[index].priority);
            process[index].ready = 0;
      }
      time = process[0].burst_time;
      for(y = 0; y < limit; y++)
      {
            //ready function
            ready(y);

            //sort by qt func
            sort_by_qt(y);

            //sort by bt func
            sort_by_bt(y);

            printf("\nProcess[%d]:\tTime:\t%d To %d\n", process[y].process_id, time, time + process[y].burst_time);
            time = time + process[y].burst_time;
            for(index = y; index < limit; index++)
            {
                  if(process[index].ready == 1)
                  {
                        process[index].ready = 0;
                  }
            }
      }
      return 0;
}
