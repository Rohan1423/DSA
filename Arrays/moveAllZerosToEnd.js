function moveZerosToEnd(arr){  // Two-Pointer (Optimal)  T.C O(n)   S.C O(1)
    let index=0;
    for(let i=0; i<arr.length; i++){
        if(arr[i]!==0){
            arr[index]=arr[i];
            index++;
        }
    }
    while(index<arr.length){
        arr[index]=0;
        index++;
    }
    return arr;
    
}

function moveZerosToEndUsingFilter (arr) {  // Using filter() (Built-in) 
    const nonZeros = arr.filter(n=> n!==0);
    const zeros = arr.length - nonZeros.length;

    return[...nonZeros, ...Array(zeros).fill(0)];
    
}
const arr=[1,2,0,0,4,0,5];
console.log(moveZerosToEndUsingFilter(arr));