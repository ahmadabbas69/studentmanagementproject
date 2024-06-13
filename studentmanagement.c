#include <stdio.h>
#include <stdlib.h>



struct Student {
int rollno;
      char first_name[15];
      char last_name[15];
      int class_num;
};

FILE *ptr;
FILE *class_file;

void save_to_class_file(int recordclass_num, char first_name[], char last_name[], int rollno) {
    if (recordclass_num == 1)
     {
        class_file = fopen("class1.txt", "a");//If the file exists, the file pointer is positioned at the end of the file.
//If the file doesn't exist, it is created.
//Any data written to the file is added to the end of the existing content, without overwriting it.
    }
     else if (recordclass_num == 2) {
        class_file = fopen("class2.txt", "a");
    }
     else if (recordclass_num == 3) {
        class_file = fopen("class3.txt", "a");
    }
     else if (recordclass_num == 4) {
        class_file = fopen("class4.txt", "a");
    }
     else if (recordclass_num == 5) {
        class_file = fopen("class5.txt", "a");
    }
     else {
        printf("Invalid class number\n");
        return;
    }

     //   fprintf(class_file, "STUDENT NAME \t CLASS \t ROLL NUMBER\n");
      fprintf(class_file, "%s %s \t%d\t\t%d\n", first_name, last_name, recordclass_num, rollno);

    fclose(class_file);
}

void save_student_info_file(struct Student student) {
    ptr = fopen("STUDENT_INFORMATION.txt", "a");

    if (ptr == NULL) {
        printf("Error opening file STUDENT_INFORMATION.txt\n");
        return;
    }

       fprintf(ptr, "%s %s \t%d\t%d\n", student.first_name, student.last_name, student.class_num, student.rollno);

    fclose(ptr);
}


void student_information();

void search_student();

void new_admission();

void start();

void lock() {
    do {
        char user_name[20];
        char password[20];

        char set_username[] = "admin";
        char set_password[] = "fast";


        printf("\n\n\n\t       <=======STUDENT MANAGEMENT SYSTEM=======>  \n");

        printf("\n\n\t\t\t Enter user name: ");
        scanf("%s", user_name);

        printf("\t\t\t Enter password: ");
        scanf("%s", password);

        int correct_U = 1;
        int correct_p = 1;

        for (int i = 0; set_username[i] != '\0' || user_name[i] != '\0'; ++i) {
            if (set_username[i] != user_name[i]) {
                correct_U = 0;
                break;
            }
        }

        for (int j = 0; set_password[j] != '\0' || password[j] != '\0'; ++j) {
            if (set_password[j] != password[j]) {
                correct_p = 0;
                break;
            }
        }

        if (correct_p && correct_U) {
            printf("\t\t\tAccess granted!\n");
            printf("\n\t\t\tPress any key to continue...");
            getchar();
            //getchar();
            start();
            } else {
            printf("\t\t\tAccess denied!\n");
            printf("\n\t\t\tPress any key to continue...");
            getchar();
            system("clear");
        }
    } while (1);
}

