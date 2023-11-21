#include<stdio.h>
#include<stdlib.h>

struct Employee {
    int empId;
    char empName[20];
    char empDept[20];
    float empSalary;
}emp;

struct Employee scanDetails();
void display(struct Employee);

int main() {
    struct Employee emp1;
    emp1 = scanDetails();

    display(emp1);

    return 0;
}

struct Employee scanDetails() {
    printf("\nEnter id: ");
    scanf("%d", &emp.empId);

    fflush(stdin);
    printf("Enter name: ");
    scanf("%[^\n]s", &emp.empName);

    fflush(stdin);
    printf("Enter dept: ");
    scanf("%[^\n]s", &emp.empDept);

    printf("Enter salary: ");
    scanf("%f", &emp.empSalary);

    return emp;
}

void display(struct Employee emp) {
    printf("\nDetails: \n");
    printf("\nId: %d\nName: %s\nDept: %s\nSalary: %.2f\n", emp.empId, emp.empName, emp.empDept, emp.empSalary);
}