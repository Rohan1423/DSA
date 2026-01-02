function reverseArr (arr) {  // Using an extra array (Simple approach) T.C O(n)  S.C O(n)
    const reversedArr = [];
    for(let i=arr.length-1; i>=0; i--){
        reversedArr.push(arr[i]);
    }
    return reversedArr;
}

function reverseArray (arr) {  // In-place reversal (Two pointers) imp  T.C O(n) S.C O(1)
    let left = 0;
    let right = arr.length-1;

    while(left<right){
        let temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
    return arr;

}

function reverseArrUsingRecursion (arr,left=0,right=arr.length-1) {  // Recursive approach  T.C O(n)  S.C O(n)

    if(left>=right) return arr;

    [arr[left],arr[right]]= [arr[right],arr[left]];
    return reverseArrUsingRecursion(arr,left+1,right-1);

}

const result = reverseArrUsingRecursion([1, 2, 3]);
console.log(result);