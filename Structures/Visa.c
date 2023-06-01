#include <stdio.h>
#include <string.h>

struct Visa
{
    char Name[50];
    char DOB[10];
    char Citicenship[50];
    char passportnumber[50];
    char DOIofPassport[50];
    char Expiry[50];
    char address[50];
};

int main(){
    
    struct Visa VisaApplicant;
    printf("Enter Applicant's Name :-  ");
    fgets(VisaApplicant.Name,sizeof(VisaApplicant.Name), stdin);

    printf("Enter Applicant's DOB :-  ");
    fgets(VisaApplicant.DOB, sizeof(VisaApplicant.DOB), stdin);

    printf("Enter Applicant's Citizenship :-  ");
    fgets(VisaApplicant.Citicenship, sizeof(VisaApplicant.Citicenship), stdin);

    printf("Enter Applicant's PassportNumber :-  ");
    fgets(VisaApplicant.passportnumber, sizeof(VisaApplicant.passportnumber), stdin);

    printf("Enter Applicant's Expiry :-  ");
    fgets(VisaApplicant.Expiry, sizeof(VisaApplicant.Expiry), stdin);

    printf("Enter Applicant's Address :-  ");
    fgets(VisaApplicant.address, sizeof(VisaApplicant.address), stdin);


    printf("\nApplicants Name:- %s" , VisaApplicant.Name);
printf("Applicant's DOB = %s", VisaApplicant.DOB);
printf("Applicant's Citizenship = %s", VisaApplicant.Citicenship);
printf("Applicant's DOI OF Password = %s", VisaApplicant.passportnumber);
printf("Applicant's Expiry = %s", VisaApplicant.Expiry);
printf("Applicant's Address = %s", VisaApplicant.address);

    return 0;
}

