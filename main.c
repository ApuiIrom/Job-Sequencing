#include<stdio.h>
#include<stdlib.h>
/* how it works is that I will store the index of profit values to an array call slot[] by giving priority to the higher profit
value but according to their deadline i.e the index of slot[] array itself will treat as a deadline number for the profit values
so if the store the index of profit value say 3 to the index of 4 like slot[4], it means that the deadline of the job with index 3's
deadline is 4. And after storing the indexes for those profit value which can be completed within deadlines will get printed and
cumulative sum of the profits will be done using the index of profit value stored in slot[] array.
 */
int slot[10];
void timeslot(int l, int k)//it accepts the index of profit value l and its deadline number k
{
    if(slot[k]==0){//if slot[] of the deadline k is empty then the job can use the time slot
        slot[k]=l;//slot[] stores the position of the profit value so that we can use it later for getting the cumulative profit value
    }
    else{// if slot is already occupied we will check for empty space in front because the job can be completed 2 or 3 days before
        while(slot[k]!=0 && k!=0)/*we will run the loop until we found the empty slot but if we cannot find the empty slot
                    (slot is pointing to garbage so it can never be zero so we'll add other condition to stop the while loop)
                     then k will be 0 which means that the job cannot be stored because some other jobs has already occupied
                     the time slot i.e, job with deadline 2 can fill the slot[1] and slot[2] but these two is already filled*/
            k--;//decremented the k value to see if there's empty slot for the job to be allocated before it's deadline
        if(k!=0)//if k==0 we cannot store it which means that there is no empty slot
            slot[k]=l;
    }
}
void main(){
printf("Enter the number of jobs\n");
int n;
scanf("%d",&n);
int profit[n],large,pos,l,k,sum=0,fk[n],deadline[n];
for(int i=1;i<=n;i++){
    printf("Enter the profit of job %d\n",i);
    scanf("%d",&profit[i]);
    printf("Enter the deadline of job %d\n",i);
    scanf("%d",&deadline[i]);
}
    for(int i=1;i<=n;i++){
            large=profit[i];
        for(int j=1;j<=n;j++){
            if(profit[j]>=large){
            large=profit[j];
            k=deadline[j];//it stores the deadline value so that k can be used to fill the time slot
            l=j;//l stores the index of the largest profit value
            }
        }
        fk[l]=profit[l];//the largest profit value is copying so that we can use it later after giving the profit value as zero in the next two lines
        timeslot(l,k);//function for storing timeslot for various jobs
        profit[l]=0;//to find the largest value again this needs to be zero
        }
           for(int i=1;i<=n;i++){
                if(slot[i]==0)/* if there is any empty slot we skip the for loop to next iteration coz there is no job done in the particular
                                                                                                                                    time slot*/
                    continue;
            printf("The J%d with profit %d is done\n",slot[i],fk[slot[i]]);/*since slot[] stores the index of profit
            and fk[] stores the profit values we can calculate the profit value by giving the value of slot[] to fk[]*/
            sum=sum+fk[slot[i]];
        }
        printf("The total profit is %d",sum);
}
