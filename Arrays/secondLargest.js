function secondLargest (arr) {  // Single pass (Optimal)n  T.C O(n)  S.C O(1)
    if (arr.length < 2) return null;
    let secondLargest = -Infinity;
    let largest = -Infinity;
    for (let i=0; i<arr.length; i++){
        if(arr[i]>largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i]>secondLargest && arr[i] !== largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest === -Infinity? null : secondLargest;
}

function secondLargestUsingSort (arr) {  // sort and pick T.C O(n log n) S.C O(1/n)    Halving once → log n    Halving for each element → n log n
    if (arr.length<2) return null;
    arr.sort((a,b)=>a-b);
    let largest = arr[arr.length-1];
    for (i=arr.length-2; i>=0; i--){
        if(arr[i]<largest) return arr[i];
    }
    return null;
}

function secondLargestUsingSet (arr) {  // Using Set T.C  O(n log n)  S.C O(n)
    const unique = [...new Set(arr)];
    if(unique.length<2) return null;

    unique.sort((a,b)=>b-a);
    return unique[1];
}

const arr = [10, 5, 20, 8];
const result = secondLargestUsingSet(arr);
console.log(result);