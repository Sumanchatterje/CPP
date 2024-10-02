#include <stdio.h>
#include <string.h>
int binarySearch(char* stations[],int n,char* target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (strcmp(stations[mid], target) == 0) {
            return mid;
        }
        else if(strcmp(stations[mid],target) < 0){
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
}
        int main(){
            char* stations[]={"Bimanbandar","Birati","Durganagar","Madhyamgram","Nimta","Rajarhat"};
            int n=sizeof(stations)/sizeof(stations[0]);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(strcmp(stations[i],stations[j])>0){
                        char* temp=stations[i];
                        stations[i]=stations[j];
                        stations[j]=temp;
                    }
                }
            }
            char target[]="Madhyamgram";
            int result=binarySearch(stations,n,target);
            if(result!=-1){
                printf("Correct Station");
            }
            else{
                printf("Caution");
            }
        }
