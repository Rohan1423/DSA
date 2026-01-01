function sumOfAllEle (arr) {  // Iterative T.C O(n)   S.C O(1)
    if(arr.length===0) return;
    let sum =0;
    for (let i = 0; i<=arr.length-1; i++){
        sum+=arr[i];
    }
    return sum;
}

function sumOfAllEleUsingRecursion (arr,index=0){   //RECUSIVE SOL T.C O(n) S.C O(n)
    if (index===arr.length) return 0;

    return arr[index]+sumOfAllEleUsingRecursion(arr,index+1);
}

const arr1 =[10,20,10,20,30,60,70];
const arr2=[100,20,10,20,30,60,70];
console.log("sumOfAllEle",sumOfAllEle(arr1));
console.log("sumOfAllEleUsingRecursion",sumOfAllEleUsingRecursion(arr2));