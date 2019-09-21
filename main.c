#include <stdio.h>
#include <stdlib.h>

/* basic of pointer*/



int main()
{
    int a = 10;
    int *p;    // deciding of pointer as above variable is of integer data type so it must be of integer
    p = &a; // it means ponter variable takes the memory of vairable a

    printf("the address of a is : %d\n", &a);


    printf("the value of pointer p is %d\n", *p);



    printf("the address of pointer p is %d\n", &p);

    return 0;
}

/* two pinters and one operation*/

int main()
{
    int a =10, b =5, c;
    int *p, *q;// two pointers are declared
    p =&a; // pointer p will take address of a
    q =&b; // pointer q will take address of b
    c= *p+*q; // sum of the accessibe value
    printf("the sum is %d", c);
    return 0;

}

/* different way of accessing value using pointer*/

int main()
{
    int i, array[3] = {2, 4, 6}; // value assign in an array
    int *p;
    p =&array[0];
    for(i = 0; i < 3 ; i++)
        printf("%d\n", &array[i]);// first and third array address must be same
    for(i = 0; i < 3 ; i++)
        printf("%d\n", *p+i);// this will gives the value stored in respective memory
    for(i = 0; i < 3 ; i++)
        printf("%d\n", p+i); // this will give the memory address of respective array
    return 0;
}


int main()

{
    char a = {'A'};
    char *p;
    p = &a;
    printf("%c", *p);

}

/*another way of accessing array using pointer*/


int main()
{
    int name[3] = {1, 2, 3};
    int *p;
    p = &name[0];

    while(p <= &name[2]){
        printf("the value is %d\n", *p);
        printf("the value of address is %x\n", p);
        p++;// it will shift the pointer to next address
    }

    return 0;


}

/* best example of call by reference*/

void swap(int *x, int *y);
int main()
{
    int a, b;
    printf("take any two number");
    scanf("%d %d", &a, &b);
    swap(&a, &b);// address is passed
    return 0;
}
void swap(int *x, int *y)// since x and y are pointers so it takes only address
{
    int temp;// a new variabe is decided
    temp = *x;
    *x = *y;
    *y = temp;
    printf("%d %d", *x, *y);

}



int main()
{

    char name[10] = "sandeep";
    char *p;
    p = &name[0];// pointer poited to first value of given array
    while( *p != 0)// since string has automatic null value at last so
    {
        printf("%c", *p);
        p++;// it shift the address of the the pointer
    }
}


/* array of pointer*/

int main()
{
    int array[4]={1,2,3,4}, i;// array of size 4 is declared
    int *array_ptr[4];// pointer array if size 4 is declared same as that of the data types it gonna hold
    for(i=0 ;i<4; i++)// loop to store the address in pointer that were declared
    {
        array_ptr[i] = &array[i];// memory is assigned to the pointer array
    }
     for(i=0 ;i<4; i++){
        printf("%d\n", *array_ptr[i]);}// execution of data using pointer

    return 0;
}


/*pointer to poiter variable*/

int main()
{
    int a=10;
    int *p;// pointerr variable is declared
    int **q;// pointer to pointer variable is declared
    p = &a; // pointer points the addess of variable a
    q = &p; // pointer points the address of pointer

    printf("the value of a is %d\n", *p);// accessing of value using pointer
    printf("the address of a is %d \n", p);
    printf("the address if a is %d\n", *q);
    printf("the address if p is %d\n", &p);
    printf("the value of p is %d\n", q);
    printf("the value of a is %d\n", **q);

}

/* call by referece */

int change(int *x);
int main()
{
    int a;
    printf("take any number");
    scanf("%d", &a);
    change(&a);
    printf("the number is changed : %d", change(&a));
    return 0;
}
int change(int *x)
{
    *x =15;
    return(*x);
}


/* passing of address of an array using pointer*/

int sum(int *x);
int main()
{
    int arr[5] = {4, 5, 6, 10, 10};
    sum(arr);// this will pass the address of first block of an array
    printf("the sum is %d", sum(arr));
    return 0;


}
int sum(int *x)// since address array is passed so receiver must be of pointer
{

    int add, i;
    add = 0;// first put the value 0 in add block
    for(i=0 ; i<5 ; i++)
    {
        add = add + *x;
        x++;

    }
    return add;
}


/* user defined string length*/

int main()
{
    char name[100], *p;
    int count;
    printf("please eneter your name\n");
    gets(name);
    p = &name;
    count = 0;
    while(*p != NULL){
        count = count +1;
        p++;
    }
    printf("the length is %d\n", count);
    printf("%d", strlen(name));

    return 0;

}


/* use of pointer in reversing the given number*/

int main()
{
    int arr[4]={1, 2, 3, 4}, *p, i;
    p =&arr[0];// pointer pointed to the address of the array
    p = p+3;//simply move the pointer to the last value
    for(i=0 ; i < 4 ;i++)
    {
        printf("%d\n", *p);// accessing the value in reverse form
        p--;// shifting the pointer to lowest order
    }
    return 0;
}

/* return pointer from function*/

int* sum();
int main()
{
    int a=5, b=10, *p;
    p = sum(a, b);// return value will be stored in p
    printf("%d", *p);// this will dereferencing the pointer
}
int* sum(int x, int y)
{
    int c, *ptr; // function where int c and pointer is declared
    c = x+y;
    ptr = &c;
    return ptr;// above function is of return pointer type so address is returned
}

/* calculation of samllest number from any five user input*/

int main()
{
    int a[5], smallest, i;
    printf("take any five numbers\n");
    for(i=0; i<5; i++){
        scanf("%d", &a[i]);
    }
    smallest = a[0];
    for(i=1; i<5; i++)
    {
        if(smallest>a[i]){
            smallest=a[i];
        }
    }
    printf("the smallest number you entered is %d ", smallest);
}

/* getting the vowel from the entered name*/

int main()
{
    char vowel, name[20];// array declaration
    int i, count=0, b;
    printf("please enter your name");// ask user for name input
    gets(name);// it will store the name in given address
    b=strlen(name);// calculation of string length for loop

    for(i=0; i<b ;i++){
        if(name[i]== 'a'|| name[i]=='e' || name[i]=='i' || name[i]=='o'){
            vowel = name[i];// it will store the character of name[i] in  vowel

            printf("%c\n", vowel);// print the character
            count =count+1;// this will count the vowel number
        }

    }
    printf("the total number of vowel is %d", count);

}

