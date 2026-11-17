// BHUMIKA VERMA 
// 590036739
#include <stdio.h>
#include <string.h>

#define SEMESTERS 8
#define MAX_STUDENTS 100

// Structure declaration
typedef struct
{

    int sapID;
    int roll_no;
    char name[100];
    char phone_no[16];
    char email[50];
    int year;
    int semester;
    float sgpa[SEMESTERS];
}
Student;

// Global variables
Student stu[MAX_STUDENTS];
int count = 0;

// Function 
void add_student_detail(void);

int findStudent(int sapid);
float getCgpa(Student s);
void displayStudent(Student s);
void searchStudent(void);
void avgCGPAyear(void);
void displayAll(void);
void deleteStudent(void);
void sortBySAP(void);
void sortByName(void);
void seedInitialData(void);

// Find student using SAP ID
int findStudent(int sapid)
{
    for (int i = 0; i < count; i++)
    {
        if (stu[i].sapID == sapid)
        {
            return i;
        }
    }
    return -1;
}

// Calculate CGPA
float getCgpa(Student s)
{
   float total = 0.0f;
    int sem = 0;
    for (int i = 0; i < s.semester; i++)
    {
        if (s.sgpa[i] > 0.0f)
        {
            total += s.sgpa[i];
            sem++;
        }
    }
    if (sem == 0)
        return 0.0f;
    return total / sem;
}

// Add student details
void add_student_detail(void)
{
  
    Student s;
    if (count >= MAX_STUDENTS)
    {
      
        printf("\nStudent limit reached!\n");
        return;
      
    }
    printf("\n Add Student Details \n");
    printf("Enter SAP ID: ");
    scanf("%d", &s.sapID);
    printf("\n");
    if (findStudent(s.sapID) != -1)
    {
      
        printf("SAP ID already exists!\n");
        return;
      
    }
   
  printf("Enter Roll number: ");
    scanf("%d", &s.roll_no);
    printf("\n");
    printf("Enter name: ");
    scanf(" %99[^\n]", s.name);
    
    printf("\n");
    printf("Enter phone number: ");
    scanf("%15s", s.phone_no);
    printf("\n");
    printf("Enter email ID: ");
    scanf("%49s", s.email);
    printf("\n");
    printf("Enter year (1-4): ");
    scanf("%d", &s.year);
    printf("\n");
  
    if (s.year < 1 || s.year > 4)
    {
        printf("Invalid year!\n");
        return;
    }
    printf("Enter semester (1-8): ");
    scanf("%d", &s.semester);
  
    if (s.semester < 1 || s.semester > 8 ||
        s.semester < (s.year - 1) * 2 + 1 ||
        s.semester > s.year * 2)
    {
      
        printf("Invalid semester for the selected year!\n");
        return;
    }
    printf("\n");

    // Initialize all SGPAs to 0
    for (int i = 0; i < SEMESTERS; i++)
    {
      
        s.sgpa[i] = 0.0f;
    }
  
    // Enter SGPA
    for (int i = 0; i < s.semester; i++)
    {
      
        do
        {
           
          printf("Enter SGPA for semester %d (0 if unavailable): ", i + 1);
            scanf("%f", &s.sgpa[i]);
            if (s.sgpa[i] < 0.0f || s.sgpa[i] > 10.0f)
            {
                printf("Invalid SGPA! Enter between 0 and 10.\n");
            }
        } while (s.sgpa[i] < 0.0f || s.sgpa[i] > 10.0f);
    }
    stu[count] = s;
    count++;
    printf("\nStudent record added successfully!\n");
}

// Display student details and personalized academic advice
void displayStudent(Student s)
{
    float cgpa = getCgpa(s);
    printf("SAP ID:              %d\n", s.sapID);
    printf("Roll number:         %d\n", s.roll_no);
    printf("Name:                %s\n", s.name);
    printf("Phone number:        %s\n", s.phone_no);
    printf("Email ID:            %s\n", s.email);
    printf("Year:                %d\n", s.year);
    printf("Current Semester:    %d\n", s.semester);
    printf("\nSGPA Details:\n");
    for (int i = 0; i < SEMESTERS; i++)
    {
        if (s.sgpa[i] > 0.0f)
            printf("Semester %d: %.2f\n", i + 1, s.sgpa[i]);
    
        else
            printf("Semester %d: Not available\n", i + 1);
    }
    printf("\nCGPA: %.2f\n", cgpa);
    
    // Personalized academic advice based on CGPA
    printf("Academic Advice: ");
    if (cgpa >= 9.0f) {
        printf("Excellent performance - Maintain your current study pattern!\n");
    } else if (cgpa >= 7.5f) {
        printf("Good performance - Try focusing on areas with lower SGPA.\n");
    } else if (cgpa >= 5.0f) {
        printf("Needs improvement - Dedicate more hours and review core concepts.\n");
    } else {
        printf("Requires immediate attention - Please connect with your advisor.\n");
    }

}

// Search student
void searchStudent(void)

