/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

int partition(int arr[], int lower, int upper){
    int i = (lower - 1);
    int pivot = arr[upper];
    int j;
    for(j = lower; j < upper; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[upper]);
    return (i + 1);
}

void quickSort(int arr[], int lower, int upper){
    if(upper > lower){
        int partitionIndex = partition(arr, lower, upper);
        quickSort(arr, lower, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, upper);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    *returnSize = 0;
    *returnColumnSizes = malloc(numsSize * numsSize * sizeof(int));
    int **result = malloc(numsSize * numsSize * sizeof(int*));

    quickSort(nums, 0, (numsSize - 1));
    int minIdx, maxIdx, check;
    int i;
    for(i = 0; i < (numsSize - 2); i++){
        minIdx = (i + 1), maxIdx = (numsSize - 1);
        if((i > 0) && (nums[i] == nums[i - 1])){continue;}
        while(minIdx < maxIdx){
            check = nums[i] + nums[minIdx] + nums[maxIdx];
            if(check < 0){minIdx++;}
            else if(check > 0){maxIdx--;}
            else{
                result[*returnSize] = malloc(3 * sizeof(int));
                (*returnColumnSizes)[*returnSize] = 3;
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[minIdx];
                result[*returnSize][2] = nums[maxIdx];
                *returnSize += 1;
                minIdx++;
                while((nums[minIdx] == nums[minIdx - 1]) && (minIdx < maxIdx)){minIdx++;}
            }
        }
    }
    return result;
}