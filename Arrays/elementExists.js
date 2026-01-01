function linearSearchToFindElement(arr,target) {  // T.C O(n)  S.C O(1)
    let i =0;
    while(i<arr.length){
        if(arr[i]===target){
        return true;
        }
        i++;
    }
    return false;

}

function binarySearchToFindElement(arr,target) {    // IF ARRAY IS SORTED T.C O(log n)  S.C O(1)
    let left=0;
    let right=arr.length-1;

    while(left<=right){
        let mid=Math.floor((left+right)/2);

        if(arr[mid]===target) return true;

        else if(arr[mid]<target){
            left = mid+1;
        }
        else{
            right = mid-1;
        }

    }
    return false;

}

function elementExists(arr,target,index=0){  // Recursive Approach
    if(index===arr.length) return false;

    if(arr[index]===target) return true;

    return elementExists(arr,target,index+1);
}

const arr1=[1,2,34,5,6,65,4,3,22];
console.log(elementExists(arr1,21));
const arr2= [10, 20, 30, 40, 50, 60, 220, 340, 650];
console.log(binarySearchToFindElement(arr2,340));