{
    int sapid;
    printf("\nEnter SAP ID to search: ");
    scanf("%d", &sapid);
    int i = findStudent(sapid);
    if (i == -1)
    {
        printf("\nStudent record not found!\n");
    }
    else
    {
        printf("\nStudent record found!\n");
        displayStudent(stu[i]);
    }
}

// Calculate average CGPA by year
void avgCGPAyear(void)
{
    int year;
    int studentcount;
    float total, cgpa;
    if (count == 0)
    {
        printf("\nNo student record available.\n");
        return;
    }
    printf("\n Average CGPA by Year \n");
   
  for (year = 1; year <= 4; year++)
    {
        total = 0.0f;
        studentcount = 0;
        for (int i = 0; i < count; i++)
        {
            if (stu[i].year == year)
            {
                cgpa = getCgpa(stu[i]);
                if (cgpa > 0.0f)
                {
                    total += cgpa;
                    studentcount++;
                }
            }
        }
        printf("Year %d: ", year);
        if (studentcount > 0)
        {
            printf("Average CGPA = %.2f\n",
                   total / studentcount);
        }
        else
        {
            printf("No CGPA data available.\n");
        }
    }
}

// Display all students
void displayAll(void)
{
    if (count == 0)
    {
        printf("\nNo student record available!\n");
        return;
    }
    printf("\nAll Student Records \n");
    for (int i = 0; i < count; i++)
    {
        displayStudent(stu[i]);
    }
}

// Delete student
void deleteStudent(void)
{
  
    int sapID;
    int index;
    if (count == 0)
    {
        printf("\nNo student record available.\n");
        return;
    }
    printf("\nEnter SAP ID to delete: ");
    scanf("%d", &sapID);
    index = findStudent(sapID);
    if (index == -1)
    {
        printf("\nStudent record not found!\n");
        return;
    }
    for (int i = index; i < count - 1; i++)
    {
        stu[i] = stu[i + 1];
    }
    count--;
    printf("\nStudent record deleted successfully!\n");
}

/* Sort record by increasing SAP ID*/
void sortBySAP(void){
    Student temp;
    if(count == 0){
        printf("\nNo records available \n");
        return;
    }
    for(int i = 0; i < count; i++){
        for(int j = i + 1; j < count; j++){
            if(stu[j].sapID < stu[i].sapID){
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
    printf("\n Records sorted by increasing SAP ID\n");
    displayAll();
}

/* 
Sort student records in increasing order of name
*/
void sortByName(void){
    Student temp;
    if(count == 0){
        printf("\nNo records available \n");
        return;
    }
  
    for(int i = 0; i < count; i++){
        for(int j = i + 1; j < count; j++){
            if(strcmp(stu[j].name , stu[i].name) < 0){
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
    printf("\n Records sorted by increasing Name\n");
    displayAll();
}

// Pre-seeding initial student data for grading presentation
void seedInitialData(void)
{
  
    stu[0] = (Student){50000101, 201, "Aarav Sharma", "+919876543210", "aarav@gmail.com", 1, 1, {8.5f, 0, 0, 0, 0, 0, 0, 0}};
    stu[1] = (Student){50000102, 202, "Bhumika Sen", "+918765432109", "bhumika@gmail.com", 2, 3, {9.2f, 8.8f, 9.4f, 0, 0, 0, 0, 0}};
    stu[2] = (Student){50000103, 203, "Chaitanya Roy", "+917654321098", "chaitanya@gmail.com", 2, 3, {7.2f, 7.8f, 7.5f, 0, 0, 0, 0, 0}};
    stu[3] = (Student){50000104, 204, "Devika Patel", "+916543210987", "devika@gmail.com", 3, 5, {5.4f, 5.8f, 4.8f, 5.2f, 5.6f, 0, 0, 0}};
    stu[4] = (Student){50000105, 205, "Eshaan Verma", "+915432109876", "eshaan@gmail.com", 4, 7, {4.2f, 4.5f, 4.0f, 3.8f, 4.1f, 4.3f, 4.0f, 0}};
    count = 5;
}

// Main function
int main(void)
{
  
    seedInitialData();
    int choice;
  
  do
    {

        printf(" STUDENT MANAGEMENT SYSTEM\n");
        printf("1. Add Student Details\n");
        printf("2. Search Student\n");
        printf("3. Display All Students\n");
        printf("4. Average CGPA by Year\n");
        printf("5. Delete Student\n");
        printf("6. Sort Records by SAP ID\n");
        printf("7. Sort Records by Name\n");
        printf("8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
      switch (choice)
        {
            case 1:
                add_student_detail();
                break;
          
            case 2:
                searchStudent();
                break;
          
            case 3:
                displayAll();
                break;
          
            case 4:
                avgCGPAyear();
                break;
          
            case 5:
                deleteStudent();
                break;
          
            case 6:
                sortBySAP();
                break;
          
            case 7:
                sortByName();
                break;
          
            case 8:
                printf("\nExiting program. Thank you!\n");
                break;
          
            default:
                printf("\nInvalid choice! Please try again.\n");
        } 
    } 
     
      while (choice != 8);
    
  return 0;
}
