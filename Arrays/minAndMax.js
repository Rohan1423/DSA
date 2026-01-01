function findMinAndMax (arr){  // iterative solution      // T.C O(n)
    if (arr.length===0) return;                      // S.C O(1)
    let min = arr[0];
    let max = arr[0];
    for (let i=0; i<arr.length-1; i++){
        if(arr[i]<min) min = arr[i];
        if(arr[i]>max) max = arr[i];
    } 
    return {min,max};

}

function findMinAndMaxUsingPCT (arr) {    // Using “Pair Comparison Technique” (faster in theory) 
 if (arr.length===0) return;              // T.C O(n)  // slightly fewer comparisons better for very large arrays in theory
                                          // S.C O(1)
 let min,max;
 let i = 0;

 if (arr.length % 2===0){
    min = arr[0];
    max = arr[1];

    i = 2;
 }
 else {
    min = max = arr[0];

    i = 1;
 }

 while (i<arr.length){
    let a = arr[i];
    let b = arr[i+1];
    if(a<b){
        if(a<min) min=a;
        if(b>max) max=b;
    }
    else{
        if(b<min) min=b;
        if(a>max) max=a;
    }
    i+=2;
 }
 return {min,max};
}

function minAndMaxUisngRecursion (arr,index=0,min = Infinity, max= -Infinity){    // Recursive Version
    if(index===arr.length)return {min,max};                                       // T.C O(n)
                                                                                  // S.C O(n)  For large arrays, recursion can cause stack overflow; iterative is safer
    if(arr[index]<min) min = arr[index];
    if(arr[index]>max) max= arr[index];
    return minAndMaxUisngRecursion(arr,index+1,min,max);
}

const arr1 = [7, 2, 9, 4, 1, 5];
const arr2 = [17, 22, 90, 4, 10, 55];
const arr3 = [2,7,6,5,4,31,23,45,6,7,100];
const result1 = findMinAndMax(arr1);
const result2 = findMinAndMaxUsingPCT(arr2);
const result3 = minAndMaxUisngRecursion(arr3);
console.log("result1",result1);
console.log("result2",result2);
console.log("result3",result3);