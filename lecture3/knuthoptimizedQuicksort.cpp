//200 points and optional

partialquicksort(x, l, r) {
    if (i-l > k)
        partialquicksort(x, l, i);
    if (r - i+1 >k)
        partialquicksort(x,i+1,r);
}

//essentially we do not want the quicksort to go all the way to the end
//we optimize this but not doing all these quicksorts at the end
//omce that happens we have the insertion take over
// but what is the number, that we want quicksort to take over at
knuthquicksort(int x[], int n){
    partialquicksort(x,0,n-1); //k = minimum size = ???

    //k =2 quicksort, k =10000 insertion sort is doing too much
    // use goldenMeanSearch in between 200 and 300
    insertion
}

//we want to use a goldenMeanSearch to test what number it is best for the
//insertion sort to take over from the quicksort
//also how much faster is this than the normal quicksort algorithm  
testprocedure(){
    int[] r = generatrandomnumbers();

    foreach trial
      int[] copy =r; //copy the array

    knuthquicksort(copy); //with k = ???
}
