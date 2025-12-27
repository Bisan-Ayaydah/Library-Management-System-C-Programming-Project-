#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int MAXSIZE = 100 ;

void displayMainMenu(){

    printf("Please Select an Operation <1-4>:\n");
    printf("1- Add a Book:\n");
    printf("2- Remove a Book:\n");
    printf("3- Search for a Book:\n");
    printf("4- Print Book List:\n");
    printf("5- Exit System:\n\n");



}

void uploadDataFile(int bins[], double prices[], int *size){

    FILE *file ;
     int i = 0;

    file = fopen("books.txt","r") ;

    if(file == NULL){

         printf("Error opening file.\n");
         return  ;


    }



    while (!feof(file)) {

             fscanf(file, "%d %lf", &bins[*size], &prices[*size]);
             (*size)++;

    }

    fclose(file);


}

void updateDataFile(int bins[], double prices[], int size){

    FILE *file ;
     int i = 0;

    file = fopen("books.txt","w") ;

    if(file == NULL){

         printf("Error opening file.\n");
         return  ;


    }

     for (i = 0; i < size; i++) {

        fprintf(file, "%d", bins[i]);
        fprintf(file,  "     ");
        fprintf(file,"%0.2f", prices[i]);
        if(i < size -1) fprintf(file,  "\n");
    }



    fclose(file);


}


void printBooks(int bins[], double prices[], int size){

    int i;


    for (i = 0; i < size; i++) {
        printf("bin# = %d", bins[i]);
        printf("    ");
        printf("price = %0.2f", prices[i]);
        printf("\n");
    }

}

void seachForBook(int bins[], double prices[], int size){

    int i;
    int bin ;

    printf("Enter bin number for book to search for\n");
    scanf("%d", &bin);



    if(size > 0){

    for (i = 0; i < size; i++) {

      if(bins[i] == bin){


         printf("bin# = %d", bins[i]);
         printf("    ");
         printf("price = %0.2f", prices[i]);
         printf("\n");

         return ;


      }

    }

     printf("Error:  book with bin %d is not found",bin);



    }
    else {

        printf(" BookStore is empty   ");

    }

}

void addBook(int bins[], double prices[], int *size){

    int i;
    int index = 0;
    int bin ;
    double price ;



    if( *size < MAXSIZE){

      printf("Enter bin number for book\n");
      scanf("%d", &bin);



        for (i = 0; i < *size; i++) {

            if(bins[i] == bin){

                printf("Book with bin %d is already exist\n",bin);

                return ;


            }


            if( bins[i] < bin  ){

                index = i + 1  ;

            }
        }


         printf("Enter price of book\n");
         scanf("%lf", &price);

          i = (*size);
        while ( i > index ) {
            bins[i] = bins[i-1];
            prices[i] = prices[i-1];

            i--;
            }

            bins[i] = bin;
            prices[i] = price;




     (*size) ++ ;

      printf("Book with bin %d has been added\n",bin);


    }
    else {

        printf("Error: Can't add book, Book Store has reached maximum Capacity");

    }


}

void removeBook(int bins[], double prices[], int *size){

    int i;
    int index = -1;
    int bin ;


      if(*size > 0  ){





      printf("Enter bin number for book to remove\n");
      scanf("%d", &bin);



        for (i = 0; i < *size; i++) {

            if(bins[i] == bin){

                index = i   ;

            }



        }

        if(index == -1)   {
                printf("Book with bin %d dose not exist\n",bin);
        }


        else {

                for(i = index; i < *size - 1; i++){
                    bins[i] = bins[i+1];
                    prices[i] = prices[i+1] ;
            }



     (*size) -- ;

      printf("Book with bin %d has been removed\n",bin);



        }
      }

      else {

         printf("Error: BookStore is empty");

      }




}

int main()
{

    int operation;

    int bins[MAXSIZE];
    double prices[MAXSIZE];
    int size = 0 ;


    printf("Welcome to My BookStore Management System:\n\n");

    printf("Uploading data file ...\n");

    uploadDataFile(bins,prices,&size) ;

    printf("Data File uploaded\n\n\n");

    displayMainMenu() ;


    while(1){

    scanf("%d", &operation);

    switch(operation){

        case 1:
            addBook(bins,prices,&size);
            printf("\n\n");
            displayMainMenu() ;
            break;
        case 2:
            removeBook(bins,prices,&size);
            printf("\n\n");
            displayMainMenu() ;
            break;
         case 3:
            seachForBook(bins,prices,size);
            printf("\n\n");
            displayMainMenu() ;
            break;

        case 4:
            printBooks(bins,prices,size);
            printf("\n\n");
            displayMainMenu() ;
            break;
        case 5:
             printf("Updating data file ...\n");

            updateDataFile(bins,prices,size) ;

            printf("Data File updated\n\n\n");
            printf("Thank you for using My BookStore Management System. GoodBye.\n");
            exit(0);


    }

}



    return 0;
}