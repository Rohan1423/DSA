function isSortedAscending (arr){      // T.C O(n)   S.C O(1) 
    for (let i=0; i<arr.length; i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}

const arr = [1,2,4,3,5,6];
console.log(isSortedAscending(arr));