void student_information() {
    system("clear");
  int ch;
 int flag;
    int a;
 printf("\t\t\t<==========STUDENT INFORMATION==========>\n\n");

printf("\n\tPlease Do not Input any character Otherwise Program will not Work \n\n");
    do {
          printf("1. Press 1 to see the detail of all students\n");
           printf("2. Press 2 to see the detail of students classwise\n");
         printf("3. press 3 to enter in the main menu again\n");
             scanf("%d", &flag);
    } while (flag != 1 && flag != 2 && flag != 3);

    if (flag == 1) {
        ptr = fopen("//home//rafay//Desktop//project//STUDENT_INFORMATION.txt", "r");

        if (ptr != NULL) {
        
        //  we can also initiaze it with int data type
        
            char c;
            `
            while ((c = fgetc(ptr)) != EOF) {
                printf("%c", c);
            }

            fclose(ptr);
        
        }
         else {
            printf("Error opening file.\n");
        }

        do {
            printf("press 1 to go back\n");
            scanf("%d", &a);

            if (a == 1) 
            {
                student_information();
            }
        } 
        while (a != 1);
    } 
    else if (flag == 2) {
        int back;

        do {
          printf("1. CLASS ONE\n");
     printf("2. CLASS TWO\n");
       printf("3. CLASS THREE\n");
         printf("4. CLASS FOUR\n");
              printf("5. CLASS FIVE\n");
     do{
               printf("Enter choice (1-5)\n");
            scanf(" %d", &ch);
                if (sizeof(ch) != 4){
             printf("Wrong input\n\n");
           continue;
               } else {
           break;}
              } while(1);

        } while (ch < 1 || ch > 5);

        if (ch >= 1 && ch <= 5) {
            char filename[100];
            sprintf(filename, "//home//rafay//Desktop//project//class%d.txt", ch);
                class_file = fopen(filename, "r");

            if (class_file != NULL) {
                char c;
                while ((c = fgetc(class_file)) != EOF) {
                    printf("%c", c);
                }

                fclose(class_file);
            }

            do {
                printf("press 1 to go back");
                scanf("%d", &back);

            } while (back != 1);

            if (back == 1) {
                student_information();
         
            }
        } 
        
        else {
         
            printf("Invalid class number\n");
        
        }
   
    }
    
     else if (flag == 3) {
    
        start();
        
    }
     else {
    
        printf("Invalid choice\n");
        start();
    }
}


void new_admission() {
    system("clear");

    printf("\n\n\t\t  <==========NEW ADMISSION==========>\n");

      printf("\n\tPlease Do not Input any character Otherwise Program will not Work \n\n");
          struct Student student;
       char ch;
      //  int j = 0;

    do {
              printf("\t\tEnter First name of student : ");
            scanf("%s", student.first_name);

        printf("\t\tEnter last name of student : ");
           scanf("%s", student.last_name);

        do {
        
            printf("\t\tEnter class : (1-5) ");
            scanf("%d", &student.class_num);
        } while (student.class_num > 5 || student.class_num < 1);

do {
             printf("\t\tEnter Roll Number : ");
                scanf("%d", &student.rollno);
        
           if (sizeof(student.rollno) != 4){
                continue;
                 } else {
           break;}
} while(1);



     save_to_class_file(student.class_num, student.first_name, student.last_name, student.rollno);
         // passing value to function to save data in individual class
        save_student_info_file(student);
          // passing vlue to function to save data in All student records file
        

             printf("\t\tRECORD SUCCESSFULLY STORED......\n");

  printf("\t\tPress (Y or y) to Admission again or press (N or n) to continue\n");
     scanf(" %c", &ch);

       // j++;
        
    } 
    while (ch == 'y' || ch == 'Y');

    start();
}
 
 
 
void search_student() {
  system("clear");
  int rollno;
   int a;

   printf("\n\n\t\t\t<==========SEARCH STUDENT==========>\n\n");
    
     printf("\n\tPlease Do not Input any character Otherwise Program will not Work \n");
     
  ptr = fopen("STUDENT_INFORMATION.txt", "r");

   printf("\t\tEnter Roll Number: ");
  scanf("%d", &rollno);
    
    if (ptr == NULL) {
    
   printf("Error opening file STUDENT_INFORMATION.txt\n");
     start();
    }

    struct Student student;
    
    int recieve = 0;

    while (fscanf(ptr, "%s %s %d %d", student.first_name, student.last_name, &student.class_num, &student.rollno) == 4) {
        if (student.rollno == rollno) {
        printf("\n\n\t\tStudent Information:\n\n");
        
    printf("\t\tFirst Name: %s\n", student.first_name);
    
         printf("\t\tLast Name: %s\n", student.last_name);
         
       printf("\t\tClass: %d\n", student.class_num);
       
   printf("\t\tRoll Number: %d\n", student.rollno);
   
      printf("\n");

            recieve = 1;
            break;
        }
    }

    if (!recieve) {
    printf("Record not found\n");
    }

    fclose(ptr);

    do {
    printf("Press 1 to go back\n");
   scanf("%d", &a);

        if (a == 1) {
            start();
        }
    } while (a != 1);
} 
 
 
 
void No_of_Record() {
    system("clear");
  printf("\n\n\t\t  <==========TOTAL STUDENTS RECORDS==========>\n");
  
   printf("\n\tPlease Do not Input any character Otherwise Program will not Work \n");
 struct Student student;
 int count = 0,back;

    ptr = fopen("STUDENT_INFORMATION.txt", "r");
    if (ptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(ptr, "%s %s %d %d", student.first_name, student.last_name, &student.class_num, &student.rollno) == 4) {
        count++;
    }

    printf("\n\n\t The total number of students in our school is: %d\n", count);
    fclose(ptr);
    
    
    do{

  printf("\n\t\t   press 1 to go back: ");
  scanf("%d",&back);
  }while(back!=1);

    if(back==1){
    start();
      }
} 
 
 
 
void start()
 {
   system("clear");
    int choice;
    printf("\n\t\t <===========================================>\n");
  printf("\t\t      <===============================>\n");
   printf("\t\t <<<========== student Managment system ==========>>>\n");
    printf("\n");
  printf("\t\t1.STUDENT INFORMATION\n");
  printf("\t\t2.NEW ADMISSION\n");
    printf("\t\t3.SEARCH STUDENT\n");
 printf("\t\t4.TOTAL STUDENTS RECORDS\n");
  printf("\t\t5.EXIT\n");
   printf("\n\n\tPlease Do not Input any character Otherwise Program will not Work \n\n");
 
 do {
         printf("\t\tENTER YOUR CHOICE: ");
       scanf(" %d", &choice);
        
           if (sizeof(choice) != 4){
                continue;
                 } else {
           break;}
        } while(1);

    switch (choice) {
    
        case 1:
            student_information();
            break;

        case 2:
            new_admission();
            break;

         case 3:
            search_student();
            break;

     case 4:
            
            No_of_Record();
            break;

     case 5:
            printf("EXITING...\n");
            exit(0);
            break;

        default:
            printf("INVALID COMMAND\n");
            start();
            break;
    }
}

int main() {
    lock();
    return 0;
}
