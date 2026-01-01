function countOccurence (arr,target) {  // T.C O(n)    S.C O(1)
    let count=0;
    for (let i =0; i<arr.length; i++){
        if(arr[i]===target){
            count++;
        }
    }
    return count;
}

function countOccurenceWithMaxLimit (arr,target,maxCount){  // Early Stop (If max occurrences needed) T.C O(n)    S.C O(1)
    let count=0;
    for(let i=0; i<arr.length; i++){
        if(arr[i]===target){
            count++;
        
            if(maxCount===count){
                break;
            }
        }

    }
    return count;
}

function countOccurenceInSorted(arr, target) {  // Count in a Sorted Array (Optimized)  
    let count = 0;

    for (let i = 0; i < arr.length; i++) {

        if (arr[i] === target) {
            count++;
        }
        else if (arr[i] > target) {
            break;
        }

    }
    return count;

}

function buildFrequencyMap(arr) {     // Using Hash Map (Frequency Count)  T.C O(n)   S.C O(n)
  const freq = {};   //  Empty object to store counts

  for (let i = 0; i < arr.length; i++) {
    const element = arr[i];  //  Take current element

    if (freq[element] === undefined) {
      freq[element] = 1;     // First time → initialize count
    } else {
      freq[element]++;      // Already exists → increment count
    }
  }

  return freq;  
}


const arr = [1,2,2,2,4,45,56];
console.log(buildFrequencyMap(arr,2));