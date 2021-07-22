/*
 *  Program to find square root of given number using binary search
 *  
 *  Compilation- gcc -o square_root square_root.c
 *  Execution- ./square_root
 *  @Dushyant Batra (1910990098) 18/07/2021
 *  Assignment - 1 
 *  Resources -> GFG
 *
 */

#include<stdio.h>

/*
 * function to calculate square root using binary search.
 *
 * Parameters:
 * num: integer number whose square root we need to find.
 * precision: integer number representing number of decimal places upto which precision should be there.
 * Prints square root of number and returns void.  
 */

void square_root(int num , int precision) {
    
    //Bounds For Calculating square root.
    int start = 0;
    int end = num;
    double ans = 0;

    //Finding integral part of square root.
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(mid * mid < num){
            ans = mid;
            start = mid + 1;
        }
	else if(mid * mid == num) {
            ans = mid;
            break;
        }
	else {
            end = mid - 1;
        }
    }
    
    //Finding decimal places of square root upto required precision
    double preciseBy = 0.1;
    for(int i = 0; i < precision ; i++) {
        while(ans * ans < num) {
            ans = ans + preciseBy;
        }
        ans = ans - preciseBy;
        preciseBy /= 10;
    }

    printf("%.*lf\n", precision, ans);

}

int main(void) {
    //number and precision
    int num=0;
    int precision=0;

    scanf("%d %d", &num, &precision);

    square_root(num , precision);

}

